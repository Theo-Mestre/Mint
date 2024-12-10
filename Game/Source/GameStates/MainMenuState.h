#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Graphics.hpp>

#include "Core/State.h"
#include "Core/AssetManagment/Assets.h"

#include "Core/Sprites/StaticSprite.h"
#include "Core/Sprites/Sprite.h"
#include "Core/Text.h"

#include "Core/UI/UIRenderer.h"

class MainMenuState
	: public Core::State
{
public:
	MainMenuState();
	~MainMenuState();

	virtual void Load() override;
	virtual void OnEventReceived(const Core::Event& _event) override;
	virtual void Update() override;
	virtual void Render(Ref<Core::Renderer> _renderer) override;
	virtual void Unload() override;

private:
	void InitSprite();

private:
	Core::Text m_title;

	Core::StaticSprite m_background;
	Core::Sprite m_sprite;

	Core::UI::UIRenderer m_uiRenderer;
	Core::UI::UIElement m_rootElement;

	Core::StaticSprite m_uiSprite;
	Ref<Core::Texture2D> m_uiTexture;
};

#endif