#include "func_for_server.h"
#include <QDebug>
#include <QCoreApplication>

QByteArray parsing(QString str)
{
	if (str == "stop")
		return ("goodbye" +str).toUtf8();
	if (str == "rigistraciya")
		return ("vvedite nik i parol: " +str).toUtf8();
		if (str != NULL)
		//добовляем в бд ник и пароль
		return ("vy uspesno za rigistrovalis" +str).toUtf8();
	if (str == "autorizaciya")
		return ("vvedite nik i parol: " +str).toUtf8();
		if (str != NULL)
		//проверяем в бд ник и пароль
		return ("vy uspesno voshli" +str).toUtf8();
	if (str == "start work")
	//проверка на автористрацию
		return ("zdes poka nichego net no ya rabotau" +str).toUtf8();
	else
		return ("net takoy komandy " +str).toUtf8();
}

//pair<int,string> func(){
// return pair<int,string> (123456, "asdfghjkuytew")
//}