#include "core.h"
#include <dbWrapper/db_wrapper.h>
#include <QDebug>

Core::Core(QObject *parent) : QObject(parent)
{

}

void Core::start()
{
    HttpServer* server = new HttpServer();
    server->startServer( 8080 );

    connect( server, &HttpServer::dataGotten, this, &Core::validationRequest );
    connect( this, &Core::validationResponceFormed, server, &HttpServer::sendDataTo );
}

void Core::validationRequest(int descriptor, QString hash)
{
    QString responce;

    DBWrapper *db = new DBWrapper();
    if( !db->SelectValues( "hash", hash ).isEmpty() )
        responce = validationSuccess;
    else
        responce = validationFailed;

    qDebug() << "responce formed: " << responce;
    emit validationResponceFormed( descriptor, responce.toLocal8Bit() );
}
