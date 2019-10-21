#pragma once
#include <windows.h>
#pragma comment(lib, "user32.lib")

namespace XWin
{
	class ScrollManager
	{
	public:
		static void Scroll(short scrollMultiplier)	// Scrollmultiplier is how far a trigger is being held down and refelects how fast the scrolling will be
		{
			INPUT mouseInput;

			mouseInput.type = INPUT_MOUSE;
			mouseInput.mi.dwFlags = MOUSEEVENTF_WHEEL;
			mouseInput.mi.mouseData = scrollMultiplier;	// Amount of scroll

			SendInput(1, &mouseInput, sizeof(INPUT));
		}
	};
}