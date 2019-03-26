#pragma once

#include <QObject>

namespace db{

/**
 * @brief The DBWrapper class provides convenient tools for working with the database
 */
class DBWrapper : public QObject
{
    Q_OBJECT

public:
    explicit DBWrapper(QObject *parent = nullptr);

private:

};

} // namespace db
