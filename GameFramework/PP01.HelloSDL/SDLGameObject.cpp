#pragma once
#include "SDLGameObject.h"
#include"Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}


void SDLGameObject::clean()
{
}