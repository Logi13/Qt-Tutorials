#include <QCoreApplication>
#include <QtTest/QTest> //QVERIFY is here

//
//This is a non working test example of diferent Sequential containers
//

int main(int argc, char *argv[])
{
    QList<int> list{1,2};

    // append another int
    list << 3;

    // We are using scopes to avoid variable name clashes

    { // iterate through list using Qt for each
        int sum(0);
        foreach (int v, list){
            sum +=v;
        }

        QVERIFY(sum == 6);
    }
    { // iterate through list using C++ 11 range based loop
        int sum = 0;
        for(int v : list) {
            sum += v;
        }
        QVERIFY(sum == 6);
    }

    { //iterate through list using JAVA style iterators
        int sum = 0;
        QList<int>::iterator i;
        for (i = list.begin(); i != list.end(); i++) {
            sum += *i;
        }
        QVERIFY(sum == 6);
    }

    // using std::sort with mutable iterator using C++11
    // list will be sorted in descending order
    std::sort(list.begin(), list.end(), [](int a, int b) { return a > b;});
    QVERIFY(list == QList<int>({3,2,1}));

    int value = 3;
    { //using std::find with const iterator
        QList<int>::const_iterator result = std::find(list.constBegin(), list.constEnd(), value);
        QVERIFY(*result == value);
    }

    { //using std::find using C++ lambda and C++ 11 auto variable
        auto result = std::find_if(list.constBegin(), list.constEnd(), [value](int v) {return v == value;});
        QVERIFY(*result == value);
    }
    QCoreApplication a(argc, argv);

    return a.exec();
}

