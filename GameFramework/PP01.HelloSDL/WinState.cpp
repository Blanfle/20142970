#pragma once
#include "WinState.h"

const std::string WinState::s_WinID = "Win";
WinState* WinState::s_pInstance = 0;

void WinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void WinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void WinState::s_winToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}
void WinState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}
bool WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/win.png", "wintext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png", "restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* winText = new AnimatedGraphic(new  LoaderParams(590, 30, 121, 161, "wintext"), 5, 1);
	GameObject* button1 = new MenuButton(new LoaderParams(550, 200, 200, 80, "mainbutton"), s_winToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(550, 300, 200, 80, "restartbutton"), s_restartPlay);
	m_gameObjects.push_back(winText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool WinState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("wintext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
	std::cout << "exiting PauseState\n";
	return true;
}