#include <QCoreApplication>

#include "mytcpserver.h"
#include "SingletonDB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*
    MyTcpServer server;

    QSqlDatabase db =
        QSqlDatabase::addDatabase("QSQLITE");//происходит выделение места и обазначения типа переменных в базе данных \ SQLITE работает из коробки\ посгрес работает чесно но не из коробки\ Mysql какашка
    db.setDatabaseName("sqlite.db");

    if (!db.open())
        qDebug() << db.lastError().text();//выдача последней ошибки

    QSqlQuery query(db);
    //создали таблицу
    query.exec("CREATE TABLE User("
        "login VARCHAR(20) NOT NULL, "
        "password VARCHAR(20) NOT NULL"
        ")");

    //добавить запись в таблицу
   // query.prepare("INSERT INTO User(login, password) "
   //             "VALUES (\"admin\", \"123\")");
                  


   query.prepare("INSERT INTO User(login, password) "
        "VALUES (:login, :password)");

    query.bindValue(":password", "123");
    query.bindValue(":login", "admin");

    query.exec();// выполнить запрос
    
    /*
    Выбрать все записи БД
    SELECT * FROM User

    Выбрать все записи БД с условием
    SELECT * FROM User WHERE .......
   */
 /*  query.exec("SELECT * FROM User");


    // вывести на экран
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");//номер "столбца"
    const int passwordIndex = rec.indexOf("password");

    while (query.next())
        qDebug() << query.value(loginIndex).toString()
        << "\t" << query.value(passwordIndex) << "\n";
        
    //закрыть соединение
    //удалить таблицу
   // query.exec("DROP TABLE User");
    //закрываем базу данных
    db.close();
    */
    
    
    qDebug()<<Singleton::getInstance()->sendQuery("SELECT * from User");
    return a.exec();
}
