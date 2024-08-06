#pragma once

#include <QWidget>
#include "ui_QTreeViewTest.h"

class QStandardItem;
class QStandardItemModel;
class QTreeView;
class SortFilterProxyModel;
class QTreeViewTest : public QWidget
{
	Q_OBJECT

public:
	QTreeViewTest(QWidget *parent = nullptr);
	~QTreeViewTest();
public slots:
	void slot_treeitem_changed(QStandardItem* item);
	Qt::CheckState getTreeItemCheckStatus(QStandardItem* item);
private:
	void initWidget();
private:
	Ui::QTreeViewTestClass ui;

	QStandardItemModel* tree_model;

	QTreeView* tree_view;

	SortFilterProxyModel* sort_model;
};
