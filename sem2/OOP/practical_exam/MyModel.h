#pragma once
#include <QAbstractTableModel>
#include "Service.h"

class TableModel : public QAbstractTableModel {
private:
	Service& serv;
	vector<Idea> ideas;
public:
	TableModel(Service& s) :serv(s) {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	void setitems(const vector<Idea>& it) {
		beginResetModel();
		this->ideas = it;
		endResetModel();
	}
	void addItem(const Idea& idea) {
		beginInsertRows(QModelIndex(), ideas.size(), ideas.size());
		ideas.push_back(idea);
		endInsertRows();
	}
	Idea getItem(int row) const {
		if (row < 0 || row >= ideas.size()) {
			throw std::out_of_range("Row index out of range");
		}
		return ideas[row];
	}
};