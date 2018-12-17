#pragma once
#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numFrames) :
	SDLGameObject(pParams), m_animSpeed(animSpeed)
{
	m_numFrames = numFrames;
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}