#include "SelectFileForm.h"

SelectFileForm::SelectFileForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.CSVButton, &QPushButton::clicked, this, &SelectFileForm::selectCSV);
	connect(ui.HTMLButton, &QPushButton::clicked, this, &SelectFileForm::selectHTML);
}

SelectFileForm::~SelectFileForm()
{}

QString SelectFileForm::getselectedformat() const
{
	return selectedformat;
}

void SelectFileForm::selectHTML()
{
	selectedformat = "html";
	accept();
}

void SelectFileForm::selectCSV()
{
	selectedformat = "csv";
	accept();
}
