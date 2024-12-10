#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "Assets.h"
#include "Mint/Logger.h"
#include "Mint/Utilities/Ref.h"

/**
 * @class AssetsManager
 * @brief This class is responsible for managing the assets in the game.
 * It provides functionalities to load, unload and retrieve assets.
 */
class AssetsManager
{
public:
	// Type alias for a map that stores assets by their type.
	using AssetsMap = std::unordered_map<std::type_index, std::vector<std::shared_ptr<Mint::Asset>>>;

public:
	/**
	* @brief Default constructor for AssetsManager.
	*/
	AssetsManager();

	/**
	* @brief Destructor for AssetsManager.
	*/
	~AssetsManager();

    /**
     * @brief Copy constructor is deleted for AssetsManager.
     */
    AssetsManager(const AssetsManager&) = delete;

    /**
     * @brief Move constructor is deleted for AssetsManager.
     */
    AssetsManager(AssetsManager&&) = delete;

    /**
     * @brief Copy assignment operator is deleted for AssetsManager.
     */
    AssetsManager& operator=(const AssetsManager&) = delete;

    /**
     * @brief Move assignment operator is deleted for AssetsManager.
     */
    AssetsManager& operator=(AssetsManager&&) = delete;

	/**
	* @brief Loads an asset of type T.
	* @param _assetName The name of the asset to load.
	* @return A reference to the loaded asset.
	*/
	template <typename T>
	Ref<T> LoadAsset(const char* _assetName);

	/**
	* @brief Unloads an asset of type T.
	* @param _asset The asset to unload.
	*/
	template <typename T>
	void UnloadAsset(Ref<T> _asset);

	/**
	* @brief Unloads all assets.
	*/
	void UnloadAllAssets();

	/**
	* @brief Checks if an asset is loaded.
	* @param _assetName The name of the asset to check.
	* @return True if the asset is loaded, false otherwise.
	*/
	bool IsAssetLoaded(const char* _assetName);

	/**
	* @brief Retrieves an asset of type T.
	* @param _assetName The name of the asset to retrieve.
	* @return A reference to the asset.
	*/
	template <typename T>
	Ref<T> GetAsset(const char* _assetName);

private:
	/**
	* @brief Adds an asset of type T to the assets map.
	* @return A reference to the added asset.
	*/
	template <typename T>
	Ref<T> AddAssets();

private:
	// Map of assets by their type.
	AssetsMap m_assets;
	// Set of loaded assets.
	std::unordered_set<std::string> m_loadedAssets;
};

#include "AssetsManager.inl"
#endif
