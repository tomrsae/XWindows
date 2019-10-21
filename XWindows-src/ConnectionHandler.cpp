#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler()
	: gamePad(nullptr), MAX_RECONNECT_ATTEMPTS(300), attemptConnect(false), controllerDisconnected(true)
{
}

void ConnectionHandler::maintainConnection()
{
	attemptConnect = true;

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
	while (attemptConnect)
	{
		if (controllerDisconnected)
		{
			if (++XWin::Controller::ATTEMPTED_RECONNECTS >= MAX_RECONNECT_ATTEMPTS)
			{
				emit stateChanged(ControllerState::FAILEDTOCONNECT);
				XWin::Controller::ATTEMPTED_RECONNECTS = 0;
				break;
			}

			gamePad = std::make_unique<XWin::Controller>();
		}

		controllerDisconnected = !(gamePad->isConnected());

		if (controllerDisconnected)
		{
			emit stateChanged(ControllerState::DISCONNECTED);
		}
		else
		{
			emit stateChanged(ControllerState::CONNECTED);
			XWin::Controller::ATTEMPTED_RECONNECTS = 0;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

bool ConnectionHandler::getIsConnected() const
{
	return !controllerDisconnected;
}

void ConnectionHandler::disableController()
{
	attemptConnect = false;
	if (!controllerDisconnected)
	{
		gamePad->disconnect();
	}

	controllerDisconnected = true;
}

void ConnectionHandler::setReconnectTime(int seconds)
{
	MAX_RECONNECT_ATTEMPTS = seconds;
}