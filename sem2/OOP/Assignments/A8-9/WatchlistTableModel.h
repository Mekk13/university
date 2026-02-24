#pragma once
#include <QAbstractTableModel>
#include "UserService.h"

class TableModel : public QAbstractTableModel {
private:
	User_Service& serv;
public:
	TableModel(User_Service& s) :serv(s) {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};