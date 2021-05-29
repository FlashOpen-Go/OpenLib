/************************************************************
 * StaticList.h
 * 2021-5-29 by FlashOpen-Go
 * StaticList实现
 * StaticList继承于SeqList，使用内置数组来实现List
 * StaticList使用是需要指定数据的类型和整个List的大小
 *
 *  更新日志：
    * 2021-5-29 FlashOpen-Go
        * 添加相关基础功能实现
*************************************************************/

#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.h"
#include "Exception.h"

namespace OpenLib
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    int m_Space[N];
public:

    /**
     * @brief StaticList : 构造函数中完成相关子类和父类之间相关数据的关联
     */
    StaticList()
    {
        this->m_Array = m_Space;
        this->m_Length = 0;
    }

    /**
     * @brief capacity : 父类中的虚函数，获取当前的List大小
     * @return ： 返回List大小
     */
    int capacity() const
    {
       return N;
    }

};

}

#endif // STATICLIST_H
