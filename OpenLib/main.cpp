#include <iostream>
#include <staticarray.h>

using namespace std;
using namespace OpenLib;


int main()
{
    StaticArray<int, 10> array;
    for (int i = 0; i < array.length(); i++)
    {
        array[i] = i;
    }

    for (int i = 0; i < array.length(); i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}
