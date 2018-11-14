#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>


class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
};


typedef InputHandler TheInputHandler;