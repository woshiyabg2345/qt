#include "QTreeViewTest.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTreeView>
#include <QVBoxLayout>
#include <qdebug.h>
#include "SortFilterProxyModel.h"
#include <QHeaderView>
QTreeViewTest::QTreeViewTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initWidget();
}

QTreeViewTest::~QTreeViewTest()
{


}

void QTreeViewTest::slot_treeitem_changed(QStandardItem* item)
{

    qDebug() << __FUNCTION__;
    disconnect(tree_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(slot_treeitem_changed(QStandardItem*)));

    if (item == NULL || !item->isCheckable())
        return;

    int state = item->checkState();
    if (item->hasChildren())
    {
        Qt::CheckState item_status = (state == Qt::Unchecked ? Qt::Unchecked : Qt::Checked);
        for (int i = 0; i < item->rowCount(); ++i)
        {
            for (int j = 0; j < item->columnCount(); ++j)
            {
                QStandardItem* childItem = item->child(i,j);
                if (childItem->isCheckable())
                    childItem->setCheckState(item_status);
            }
        }
        if (state == Qt::PartiallyChecked)
            item->setCheckState(Qt::Checked);
    }
    else
    {
        QStandardItem* parent_item = item->parent();
        if (parent_item->isCheckable() == false)
            return;

        int sibling_state = getTreeItemCheckStatus(item);
        if (sibling_state == Qt::PartiallyChecked)
        {
            if (parent_item->isTristate())
                parent_item->setCheckState(Qt::PartiallyChecked);
            else
                parent_item->setCheckState(Qt::Unchecked);
        }
        else if (sibling_state == Qt::Checked)
            parent_item->setCheckState(Qt::Checked);
        else    parent_item->setCheckState(Qt::Unchecked);
    }

    connect(tree_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(slot_treeitem_changed(QStandardItem*)));

}

Qt::CheckState QTreeViewTest::getTreeItemCheckStatus(QStandardItem* item)
{
    QStandardItem* parent_item = item->parent();
    if (parent_item == NULL)
        return item->checkState();

    int checkedCount = 0, unCheckedCount = 0, state;
    for (int i = 0; i < parent_item->rowCount(); ++i)
    {
        for (int j = 0; j < parent_item->columnCount(); j++)
        {
            QStandardItem* siblingItem = parent_item->child(i,j);
            state = siblingItem->checkState();

            if (state == Qt::PartiallyChecked)
                return Qt::PartiallyChecked;
            else if (state == Qt::Unchecked)
                ++unCheckedCount;
            else    ++checkedCount;
        }
    }

    qDebug() << __FUNCTION__ << " checkCount " << checkedCount << " unCheckCount " << unCheckedCount;
    if (checkedCount == 0)
        return Qt::Unchecked;
    if (checkedCount > 0 && unCheckedCount > 0)
        return Qt::PartiallyChecked;

    return Qt::Checked;

 
 
}

void QTreeViewTest::initWidget()
{
    tree_view = new QTreeView;
    tree_view->setSortingEnabled(true);
    tree_view->setFocusPolicy(Qt::NoFocus);
  //  tree_view->setShowGrid(false);
    tree_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tree_view->header()->setSectionResizeMode(QHeaderView::Interactive);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tree_view);
    this->setLayout(mainLayout);

    tree_model = new QStandardItemModel(0, 1, this);
  

    //控制第一列节点个数
    int mainLevel = 3;

    for (int i = 0; i < mainLevel; ++i) {
        QList<QStandardItem*> items;
        //控制有列个数
        int LevelCount = 5;
        for (int j = 0; j < LevelCount; ++j) {
            QStandardItem* item = new QStandardItem(QString("%0").arg(i));
            //控制可选择框
            item->setCheckable(true);
      
            items.push_back(item);
        }
        tree_model->appendRow(items);

        // 设置内层行数
        for (int i = 0; i < 2; ++i) {
            QList<QStandardItem*> childItems;
            //设置内层列数
            for (int i = 0; i < 5; ++i) {
                QStandardItem* item = new QStandardItem(QString("neibu"));
                if (i == 0)
                    item->setToolTip(QString("neibu"));
                item->setCheckable(true);
                childItems.push_back(item);
            }
            items.at(0)->appendRow(childItems);
        }
    }


    /*
    tree_model = new QStandardItemModel(tree_view);
    tree_view->setModel(tree_model);
    for (int i = 0; i < 10; i++)
    {
        QStandardItem* parent_item = new QStandardItem("AAA");
        parent_item->setCheckable(true);
        parent_item->setTristate(true);

        for (int j = 0; j < 5; j++)
        {
            QStandardItem* item = new QStandardItem("BBB");
            
            item->setCheckable(true);
            parent_item->appendRow(item);
        }
        tree_model->appendRow(parent_item);
    }
    qDebug() << __FUNCTION__ << " treeView rowCount: " << tree_model->rowCount();
   */
    sort_model = new   SortFilterProxyModel(this);
    sort_model->setSourceModel(tree_model);
    tree_view->setModel(sort_model);


    
    connect(tree_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(slot_treeitem_changed(QStandardItem*)));


}
