#pragma once

#include <QDialog>
#include "ui_SelectFileForm.h"

class SelectFileForm : public QDialog
{
	Q_OBJECT

public:
	SelectFileForm(QWidget *parent = nullptr);
	~SelectFileForm();

	QString getselectedformat() const;

private slots:
	void selectCSV();
	void selectHTML();
	
private:
	Ui::SelectFileFormClass ui;
	QString selectedformat="";
};
