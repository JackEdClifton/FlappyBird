#pragma once

/* score text */
struct ScoreText : sf::Font, sf::Text {
	int score = 0;
	sf::Font font;
	sf::Text text;
	ScoreText();
	void addPoint();
};