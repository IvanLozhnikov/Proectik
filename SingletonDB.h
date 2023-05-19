#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

//Улучшенная реализация 
class Singleton;

class SingletonDestroyer
{
private:
	Singleton* p_instance;
public:
	~SingletonDestroyer() { 
		delete p_instance ;
	}
	void initialize(Singleton* p) {
		p_instance = p ;
	}
};


class Singleton
{
private:
	static Singleton* p_instance;
	static SingletonDestroyer destroyer;//корзина
	QSqlDatabase db;
protected:
	Singleton() {
		db = QSqlDatabase::addDatabase("QSQLITE");//происходит выделение места и обазначения типа переменных в базе данных \ SQLITE работает из коробки\ посгрес работает чесно но не из коробки\ Mysql какашка
		db.setDatabaseName("sqlite.db");
		//db.setDatabaseName("sqlite1.db");
		if (!db.open())
			qDebug() << db.lastError().text();//выдача последней ошибки	
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator = (Singleton&)=delete;
	~Singleton() {
		db.close();
	}
	friend class SingletonDestroyer;
public:
	static Singleton* getInstance() {
		if (!p_instance)
		{
			p_instance = new Singleton();
			destroyer.initialize(p_instance);
		}
		return p_instance;
	}
	QString sendQuery(QString msg)
	{
		QString res = "";
		QSqlQuery query(db);
		query.exec(msg);// выполнить запрос

		QSqlRecord rec = query.record();
		const int loginIndex = rec.indexOf("login");//номер "столбца"
		const int passwordIndex = rec.indexOf("password");
		while (query.next())
		{
			res=res+query.value(loginIndex).toString() + "\t" + query.value(passwordIndex).toString() + "\n";
		}
		qDebug() << res;

		return res;
	}
};
