#include "Object.h"

#include <cstdlib>
#include <iostream>

using namespace std;

namespace OpenLib
{

void* Object::operator new(unsigned long long size) throw()
{
    return malloc(size);
}


void Object::operator delete(void* p)
{
    free(p);
}


void* Object::operator new[](unsigned long long size) throw()
{
    return malloc(size);
}


void Object::operator delete[](void* p)
{
    free(p);
}

Object::~Object()
{

}

}
