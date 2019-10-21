#pragma once

#include <QtWidgets/QMainWindow>
#include <thread>
#include "qmessagebox.h"
#include "ui_XWindows.h"
#include "ConnectionHandler.h"
#include "XSettings.h"
#include "ControllerLayout.h"

class XWindows : public QMainWindow
{
	Q_OBJECT

public:
	XWindows(QWidget *parent = Q_NULLPTR);
	~XWindows();

private slots:
	void on_toggleBtn_clicked();
	void on_settingsBtn_clicked();
	void on_xboxBtn_clicked();
	void on_controllerState_changed(const int);
	void on_settings_changed(const QSettings&);

private:
	Ui::XWindowsClass ui;
	XSettings settings;
	QThread	controllerThread;
	ConnectionHandler connectionHandler;

	const QString verNum = "1.0";
	const QPixmap controllerON = QPixmap(":/XWindows/ControllerON.png");
	const QPixmap controllerOFF = QPixmap(":/XWindows/ControllerOFF.png");

	bool controllerToggled = true;

	void connectController();
	void disableController();
};