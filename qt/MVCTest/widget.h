#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    void setUi();
    void initMenu();
    void initStackWidget();

    QVBoxLayout *mainLayout;
    QButtonGroup *buttonGroup;
    QStackedLayout *stackLayout;

private slots:
    void buttonGroupSlot(int);
};

#endif // WIDGET_H

