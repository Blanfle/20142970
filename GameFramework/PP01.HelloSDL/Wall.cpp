#pragma once
#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Wall::draw()
{
	SDLGameObject::draw();
}
void Wall::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
}
void Wall::clean()
{
}