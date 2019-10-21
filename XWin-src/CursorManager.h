#pragma once
#include <windows.h>
#pragma comment(lib, "user32.lib")

namespace XWin
{
	// Contains only static members with the sole purpose of moving the system cursor around
	class CursorManager
	{
	private:
		static POINT pCursor;

		static void UpdateCursorPos() { GetCursorPos(&pCursor); }
	public:
		static void Move(short moveMultiplier_x, short moveMultiplier_y)
			// Multipliers are joystick x/y coordinates -10 -> 10 (where 0 is middle)
		{
			UpdateCursorPos();

			SetCursorPos(
				pCursor.x + moveMultiplier_x,
				pCursor.y - moveMultiplier_y
			);

			Sleep(10);
		}
	};
}