#include "Buttons.h"

namespace XWin
{
	// Button functionality, defined in `ButtonFunctions`

	void Buttons::ButtonFunction::L_MOUSE(bool* active)
	{
		mouseInput(active, MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP);
	}

	void Buttons::ButtonFunction::R_MOUSE(bool* active)
	{
		mouseInput(active, MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_RIGHTUP);
	}

	void Buttons::ButtonFunction::M_MOUSE(bool* active)
	{
		mouseInput(active, MOUSEEVENTF_MIDDLEDOWN, MOUSEEVENTF_MIDDLEUP);
	}

	void Buttons::ButtonFunction::BACK(bool* active)
	{
		keyInput(active, VK_BACK);
	}

	void Buttons::ButtonFunction::ENTER(bool* active)
	{
		keyInput(active, VK_RETURN);
	}

	void Buttons::ButtonFunction::A_UP(bool* active)
	{
		keyInput(active, VK_UP);
	}

	void Buttons::ButtonFunction::A_DOWN(bool* active)
	{
		keyInput(active, VK_DOWN);
	}

	void Buttons::ButtonFunction::A_LEFT(bool* active)
	{
		keyInput(active, VK_LEFT);
	}

	void Buttons::ButtonFunction::A_RIGHT(bool* active)
	{
		keyInput(active, VK_RIGHT);
	}

	void Buttons::ButtonFunction::B_BACK(bool* active)
	{
		keyInput(active, VK_BROWSER_BACK);
	}

	void Buttons::ButtonFunction::B_FORWARD(bool* active)
	{
		keyInput(active, VK_BROWSER_FORWARD);
	}

	void Buttons::ButtonFunction::B_HOME(bool* active)
	{
		keyInput(active, VK_BROWSER_HOME);
	}

	void Buttons::ButtonFunction::B_REFRESH(bool* active)
	{
		keyInput(active, VK_BROWSER_REFRESH);
	}

	void Buttons::ButtonFunction::WIN(bool* active)
	{
		keyInput(active, VK_LWIN);
	}

	void Buttons::ButtonFunction::WINTAB(bool* active)
	{
		keyInput(active, VK_LWIN, VK_TAB);
	}

	void Buttons::ButtonFunction::MEDIA(bool* active)
	{
		keyInput(active, VK_MEDIA_PLAY_PAUSE);
		keyInput(active, VK_BROWSER_HOME);
	}

	void Buttons::ButtonFunction::MEDIA_NEXT(bool* active)
	{
		keyInput(active, VK_MEDIA_NEXT_TRACK);
	}

	void Buttons::ButtonFunction::MEDIA_PREVIOUS(bool* active)
	{
		keyInput(active, VK_MEDIA_PREV_TRACK);
	}

	void Buttons::ButtonFunction::MEDIA_STOP(bool* active)
	{
		keyInput(active, VK_MEDIA_STOP);
	}

	// Private helper functions

	void Buttons::ButtonFunction::keyInput(bool* active,
		const WORD& vkName)
	{
		INPUT kbInput;
		kbInput.type = INPUT_KEYBOARD;
		kbInput.ki.wVk = vkName;

		if (*active)
		{
			kbInput.ki.dwFlags = KEYEVENTF_KEYUP;
			*active = false;
		}
		else
		{
			kbInput.ki.dwFlags = KEYEVENTF_KEYDOWN;
			*active = true;
		}

		SendInput(1, &kbInput, sizeof(INPUT));
	}

	void Buttons::ButtonFunction::keyInput(bool* active,
		const WORD& vkName1,
		const WORD& vkName2)
	{
		INPUT vkInput1;
		vkInput1.type = INPUT_KEYBOARD;
		vkInput1.ki.wVk = vkName1;

		INPUT vkInput2;
		vkInput2.type = INPUT_KEYBOARD;
		vkInput2.ki.wVk = vkName2;


		if (*active)
		{
			vkInput1.ki.dwFlags = KEYEVENTF_KEYUP;
			vkInput2.ki.dwFlags = KEYEVENTF_KEYUP;
			*active = false;
		}
		else
		{
			vkInput1.ki.dwFlags = KEYEVENTF_KEYDOWN;
			vkInput2.ki.dwFlags = KEYEVENTF_KEYDOWN;
			*active = true;
		}

		SendInput(1, &vkInput1, sizeof(INPUT));
		SendInput(1, &vkInput2, sizeof(INPUT));
	}

	void Buttons::ButtonFunction::mouseInput(bool* active,
		const WORD& mouseAction1,
		const WORD& mouseAction2)
	{
		INPUT mouseInput;
		mouseInput.type = INPUT_MOUSE;
		mouseInput.mi.time = 0;

		if (*active)
		{
			mouseInput.mi.dwFlags = mouseAction2;
			*active = false;
		}
		else
		{
			mouseInput.mi.dwFlags = mouseAction1;
			*active = true;
		}

		SendInput(1, &mouseInput, sizeof(INPUT));
		ZeroMemory(&mouseInput, sizeof(INPUT));
	}
}