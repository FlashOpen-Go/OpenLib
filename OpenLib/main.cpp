#include <iostream>
#include "linklist.h"

using namespace std;
using namespace OpenLib;


int main()
{
    LinkList<int> array;
    for (int i = 0; i < 5; i++)
    {
        array.insert(i);
    }

    array.remove(1);

    for (int i = 0; i < array.length(); i++)
    {
        cout << array.get(i) << endl;
    }

    return 0;
}
