#pragma once
#include "constants.h"

// single pipe
struct Pipe : public sf::Sprite {

	// methods
	Pipe(sf::Texture& texture, float x, float y);
};

// pipe pairs
struct PipePair {

	// store top and bottom pipes
	std::tuple<Pipe*, Pipe*> pipes;

	// position
	float xPos = 0.0f;
	const float WIDTH = 50.0f;
	const float HEIGHT = 800.0f;

	// mechanics
	const float vel = -150.0f;

	// decides if user gets point from bird passing
	bool hasPoint = 1;

	// methods
	PipePair(Pipe* p1, Pipe* p2);
	void draw(sf::RenderWindow& window);
	void move(float pixels);
	Pipe* getpipe(int index);
	int checkCollision(float x, float y, float w, float h);
	int checkCollision(float x, float y, float r);
	int checkPassed(float x);
};