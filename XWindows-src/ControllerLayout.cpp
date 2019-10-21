#include "ControllerLayout.h"

// Keep for potential functionality

ControllerLayout::ControllerLayout(QWidget *parent)
	: QDialog(parent)
{
	this->setFixedSize(635, 322);
	ui.setupUi(this);
}

ControllerLayout::~ControllerLayout()
{
}
