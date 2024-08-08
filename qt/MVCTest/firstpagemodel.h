#ifndef FIRSTPAGEMODEL_H
#define FIRSTPAGEMODEL_H

#include <QObject>

class FirstPageModel : public QObject
{
    Q_OBJECT
public:
    explicit FirstPageModel(QObject *parent = nullptr);

signals:

public slots:
    void countSlot();
};

#endif // FIRSTPAGEMODEL_H

