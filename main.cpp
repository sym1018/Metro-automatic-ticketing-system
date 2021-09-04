#include "widget.h"
#include <QApplication>
#include "m_list.h"
#include "Graph.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    Widget w;

    w.show();

    return a.exec();
}
