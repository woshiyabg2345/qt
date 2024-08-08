#include "firstpageview.h"

#include <QPushButton>
#include "singleton.h"
#include "firstpagecontroller.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
FirstPageView::FirstPageView(QWidget *parent) : QWidget(parent)
{
    setUi();
}

void FirstPageView::setUi()
{
    QPushButton *firstPage = new QPushButton(QString::fromLocal8Bit("���ǵ�һҳ��ҳ�棺�����ʵ��2+3���㹦�ܣ�ҵ���߼����ܣ�"));
    connect(firstPage, SIGNAL(clicked(bool)), this, SLOT(showUiSlot()));
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(firstPage);
    mainLayout->addStretch();

    connect(&Singleton<FirstPageController>::getInstance(), SIGNAL(showFinishedCountUiSignal()), this, SLOT(showFinishedCountResultUISlot()));

}

void FirstPageView::showUiSlot()
{
    emit Singleton<FirstPageController>::getInstance().startedCountSignal();
}

void FirstPageView::showFinishedCountResultUISlot()
{
    qDebug()<< QString::fromLocal8Bit("��ʾ�������棡����");
        QMessageBox::warning(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("��ʾ�������棡����"),QMessageBox::Yes,QMessageBox::No);
}

