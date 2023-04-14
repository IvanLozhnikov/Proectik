#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "func_for_server.h"

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer/*откуда*/, &QTcpServer::newConnection/*что*/,
            this, &MyTcpServer::slotNewConnection/*что сделать*/);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
    QTcpSocket *curr_mTcpSocket; 
        curr_mTcpSocket = mTcpServer->nextPendingConnection();/*конект*/
        curr_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");/*отчёт*/
        connect(curr_mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(curr_mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
       mTcpSocet->push_back(curr_mTcpSocket);
    }
}

void MyTcpServer::slotServerRead()
{
    QByteArray array;
    QString mystr = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        array =mTcpSocket->readAll();
        mystr += array;
    }
    array = "";
    array.append(mystr.toUtf8());
    qDebug() << mystr;
    mTcpSocket->write(parsing(mystr));
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
