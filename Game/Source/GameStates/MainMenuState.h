#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Graphics.hpp>

#include "Mint/State.h"
#include "Mint/AssetManagment/Assets.h"

#include "Mint/Sprites/StaticSprite.h"
#include "Mint/Sprites/Sprite.h"
#include "Mint/Text.h"

#include "Mint/UI/UIRenderer.h"

class MainMenuState
	: public Mint::State
{
public:
	MainMenuState();
	~MainMenuState();

	virtual void Load() override;
	virtual void OnEventReceived(const Mint::Event& _event) override;
	virtual void Update() override;
	virtual void Render(Ref<Mint::Renderer> _renderer) override;
	virtual void Unload() override;

private:
	void InitSprite();

private:
	Mint::Text m_title;

	Mint::StaticSprite m_background;
	Mint::Sprite m_sprite;

	Mint::UI::UIRenderer m_uiRenderer;
	Mint::UI::UIElement m_rootElement;

	Mint::StaticSprite m_uiSprite;
	Ref<Mint::Texture2D> m_uiTexture;
};

#endif