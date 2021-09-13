#pragma once


struct NewBird : public sf::Sprite {

	// position
	const float width = 50.0f;
	const float height = 50.0f;
	const float xPos = 50.0f;

	// mechanics
	const float acceleration = 1000.0f;
	const float maxFallingVel = 400.0f;
	const float jumpVel = -400.0f;
	float vel = 0.0f;

	// graphics
	float flap = 0.0f;
	const float flapDelay = 0.1f;
	int texture = 0;
	sf::Texture texture_0, texture_1;

	// methods
	NewBird(sf::Texture& Texture_0, sf::Texture Texture_1);
	void flapwing(float num);
};




