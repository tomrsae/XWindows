# XWindows - Controller support for Windows
XWindows' goal is to add an easy, laid-back alternative to the good ol' keyboard and mouse.

This program is excellent for setups that use an XBOX controller, for example couch/bed-setups.

![User interface](https://i.gyazo.com/3e696df2bad2045cd38bd519faf6695f.png)

## Downloading and using XWindows
### Downloading
The installer can be found in the **"Releases"** tab of this page. Once downloaded, launch the installer and it will take care of the techinal aspect for you.

### Using
Once installed, XWindows can be launched from any shortcut. The program attempts to connect to the controller immediately and allows for on-boot startup, meaning you won't really need a keyboard or mouse at all after initial setup.

The controller can also temporarily be turned off by the click of a button. If the controller is disconnected while in use, the program will attempt to reconnect within 5 minutes by default, before it automatically stops attempting to reconnect. See the settings section for more information.

Clicking the XBOX logo in the upper left corner opens a new window displaying the controls.

![Controller layout](https://i.gyazo.com/65ffa6266d6ff25d37d3f5cd28bb18d9.png)

## Settings
The program offers the user to change some crucial controller settings.
This includes joystick(mouse) sensitivty, trigger(scroll) sensitivity etc.

*Settings are saved on exit*

### Joystick sensitivity (1-10)
Changes how fast the mouse moves with respect to the joystick.
In addition to this setting, the mouse moves faster depending on how much you tilt the joystick, allowing for more prescision.

*5 is default*

### Trigger sensitivity (1-10)
Changes how fast you scroll with respect to the triggers.
In addition to this setting, the scroll is faster depending on how hard you press the triggers.

*5 is default*

### Maximum reconnects (in minutes)
With this setting you can change how many minutes the program will attempt to reconnect for, in case the controller disconnects.
After this time has ran out, the program will stop trying to reconnect and go to an "OFF" state, requiring you to turn it back on.

*5 minutes is default*

### Start XWindows on system startup
Ticking this checkbox puts the program in the "startup" registry, causing it to open once Windows starts up.
Ticking it off removes it from this registry.

*default is off*

## Technical details
The software is written purely in C++, with the use of `XINPUT`.
QT has been used for the GUI.

There are two source code directories: *XWin* & *XWindows*

**XWin** is the static library that contains all the controller functionality. This library interfaces a `Controller` object used by the GUI. This library can be used as a framework for other controller applications for Windows, although it may require some code modifications for certain games etc. (see league-controller project on my page.)

**XWindows** is the QT project that interfaces the *XWin* library, and that also takes care of the reconnecting with the use of `QThread` so as to not block the entire program while the controller is not connected.

## Windows' base controller support
is garbage. It's really sad that they've added certain functionality that cannot be toggled on and off, but not added full support for it. This makes it hard for apps such as this to work 100% in Windows menus. There is an open issue on this in the repository, in case anyone who sees this has any idea what can be done about this.
