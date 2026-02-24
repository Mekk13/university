#pragma once
#include <QWidget>
#include <QAbstractItemModel>

class WatchlistWidget : public QWidget
{
	Q_OBJECT
public:
	WatchlistWidget(QAbstractItemModel* model, QWidget* parent = nullptr);
	~WatchlistWidget();
};