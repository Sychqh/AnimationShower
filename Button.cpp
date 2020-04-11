#include "Button.h"

am::Button::Button()
{
}

am::Button::~Button()
{
}

am::Button::Button(std::string string, sf::Vector2f position) {
	m_texture.loadFromFile("Resources/Images/button.png");
	
	m_shape.setSize((sf::Vector2f)m_texture.getSize());
	m_shape.setTexture(&m_texture);
	m_shape.setPosition(position);

	m_shape.setOrigin(sf::Vector2f(m_shape.getSize().x / 2, m_shape.getSize().y / 2));

	m_font.loadFromFile("Resources/VTKS BLOCKETO.ttf");

	m_text.setString(string);
	m_text.setFont(m_font);
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(sf::Vector2f(position.x, position.y));

	m_sBufMenuScroll.loadFromFile("Resources/Sounds/menuScroll.wav");
	m_sBufMenuClick.loadFromFile("Resources/Sounds/menuClick.wav");

	m_soundPlayedScroll = false;
	m_soundPlayedClick = false;
	//m_sprite.getTextureRect().
}

void am::Button::Draw(sf::RenderWindow& window) const {
	window.draw(m_shape);
	window.draw(m_text);
}

bool am::Button::UnderCursor(sf::RenderWindow& window) {
	if (sf::Mouse::getPosition(window).x > m_shape.getPosition().x - m_shape.getOrigin().x
		&& sf::Mouse::getPosition(window).y > + m_shape.getPosition().y - m_shape.getOrigin().y
		&& sf::Mouse::getPosition(window).x < + m_shape.getPosition().x + m_shape.getSize().x - m_shape.getOrigin().x
		&& sf::Mouse::getPosition(window).y < + m_shape.getPosition().y + m_shape.getSize().y - m_shape.getOrigin().y) {
		
		m_shape.setFillColor(sf::Color::Green);
	   
		m_shape.setScale(sf::Vector2f(1.1f, 1.1f));
		m_text.setScale(sf::Vector2f(1.1f, 1.1f));

		if (!m_soundPlayedScroll) {
			m_sound.setBuffer(m_sBufMenuScroll);
			m_sound.play();
			
			m_soundPlayedScroll = true;
		}

		return true;
	}
	else {
		m_soundPlayedScroll = false;

		m_shape.setFillColor(sf::Color::Cyan);

		m_shape.setScale(sf::Vector2f(1.0f, 1.0f));
		m_text.setScale(sf::Vector2f(1.0f, 1.0f));

		return false;
	}
}

void am::Button::Update(sf::RenderWindow& window, int& currentAnim, int animChange) {
	if (UnderCursor(window)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			currentAnim = animChange;
		
			if (!m_soundPlayedClick) {
				m_sound.setBuffer(m_sBufMenuClick);
				m_sound.play();

				m_soundPlayedClick = true;
			}
			
			m_shape.setScale(sf::Vector2f(0.9f, 0.9f));
			m_text.setScale(sf::Vector2f(0.9f, 0.9f));
		}
		else {
			m_soundPlayedClick = false;
		}
	}
}
