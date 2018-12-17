#pragma once
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.001);
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getY() < 0) {
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-2);
	}
	SDLGameObject::update();
}
void Enemy::clean()
{
}
void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}

Enemy2::Enemy2(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(0);
	m_velocity.setX(2);
}
void Enemy2::draw()
{
	SDLGameObject::draw2();
}
void Enemy2::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getX() < 100) {
		m_velocity.setX(2);
	}
	else if (m_position.getX() > 1000) {
		m_velocity.setX(-2);
	}
	SDLGameObject::update();
}
void Enemy2::clean()
{
}
void Enemy2::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}