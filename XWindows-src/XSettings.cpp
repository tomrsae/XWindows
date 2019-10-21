#include "XSettings.h"

XSettings::XSettings(QWidget *parent)
	: QDialog(parent), settings("Henduww", "XWindows", this), startOnBootSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat)
{
	this->setFixedSize(351, 458);
	ui.setupUi(this);

	ui.js_sense->setValue(settings.value("js_sensitivity", 5.0f).toDouble());
	ui.trigger_sense->setValue(settings.value("trigger_sensitivity", 5).toInt());
	ui.max_reconnects->setValue(settings.value("max_reconnects", 5).toInt());
	ui.startWithSystem->setChecked(settings.value("startOnBoot", false).toBool());
}

XSettings::~XSettings()
{
}

void XSettings::on_okBtn_clicked()
{
	updateSettings();
	emit accepted();
	this->close();
}

void XSettings::on_cancelBtn_clicked()
{
	emit rejected();
	this->close();
}

void XSettings::updateSettings()
{
	settings.setValue("js_sensitivity", ui.js_sense->value());
	settings.setValue("trigger_sensitivity", ui.trigger_sense->value());
	settings.setValue("max_reconnects", ui.max_reconnects->value());
	settings.setValue("startOnBoot", ui.startWithSystem->isChecked());

	if (ui.startWithSystem->isChecked())
	{
		startOnBootSettings.setValue("XWindows", QCoreApplication::applicationFilePath().replace('/', '\\'));
	}
	else
	{
		startOnBootSettings.remove("XWindows");
	}

	emit settingsChanged(settings);
}