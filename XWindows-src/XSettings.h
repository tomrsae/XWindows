#pragma once

#include <QDialog>
#include "qsettings.h"
#include "ui_XSettings.h"
#include "qmessagebox.h"

class XSettings : public QDialog
{
	Q_OBJECT

public:
	XSettings(QWidget *parent = Q_NULLPTR);
	~XSettings();

	const QSettings* getSettings() const;

signals:
	void settingsChanged(const QSettings&);
	void anyChangeMade();

public slots:
	void on_settings_opened();

private slots:
	void on_any_change();
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();

	// Slots to detect unsaved change
	void on_js_sense_valueChanged();
	void on_trigger_sense_valueChanged();
	void on_max_reconnects_valueChanged();
	void on_startWithSystem_stateChanged();
	void on_useReconnectTimeout_stateChanged();

private:
	Ui::XSettings ui;

	QSettings settings;
	QSettings startOnBootSettings;
	bool hasUnsavedChange;

	void updateSettings();
};
