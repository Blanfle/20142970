#pragma once
#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";
PauseState* PauseState::s_pInstance = 0;

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png", "resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	m_gameObjects.push_back(new MenuButton(new LoaderParams(550, 100, 200, 80, "mainbutton"), s_pauseToMain));
	m_gameObjects.push_back(new MenuButton(new LoaderParams(550, 300, 200, 80, "resumebutton"), s_resumePlay));
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}