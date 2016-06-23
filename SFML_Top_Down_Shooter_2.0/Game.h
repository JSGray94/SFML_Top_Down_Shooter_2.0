#pragma once

#include <SFML\Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow mWindow;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;

	float playerSpeed = 200.0f;

	//60fps
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
};

