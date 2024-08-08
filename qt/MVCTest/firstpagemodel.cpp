#include "firstpagemodel.h"
#include "firstpagecontroller.h"
#include "singleton.h"

#include <QDebug>

FirstPageModel::FirstPageModel(QObject *parent) : QObject(parent)
{

}

void FirstPageModel::countSlot()
{
    int a = 2;
    int b = 3;
    emit Singleton<FirstPageController>::getInstance().finishedCountSignal();
    //qDebug() << QString::fromUtf8("页面1的逻辑功能计算结果为==%1").arg(a + b);
    qDebug() << QString::fromLocal8Bit("页面1的逻辑功能计算结果为 == %1").arg(a + b);
}

