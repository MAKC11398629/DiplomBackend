#include "dbWrapper/db_wrapper.h"

db::DBWrapper::DBWrapper( QObject* parent ) : QObject(parent)
{
    mDb = IDataBase::instance();
}

void db::DBWrapper::InsertValues( QStringList params )
{
    // пока ничо не вставляем
}

void db::DBWrapper::DeleteValues( QStringList params )
{
    // пока что пусто как возвращаемое значение
}

QList<QStringList> db::DBWrapper::SelectValues( QString field, QString key )
{
    if( !key.isEmpty() && !field.isEmpty() )
    {
        QString sql = "SELECT * FROM \"Users\" ";
        sql += "WHERE \"" + field + "\"=\"" + key + '\"';
        return mDb->makeRequest( sql );
    }
    return QList<QStringList>();
}
