#pragma once
//#include <SFML/Graphics.hpp>
#include "stdafx.h"

using namespace sf;

class Bob
{
	// All the private variables can only be accessed internally
private:

	// Where is Bob
	Vector2f m_Position;

	// Of course we will need a sprite
	Sprite m_Sprite;

	// And a texture...for each frame
	Texture m_Texture;
	Texture wr_Texture[13]; //textures for walking right
	Texture wl_Texture[13]; //textures for walking left
	Texture sb_Texture[3]; //texture for the speedbike intro

	int indice_wr;
	int indice_wl;
	int indice_sb;

	int look_position; //standard standing position for psylocke
					  // will be 0 for looking right and 1 for left

	// Which direction(s) is the player currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	// Bob's speed in pixels per second
	float m_Speed;

	// Public functions
public:

	// We will set Bob up in the constructor
	Bob();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Move Bob in a specific direction
	void moveLeft();

	void moveRight();

	// Stop Bob moving in a specific direction
	void stopLeft();

	void stopRight();

	// We will call this function once every frame
	void update(float elapsedTime);

	void movePos(float x, float y);

	int getXPosition();

	void sbFlight(float elapsedTime);

};