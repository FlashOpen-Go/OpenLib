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
    LinkList<int> list;
    for (int i = 0 ; i < 5; i++)
    {
        list.insert(0, i);
    }

    for (int i = 0 ; i < list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    for (list.move(0, 2); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }

    return 0;
}
