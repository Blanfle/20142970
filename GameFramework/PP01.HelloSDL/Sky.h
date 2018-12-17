#pragma once
#include "SDLGameObject.h"

class Sky : public SDLGameObject
{
public:
	Sky(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
};
