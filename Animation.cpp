#include "Animation.h"

am::Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	m_imageCount = imageCount;
	m_currentImage.x = 0;

	m_switchTime = switchTime;
	m_totalTime = 0.0f;

	m_uvRect.width = texture->getSize().x / float(imageCount.x);
	m_uvRect.height = texture->getSize().y / float(imageCount.y);
}

am::Animation::~Animation()
{
}

void am::Animation::Update(int row, float deltaTime) {
	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime) {
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x) {
			m_currentImage.x = 0;
		}
	}

	m_uvRect.left = m_currentImage.x * m_uvRect.width;
	m_uvRect.top = m_currentImage.y * m_uvRect.height;
}

void am::Animation::Set(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	m_imageCount = imageCount;
	m_currentImage.x = 0;

	m_switchTime = switchTime;
	m_totalTime = 0.0f;

	m_uvRect.width = texture->getSize().x / float(imageCount.x);
	m_uvRect.height = texture->getSize().y / float(imageCount.y);
}