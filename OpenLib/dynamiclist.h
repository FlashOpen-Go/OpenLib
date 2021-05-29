/************************************************************
 * DynamicList.h
 * 2021-5-29 by FlashOpen-Go
 * DynamicList实现
 * DynamicList继承于SeqList，使用动态内存分配来实现List
 * DynamicList使用是需要指定数据的类型和整个List的大小
 *
 *  更新日志：
    * 2021-5-29 FlashOpen-Go
        * 添加相关基础功能实现
*************************************************************/

#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    // 顺序存储空间的大小
    int m_Size;
public:

    /**
     * @brief DynamicList : 构造函数，用于申请空间并关联父类和子类之间的相关数据
     * @param size ：需要创建List的大小
     */
    DynamicList(int size)
    {
        this->m_Array = new T[size];
        if (this->m_Array != nullptr)
        {
            m_Size = size;
            this->m_Length = 0;
        }
        else
        {
            THROW_EXCEPTION(NoEnonghMemoryException, "no memory to creater dynamiclist...");
        }

    }

    /**
     * @brief capacity : 实现父类的虚函数，用于获取当前List的最大空间
     * @return ： 返回当前List的最大空间
     */
    int capacity() const
    {
        return m_Size;
    }

    /**
     * @brief resize : 重新设置List的大小
     * @param size ：重新设置大小
     */
    void resize(int size)
    {
        if (m_Size != size)
        {
            T* Temp_p = new T[size];
            if (Temp_p != nullptr)
            {
                T* Temp_Old_Array = this->m_Array;
                int Temp_CopySize = this->m_Length > size ? size : this->m_Length;  // 确定需要拷贝数据的长度
                // 先进行数据的拷贝和相关值的设置，再释放之前的空间，防止释放空间是导致异常，使得相关的操作被打断，保证异常安全
                for (int i = 0; i < Temp_CopySize; i++)
                {
                    Temp_p[i] = this->m_Array[i];
                }
                this->m_Array = Temp_p;
                this->m_Length = Temp_CopySize;
                m_Size = size;
                delete [] Temp_Old_Array;
            }
            else
            {
                THROW_EXCEPTION(NoEnonghMemoryException, "no memory to resize dynamiclist...");
            }
        }
    }

    ~DynamicList()
    {
        delete[] this->m_Array;
    }
};

}

#endif // DYNAMICLIST_H
