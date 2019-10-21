#include "Controller.h"

namespace XWin
{
	Controller::Controller() :
		// Initializer list
		m_joysticks(m_xsState.Gamepad),
		m_triggers(m_xsState.Gamepad),
		m_buttons(),
		m_activeBtn(),
		m_tAsyncJoystickThread(&Controller::async_registerJoystickInput, this),
		m_tAsyncTriggerThread(&Controller::async_registerTriggerInput, this),
		m_tAsyncButtonThread(&Controller::async_registerButtonInput, this)
	{ }

	Controller::~Controller()
	{
		if (m_tAsyncJoystickThread.joinable()
			&& m_tAsyncTriggerThread.joinable()
			&& m_tAsyncButtonThread.joinable()
			)
		{
			m_tAsyncJoystickThread.join();
			m_tAsyncTriggerThread.join();
			m_tAsyncButtonThread.join();
		}
	}

	bool Controller::isConnected()
	{
		if (manualDisconnect)
			return false;

		// Returns whether program is able to retrieve an XINPUT_STATE 
		ZeroMemory(&m_xsState, sizeof(XINPUT_STATE));

		return XInputGetState(0, &m_xsState) == ERROR_SUCCESS;
	}

	void Controller::disconnect()
	{
		manualDisconnect = true;

		if (m_tAsyncJoystickThread.joinable()
			&& m_tAsyncTriggerThread.joinable()
			&& m_tAsyncButtonThread.joinable()
			)
		{
			m_tAsyncJoystickThread.join();
			m_tAsyncTriggerThread.join();
			m_tAsyncButtonThread.join();
		}
	}

	void Controller::async_registerJoystickInput()
	{
		while (isConnected())
		{
			if (!m_joysticks.L_inDeadZone())
			{
				// The left joystick is moved
				CursorManager::Move(
					static_cast<short>(m_joysticks.L_getPos_x() * JOYSTICK_SENSITIVITY),
					static_cast<short>(m_joysticks.L_getPos_y() * JOYSTICK_SENSITIVITY)
				);
			}

			if (!m_joysticks.R_inDeadZone())
			{
				// The right joystick is moved
			}

			std::this_thread::sleep_for(std::chrono::microseconds(500)); // Minimal sleep to reduce mouse-"lag"
		}
	}

	void Controller::async_registerTriggerInput()
	{
		while (isConnected())
		{
			if (!m_triggers.L_inDeadZone())
			{
				// The left trigger is pressed
				ScrollManager::Scroll(m_triggers.L_getValue());
			}

			if (!m_triggers.R_inDeadZone())
			{
				// The right trigger is pressed
				ScrollManager::Scroll(m_triggers.R_getValue());
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(TRIGGER_SENSITIVITY)); // Sleep amount is decided by TRIGGER_SENSITIVITY > 50 (Minimun value to prevent excessive CPU usage)
		}
	}

	void Controller::async_registerButtonInput()
	{
		while (isConnected())
		{
			Buttons::ButtonFlag clickedButton = static_cast<Buttons::ButtonFlag>(m_xsState.Gamepad.wButtons); // Used for determining whether a button was clicked at all
			Buttons::identifyButton(clickedButton, &m_activeBtn);

			// Button is clicked
			if (clickedButton != Buttons::ButtonFlag::NONE)
			{
				if (m_activeBtn.isActive())
				{
					// Button is being held down
				}
				else
				{
					// Initial button click
					m_activeBtn.performAction();
				}
			}
			else
			{
				if (m_activeBtn.isActive())
				{
					// Button was released
					m_activeBtn.performAction();
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(25));
		}
	}
}

