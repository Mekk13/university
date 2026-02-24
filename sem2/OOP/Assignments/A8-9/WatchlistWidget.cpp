#include "WatchlistWidget.h"
#include <QVBoxLayout>
#include <QTableView>

WatchlistWidget::WatchlistWidget(QAbstractItemModel* model, QWidget* parent) : QWidget(parent)
{
    this->setWindowTitle("Watchlist");
    auto* layout = new QVBoxLayout(this);

    auto* tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->resizeColumnsToContents();

    layout->addWidget(tableView);
    this->setLayout(layout);
    this->setMinimumSize(500, 600);
}

WatchlistWidget::~WatchlistWidget() {}