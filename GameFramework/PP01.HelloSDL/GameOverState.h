#pragma once
#include "GameState.h"
#include "Game.h"
#include "AnimatedGraphic.h"

class GameObject;

class GameOverState : public GameState
{
public:
	static GameOverState* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new GameOverState();
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static GameOverState* s_pInstance;
	static const std::string s_gameOverID;
};