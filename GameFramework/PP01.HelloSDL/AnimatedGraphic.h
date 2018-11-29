#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject 
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	void update();
	int m_animSpeed;
};