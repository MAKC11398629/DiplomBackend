#pragma once

#include <QObject>
#include "idatabase.h"

namespace db{

/**
 * @brief The DBWrapper class provides convenient tools for working with the database
 */
class DBWrapper : public QObject
{
    Q_OBJECT
    IDataBase *mDb;
public:
    explicit DBWrapper(QObject *parent = nullptr);

    /**
     * @brief IsContainsInjections
     * @param params for sql command that needs check
     * @return true if almost one param contains injection else false
     */
    bool IsContainsInjections( QStringList params );

    /// standart operations with db
    virtual void InsertValues( QStringList params );
    virtual void DeleteValues( QStringList params );


    virtual QList<QStringList> SelectValues( QString field, QString key );

private:

};

} // namespace db
