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
		"Simple Game Engine",
		Style::Fullscreen);

	m_BackgroundTexture.loadFromFile("start_screen.jpg");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	

	// Load the background into the texture
	// Be sure to scale this image to your screen size
	

}

void Engine::start()
{
	// Timing
	Clock clock;
	int start = 0;

	while (m_Window.isOpen())
	{
		if (start == 0)
		{
			m_Window.draw(m_BackgroundSprite);
			m_Window.display();
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				start = 1;
				m_BackgroundTexture.loadFromFile("background.jpg");

				// Associate the sprite with the texture
				m_BackgroundSprite.setTexture(m_BackgroundTexture);
			}
		}
		if (start == 1)
		{
			// Restart the clock and save the elapsed time into dt
			Time dt = clock.restart();

			// Make a fraction from the delta time
			float dtAsSeconds = dt.asSeconds();
			//while( dtAsSeconds = dt.asSeconds() < 0.05)
				;

			input();
			//printf("secunde %f \n", dtAsSeconds);
			update(dtAsSeconds);
			draw();
		}
	}
}