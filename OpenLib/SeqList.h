/************************************************************
 * SeqList.h
 * 2021-5-29 by FlashOpen-Go
 * SeqList实现，SeqList是List的抽象类，之后的相关List均基于当前抽象类实现
 *
 *  更新日志：
    * 2021-5-26 FlashOpen-Go
        * 添加相关基础功能实现
    * 2021-5-29 FlashOpen-Go
        * 修复insert操作时未插入数据的问题
*************************************************************/

#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_Array;
    int m_Length;
public:
    bool insert(int i, const T& e)
    {
        bool ret = (i >=0 && i <= m_Length);
        ret &= (i < capacity());
        if (ret)
        {
            for (int j = m_Length - 1; j >= i; j--)
            {
                m_Array[ j + 1] = m_Array[j];
            }
            m_Array[i] = e;
            m_Length++;
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = (i >=0 && i < m_Length);
        if (ret)
        {
            for (int j = i; j < m_Length - 1; j++)
            {
                m_Array[j] = m_Array[j + 1];
            }
            m_Length--;
        }
        return ret;
    }

    bool set(int i, const T& e)
    {
        bool ret = (i >=0 && i <m_Length);
        if (ret)
        {
            m_Array[i] = e;
        }
        return ret;
    }

    bool get(int i, T& e)
    {
        bool ret = (i >=0 && i < m_Length);
        if (ret)
        {
            e = m_Array[i];
        }
        return ret;
    }

    int length() const
    {
        return m_Length;
    }

    void clear()
    {
        m_Length = 0;
    }

    T& operator[] (int i)
    {
        bool ret = (i >=0 && i < m_Length);
        if (ret)
        {
            return m_Array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid");
        }
    }

    T operator[](int i) const
    {
        return (const_cast<SeqList<T>&>(*this))[i];
    }
    virtual int capacity() const = 0;
};


}


#endif // SEQLIST_H
