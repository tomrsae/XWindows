#pragma once
#include <thread>
#include "Buttons.h"
#include "Joysticks.h"
#include "Triggers.h"
#include "CursorManager.h"
#include "ScrollManager.h"

namespace XWin
{
	class Controller
	{
	private:
		// Utility
		XINPUT_STATE	m_xsState;							// Contains current controller state information

		void			async_registerJoystickInput();		// Responsible for monitoring and acting on joystick input
		void			async_registerTriggerInput();		// Responsible for monitoring and acting on trigger input
		void			async_registerButtonInput();		// Responsible for monitoring and acting on button input

		// Functionality
		Joysticks		m_joysticks;						// Joystick information
		Triggers		m_triggers;							// Trigger information
		Buttons			m_buttons;							// Button functionality
		Buttons::Button m_activeBtn;						// Used for saving the state of a button to perform the appropriate action (click/release action)
															// Also provides added functionality for button combinations

		std::thread		m_tAsyncJoystickThread;				// Thread responsible for continously checking joystick input
		std::thread		m_tAsyncTriggerThread;				// Thread responsible for continously checking trigger input
		std::thread		m_tAsyncButtonThread;				// Thread responsible for continously checking button input

	public:
		Controller();										// Main ctor
		Controller(const Controller&) = delete;				// Copy ctor - Meaningless
		~Controller();										// Destructor

		static float	JOYSTICK_SENSITIVITY;				// Joystick sensitivity - MUST BE > 1
		static short	TRIGGER_SENSITIVITY;				// Trigger sensitivity - MUST BE > 50
		static int		ATTEMPTED_RECONNECTS;				// Keeps track of how many times a reconnection has been attempted

		bool manualDisconnect = false;						// Is checked on program loop, allows for manual disconnect

		bool isConnected();                                 // Verifies that controller is connected
		void disconnect();									// Manually disables controller
	};
}