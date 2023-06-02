#include <QtTest>
#include "func_for_server.h"
// add necessary includes here

class func_for_server_test : public QObject
{
    Q_OBJECT

public:
    func_for_server_test();
    ~func_for_server_test();

private slots:
    void test_case1();

};

func_for_server_test::func_for_server_test()
{

}

func_for_server_test::~func_for_server_test()
{

}

void func_for_server_test::test_case1()
{
//QVERIFY(parsing("hkblhbldusvhnbsj")=="check is thing work");
QVERIFY2(parsing("hkblhbldusvhnbsj",123)=="check is thing work","parsing(hkblhbldusvhnbsj)!=check is thing work");
}

QTEST_APPLESS_MAIN(func_for_server_test)

#include "tst_func_for_server_test.moc"
