#pragma once
#include "PlayState2.h"

const std::string PlayState2::s_playID = "PLAY";
PlayState2* PlayState2::s_pInstance = 0;

void PlayState2::update()
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
		TheGame::Instance()->getStateMachine()->changeState(WinState::Instance());
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}
void PlayState2::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState2::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter3.png", "helicopter3", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/wall.png", "wall", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/city.png", "city", TheGame::Instance()->getRenderer())) {
		return false;
	}
	m_gameObjects.push_back(new Wall(new LoaderParams(1200, 0, 128, 480, "wall")));
	m_gameObjects.push_back(new Sky(new LoaderParams(0, 0, 1280, 480, "city")));
	m_gameObjects.push_back(new Player(new LoaderParams(50, 100, 128, 55, "helicopter")));
	m_gameObjects.push_back(new Enemy2(new LoaderParams(300, 200, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy2(new LoaderParams(500, 50, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy2(new LoaderParams(700, 300, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy2(new LoaderParams(900, 100, 128, 55, "helicopter2")));
	m_gameObjects.push_back(new Enemy2(new LoaderParams(1100, 400, 128, 55, "helicopter2")));

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState2::onExit()
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

void SDLGameObject::draw2()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
}
bool PlayState2::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
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