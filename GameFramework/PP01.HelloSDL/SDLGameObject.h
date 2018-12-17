#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void draw2();
	virtual void update();
	virtual void clean();
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames = 5;
	std::string m_textureID;
};