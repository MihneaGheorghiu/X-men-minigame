#include "stdafx.h"
#include "engine.h"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	printf("Rezolutie %d x %d", resolution.x, resolution.y);
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"x-men test game",
		Style::Fullscreen);

	m_BackgroundTexture.loadFromFile("start_screen.jpg");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	

	// Load the background into the texture
	// Be sure to scale this image to your screen size
	

}

void Engine::introCutscene()
{
	m_BackgroundTexture.loadFromFile("intro_cutscene.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	Clock clock;
	
	m_Bob.movePos(0, 100);
	
	while ( m_Bob.getXPosition() < 1300)
	{
		Time dt = clock.restart();
		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		m_Bob.sbFlight(dtAsSeconds);
		draw();
	}

	// Set the Psylcoke's starting position - for game level
	m_Bob.movePos(640, 530);
	//set starting sprite
	//m_Bob.
	
}

void Engine::start()
{
	// Timing
	Clock clock;
	int start = 0;

	while (m_Window.isOpen())
	{
		//start screen
		if (start == 0)
		{
			m_Window.draw(m_BackgroundSprite);
			m_Window.display();
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				start = 1;
				
			}
		}

		//introduction cutscene
		if (start == 1)
		{
			introCutscene();
			start = 2;
			m_BackgroundTexture.loadFromFile("background.jpg");

			// Associate the sprite with the texture
			m_BackgroundSprite.setTexture(m_BackgroundTexture);
		}

		//level screen
		if (start == 2)
		{
			// Restart the clock and save the elapsed time into dt
			Time dt = clock.restart();

			// Make a fraction from the delta time
			float dtAsSeconds = dt.asSeconds();
			//while( dtAsSeconds = dt.asSeconds() < 0.05)
			//	;

			input();
			//printf("secunde %f \n", dtAsSeconds);
			update(dtAsSeconds);
			draw();
		}
	}
}