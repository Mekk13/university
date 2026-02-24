#include "Admin_Window.h"
#include <QMessageBox>

Admin_Window::Admin_Window(User user, Service* serv, QWidget *parent)
	: QWidget(parent), user(user), service(serv)
{
	ui.setupUi(this);
	service->registerObserver(this);
	populate_combo();
	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &Admin_Window::populateItemList);
	connect(ui.add_button, &QPushButton::clicked, this, &Admin_Window::on_add_clicked);
	connect(ui.item_list, &QListWidget::itemClicked, this, &Admin_Window::on_selected_item);
	setWindowTitle(QString::fromStdString(user.getName()) + " - " + QString::fromStdString(user.getType()));
	populateItemList();
}

Admin_Window::~Admin_Window()
{}

void Admin_Window::update()
{
	populate_combo();
	populateItemList();
}

void Admin_Window::populate_combo()
{
	ui.comboBox->clear(); 
	ui.comboBox->addItem("All Categories");
	vector<Item> items = service->getItems();
	for (auto& item : items) {
		if (ui.comboBox->findText(QString::fromStdString(item.getCategory())) == -1) {
			ui.comboBox->addItem(QString::fromStdString(item.getCategory()));
		}
	}
	
}

void Admin_Window::on_add_clicked()
{
	string name = ui.name_edit->text().toStdString();
	string category = ui.category_edit->text().toStdString();
	int price = ui.price_edit->text().toInt();
	if (name.empty() || category.empty() || price <= 0) {
		QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly.");
		return;
	}	
	Item newItem(name, category, price);
	service->addItem(newItem);
	service->notify();
	
}

void Admin_Window::on_selected_item()
{
	//when an item is selected from the list , another window will pop up and show all offers for the item sorted descending by date
	QListWidgetItem* selectedItem = ui.item_list->currentItem();
	if (!selectedItem) {
		QMessageBox::warning(this, "Selection Error", "Please select an item from the list.");
		return;
	}
	Item item = selectedItem->data(Qt::UserRole).value<Item>();
	QString itemDetails = QString::fromStdString(item.getName()) + " - " + QString::fromStdString(item.getCategory()) + " - " + QString::number(item.getPrice());
	
	int index = service->getItemIndex(item);
	vector<tuple<int, string, int>> offers = service->getOffersForItemSortedByDate(index);
	if (offers.empty()) {
		QMessageBox::information(this, "Offers", "No offers available for this item.");
		return;
	}
	QString offerDetails;
	for (const auto& offer : offers) {
		int userId = get<0>(offer);
		string date = get<1>(offer);
		int amount = get<2>(offer);
		offerDetails += QString("User ID: %1, Date: %2, Amount: %3\n").arg(userId).arg(QString::fromStdString(date)).arg(amount);
	}
	QMessageBox::information(this, "Offers", offerDetails);
}

void Admin_Window::populateItemList()
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

