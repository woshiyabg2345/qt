#pragma once

#include <QSortFilterProxyModel>
#include <QModelIndex>
class SortFilterProxyModel  : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	SortFilterProxyModel(QObject *parent);
	~SortFilterProxyModel();

	virtual bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;
	virtual bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const override;
};
