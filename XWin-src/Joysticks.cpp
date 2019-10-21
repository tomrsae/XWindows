#include "Joysticks.h"

namespace XWin
{
	// Positions (as coordinates)

	short Joysticks::L_getPos_x() const
	{
		return m_xgPad.sThumbLX / static_cast<short>(3276.80f);
	}

	short Joysticks::L_getPos_y() const
	{
		return m_xgPad.sThumbLY / static_cast<short>(3276.80f);
	}

	short Joysticks::R_getPos_x() const
	{
		return m_xgPad.sThumbRX / static_cast<short>(32768.0f);
	}

	short Joysticks::R_getPos_y() const
	{
		return m_xgPad.sThumbRY / static_cast<short>(32768.0f);
	}

	// In Dead-zone

	bool Joysticks::L_inDeadZone() const
	{
		if (m_xgPad.sThumbLX > LEFT_THUMB_DEADZONE ||
			m_xgPad.sThumbLX < -LEFT_THUMB_DEADZONE)
			return false;

		if (m_xgPad.sThumbLY > LEFT_THUMB_DEADZONE ||
			m_xgPad.sThumbLY < -LEFT_THUMB_DEADZONE)
			return false;

		return true;
	}

	bool Joysticks::R_inDeadZone() const
	{
		if (m_xgPad.sThumbRX > RIGHT_THUMB_DEADZONE ||
			m_xgPad.sThumbRX < -RIGHT_THUMB_DEADZONE)
			return false;

		if (m_xgPad.sThumbRY > RIGHT_THUMB_DEADZONE ||
			m_xgPad.sThumbRY < -RIGHT_THUMB_DEADZONE)
			return false;

		return true;
	}
}
