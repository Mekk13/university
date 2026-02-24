#include "MyModel.h"

int TableModel::rowCount(const QModelIndex& parent) const
{
	return serv.getIdeaCount();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	int row = index.row();
	int col = index.column();

	if (row < 0 || row >= ideas.size())
		return QVariant();

	Idea idea = this->ideas[row];

	if (role == Qt::DisplayRole) {
		switch (col) {
		case 0: return QString::fromStdString(idea.getTitle());
		case 1: return QString::fromStdString(idea.getDescription());
		case 2: return QString::fromStdString(idea.getStatus());
		case 3: return QString::fromStdString(idea.getCreator());
		case 4: return idea.getDuration();
		default: return QVariant();
		}
	}
	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
		switch (section) {
		case 0: return QString("Title");
		case 1: return QString("Descriiption");
		case 2: return QString("Status");
		case 3: return QString("Creator");
		case 4: return QString("Duration");
		default: break;
		}
	}
	return QVariant();
}
