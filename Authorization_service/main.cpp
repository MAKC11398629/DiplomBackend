#include <QCoreApplication>
#include "dbWrapper/idatabase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IDataBase *idb = IDataBase::instance();
    idb->OpenDataBase();

    return a.exec();
}
