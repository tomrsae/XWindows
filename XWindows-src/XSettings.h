#pragma once

#include <QDialog>
#include "qsettings.h"
#include "ui_XSettings.h"

class XSettings : public QDialog
{
	Q_OBJECT

public:
	XSettings(QWidget *parent = Q_NULLPTR);
	~XSettings();

signals:
	void settingsChanged(const QSettings&);

private slots:
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();

private:
	Ui::XSettings ui;

	QSettings settings;
	QSettings startOnBootSettings;

	void updateSettings();
};
