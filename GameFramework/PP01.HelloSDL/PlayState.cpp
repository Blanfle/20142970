﻿#pragma once
#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[3])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[4])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[5])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[6])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[7])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[0])))
	{
		TheGame::Instance()->getStateMachine()->changeState(PlayState2::Instance());
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/wall.png", "wall", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/sky.png", "sky", TheGame::Instance()->getRenderer())) {
		return false;
	}
	m_gameObjects.push_back(new Wall(new LoaderParams(-50, 0, 128, 480, "wall")));
	m_gameObjects.push_back(new Sky(new LoaderParams(0, 0, 1280, 480, "sky")));
	m_gameObjects.push_back(new Player(new LoaderParams(1200, 100, 128, 55, "helicopter")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(100, 200, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 50, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(500, 300, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(700, 100, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(900, 400, 128, 55, "helicopter2")));
	
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
}
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}