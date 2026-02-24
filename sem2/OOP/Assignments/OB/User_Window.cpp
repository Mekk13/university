#include "User_Window.h"
#include <QListWidget>
#include <QMessageBox>
#include <QDate>

User_Window::User_Window(User user, Service* serv,QWidget *parent)
	: QWidget(parent), user(user), service(serv)
{
	ui.setupUi(this);
	service->registerObserver(this);
	populate_combo();
	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &User_Window::populateItemList);
	connect(ui.bid_button, &QPushButton::clicked, this, &User_Window::on_bid_pushed);
	setWindowTitle(QString::fromStdString(user.getName()) + " - " + QString::fromStdString(user.getType()));
	populateItemList();
}


User_Window::~User_Window()
{}

void User_Window::update()
{
	populate_combo();
	populateItemList();
}

void User_Window::populate_combo()
{
	ui.comboBox->addItem("All Categories");
	vector<Item> items = service->getItems();
	for ( auto& item : items) {
		if (ui.comboBox->findText(QString::fromStdString(item.getCategory())) == -1) {
			ui.comboBox->addItem(QString::fromStdString(item.getCategory()));
		}
	}
}

void User_Window::on_bid_pushed()
{
	int itemIndex = ui.item_list->currentRow();
	if (itemIndex < 0) {
		QMessageBox::warning(this, "Input Error", "Please select an item and enter a valid bid amount.");
		return;
	}

	vector<Item> sortedItems = service->getitemsSorted();
	Item item = sortedItems[itemIndex]; 

	int price = ui.bid_line_edit->text().toInt();
	if (price <= 0 || price < item.getPrice()) {
		QMessageBox::warning(this, "Input Error", "Please enter a valid bid amount.");
		return;
	}

	int userId = user.getId();
	QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");
	string date = currentDate.toStdString();


	int repoIndex = service->getItemIndex(item);
	if (repoIndex < 0) {
		QMessageBox::warning(this, "Error", "Could not find the item in the repository.");
		return;
	}

	service->addOffer(repoIndex, userId, date, price);
	service->change_item_price(repoIndex, price);
	service->notify();
}


void User_Window::populateItemList()
{
	ui.item_list->clear();
	string selectedCategory = ui.comboBox->currentText().toStdString();
	bool filter = selectedCategory != "All Categories";
	vector<Item> items = service->getitemsSorted();

	for (auto& item : items) {
		if (!filter || item.getCategory() == selectedCategory) {
			QString itemText = QString::fromStdString(item.getName()) + " - " + QString::fromStdString(item.getCategory()) + " - " + QString::number(item.getPrice());
			QListWidgetItem* listItem = new QListWidgetItem(itemText);
			listItem->setData(Qt::UserRole, QVariant::fromValue(item)); // Store the item in the list item
			ui.item_list->addItem(listItem);
		}
		
	}
}

