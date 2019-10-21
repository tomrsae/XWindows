#pragma once
#include <windows.h>
#include <array>
#include <functional>
#pragma comment(lib, "user32.lib")

#define KEYEVENTF_KEYDOWN 0

namespace XWin
{
	class Buttons					// Defines XBOX 360/One controllers supported buttons and which actions can be performed with them
	{
	public:
		const enum class ButtonFlag	// Flags for the supported XBOX buttons
		{
			A = 0x1000,
			B = 0x2000,
			X = 0x4000,
			Y = 0x8000,

			DPAD_UP = 0x0001,
			DPAD_DOWN = 0x0002,
			DPAD_LEFT = 0x0004,
			DPAD_RIGHT = 0x0008,

			LB = 0x0100,
			RB = 0x0200,

			START = 0x0010,
			BACK = 0x0020,

			THUMB_L = 0x0040,
			THUMB_R = 0x0080,

			NONE = 0x0000
		};

		struct Button			// Defines a supported controller button
		{
		public:

			Button(const ButtonFlag, const std::function<void(bool*)>);

			Button();

			void performAction();
			bool isActive() const;
			ButtonFlag getFlag() const;

		private:
			ButtonFlag bFlag;	// Button identifier
			bool active;
			std::function<void(bool*)> fBtnFunctionality;	// Button functionality. Supported functionality defined in `ButtonFunctions` struct, and is to be passed with the ctor
		};

		// Determines whether flag is a supported button and assigns it to pointer if found, leaves pointer alone if not found or if active to allow holding down buttons
		static void identifyButton(const ButtonFlag&, Button*);

	private:
		static std::array<Buttons::Button, 14> buttons; // Supported buttons

		struct ButtonFunction	// Button functionality
		{
			// bool parameter determines whether button was released when function is called
			static void L_MOUSE(bool*);			// Mouse left click functionality

			static void R_MOUSE(bool*);			// Mouse right click functionality

			static void M_MOUSE(bool*);			// Middle mouse button functionality - may be both toggled and held

			static void BACK(bool*);			// Imitates BACKSPACE key (for deleting text and going back on history inside browser)

			static void ENTER(bool*);			// Imitates RETURN(enter) key to make selection in menus and submit forms

			static void A_UP(bool*);			// UP arrow key

			static void A_DOWN(bool*);			// DOWN arrow key 

			static void A_LEFT(bool*);			// LEFT arrow key

			static void A_RIGHT(bool*);			// RIGHT arrow key

			static void B_BACK(bool*);			// BROWSER BACK vk

			static void B_FORWARD(bool*);		// BROWSER FORWARD vk

			static void B_HOME(bool*);			// BROWSER HOME vk

			static void B_REFRESH(bool*);		// BROWSER REFRESH vk

			static void WIN(bool*);				// Opens Windows Start menu

			static void WINTAB(bool*);			// Imitates Windows Key + TAB to select from open processes in current desktop

			static void MEDIA(bool*);			// MEDIA - PAUSE/PLAY vk

			static void MEDIA_NEXT(bool*);		// MEDIA - NEXT TRACK vk

			static void MEDIA_PREVIOUS(bool*);	// MEDIA - NEXT TRACK vk

			static void MEDIA_STOP(bool*);		// MEDIA - STOP vk

		private:
			static void keyInput(bool*,		// Helper function - simulates keypresses on keyboard
				const WORD&);

			static void keyInput(bool*,		// OVERLOAD - Helper function - simulates two simultaneous key presses on keyboard
				const WORD&,
				const WORD&);

			static void mouseInput(bool*,	// Helper function - simulates mouse button clicks
				const WORD&,
				const WORD&);
		};
	};
}