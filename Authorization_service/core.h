#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <web/httpserver.h>

class Core : public QObject
{
    Q_OBJECT

    const QString validationSuccess = "\"validation\": \"true\"";
    const QString validationFailed = "\"validation\": \"false\"";

    HttpServer* mServer = nullptr;

public:
    explicit Core(QObject *parent = nullptr);

    void start();

signals:
    void validationResponceFormed( int descriptor, QByteArray responce );
public slots:
    void validationRequest( int descriptor, QString hash );
};

#endif // CORE_H
