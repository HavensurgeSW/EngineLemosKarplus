#pragma once
#include "Exports.h"
#include "glew.h"
#include "glfw3.h"
static enum KeyBoard
{
	KEY_SPACE = 32,
	
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_A = 65,
	KEY_B = 66,
	KEY_C = 67,
	KEY_D = 68,
	KEY_E = 69,
	KEY_F = 70,
	KEY_G = 71,
	KEY_H = 72,
	KEY_I = 73,
	KEY_J = 74,
	KEY_K = 75,
	KEY_L = 76,
	KEY_M = 77,
	KEY_N = 78,
	KEY_O = 79,
	KEY_P = 80,
	KEY_Q = 81,
	KEY_R = 82,
	KEY_S = 83,
	KEY_T = 84,
	KEY_U = 85,
	KEY_V = 86,
	KEY_W = 87,
	KEY_X = 88,
	KEY_Y = 89,
	KEY_Z = 90,


	KEY_ESCAPE = 256,
	KEY_ENTER = 257,
	KEY_TAB = 258,
	KEY_BACKSPACE = 259,
	KEY_RIGHT = 262,
	KEY_LEFT = 263,
	KEY_DOWN = 264,
	KEY_UP = 265,

	KEY_F1 = 290,
	KEY_F2 = 291,
	KEY_F3 = 292,
	KEY_F4 = 293,
	KEY_F5 = 294,
	KEY_F6 = 295,
	KEY_F7 = 296,
	KEY_F8 = 297,
	KEY_F9 = 298,
	KEY_F10 = 299,
	KEY_F11 = 300,
	KEY_F12 = 301,
	KEY_F25 = 314,
	KEY_KP_0 = 320,
	KEY_KP_1 = 321,
	KEY_KP_2 = 322,
	KEY_KP_3 = 323,
	KEY_KP_4 = 324,
	KEY_KP_5 = 325,
	KEY_KP_6 = 326,
	KEY_KP_7 = 327,
	KEY_KP_8 = 328,
	KEY_KP_9 = 329,
	
};

class FLK_API Input
{
private:
	bool CheckKeyPress(GLFWwindow* contextWindow, KeyBoard _keyBoard, unsigned int type);
public:

	Input();
	~Input();
	void PollEvents();
	bool GetKeyDown(GLFWwindow* contextWindow, KeyBoard _keyBoard);
	bool GetKey(GLFWwindow* contextWindow, KeyBoard _keyBoard);
	bool GetKeyUp(GLFWwindow* contextWindow, KeyBoard _keyBoard);
};

