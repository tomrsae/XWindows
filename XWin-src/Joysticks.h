#pragma once
#include <Windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput.lib")

namespace XWin
{
	struct Joysticks									// Provides the means to read joystick positions
	{
	private:
		static const int LEFT_THUMB_DEADZONE = 5849;	// Defines left stick deadzone
		static const int RIGHT_THUMB_DEADZONE = 8689;	// Defines right stick deadzone

		XINPUT_GAMEPAD& m_xgPad;						// Reference to gamepad object to read real-time information of joysticks

	public:
		Joysticks(XINPUT_GAMEPAD& gPad)					// Default ctor, takes reference to gamepad and assigns to m_xgPad
			: m_xgPad(gPad) { }

		Joysticks(const Joysticks&) = delete;			// Copy ctor - Meaningless

		// Left joystick
		short	L_getPos_x()	const;					// Returns left thumbstick x position
		short	L_getPos_y()	const;					// Returns left thumbstick y position
		bool	L_inDeadZone()	const;					// Determines if left thumbstick is in deadzone or not

		// Right joystick
		short	R_getPos_x()	const;					// Returns right stumbstick x position
		short	R_getPos_y()	const;					// Returns right thumbstick y position
		bool	R_inDeadZone()	const;					// Determines if right thumbstick is in deadzone or not
	};
}