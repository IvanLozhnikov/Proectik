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
       mTcpSocket[curr_mTcpSocket->socketDescriptor()] = curr_mTcpSocket;
    }
}

void MyTcpServer::slotServerRead()
{
    
    QTcpSocket *curr_mTcpSocket = (QTcpSocket*)sender(); 
    //mTcpSocet[mTcpServer->socketDescriptor()];
    QByteArray array;
    QString mystr = "";
    while(curr_mTcpSocket->bytesAvailable()>0)
    {
        array =curr_mTcpSocket->readAll();
        mystr += array;
    }
    array = "";
    array.append(mystr.toUtf8());
    qDebug() << mystr;
    curr_mTcpSocket->write(parsing(mystr,curr_mTcpSocket->socketDescriptor()));
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *curr_mTcpSocket = (QTcpSocket*)sender();
    
    for(auto it = mTcpSocket.begin(); it!=mTcpSocket.end();it++)
        if(*it ==curr_mTcpSocket)
        {
            mTcpSocket.remove(it.key());
            Singleton::getInstance()->sendQuery("update Users set token = 0 WHERE token = '" + QString::number(it.key())+"'" );
            break;
        }
    curr_mTcpSocket->close();
    
}
