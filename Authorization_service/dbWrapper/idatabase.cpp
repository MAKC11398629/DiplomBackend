#include "idatabase.h"

#include <QSqlQuery>
#include <QSqlRecord>
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
    OpenDataBase();
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

QList<QStringList> IDataBase::makeRequest(QString sqlRequest)
{
    QSqlQuery query;
    query.exec( sqlRequest );

    QList<QStringList> responce_table;
    if( !query.isSelect() )
        return QList<QStringList>();
    else
    {
        while( query.next() )
        {
            QStringList responce_row;

            for( int i = 0; i < query.record().count(); i++ )
                responce_row << query.value(i).toString();

            responce_table.append( responce_row );
        }

        if( responce_table.isEmpty() )
            qDebug() << "Not data on request: " << sqlRequest;
        else
            qDebug() << "request executed:" << sqlRequest << "returned data:" << responce_table;
    }
    return responce_table;
}
