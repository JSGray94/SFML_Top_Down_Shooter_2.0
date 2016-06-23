#include "Game.h"
#include "TextureHolder.h"

//The constructor for the game class.
Game::Game()
	: mWindow(sf::VideoMode(1366, 768), "Top Down Shooter")
	, mTexture()
	, mPlayer()
{
	TextureHolder textures;
	textures.load(Textures::Airplane, "res/sprite.png");

	mPlayer.setTexture(textures.get(Textures::Airplane));
	mPlayer.setPosition(100, 100);
}

//The main run method.
//This runs at a consistant fps no matter the system.
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

//Handles player input.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		isMovingUp = isPressed;
	if (key == sf::Keyboard::A)
		isMovingLeft = isPressed;
	if (key == sf::Keyboard::S)
		isMovingDown = isPressed;
	if (key == sf::Keyboard::D)
		isMovingRight = isPressed;
}

//Handles things like player input etc.
void Game::processEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

//This function updates game logic
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (isMovingUp)
		movement.y -= playerSpeed;
	if (isMovingDown)
		movement.y += playerSpeed;
	if (isMovingLeft)
		movement.x -= playerSpeed;
	if (isMovingRight)
		movement.x += playerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

//This function updates the game screen
void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}