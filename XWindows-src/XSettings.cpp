#include "XSettings.h"

XSettings::XSettings(QWidget *parent)
	: QDialog(parent), hasUnsavedChange(false), settings("Henduww", "XWindows", this), startOnBootSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat)
{
	this->setFixedSize(351, 458);
	ui.setupUi(this);

	QObject::connect(this, &XSettings::anyChangeMade, this, &XSettings::on_any_change);
}

XSettings::~XSettings()
{
}

const QSettings* XSettings::getSettings() const
{
	return &settings;
}

void XSettings::on_okBtn_clicked()
{
	updateSettings();
	emit accepted();
	this->close();
}

void XSettings::on_cancelBtn_clicked()
{
	if (hasUnsavedChange)
	{
		QMessageBox warning;
		warning.setWindowTitle("Unsaved changes");
		warning.setIcon(QMessageBox::Icon::Warning);
		warning.setText("You have unsaved changes!");
		warning.setInformativeText("Are you sure you want to cancel?");
		warning.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
		warning.setDefaultButton(QMessageBox::No);

		int answer = warning.exec();
		if (answer == QMessageBox::No)
			return;
	}

	emit rejected();
	this->close();
}

void XSettings::on_settings_opened()
{
	ui.js_sense->setValue(settings.value("js_sensitivity", 5.0f).toDouble());
	ui.trigger_sense->setValue(settings.value("trigger_sensitivity", 5).toInt());
	ui.useReconnectTimeout->setChecked(settings.value("useReconnectTimeout", true).toBool());
	ui.max_reconnects->setValue(settings.value("max_reconnects", 5).toInt());
	ui.startWithSystem->setChecked(settings.value("startOnBoot", false).toBool());

	ui.okBtn->setDisabled(true);
	hasUnsavedChange = false;
}

void XSettings::updateSettings()
{
	settings.setValue("js_sensitivity", ui.js_sense->value());
	settings.setValue("trigger_sensitivity", ui.trigger_sense->value());
	settings.setValue("useReconnectTimeout", ui.useReconnectTimeout->isChecked());
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

void XSettings::on_any_change()
{
	double epsilon = 0.001; // used to compare old js sense to new one

	if (std::abs(ui.js_sense->value() - settings.value("js_sensitivity", 5.0f).toDouble()) > epsilon
		|| ui.trigger_sense->value() != settings.value("trigger_sensitivity", 5).toInt()
		|| ui.max_reconnects->value() != settings.value("max_reconnects", 5).toInt()
		|| ui.useReconnectTimeout->isChecked() != settings.value("useReconnectTimeout", true).toBool()
		|| ui.startWithSystem->isChecked() != settings.value("startOnBoot", false).toBool()
		)
	{
		ui.okBtn->setDisabled(false);
		hasUnsavedChange = true;
	}
	else
	{
		ui.okBtn->setDisabled(true);
		hasUnsavedChange = false;
	}
}

void XSettings::on_useReconnectTimeout_stateChanged()
{
	ui.max_reconnects->setDisabled(!ui.useReconnectTimeout->isChecked());
	emit anyChangeMade();
}

void XSettings::on_js_sense_valueChanged()
{
	emit anyChangeMade();
}

void XSettings::on_trigger_sense_valueChanged()
{
	emit anyChangeMade();
}

void XSettings::on_max_reconnects_valueChanged()
{
	emit anyChangeMade();
}

void XSettings::on_startWithSystem_stateChanged()
{
	emit anyChangeMade();
}