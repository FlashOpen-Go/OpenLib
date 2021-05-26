#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace OpenLib
{
template <typename T>
class SmartPointer : public Object
{
protected:
    T* m_Pointer;

public:
    SmartPointer(T* p = nullptr)
    {
        m_Pointer = p;
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        m_Pointer = obj.m_Pointer;
        const_cast<SmartPointer<T>&>( obj ).m_Pointer = nullptr;
    }

    SmartPointer& operator=(const SmartPointer<T>& obj)
    {
        if (this != &obj)
        {
            delete m_Pointer;
            m_Pointer = obj.m_Pointer;
            const_cast<SmartPointer<T>&>(obj.m_Pointer) = nullptr;
        }
        return this;
    }

    T* operator->()
    {
        return m_Pointer;
    }

    T& operator*()
    {
        return *m_Pointer;
    }

    bool isNull()
    {
        return m_Pointer == nullptr;
    }

    T* get()
    {
        return m_Pointer;
    }

    ~SmartPointer()
    {
        delete m_Pointer;
    }
};

}


#endif // SMARTPOINTER_H
