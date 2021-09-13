
/* modules and libraries */
#include "SFML/Graphics.hpp"
#include "text.h"

/* score text */
ScoreText::ScoreText() {
	font.loadFromFile("assets/Fonts/Pangolin-Regular.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Color(0, 0, 0));
	text.setPosition(280, 10);
	text.setString("0");
}

void ScoreText::addPoint() {
	score++;
	text.setString(std::to_string(score));
}
