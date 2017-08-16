#include "stdafx.h"
#include "bob.h"

Bob::Bob()
{
	// How fast does Bob move?
	m_Speed = 400;
	indice_wr = 0;

	// Associate a texture with the sprite
	//m_Texture.loadFromFile("bob.png");

	m_Texture.loadFromFile("psy_start_1.png");
	//will rewrite later in a better fashion
	wr_Texture[0].loadFromFile("wr1.png");
	wr_Texture[1].loadFromFile("wr2.png");
	wr_Texture[2].loadFromFile("wr3.png");
	wr_Texture[3].loadFromFile("wr4.png");
	wr_Texture[4].loadFromFile("wr5.png");
	wr_Texture[5].loadFromFile("wr6.png");
	wr_Texture[6].loadFromFile("wr7.png");
	wr_Texture[7].loadFromFile("wr8.png");
	wr_Texture[8].loadFromFile("wr9.png");
	wr_Texture[9].loadFromFile("wr10.png");
	wr_Texture[10].loadFromFile("wr11.png");
	wr_Texture[11].loadFromFile("wr12.png");
	wr_Texture[12].loadFromFile("wr13.png");


	m_Sprite.setTexture(m_Texture);


	//load the walking right textures
	//wr_Texture[0].loadFromFile();
	
	
	// Set the Bob's starting position
	m_Position.x = 640;
	m_Position.y = 530;

}

// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
	
	return m_Sprite;
}

void Bob::moveLeft()
{
	m_LeftPressed = true;
}

void Bob::moveRight()
{
	m_RightPressed = true;
	//m_Texture.loadFromFile("wr1.png");
	//m_Sprite.setTexture(m_Texture);
}

void Bob::stopLeft()
{
	m_LeftPressed = false;
}

void Bob::stopRight()
{
	m_RightPressed = false;
	m_Texture.loadFromFile("psy_start_1.png");
	m_Sprite.setTexture(m_Texture);
	indice_wr = 0;

}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		if (indice_wr == 13)
			indice_wr = 0;
		m_Sprite.setTexture(wr_Texture[indice_wr]);
		Sleep(75);//so the textures don't change to quickly, will review later
		indice_wr++;
		if(m_Position.x < 1200)
			m_Position.x += m_Speed * elapsedTime / 2;
	}

	

	if (m_LeftPressed)
	{
		if(m_Position.x > 0)
			m_Position.x -= m_Speed * elapsedTime;
	}

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);

}