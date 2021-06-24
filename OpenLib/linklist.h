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
    Node* m_Current;
    int m_Step;

    Node* FindPos(int p) const
    {
        Node* TempCurr = reinterpret_cast<Node*>( &ListHead );
        for (int i = 0 ; i < p; i++)
        {
            TempCurr = TempCurr->next;
        }
        return TempCurr;
    }

    virtual Node* create()
    {
        return new Node();
    }
    virtual void destory(Node* dp)
    {
        delete dp;
    }

public:
    LinkList()
    {
        ListHead.next = nullptr;
        m_Length = 0;
        m_Current = nullptr;
        m_Step = 0;
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
            Node* NewNode = create();
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
            destory(TempToDelNode);
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

    int find(const T&e)
    {
        int ret = -1;

        int TempCount = 0;
        Node* TempNode = ListHead.next;
        while(TempNode != nullptr)
        {
            if (TempNode->m_Value == e)
            {
                ret = TempCount;
                break;
            }
            else
            {
                TempCount++;
                TempNode = TempNode->next;
            }
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
            destory( TempToDelNode );
        }
        m_Length = 0;
    }

    bool move(int i, int step = 1)
    {
        bool ret = (i >= 0) && (i < m_Length) && (step > 0);

        if (ret)
        {
            m_Current = FindPos(i)->next;
            m_Step = step;
        }

        return ret;
    }

    bool end()
    {
        return (m_Current == nullptr);
    }

    T current()
    {
        if (!end())
        {
            return m_Current->m_Value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No value at current ...");
        }
    }

    bool next()
    {
        int TempCount_i = 0;
        while((TempCount_i < m_Step) && (!end()))
        {
            m_Current = m_Current->next;
            TempCount_i++;
        }
        return (TempCount_i == m_Step);
    }

    ~LinkList()
    {
        clear();
    }

};

}

#endif // LINKLIST_H
