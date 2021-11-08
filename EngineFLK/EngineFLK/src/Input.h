#ifndef INPUT_H
#define INPUT_H
#include "Exports.h"

#include "LibIncludes.h"

#include "Window.h"
#include "Vector2.h"

enum KeyCode
{
	ALPHA_0 = 48,
	ALPHA_1 = 49,
	ALPHA_2 = 50,
	ALPHA_3 = 51,
	ALPHA_4 = 52,
	ALPHA_5 = 53,
	ALPHA_6 = 54,
	ALPHA_7 = 55,
	ALPHA_8 = 56,
	ALPHA_9 = 57,
	NUMPAD_0 = 320,
	NUMPAD_1 = 321,
	NUMPAD_2 = 322,
	NUMPAD_3 = 323,
	NUMPAD_4 = 324,
	NUMPAD_5 = 325,
	NUMPAD_6 = 326,
	NUMPAD_7 = 327,
	NUMPAD_8 = 328,
	NUMPAD_9 = 329,

	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,

	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	F13 = 302,
	F14 = 303,
	F15 = 304,
	F16 = 305,
	F17 = 306,
	F18 = 307,
	F19 = 308,
	F20 = 309,
	F21 = 310,
	F22 = 311,
	F23 = 312,
	F24 = 313,
	F25 = 314,

	RIGHT = 262,
	LEFT = 263,
	DOWN = 264,
	UP = 265,

	ESCAPE = 256,
	ENTER = 257,
	SPACE = 32,
	APOSTROPHE = 39,
	COMMA = 44,
	MINUS = 45,
	PERIOD = 46,
	SLASH = 47,
	SEMICOLON = 59,
	EQUAL = 61,
	LEFT_BRACKET = 91,
	BACKSLASH = 92,
	RIGHT_BRACKET = 93,
	GRAVE_ACCENT = 96,
	WORLD_1 = 161,
	WORLD_2 = 162,
	TAB = 258,
	BACKSPACE = 259,
	INSERT = 260,
	DELETE = 261,
	PAGE_UP = 266,
	PAGE_DOWN = 267,
	HOME = 268,
	END = 269,
	CAPS_LOCK = 280,
	SCROLL_LOCK = 281,
	NUM_LOCK = 282,
	PRINT_SCREEN = 283,
	PAUSE = 284,
	NUMPAD_DECIMAL = 330,
	NUMPAD_DIVIDE = 331,
	NUMPAD_MULTIPLY = 332,
	NUMPAD_SUBTRACT = 333,
	NUMPAD_ADD = 334,
	NUMPAD_ENTER = 335,
	NUMPAD_EQUAL = 336,

	LEFT_SHIFT = 340,
	LEFT_CONTROL = 341,
	LEFT_ALT = 342,
	LEFT_SUPER = 343,
	RIGHT_SHIFT = 344,
	RIGHT_CONTROL = 345,
	RIGHT_ALT = 346,
	RIGHT_SUPER = 347,

	MENU = 348
};

enum MouseButton
{
	LEFT_MOUSE_BUTTON = 0,
	RIGHT_MOUSE_BUTTON = 1,
	MOUSE_WHEEL = 2
};

enum KeyState
{
	GET_KEY_UP = 0,
	GET_KEY = 1,
	GET_KEY_DOWN = 2,
};

class FLK_API Input
{
private:
	static Window* window;	

public:
	Input();
	~Input();

	static bool GetMouseButtonDown(MouseButton mouseButton); //LITERALLY WONT WORK
	static bool GetMouseButton(MouseButton mouseButton);
	static bool GetMouseButtonUp(MouseButton mouseButton); //LITERALLY WONT WORK

	static Vector2 GetMousePosition();

	static bool GetKeyDown(KeyCode keycode); //LITERALLY WONT WORK
	static bool GetKey(KeyCode keycode);
	static bool GetKeyUp(KeyCode keycode); //LITERALLY WONT WORK
	
	static void SetContextWindow(Window* contextWindow);
	static void PollEvents();

private:
	static bool CheckKeyPress(KeyCode keycode, int type);
	static bool CheckMouseButtonPress(MouseButton mouseButton, int type);
	static void KeyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif