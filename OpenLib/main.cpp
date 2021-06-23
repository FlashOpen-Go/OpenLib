#include <iostream>
#include "linklist.h"

using namespace std;
using namespace OpenLib;

class Test111 : public Object
{
protected:
    int v;
public:
    Test111()
    {

    }
    Test111(int v)
    {
        this->v = v;
    }
    bool operator == (const Test111& t)
    {
        return (v == t.v);
    }
};

int main()
{
    Test111 t1(1);
    Test111 t2(2);
    Test111 t3(3);

    LinkList<Test111> array;

    array.insert(t1);
    array.insert(t2);
    array.insert(t3);

    cout << array.find(t2) << endl;

    return 0;
}
