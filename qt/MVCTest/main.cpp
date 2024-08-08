#include "widget.h"
#include <QApplication>
#include "singleton.h"

/*

https://blog.csdn.net/panchang199266/article/details/104849986?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-104849986-blog-52072380.235%5Ev43%5Epc_blog_bottom_relevance_base8&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-104849986-blog-52072380.235%5Ev43%5Epc_blog_bottom_relevance_base8&utm_relevant_index=1
*/
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.resize(960, 640);
    w.setWindowTitle(QString::fromLocal8Bit("Qt/C++架构工程demo版本V1.0.0"));
    w.setStyleSheet("font: bold 12px;");


    w.show();
    //Singleton<QWidget>* p = new Singleton<QWidget>();

    return a.exec();
}

