#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};

class Enemy2 : public SDLGameObject
{
public:
	Enemy2(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};
