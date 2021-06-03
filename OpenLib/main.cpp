#include <iostream>
#include <dynamicarray.h>

using namespace std;
using namespace OpenLib;


int main()
{
    DynamicArray<int> array(10);
    for (int i = 0; i < array.length(); i++)
    {
        array[i] = i;
    }

    for (int i = 0; i < array.length(); i++)
    {
        cout << array[i] << endl;
    }

    DynamicArray<int> array2(5);
    array2 =array;
    array2.resize(14);
    for (int i = 0; i < array2.length(); i++)
    {
        cout << array2[i] << endl;
    }

    return 0;
}
