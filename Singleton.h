//классическая реализация патерн проектирования позволяющий создать объект в единственном числе с доступом из любой части кода
/*class Singleton
{
	private:
		static Singleton * p_instance;//выделение памяти при помощи ссылки/ статик значит что данное поля эдентичное для всех представителей класса

		Singleton(){}
		Singleton(const Singleton& );
		Singleton& operator = delete;
	public:
		static Singleton* getInstance(){
			if (!p_instance)
				p_instance = new Singleton();
			return p_instance;
		}
}


Singleton::getInstance();

delete Singleton::getInstance(); //удаление6 памяти на том, кто использует класс, а не автоматически в классе!!!!
*/


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