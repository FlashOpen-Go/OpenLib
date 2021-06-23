#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
      T m_Value;
      Node* next;
    };

    mutable struct : public Object
    {
        char array[sizeof (T)];
        Node* next;
    }ListHead;
    int m_Length;

    Node* FindPos(int p) const
    {
        Node* TempCurr = reinterpret_cast<Node*>( &ListHead );
        for (int i = 0 ; i < p; i++)
        {
            TempCurr = TempCurr->next;
        }
        return TempCurr;
    }

public:
    LinkList()
    {
        ListHead.next = nullptr;
        m_Length = 0;
    }

    bool insert(const T& e)
    {
        return insert(m_Length, e);
    }

    bool insert(int i, const T& e)
    {
        bool ret = true;
        ret = (i >= 0) && (i <= m_Length);
        if (ret)
        {
            Node* NewNode = new Node();
            if (NewNode != nullptr)
            {
                NewNode->m_Value = e;
                Node * TempInsert = FindPos(i);
                NewNode->next = TempInsert->next;
                TempInsert->next = NewNode;
                m_Length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnonghMemoryException, "No enongh memory to creater new Node ...");
            }
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = true;
        ret = (i >= 0) && (i <= m_Length);
        if (ret)
        {
            Node * TempPosNode = FindPos(i);
            Node* TempToDelNode = TempPosNode->next;
            TempPosNode->next = TempToDelNode->next;
            delete TempToDelNode;
            m_Length--;
        }
        return ret;
    }

    bool set(int i, const T& e)
    {
        bool ret = true;
        ret = (i >= 0) && (i <= m_Length);
        if (ret)
        {
            FindPos(i)->next->m_Value = e;
        }
        return ret;
    }

    T get(int i)
    {
        T ret;
        if ( get(i, ret) )
            return ret;
        else
            THROW_EXCEPTION(IndexOutOfBoundsException, "i is index out of range ...");
        return ret;
    }

    bool get(int i, T& e)
    {
        bool ret = true;
        ret = (i >= 0) && (i <= m_Length);
        if (ret)
        {
            e = FindPos(i)->next->m_Value;
        }
        return ret;
    }

    int length() const
    {
        return m_Length;
    }

    void clear()
    {
        Node* TempToDelNode = ListHead.next;
        while(ListHead.next)
        {
            ListHead.next = TempToDelNode->next;
            delete TempToDelNode;
        }
        m_Length = 0;
    }

    ~LinkList()
    {
        clear();
    }

};

}

#endif // LINKLIST_H
