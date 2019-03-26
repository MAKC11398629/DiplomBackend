#include "idatabase.h"

#include <QSqlQuery>
#include <QDebug>

IDataBase *IDataBase::instance()
{
    static IDataBase *mInstance;
    if( !mInstance )
        mInstance = new IDataBase();
    return mInstance;
}

IDataBase::IDataBase(QObject *parent) : QObject(parent)
{

}

bool IDataBase::OpenDataBase()
{
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( DB_URL );
    db.open();

    mDb = &db;

    if( db.isOpen() )
    {
        qDebug() << "database is opened";
        return true;
    }

    qDebug() << "Unable to open database\nPlease check the path correct";
    return false;
}

QVariant IDataBase::makeRequest(QString sqlRequest)
{
    QSqlQuery query;
    query.exec( sqlRequest );

    QStringList responce;
    while( query.next() )
    {
        responce << query.value(0).toString();

    }

    if( responce.isEmpty() )
        qDebug() << "Not data on request: " << sqlRequest;

    qDebug() << "request executed:" << sqlRequest << "returned data:" << responce;

    return responce;
}
