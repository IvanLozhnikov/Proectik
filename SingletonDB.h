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
	//db
protected:
	Singleton() {
		//db.open
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator = (Singleton&)=delete;
	~Singleton() {
		//bd.close
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
		return "query";
	}
};

Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;