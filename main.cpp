#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Button.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Animation Shower");

	sf::RectangleShape bg(sf::Vector2f(800.0f, 600.0f));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("Resources/Images/background.png");
	bg.setTexture(&bgTexture);

	sf::RectangleShape player(sf::Vector2f(256.0f, 256.0f));
	player.setPosition(sf::Vector2f(160.0f, 195.0f));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Resources/Sprites/slimeSprite.png");
	player.setTexture(&playerTexture);

	am::Animation animation(&playerTexture, sf::Vector2u(3, 3), 0.2f);

	float deltaTime = 0.0f;
	sf::Clock clock;
	float timeAnim = 0.0f;
	int currentAnim = 0;

	am::Button bt1("Idle", sf::Vector2f(500.0f, 200.0f));
	am::Button bt2("Jump", sf::Vector2f(500.0f, 300.0f));
	am::Button bt3("Fall", sf::Vector2f(500.0f, 400.0f));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			
			}
		}
		deltaTime = clock.restart().asSeconds();
	
		bt1.Update(window, currentAnim, 0);
		bt2.Update(window, currentAnim, 1);
		bt3.Update(window, currentAnim, 2);

		animation.Update(currentAnim, deltaTime);
		player.setTextureRect(animation.m_uvRect);
	
		window.clear();
		window.draw(bg);
		window.draw(player);
		bt1.Draw(window);
		bt2.Draw(window);
		bt3.Draw(window);
		window.display();
	}

	return 0;
}