#ifndef FIRSTPAGECONTROLLER_H
#define FIRSTPAGECONTROLLER_H

#include <QObject>
#include <QThread>
#include "firstpagemodel.h"
#include "singleton.h"

class FirstPageController : public QObject
{
    SINGLETON(FirstPageController)
    Q_OBJECT

signals:
    void startedCountSignal();
    void finishedCountSignal();
    void showFinishedCountUiSignal();

private:
    void initController();
    QThread *threadCount;
    FirstPageModel *firstPageModel;

private slots:
    void startCountSlot();
    void quitCountThreadSlot();
    void finishedCountThreadSlot();


};

#endif // FIRSTPAGECONTROLLER_H

