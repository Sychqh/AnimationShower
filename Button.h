#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>

namespace am {
	class Button {
	private:
		sf::Texture m_texture;
		sf::RectangleShape m_shape;
		//sf::Sprite m_sprite;

		sf::Font m_font;
		sf::Text m_text;

		sf::SoundBuffer m_sBufMenuScroll;
		sf::SoundBuffer m_sBufMenuClick;
		sf::Sound m_sound;
		bool m_soundPlayedScroll;
		bool m_soundPlayedClick;
	public:
		Button();
		~Button();
		Button(std::string string, sf::Vector2f position);

		void Draw(sf::RenderWindow& window) const;

		bool UnderCursor(sf::RenderWindow& window);

		void Update(sf::RenderWindow& window, int& currentAnim, int animChange);
	};
}

