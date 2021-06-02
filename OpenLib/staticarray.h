/************************************************************
 * StaticArray.h
 * 2021-6-2 by FlashOpen-Go
 * StaticArray实现
 * StaticArray继承于Array
 * StaticArray使用是需要指定数据的类型和整个数组的大小
 *
 *  更新日志：
    * 2021-6-2 FlashOpen-Go
        * 添加相关基础功能实现
*************************************************************/

#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.h"

namespace OpenLib
{

template <typename T, int N>
class StaticArray : public Array<T>
{
protected:
    T m_Space[N];

public:
    /**
     * @brief StaticArray : 构造函数，完成子类和父类中部分变量的链接
     */
    StaticArray()
    {
        Array<T>::m_Array = m_Space;
    }

    /**
     * @brief StaticArray：拷贝构造函数
     * @param obj
     */
    StaticArray(const StaticArray<T, N>& obj)
    {
        Array<T>::m_Array = m_Space;
        for (int i = 0; i < N; i++)
        {
            m_Space[i] = obj[i];
        }
    }

    /**
     * @brief operator = ： 赋值操作
     * @param obj
     * @return
     */
    StaticArray<T, N>& operator=(const StaticArray<T, N>& obj)
    {
        if (this != &obj)
        {
            for (int i = 0; i < N; i++)
            {
                m_Space[i] = obj[i];
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
        return N;
    }

};

}

#endif // STATICARRAY_H
