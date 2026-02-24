#pragma once
#include "Test3.h"
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QStandardItemModel>
#include "Repo.h"

Test3::Test3(QWidget *parent)
    : QMainWindow(parent)
{
	repo = Repo();
    ui.setupUi(this);
	readFromFile();
	populateList();
	connect(ui.addButton, &QPushButton::clicked, this, &Test3::onaddpushed);
	connect(ui.solutionButton, &QPushButton::clicked, this, &Test3::onsolutionpushed);
}

Test3::~Test3()
{}

void Test3::readFromFile()
{
	QFile file("file.txt");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList parts = line.split(",");
		if (parts.size() == 3) {
			Equation eq;
			eq.a = parts[0].toDouble();
			eq.b = parts[1].toDouble();
			eq.c = parts[2].toDouble();
			repo.addEquation(eq);
		}
	}
	file.close();
}


void Test3::populateList()
{
	QStandardItemModel* model = new QStandardItemModel(this);
	ui.listView->setModel(model);
	ui.listView->setStyleSheet("QListView { background-color: white; }");
	for (const auto& eq : repo.getEquations()) {
		QString equationStr;
		if (eq.a == 0 && eq.b != 0 && eq.c != 0)
			equationStr = QString::number(eq.b) + "x + " + QString::number(eq.c) + " = 0";
		else if (eq.a == 0 && eq.b == 0 && eq.c != 0)
			equationStr = QString::number(eq.c) + " = 0";
		else if (eq.a == 0 && eq.b == 0 && eq.c == 0)
			equationStr = "0 = 0";
		else
			equationStr = QString::number(eq.a) + "x^2 + " + QString::number(eq.b) + "x + " + QString::number(eq.c) + " = 0";
		QStandardItem* item = new QStandardItem(equationStr);
		if (eq.b * eq.b - 4 * eq.a * eq.c >= 0) {
			item->setBackground(QColor(200, 250, 150));
		}
		model->appendRow(item);
	}
}

void Test3::onaddpushed()
{
	//read the a b and c from the line edits aEdit, bEdit and cEdit, and then form an equation and push it to the equations vector
	double a = ui.aEdit->text().toDouble();
	double b = ui.bEdit->text().toDouble();
	double c = ui.cEdit->text().toDouble();
	Equation eq = { a, b, c };
	repo.addEquation(eq);
	populateList();

}
void Test3::onsolutionpushed()
{
	QModelIndexList selectedIndexes = ui.listView->selectionModel()->selectedIndexes();
	if (selectedIndexes.isEmpty()) {
		ui.solution->setText("No equation selected");
		return;
	}
	int row = selectedIndexes.first().row();
	if (row < 0 || row >= repo.getEquations().size()) {
		ui.solution->setText("Invalid selection");
		return;
	}
	const Equation& eq = repo.getEquations()[row];
	double a = eq.a, b = eq.b, c = eq.c;
	double discriminant = b * b - 4 * a * c;
	if (a == 0 && b == 0) {
		ui.solution->setText(c == 0 ? "Infinite solutions" : "No solution");
	}
	else if (a == 0) {
		double x = -c / b;
		ui.solution->setText(QString("Linear: x = %1").arg(x));
	}
	else if (discriminant > 0) {
		double x1 = (-b + sqrt(discriminant)) / (2 * a);
		double x2 = (-b - sqrt(discriminant)) / (2 * a);
		ui.solution->setText(QString("Real solutions: x1 = %1, x2 = %2").arg(x1).arg(x2));
	}
	else if (discriminant == 0) {
		double x = -b / (2 * a);
		ui.solution->setText(QString("Real solution: x = %1").arg(x));
	}
	else {
		double realPart = -b / (2 * a);
		double imagPart = sqrt(-discriminant) / (2 * a);
		ui.solution->setText(QString("Complex: x1 = %1 + %2i, x2 = %1 - %2i").arg(realPart).arg(imagPart));
	}
}


