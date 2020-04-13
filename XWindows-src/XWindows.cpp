#include "XWindows.h"

XWindows::XWindows(QWidget *parent)
	: QMainWindow(parent), connectionHandler(), controllerThread(this), settings(), systemTrayIcon(this)
{
	this->setFixedSize(391, 590);
	ui.setupUi(this);
	ui.label_verNum->setText(verNum);
	ui.label_savingChanges->setVisible(false);

	systemTrayIcon.setIcon(QIcon(":/XWindows/ControllerON.png"));
	systemTrayIcon.setVisible(true);

	connectionHandler.moveToThread(&controllerThread);
	QObject::connect(&controllerThread, &QThread::started, &connectionHandler, &ConnectionHandler::maintainConnection);
	QObject::connect(&connectionHandler, &ConnectionHandler::stateChanged, this, &XWindows::on_controllerState_changed);
	QObject::connect(&settings, &XSettings::settingsChanged, this, &XWindows::on_settings_changed);
	QObject::connect(this, &XWindows::settingsOpened, &settings, &XSettings::on_settings_opened);

	init();
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

void XWindows::init()
{
	XWin::Controller::JOYSTICK_SENSITIVITY = (settings.getSettings()->value("js_sensitivity", 5.0f).toFloat()) / 3.33333333f;
	XWin::Controller::TRIGGER_SENSITIVITY = (10 - settings.getSettings()->value("trigger_sensitivity", 5).toInt()) * 10; // Subtract from 10 to make lower values a slower sensitivity - and vice-versa
	connectionHandler.setUseTimeout(settings.getSettings()->value("useReconnectTimeout", true).toBool());
	connectionHandler.setReconnectTime((settings.getSettings()->value("max_reconnects", 5).toInt() * 60));

	connectController();
}

void XWindows::on_controllerState_changed(const int state)
{
	QString notificationTitle = "";
	QString notificationContent = "";

	if (state == ControllerState::CONNECTED)
	{
		ui.label_reconnect->setVisible(false);
		notificationTitle = "Controller connected";
		notificationContent = "You may now use the controller as an input device.";
	}
	else if (state == ControllerState::DISCONNECTED && controllerToggled)
	{
		ui.label_reconnect->setVisible(true);
		notificationTitle = "Controller disconnected";
		notificationContent = "If this was not intended, please try restaring the program and the controller.";
	}
	else if (state == ControllerState::FAILEDTOCONNECT && controllerToggled)
	{
		ui.label_reconnect->setVisible(false);
		disableController();
		notificationTitle = "Connection timeout";
		notificationContent = "A connection could not be established in the specified time period.\nXWindows has been deactivated, and must be reactivated manually.";
	}

	bool hasNotification = (!notificationTitle.isEmpty() && !notificationContent.isEmpty());

	if (hasNotification && !this->hasFocus())
	{
		systemTrayIcon.show();
		systemTrayIcon.showMessage(notificationTitle, notificationContent, QSystemTrayIcon::NoIcon, 7000);
		systemTrayIcon.hide();
	}
}

void XWindows::on_settingsBtn_clicked()
{
	emit settingsOpened();
	settings.exec();
}

void XWindows::on_settings_changed(const QSettings& newSettings)
{
	bool reestablishConnection = false;

	if (controllerToggled)
	{
		disableController();
		ui.label_savingChanges->setVisible(true);
		reestablishConnection = true;
	}

	XWin::Controller::JOYSTICK_SENSITIVITY = (newSettings.value("js_sensitivity", 5.0f).toFloat()) / 3.33333333f;
	XWin::Controller::TRIGGER_SENSITIVITY = (10 - newSettings.value("trigger_sensitivity", 5).toInt()) * 10; // Subtract from 10 to make lower values a slower sensitivity - and vice-versa
	connectionHandler.setUseTimeout(newSettings.value("useReconnectTimeout", true).toBool());
	connectionHandler.setReconnectTime((newSettings.value("max_reconnects", 5).toInt() * 60));

	if (reestablishConnection)
	{
		connectController();
		ui.label_savingChanges->setVisible(false);
	}
}

void XWindows::on_xboxBtn_clicked()
{
	ControllerLayout controllerLayout;
	controllerLayout.exec();
}
