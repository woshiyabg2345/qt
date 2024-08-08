#include "firstpagecontroller.h"
#include <QDebug>

FirstPageController::FirstPageController()
{
    initController();
}

FirstPageController::~FirstPageController()
{

}

void FirstPageController::initController()
{
    connect(this, SIGNAL(startedCountSignal()), this, SLOT(startCountSlot()));
}

void FirstPageController::startCountSlot()
{
    threadCount = new QThread;
    firstPageModel = new FirstPageModel();
    firstPageModel->moveToThread(threadCount);
    connect(threadCount, SIGNAL(started()), firstPageModel, SLOT(countSlot()));
    connect(threadCount, SIGNAL(finished()), threadCount, SLOT(deleteLater()));
    //保证线程先结束，再去更新UI，可以防止UI卡死
    connect(threadCount, SIGNAL(finished()), this, SLOT(finishedCountThreadSlot()));
    connect(this, SIGNAL(finishedCountSignal()), this, SLOT(quitCountThreadSlot()));
    threadCount->start();
}

void FirstPageController::quitCountThreadSlot()
{
    threadCount->quit();
    threadCount->wait();
}

void FirstPageController::finishedCountThreadSlot()
{
    qDebug() << QString::fromLocal8Bit("完成计算逻辑功能！！！");
    emit showFinishedCountUiSignal();
}

