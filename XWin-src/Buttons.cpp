#include "Buttons.h"

namespace XWin
{
	Buttons::Button::Button(const ButtonFlag flag, const std::function<void(bool*)> func)
		: bFlag(flag), fBtnFunctionality(func), active(false) { }

	Buttons::Button::Button()
		: bFlag(ButtonFlag::NONE), fBtnFunctionality([](bool) { return false; }), active(false) { }

	void Buttons::Button::performAction()
	{
		fBtnFunctionality(&active);
	}

	bool Buttons::Button::isActive() const
	{
		return active;
	}

	Buttons::ButtonFlag Buttons::Button::getFlag() const
	{
		return bFlag;
	}

	void Buttons::identifyButton(const ButtonFlag& flag, Button* identifiedButton)
	{
		if (flag == ButtonFlag::NONE)
		{
			return;
		}
		else
		{
			for (unsigned int i = 0; i < buttons.size(); i++)
			{
				if (buttons[i].getFlag() == flag)
				{
					if (!identifiedButton->isActive())
						* identifiedButton = buttons[i];
					return;
				}
			}
		}
	}
}