/************************************************************
 * DynamicArray.h
 * 2021-6-3 by FlashOpen-Go
 * DynamicArray实现
 * DynamicArray继承于Array
 * DynamicArray使用时可以动态调节数组的大小
 *
 *  更新日志：
    * 2021-6-3 FlashOpen-Go
        * 添加相关基础功能实现
*************************************************************/
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "array.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_Length;

public:
    /**
     * @brief DynamicArray : 构造函数
     * @param length ： 指定创建的数组大小
     */
    DynamicArray(int length)
    {
        T* TempArray = new T[length];
        if (TempArray != nullptr)
        {
            this->m_Array = TempArray;
            m_Length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnonghMemoryException, "No memory to creater dynamicarray object ...");
        }
    }

    /**
     * @brief DynamicArray : 拷贝构造函数
     * @param obj : 需要拷贝的数据
     */
    DynamicArray(const DynamicArray<T>& obj)
    {
        T* TempArray = new T[obj.length()];
        if (TempArray != nullptr)
        {
            for (int i = 0; i < m_Length; i++)
                TempArray[i] = obj.m_Array[i];
            this->m_Array = TempArray;
            m_Length = obj.length;
        }
        else
        {
            THROW_EXCEPTION(NoEnonghMemoryException, "No memory to creater dynamicarray object ...");
        }
    }

    /**
     * @brief operator = 赋值操作
     * @param obj
     * @return
     */
    DynamicArray<T>& operator = (const DynamicArray<T>& obj)
    {
        if (this != &obj)
        {
            T* TempArray = new T[obj.m_Length];
            if (TempArray != nullptr)
            {
                T* TempOldArray = this->m_Array;
                for (int i = 0; i < obj.length(); i++)
                    TempArray[i] = obj.m_Array[i];
                this->m_Array = TempArray;
                this->m_Length = obj.length();
                delete [] TempOldArray;
            }
            else
            {
                THROW_EXCEPTION(NoEnonghMemoryException, "No memory to creater dynamicarray object ...");
            }
        }
        return *this;
    }

    /**
     * @brief length
     * @return
     */
    int length() const
    {
        return m_Length;
    }


    void resize(int length)
    {
        if (this->m_Length != length)
        {
            T* TempArray = new T[length];
            if (TempArray != nullptr)
            {
                int TempCopySize = m_Length > length ? length : m_Length;
                T* TempOldArray = this->m_Array;
                for (int i = 0; i < TempCopySize; i++)
                    TempArray[i] = this->m_Array[i];
                this->m_Length = length;
                this->m_Array = TempArray;
                delete [] TempOldArray;
            }
            else
            {
                THROW_EXCEPTION(NoEnonghMemoryException, "No memory to creater dynamicarray object ...");
            }
        }
    }


    ~DynamicArray()
    {
        delete [] this->m_Array;
    }

};

}

#endif // DYNAMICARRAY_H
