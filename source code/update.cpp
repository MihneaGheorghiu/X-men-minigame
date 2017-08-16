#include "stdafx.h"
#include "engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	m_Bob.update(dtAsSeconds);
}