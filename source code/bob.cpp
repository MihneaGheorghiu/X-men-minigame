#include "stdafx.h"
#include "bob.h"

Bob::Bob()
{
	// How fast does Psylcoke move?
	m_Speed = 400;

	indice_wr = 0;
	indice_wl = 0;
	indice_sb = 0;

	// Associate a texture with the sprite
	//starting in right looking position
	look_position = 0;
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

	//adding textures for wl - will rewrite later in a better fashion
	wl_Texture[0].loadFromFile("wl1.png");
	wl_Texture[1].loadFromFile("wl2.png");
	wl_Texture[2].loadFromFile("wl3.png");
	wl_Texture[3].loadFromFile("wl4.png");
	wl_Texture[4].loadFromFile("wl5.png");
	wl_Texture[5].loadFromFile("wl6.png");
	wl_Texture[6].loadFromFile("wl7.png");
	wl_Texture[7].loadFromFile("wl8.png");
	wl_Texture[8].loadFromFile("wl9.png");
	wl_Texture[9].loadFromFile("wl10.png");
	wl_Texture[10].loadFromFile("wl11.png");
	wl_Texture[11].loadFromFile("wl12.png");
	wl_Texture[12].loadFromFile("wl13.png");

	sb_Texture[0].loadFromFile("speed1.png");
	sb_Texture[1].loadFromFile("speed2.png");
	sb_Texture[2].loadFromFile("speed3.png");

	//m_Sprite.setTexture(m_Texture);
	//m_Position.x = 100;
	//m_Position.y = 200;

	//load the walking right textures
	//wr_Texture[0].loadFromFile();
	
}

// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
	
	return m_Sprite;
}

int Bob::getXPosition()
{
	//printf("get position x = %f\n", m_Position.x);
	return m_Position.x;
}

void Bob::movePos(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	//printf("x = %f, y = %f\n", m_Position.x, m_Position.y);
}

void Bob::moveLeft()
{
	m_LeftPressed = true;
	look_position = 1;
}

void Bob::moveRight()
{
	m_RightPressed = true;
	look_position = 0;
	//m_Texture.loadFromFile("wr1.png");
	//m_Sprite.setTexture(m_Texture);
}

void Bob::stopLeft()
{
	m_LeftPressed = false;
	if( look_position == 1)
		m_Texture.loadFromFile("psy_start_2.png");
	m_Sprite.setTexture(m_Texture);
	indice_wl = 0;
}

void Bob::stopRight()
{
	m_RightPressed = false;
	if( look_position == 0)
		m_Texture.loadFromFile("psy_start_1.png");
	m_Sprite.setTexture(m_Texture, true);
	indice_wr = 0;

}

//move psylocke across the screen
void Bob::sbFlight(float elapsedTime)
{
	

	if ( m_Position.x < 1300)
	{
		if (indice_sb == 3)
			indice_sb = 0;
		m_Sprite.setTexture(sb_Texture[indice_sb], true);
		m_Sprite.setPosition(m_Position.x, m_Position.y);
		Sleep(75);//so the textures don't change to quickly, will review later
		indice_sb++;
		
		m_Position.x += m_Speed * elapsedTime / 2;
		m_Position.y += m_Speed * elapsedTime / 5;
	}

	//prepare for game level
	//m_Texture.loadFromFile("psy_start_1.png");
	//m_Sprite.setTexture(m_Texture);

	
}

// Move Psylocke based on the input this frame,
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
		if (indice_wl == 13)
			indice_wl = 0;
		m_Sprite.setTexture(wl_Texture[indice_wl]);
		Sleep(75);//so the textures don't change to quickly, will review later
		indice_wl++;
		
		if(m_Position.x > 0)
			m_Position.x -= m_Speed * elapsedTime / 2;
	}

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);

}