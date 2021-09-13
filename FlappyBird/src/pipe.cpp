
#include <iostream>

// modules and libraries
#include "SFML/Graphics.hpp"
#include "constants.h"
#include "pipe.h"
#include "times.h"


Pipe::Pipe(sf::Texture& texture, float x, float y) : sf::Sprite{ texture } {
	setPosition(x, y);
}


PipePair::PipePair(Pipe* p1, Pipe* p2) {
	pipes = std::make_tuple(
		p1, p2
	);
}

// draw pipes
void PipePair::draw(sf::RenderWindow& window) {
	auto p1 = *std::get<0>(pipes);
	auto p2 = *std::get<1>(pipes);
	window.draw(p1);
	window.draw(p2);
}

// move pipes
void PipePair::move(float pixels) {
	
	// wrap around screen
	if (xPos < -WIDTH) {
		pixels += CONST::PIPE_COUNT * CONST::PIPE_GAP;
		hasPoint = true;

		// set to random height
		auto position = (*getpipe(0)).getPosition();
		auto pipeX = position.x;
		auto pipeY = position.y;
		pipeY = static_cast<float>(randint(50, CONST::WINDOW_HEIGHT - 250));
		(*getpipe(0)).setPosition(pipeX, pipeY-HEIGHT);
		(*getpipe(1)).setPosition(pipeX, pipeY + 200.0f);

	}

	// move both pipes
	(*std::get<0>(pipes)).move(pixels, 0.0f);
	(*std::get<1>(pipes)).move(pixels, 0.0f);
	
	// reset object position attribute
	xPos = (*std::get<0>(pipes)).getPosition().x;
}

// pipe getter
Pipe* PipePair::getpipe(int index) {
	if (!index) { return std::get<0>(pipes); }
	else { return std::get<1>(pipes); }
}


// birds collision (circle)
int PipePair::checkCollision(float x, float y, float r) {

	// move bird position to reference center
	x += r / 2;
	y += r / 2;

	// get corner positions of pipes
	float x1 = xPos;
	float x2 = xPos + WIDTH;
	float y1 = getpipe(0)->getPosition().y + 
		
		
		
		HEIGHT;
	float y2 = getpipe(1)->getPosition().y;

	// get distances
	float dx = 0;
	float dy1 = y1 - y;
	float dy2 = y2 - y;
	
	// bird if left of pipes, use left corner
	if (x < xPos)
		dx = x1 - x;

	// bird is right of pipes, use right corner
	else if (x > xPos + WIDTH)
		dx = x - x2;

	// check for collision
	if (r*r > (dx * dx) + (dy1 * dy1)) std::cout << "Top\n";
	if (r*r > (dx * dx) + (dy2 * dy2)) std::cout << "Bottom\n";
	
	// no collision
	return 0;
}


// bird collision (rect)
int PipePair::checkCollision(float x, float y, float w, float h) {

	// check collision with pipes
	if (x + w > xPos && x < xPos + WIDTH) {
		if (y < 
			
			
			HEIGHT + (*getpipe(0)).getPosition().y || y + h > (*getpipe(1)).getPosition().y) {
			return 1;
		}
	}
	// check collision with screen
	if ((y < 0) || ((y + h) > CONST::WINDOW_HEIGHT)) {
		return 1;
	}
	return 0;
}

// if bird passes give point
int PipePair::checkPassed(float x) {
	if ((x > xPos + WIDTH) && hasPoint) {
		hasPoint = false;
		return true;
	}
	return false;
}

