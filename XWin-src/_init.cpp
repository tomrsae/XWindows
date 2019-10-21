#include "Controller.h"

// Initializes static members

namespace XWin
{
	float	Controller::JOYSTICK_SENSITIVITY = 1.5f;
	short	Controller::TRIGGER_SENSITIVITY = 50;
	int		Controller::ATTEMPTED_RECONNECTS = 0;

	POINT CursorManager::pCursor = POINT();

	// Colored ABXY buttons
	std::array<Buttons::Button, 14> Buttons::buttons = {
		// Colored ABXY buttons
		Button(ButtonFlag::A,			ButtonFunction::L_MOUSE),
		Button(ButtonFlag::B,			ButtonFunction::BACK),
		Button(ButtonFlag::X,			ButtonFunction::R_MOUSE),
		Button(ButtonFlag::Y,			ButtonFunction::ENTER),

		// D-PAD buttons
		Button(ButtonFlag::DPAD_UP,		ButtonFunction::A_UP),
		Button(ButtonFlag::DPAD_DOWN,	ButtonFunction::A_DOWN),
		Button(ButtonFlag::DPAD_LEFT,	ButtonFunction::A_LEFT),
		Button(ButtonFlag::DPAD_RIGHT,	ButtonFunction::A_RIGHT),

		// Shoulder buttons
		Button(ButtonFlag::LB,			ButtonFunction::B_BACK),
		Button(ButtonFlag::RB,			ButtonFunction::B_FORWARD),

		// Menu buttons
		Button(ButtonFlag::START,		ButtonFunction::WIN),
		Button(ButtonFlag::BACK,		ButtonFunction::WINTAB),

		// Thumbstick buttons (joystick-click)
		Button(ButtonFlag::THUMB_L,		ButtonFunction::M_MOUSE),
		Button(ButtonFlag::THUMB_R,		ButtonFunction::MEDIA)
	};
}