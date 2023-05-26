#include "func_for_server.h"
#include <QDebug>
#include <QCoreApplication>


QByteArray parsing(QString str, long desc)
{
QByteArray ansv;//создание масива дл€ ответа на сервер
QStringList args = str.split(" ");//создание списка копирующего строку ввода раздел€€ еЄ по пробелу
	str = args.front();//оставл€ет в строке первое слова из неЄ 
	args.pop_front();//удал€ет слово команду (первое) из списка

//по строке определ€ет какую функцию нужно выполн€ть
	if(str=="auth")
	{
		return auth(args[0],args[1],desc);
		//sends the list to the authorization function
	}
	if(str=="reg")
	{
		return reg(args[0],args[1],desc);
		//sends the list to the registration function
	}
	if(str=="checktask")
	{
	return checktask(args[0],args[1],args[2],desc);
	//chech task_number task_variant answer
	// if true update users
	}
	if(str=="stat")
	{
	return "stat(desc)\r\n";
	//plug
	}
	return "check is this thing work \r\n";
	//it speaks for itself
}

QByteArray auth(QString log, QString pas,long desc)
{
QByteArray ansv;
		if(Singleton::getInstance()->sendQuery("SELECT * from Users where login = '"+log+"' and password = '"+pas+"' and token = 0")!="")
			{
			ansv= ("auth+ "+log+"\r\n").toUtf8();
			//success authorization report
			QString socket_descriptor=QString::number(desc);
			Singleton::getInstance()->sendQuery("update Users set token = '" + socket_descriptor + "' WHERE login = '" + log+"'" );
			//shows that is online
			return ansv;
			}
		else 
			{
			ansv= "auth- \r\n";
			//authorization denied report
			qDebug()<<ansv;
			return ansv;
			}
}
QByteArray reg(QString log, QString pas,long desc)
{
QByteArray ansv;
QString socket_descriptor=QString::number(desc);
if(Singleton::getInstance()->sendQuery("SELECT * from Users where login = '"+log+"'")=="")
//check registration before doing some thing
{	
	Singleton::getInstance()->sendQuery("insert into Users (userid,login, password, token) VALUES ('" + socket_descriptor + "','"+log+"','"+pas+"',0)");
	//registration

	//Singleton::getInstance()->sendQuery("INSERT into Users (userid,login, password, token) VALUES (224,'admin','admin',0)");
	//code for check how registration work

	if(Singleton::getInstance()->sendQuery("SELECT * from Users where login = '"+log+"' and password = '"+pas+"' and token = 0")!="")
	//check registration	
	{
	ansv= "reg+ \r\n";//success registration report
	return ansv;
	}
	else
	{
	ansv= "reg- \r\n";//error registration report
	return ansv;
	}
}
else
	{
	ansv= "reg- already taken \r\n";//registration denied report
	return ansv;
	}

}

QByteArray checktask(QString numb,QString var,QString otvet,desc)
{
QByteArray ansv;
QString socket_descriptor=QString::number(desc);
QMap<QString,int> Spisok_var;
Spisok_var.insert(0);
QMap<QString,Spisok_var> Spisok_nomerov;
if(otvet==Spisok_nomerov[numb,Spisok_var[var]])
	{
	if("SELECT * from Users where token = '"+desc+"' and task'"+numb+"' = 0")!="")
		{
		Singleton::getInstance()->sendQuery("update Users set task'"+numb+"' = 1 where token ='"+desc+"'")
		ansv= "Check+\r\n";//«адание выполнено успешно
		return ansv;
		}
	else
		{
		Singleton::getInstance()->sendQuery("update Users set task'"+numb+"' = 0 where token ='"+desc+"'")
		ansv= "Check=\r\n";//«адание исправлено успешно
		return ansv;
		}
	}
else
	{
	Singleton::getInstance()->sendQuery("update Users set task'"+number+"' = -1 where token ='"+desc+"'")
	ansv= "Check- \r\n";//«адание провалено 
	return ansv;
	}

}
/*	first prototype

if (str == "stop")
		return ("goodbye" +str).toUtf8();
	if (str == "rigistraciya")
		return ("vvedite nik i parol: " +str).toUtf8();
		if (str != NULL)
		//добовл€ем в бд ник и пароль
		return ("vy uspesno za rigistrovalis" +str).toUtf8();
	if (str == "autorizaciya")
		return ("vvedite nik i parol: " +str).toUtf8();
		if (str != NULL)
		//провер€ем в бд ник и пароль
		return ("vy uspesno voshli" +str).toUtf8();
	if (str == "start work")
	//проверка на автористрацию
		return ("zdes poka nichego net no ya rabotau" +str).toUtf8();
	else
		return ("net takoy komandy " +str).toUtf8();*/

//pair<int,string> func(){
// return pair<int,string> (123456, "asdfghjkuytew")
//}