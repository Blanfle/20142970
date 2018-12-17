#pragma once
#include "Sky.h"

Sky::Sky(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Sky::draw()
{
	SDLGameObject::draw();
}
void Sky::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
}
void Sky::clean()
{
}