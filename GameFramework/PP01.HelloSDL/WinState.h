#pragma once
#include "GameState.h"
#include "Game.h"
#include "AnimatedGraphic.h"

class GameObject;

class WinState : public GameState
{
public:
	static WinState* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new WinState();
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_WinID; }
private:
	static void s_winToMain();
	static void s_restartPlay();
	static WinState* s_pInstance;
	static const std::string s_WinID;
	//	std::vector<GameObject*> m_gameObjects;
};