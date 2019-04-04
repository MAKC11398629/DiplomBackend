#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class HttpServer : public QObject
{
    Q_OBJECT
    QTcpServer* mServer;

    // map format: descriptor : socket
    QMap<QTcpSocket*, int> mConnectedMap;
public:
    explicit HttpServer(QObject *parent = nullptr);

    bool startServer( QString address, int port );
    bool startServer( int port );

    bool closeServer();

signals:
    void serverStopped();
    void dataGotten( int socket_descriptor, QByteArray data );
public slots:
    // slots on acception
    void acceptConnection();
    void getDataFromSocket();

    // slots on sending
    void sendDataTo(int descriptor , QByteArray data);

};

#endif // HTTPSERVER_H
