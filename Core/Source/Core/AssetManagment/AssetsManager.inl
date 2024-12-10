#include "AssetsManager.h"

inline AssetsManager::AssetsManager()
{
	m_assets.reserve((size_t)Core::Asset::Type::Count);
}
inline AssetsManager::~AssetsManager()
{
	UnloadAllAssets();
}

template <typename T>
inline Ref<T> AssetsManager::LoadAsset(const char* _assetName)
{
	static_assert(std::is_base_of<Core::Asset, T>::value, "T must be a subclass of Asset");

	// Check if asset is already loaded
	if (IsAssetLoaded(_assetName))
	{
		return GetAsset<T>(_assetName);
	}

	// Create asset
	Ref<T> asset = AddAssets<T>();
	asset->Load(_assetName);

	return asset;
}

template <typename T>
inline void AssetsManager::UnloadAsset(Ref<T> _asset)
{
	static_assert(std::is_base_of<Core::Asset, T>::value, "T must be a subclass of Asset");

	_asset->Unload();

	// Remove from assets
	auto& assets = m_assets[std::type_index(typeid(T))];
	assets.erase(std::remove(assets.begin(), assets.end(), _asset), assets.end());

	// Remove from loaded assets
	m_loadedAssets.erase(_asset->GetName());
}

inline void AssetsManager::UnloadAllAssets()
{
	for (auto& pair : m_assets)
	{
		for (auto& asset : pair.second)
		{
			asset->Unload();
		}
		pair.second.clear();
	}
	m_loadedAssets.clear();
}

inline bool AssetsManager::IsAssetLoaded(const char* _assetName)
{
	return m_loadedAssets.find(_assetName) != m_loadedAssets.end();
}

template <typename T>
inline Ref<T> AssetsManager::GetAsset(const char* _assetName)
{
	static_assert(std::is_base_of<Core::Asset, T>::value, "T must be a subclass of Asset");

	auto& assets = m_assets[std::type_index(typeid(T))];
	auto compare = [&_assetName](const Ref<Core::Asset>& _asset) { return _asset->GetName().c_str() == _assetName; };

	auto asset = std::find_if(assets.begin(), assets.end(), compare);

	if (asset != assets.end())
	{
		return std::static_pointer_cast<T>(*asset);
	}

	LogError("Asset not found: {}", _assetName);
	return nullptr;
}

template <typename T>
inline Ref<T> AssetsManager::AddAssets()
{
	auto typeIndex = std::type_index(typeid(T));
	if (m_assets.find(typeIndex) == m_assets.end())
	{
		m_assets[typeIndex] = std::vector<Ref<Core::Asset>>();
	}

	std::vector<Ref<Core::Asset>>& assets = m_assets[typeIndex];
	Ref<T> asset = CreateRef<T>();
	assets.push_back(asset);

	return asset;
}