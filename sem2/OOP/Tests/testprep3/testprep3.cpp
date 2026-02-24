#include "testprep3.h"
#include <QFile.h>
#include <QTextStream>
#include <QListWidgetItem> 
#include <QListView>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QMessageBox>

testprep3::testprep3(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	this->readFromFile();
	connect(ui.PaidCheckBox, &QCheckBox::checkStateChanged, this, &testprep3::onPaidChecked);
	connect(ui.UnpaidCheckBox, &QCheckBox::checkStateChanged, this, &testprep3::onUnPaidChecked);
	connect(ui.pushButton, &QPushButton::clicked, this, &testprep3::onButtonPressed);

}

testprep3::~testprep3()
{}

void testprep3::readFromFile()
{
    QFile file("file.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList parts = line.split(";");
		if (parts.size() == 4) {
			Bill bill;
			bill.name = parts[0].trimmed();
			bill.serialnr = parts[1].trimmed();
			bill.sum = parts[2].trimmed().toDouble();
			bill.ispaid = (parts[3].trimmed().toLower() == "true");
			bills.push_back(bill);
		}
	}
	file.close();
	populateList();
}

void testprep3::populateList()
{
	ui.listViewbills->setStyleSheet("QListView { background-color: white; }");
	QStandardItemModel* model;
	model = new QStandardItemModel(this);
	ui.listViewbills->setModel(model); 

	//sort bills
	std::sort(bills.begin(), bills.end(), [](const Bill& a, const Bill& b) {
		return a.name < b.name; // Sort by name
		});
	
	for (const Bill& bill : bills) {
		QStandardItem* item = new QStandardItem(QString("%1, %2, %3").arg(bill.name).arg(bill.serialnr).arg(bill.sum));
		if (!bill.ispaid) {
			item->setBackground(Qt::red); // Set unpaid bills to red
		}
		model->appendRow(item);
	}
}

void testprep3::onPaidChecked()
{
	if (ui.PaidCheckBox->isChecked() && ui.UnpaidCheckBox->isChecked()) {
		// If both checkboxes are checked, show all bills
		populateList();
		return;
	}
	//if the "Paid" checkbox is checked, filter the list to show only paid bills using simple functions
	QList<QString> paidBills;
	for (const Bill& bill : bills) {
		if (bill.ispaid) {
			paidBills.append(QString("%1, %2, %.3").arg(bill.name).arg(bill.serialnr).arg(bill.sum));
		}
	}
	QStringListModel* model = new QStringListModel(this);
	model->setStringList(paidBills);
	ui.listViewbills->setModel(model);
}

void testprep3::onUnPaidChecked()
{
	if (ui.PaidCheckBox->isChecked() && ui.UnpaidCheckBox->isChecked()) {
		// If both checkboxes are checked, show all bills
		populateList();
		return;
	}
	//if the "Unpaid" checkbox is checked, filter the list to show only unpaid bills using simple functions
	QList<QString> unpaidBills;
	for (const Bill& bill : bills) {
		if (!bill.ispaid) {
			unpaidBills.append(QString("%1, %2, %.2f").arg(bill.name).arg(bill.serialnr).arg(bill.sum));
		}
	}
	QStringListModel* model = new QStringListModel(this);
	model->setStringList(unpaidBills);
	ui.listViewbills->setModel(model);
}



void testprep3::onButtonPressed()
{
	//calculate the owed sum for unpaid bills for a given company in ui.company qlineedit
	QString company = ui.company->text().trimmed();
	double owedSum = 0.0;
	int ok = 0;
	for (const Bill& bill : bills) {
		if (!bill.ispaid && bill.name == company) {
			ok = 1;
			owedSum += bill.sum;
		}
	}
	if (ok == 0) {
		//show error window
		QMessageBox::warning(this, "Error", "No unpaid bills found for the specified company.");
		return;
	}
	ui.lineEdit->setText(QString::number(owedSum, 'f', 2)); // Display the owed sum in lineEdit
}

