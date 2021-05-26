#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
#include "Object.h"
#include "SeqList.h"

using namespace std;
using namespace OpenLib;

class Test : public Object
{
public:
    int i;
    int j;

};

class Filea : public Test
{
public:
    int f;
};

int main(int argc, char *argv[])
{
//    SmartPointer<Test> sp = new Test();
//    SmartPointer<Test> new_sp = sp;

//    cout << sp.isNull() << endl;
//    cout << new_sp.isNull() << endl;

    Object* p = new Test();
    Object* q = new Filea();

    SeqList<int>* ll;

    delete p;
    delete q;

    try
    {
        THROW_EXCEPTION(InvalidParameterException, "__FILE__, __LINE__");
    }
    catch (const ArithmeticException& e)
    {
        cout << "ArithmeticException: ";
        cout << e.message() << " ," << e.location() << endl;
    }
    catch (const InvalidParameterException& e)
    {
        cout << "InvalidParameterException: ";
        cout << e.message() << " ," << e.location() << endl;
    }
    catch (const NoEnonghMemoryException& e)
    {
        cout << "NoEnonghMemoryException: ";
        cout << e.message() << " ," << e.location() << endl;
    }
    catch (const IndexOutOfBoundsException& e)
    {
        cout << "IndexOutOfBoundsException: ";
        cout << e.message() << " ," << e.location() << endl;
    }
    catch (const NullPointerException& e)
    {
        cout << "NullPointerException: ";
        cout << e.message() << " ," << e.location() << endl;
    }
    catch (const Exception& e)
    {
        cout << "Exception: ";
        cout << e.message() << " ," << e.location() << endl;
    }

    return 0;
}
