#pragma once

#include <qthread.h>
#include "..//XWin/Controller.h"

enum ControllerState
{
	DISCONNECTED = 0,
	CONNECTED = 1,
	FAILEDTOCONNECT = 2,
	NONE = 99
};

class ConnectionHandler : public QObject
{
	Q_OBJECT

public:
	ConnectionHandler();

	bool getIsConnected() const;				// Encapsulates `controllerDisconnected`
	void setUseTimeout(bool);					// Encapsulates `useReconnectTimeout`
	void setReconnectTime(int);					// Encapsulates `MAX_RECONNECT_ATTEMPTS`
	void disableController();					// Allows for manual disabling of controller

public slots:
	void maintainConnection();					// Performs and maintains controller connection

signals:
	void stateChanged(const int);				// Is emitted once controllerstate is changed

private:
	std::unique_ptr<XWin::Controller> gamePad;	// Pointer to Controller object
	bool attemptConnect;
	bool controllerDisconnected;				// Controls current state of the controller
	bool useReconnectTimeout;
	int MAX_RECONNECT_ATTEMPTS;					// Maximum amount of reconnection attempts. +1 == +1 second
	int lastState;								// Saves last confirmed state of the controller to detect changes
};