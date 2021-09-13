
// modules and libraries
#include "SFML/Graphics.hpp"
#include "bird.h"

// bird
NewBird::NewBird(sf::Texture& Texture_0, sf::Texture Texture_1) : sf::Sprite{ Texture_0 } {
	setPosition(xPos, getPosition().y);
	texture_0 = Texture_0;
	texture_1 = Texture_1;
}

void NewBird::flapwing(float num) {
	flap += num;
	if (flap > flapDelay) {
		flap -= flapDelay;
		texture = !texture;
		if (texture) { setTexture(texture_1); }
		else { setTexture(texture_0); }
	}
}
