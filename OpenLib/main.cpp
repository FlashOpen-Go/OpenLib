#include <iostream>
#include "DynamicList.h"

using namespace std;
using namespace OpenLib;


int main()
{
    DynamicList<int> ll(4);

    for (int i = 0; i < 4; i++)
    {
        ll.insert(0, i);
    }

    for (int i = 0; i < ll.length(); i++)
    {
        cout << "ll[" << i << "] = " << ll[i] << endl;
    }

    ll [ 3 ] = 9;
    ll.remove(3);

    for (int i = 0; i < ll.length(); i++)
    {
        cout << "ll[" << i << "] = " << ll[i] << endl;
    }

    return 0;
}
