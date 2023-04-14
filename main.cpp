#include <QCoreApplication>

#include "mytcpserver.h"
#include "SingletonDB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*
    MyTcpServer server;

    QSqlDatabase db =
        QSqlDatabase::addDatabase("QSQLITE");//���������� ��������� ����� � ����������� ���� ���������� � ���� ������ \ SQLITE �������� �� �������\ ������� �������� ����� �� �� �� �������\ Mysql �������
    db.setDatabaseName("sqlite.db");

    if (!db.open())
        qDebug() << db.lastError().text();//������ ��������� ������

    QSqlQuery query(db);
    //������� �������
    query.exec("CREATE TABLE User("
        "login VARCHAR(20) NOT NULL, "
        "password VARCHAR(20) NOT NULL"
        ")");

    //�������� ������ � �������
   // query.prepare("INSERT INTO User(login, password) "
   //             "VALUES (\"admin\", \"123\")");
                  


   query.prepare("INSERT INTO User(login, password) "
        "VALUES (:login, :password)");

    query.bindValue(":password", "123");
    query.bindValue(":login", "admin");

    query.exec();// ��������� ������
    
    /*
    ������� ��� ������ ��
    SELECT * FROM User

    ������� ��� ������ �� � ��������
    SELECT * FROM User WHERE .......
   */
 /*  query.exec("SELECT * FROM User");


    // ������� �� �����
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");//����� "�������"
    const int passwordIndex = rec.indexOf("password");

    while (query.next())
        qDebug() << query.value(loginIndex).toString()
        << "\t" << query.value(passwordIndex) << "\n";
        
    //������� ����������
    //������� �������
   // query.exec("DROP TABLE User");
    //��������� ���� ������
    db.close();
    */
    
    
    qDebug()<<Singleton::getInstance()->sendQuery("SELECT * from User");
    return a.exec();
}
