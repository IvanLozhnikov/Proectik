#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H
#include<QByteArray>
#include <QString>
#include "SingletonDB.h"
QByteArray parsing(QString str,long desc);
QByteArray auth(QString log, QString pas,long desc);
QByteArray reg(QString log, QString pas,long desc);
QByteArray checktask(QString numb,QString var,QString otvet,long desc);
bool tasks(QString numb,QString var,QString otvet);
QByteArray stat(long desc);
#endif