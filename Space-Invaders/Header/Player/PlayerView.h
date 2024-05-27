#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"
namespace Player
{
	class PlayerView
	{
	private:

		const sf::String player_texture_path = "assets/textures/player_ship.png";
		const float player_sprite_width = 60.f;
		const float player_sprite_Height = 60.f;
		sf::RenderWindow* gameWindow;
		sf::Texture playerTexture;
		sf::Sprite playerSprite;
		PlayerController* playerController;
		void initializePlayerScript();
		void scaleSprite();
	public:
		PlayerView();
		~PlayerView();
		void initialize(PlayerController* _playerController);
		void update();
		void render();
	};
}
