#include "httpserver.h"
#include <QDebug>

HttpServer::HttpServer(QObject *parent) : QObject(parent)
{

}

bool HttpServer::startServer(QString address, int port)
{
    //TODO: realisation
    return true;
}

bool HttpServer::startServer(int port)
{
    mServer = new QTcpServer();
    mServer->listen( QHostAddress::AnyIPv4, port );

    if( !mServer->isListening() )
    {
        return false;
    }

    qDebug() << "server started at port: " << port;
    connect( mServer, &QTcpServer::newConnection, this, &HttpServer::acceptConnection );

    return true;
}

bool HttpServer::closeServer()
{
    if( !mServer->isListening() )
        return false; // couldn't stop not listening server

    mServer->close();
    emit serverStopped();

    return true;
}

void HttpServer::sendDataTo( int descriptor, QByteArray data )
{
    QTcpSocket *tmp_socket = mConnectedMap.key( descriptor );
    tmp_socket->write( data );
}

void HttpServer::acceptConnection()
{
    QTcpSocket *tmp_socket = mServer->nextPendingConnection();
    connect( tmp_socket, &QTcpSocket::readyRead, this, &HttpServer::getDataFromSocket );

    mConnectedMap.insert( tmp_socket, mConnectedMap.size() );
}

void HttpServer::getDataFromSocket()
{
    QTcpSocket* tmp_socket = static_cast<QTcpSocket*>( QObject::sender() );
    emit dataGotten( mConnectedMap.value(tmp_socket), tmp_socket->readAll() );
}
