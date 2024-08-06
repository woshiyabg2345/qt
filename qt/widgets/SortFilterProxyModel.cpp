#include "SortFilterProxyModel.h"

SortFilterProxyModel::SortFilterProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{}

SortFilterProxyModel::~SortFilterProxyModel()
{}

bool SortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex & source_parent) const
{
	QString data = sourceModel()->index(source_row, 0, source_parent).data(Qt::DisplayRole).toString();
	if (this->filterRegularExpression().match(data).hasMatch())
		return true;
	return false;
}

bool SortFilterProxyModel::lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const
{
	

	QVariant leftData = sourceModel()->data(source_left);
	QVariant rightData = sourceModel()->data(source_right);

	switch (source_left.column())
	{
	case 0:
		return leftData.toInt() < rightData.toInt();
	default:
		break;
	}
	return false;
}
