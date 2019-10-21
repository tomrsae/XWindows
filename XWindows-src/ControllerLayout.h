#pragma once

#include <QDialog>
#include "ui_ControllerLayout.h"

// Keep for potential functionality

class ControllerLayout : public QDialog
{
	Q_OBJECT

public:
	ControllerLayout(QWidget *parent = Q_NULLPTR);
	~ControllerLayout();

private:
	Ui::ControllerLayout ui;
};
