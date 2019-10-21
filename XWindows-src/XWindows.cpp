#include "XWindows.h"

XWindows::XWindows(QWidget *parent)
	: QMainWindow(parent), connectionHandler(), controllerThread(this), settings()
{
	this->setFixedSize(391, 590);
	ui.setupUi(this);
	ui.label_verNum->setText(verNum);

	connectionHandler.moveToThread(&controllerThread);
	QObject::connect(&controllerThread, &QThread::started, &connectionHandler, &ConnectionHandler::maintainConnection);
	QObject::connect(&connectionHandler, &ConnectionHandler::stateChanged, this, &XWindows::on_controllerState_changed);
	QObject::connect(&settings, &XSettings::settingsChanged, this, &XWindows::on_settings_changed);
	connectController();
}

XWindows::~XWindows()
{
	if (controllerThread.isRunning())
	{
		connectionHandler.disableController();
		controllerThread.quit();
		controllerThread.wait();
	}
}

void XWindows::on_toggleBtn_clicked()
{
	if (controllerToggled)
	{
		disableController();
	}
	else
	{
		connectController();
	}
}

void XWindows::connectController()
{
	ui.label_controller->setPixmap(controllerON);
	ui.toggleBtn->setText("Turn OFF");
	controllerToggled = true;

	if (!controllerThread.isRunning())
	{
		controllerThread.start(QThread::Priority::HighestPriority);
	}
}

void XWindows::disableController()
{
	ui.label_controller->setPixmap(controllerOFF);
	ui.toggleBtn->setText("Turn ON");
	ui.label_reconnect->setVisible(false);

	controllerToggled = false;

	if (controllerThread.isRunning())
	{
		connectionHandler.disableController();
		controllerThread.quit();
		controllerThread.wait();
	}
}

void XWindows::on_controllerState_changed(const int state)
{
	if (state == ControllerState::CONNECTED)
	{
		ui.label_reconnect->setVisible(false);
	}
	else if (state == ControllerState::DISCONNECTED && controllerToggled)
	{
		ui.label_reconnect->setVisible(true);
	}
	else if (state == ControllerState::FAILEDTOCONNECT && controllerToggled)
	{
		ui.label_reconnect->setVisible(false);
		disableController();
	}
}

void XWindows::on_settingsBtn_clicked()
{
	if (controllerToggled)
	{
		QMessageBox warning;
		warning.setWindowTitle("Could not open settings");
		warning.setIcon(QMessageBox::Icon::Critical);
		warning.setText("Please turn the controller OFF before modifying its settings!");
		warning.exec();
		return;
	}

	settings.exec();
}

void XWindows::on_settings_changed(const QSettings& settings)
{
	XWin::Controller::JOYSTICK_SENSITIVITY = (settings.value("js_sensitivity", 5.0f).toFloat()) / 3.33333333f;
	XWin::Controller::TRIGGER_SENSITIVITY = (10 - settings.value("trigger_sensitivity", 5).toInt()) * 10; // Subtract from 10 to make lower values a slower sensitivity - and vice-versa
	connectionHandler.setReconnectTime((settings.value("max_reconnects", 5).toInt() * 60));
}

void XWindows::on_xboxBtn_clicked()
{
	ControllerLayout controllerLayout;
	controllerLayout.exec();
}
