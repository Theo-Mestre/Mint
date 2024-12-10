#include "gamepch.h"
#include "MainMenuState.h"

#include "Mint/Logger.h"
#include "Mint/Managers/Manager.h"
#include "Mint/Window/Window.h"
#include "Mint/Managers/Renderer.h"
#include "Mint/AssetManagment/AssetsManager.h"
#include "Mint/Managers/StateManager.h"
#include "Mint/Time.h"
#include "Mint/Inputs/Inputs.h"

MainMenuState::MainMenuState()
	: m_uiRenderer(Mint::UI::Size(1920, 1080))
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Load()
{
	auto assetsManager = Manager::GetManager<AssetsManager>();

	auto tex2D = assetsManager->LoadAsset<Mint::Texture2D>("Textures/Background.png");
	m_background.SetTexture(tex2D);

	auto font = assetsManager->LoadAsset<Mint::Font>("Fonts/Font.ttf");
	m_title.SetFont(font);
	m_title.setString("Main Menu");
	m_title.setCharacterSize(72);

	InitSprite();
	

	m_uiTexture = CreateRef<Mint::Texture2D>();

	Mint::UI::Style style;
	style.Deserialize("Styles/style.style");
	m_rootElement.SetStyle(style);


	Mint::UI::UIElement* element = new Mint::UI::UIElement();
	Mint::UI::Style style2;
	style2.Bound.position = { 25, 50 };
	style2.Bound.size = { 150, 40 };
	style2.BackgroundColor = Mint::UI::Color::Blue;
	style2.ResetResolvedBound();
	element->SetStyle(style2);

	Mint::UI::UIElement* element2 = new Mint::UI::UIElement();
	style2.Bound.position = { 50, 50 };
	style2.BackgroundColor = Mint::UI::Color::Cyan;
	element2->SetStyle(style2);

	m_rootElement.Add(element);
	m_rootElement.Add(element2);
}

void MainMenuState::InitSprite()
{
	auto assetsManager = Manager::GetManager<AssetsManager>();

	Mint::Animation::Data data;
	data.texture = assetsManager->LoadAsset<Mint::Texture2D>("Textures/PlayerWoodMan.png");
	data.frameNumber = 6;
	data.frameY = 48;
	data.frameWidth = 48;
	data.frameHeight = 48;
	data.frameTime = 0.1f;

	m_sprite = Mint::Sprite(data);
	m_sprite.Init();
	m_sprite.setScale(3, 3);
	m_sprite.setPosition(100, 100);
}

void MainMenuState::OnEventReceived(const Mint::Event& _event)
{
	if (_event.type == sf::Event::KeyPressed)
	{
		if (_event.key.code == sf::Keyboard::Space)
		{
			auto direction = m_sprite.GetDirection();
			direction = direction == Mint::AnimDirection::Forward ? Mint::AnimDirection::Backward : Mint::AnimDirection::Forward;
			m_sprite.SetDirection(direction);
		}
	}
}

void MainMenuState::Update()
{
	m_sprite.Update();
}

void MainMenuState::Render(Ref<Mint::Renderer> _renderer)
{
	m_uiRenderer.Submit(&m_rootElement);
	m_uiRenderer.Render();

	_renderer->Submit(&m_background);
	_renderer->Submit(&m_title);
	_renderer->Submit(&m_sprite);

	m_uiTexture->Get() = m_uiRenderer.GetRenderTexture().getTexture();
	m_uiSprite.SetTexture(m_uiTexture);

	_renderer->Submit(&m_uiSprite);
}

void MainMenuState::Unload()
{
}