/************************************************************
 * Array.h
 * 2021-6-2 by FlashOpen-Go
 * Array实现
 * Array封装的数组类，抽象类，需要子类继承
 *
 *  更新日志：
    * 2021-6-2 FlashOpen-Go
        * 完成Array抽象类的相关功能
*************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T>
class Array : public Object
{
protected:
    T* m_Array;

public:
    /**
     * @brief set : 设置指定位置元素的数值
     * @param i ： 位置
     * @param e ：指定值
     * @return ：　设置设否成功
     */
    virtual bool set(int i, const T& e)
    {
        bool ret = ((i >= 0) && (i < length()));
        if (ret)
            m_Array[i] = e;
        return ret;
    }

    /**
     * @brief get　：获取指定位置元素的数值
     * @param i ： 位置
     * @param e ：指定位置的数值
     * @return ：获取是否成功
     */
    virtual bool get(int i, T& e) const
    {
        bool ret = ((i >= 0) && (i < length()));
        if (ret)
            e = m_Array[i];
        return ret;
    }

    /**
     * @brief operator [] ： 重载 [] 操作
     * @param i ：位置
     * @return ： 返回指定位置的值
     */
    T& operator[] (int i)
    {
        if ((i >= 0) && (i < length()))
        {
            return m_Array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "i is indexof...");
        }
    }

    /**
     * @brief operator []
     * @param i
     * @return
     */
    T operator[] (int i) const
    {
        return (const_cast<Array<T>&>(*this))[i];
    }

    /**
     * @brief length : 获取数组长度，纯虚函数，由子类继承之后实现
     * @return
     */
    virtual int length() const = 0;
};

}

#endif // ARRAY_H
