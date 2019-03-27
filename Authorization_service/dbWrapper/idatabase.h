#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDir>

/**
 * @brief The IDataBase low-level database class
 */
class IDataBase : public QObject
{
    Q_OBJECT

    // constants and links
    const QString DB_URL = "C:/Qt_Projects/DiplomBackend/Authorization_service/Schemas/users.db";

    // fields
    QSqlDatabase *mDb;

// methods
private:
    /**
     * @brief IDataBase private constructor
     * @param parent
     */
    explicit IDataBase(QObject *parent = nullptr);

public:
    /**
     * @brief openDataBase method is trying to open a database for a given const link dbUrl
     * @return true if DataBase is successfully opened
     */
    bool OpenDataBase();

    /**
     * @brief makeRequest
     * @param sqlRequest makes request to db without check on sql injections
     *        and valid - it's DbWrappers work
     * @return QStringList with returned value
     */
    QList<QStringList> makeRequest( QString sqlRequest );

    /**
     * @brief instance
     * @return instance if it's exists else create new instance
     */
    static IDataBase *instance();
};

#endif // IDATABASE_H
