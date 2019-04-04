#include "dbWrapper/db_wrapper.h"

DBWrapper::DBWrapper( QObject* parent ) : QObject(parent)
{

}

void DBWrapper::InsertValues( QStringList params )
{
    // пока ничо не вставляем
}

void DBWrapper::DeleteValues( QStringList params )
{
    // пока что пусто как возвращаемое значение
}

QList<QStringList> DBWrapper::SelectValues( QString field, QString key )
{
    mDb = IDataBase::instance();
    if( !key.isEmpty() && !field.isEmpty() )
    {
        QString sql = "SELECT * FROM \"Users\" ";
        sql += "WHERE \"" + field + "\"=\"" + key + '\"';
        return mDb->makeRequest( sql );
    }
    return QList<QStringList>();
}

