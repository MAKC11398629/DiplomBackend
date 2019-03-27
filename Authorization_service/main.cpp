#include <QCoreApplication>
#include "dbWrapper/db_wrapper.h"
#include <QDebug>

using namespace db;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBWrapper *wrap = new DBWrapper();
    qDebug() << wrap->SelectValues( "UserName", "Max" );
    return a.exec();
}
