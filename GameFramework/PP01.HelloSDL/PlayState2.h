#pragma once
#include "GameState.h"
#include "TextureManager.h"
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "WinState.h"
#include "Wall.h"
#include "Sky.h"

class GameObject;
class PlayState2 : public GameState
{
public:
	static PlayState2* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new PlayState2();
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual std::string getStateID() const { return s_playID; }
private:
	static const std::string s_playID;
	static PlayState2* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};