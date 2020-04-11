#pragma once
#include <SFML\Graphics.hpp>
namespace am {
	class Animation {
	private:
		sf::Vector2u m_imageCount;
		sf::Vector2u m_currentImage;
		float m_totalTime;
		float m_switchTime;

	public:
		sf::IntRect m_uvRect;

	public:
		Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~Animation();

		void Update(int row, float deltaTime);

		void Set(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	};
}
