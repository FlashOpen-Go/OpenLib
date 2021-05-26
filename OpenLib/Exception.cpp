#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace OpenLib
{

/**
 * @brief Exception::Init : 统一的初始化函数
 * @param message
 * @param file
 * @param line
 */
void Exception::Init(const char* message, const char* file, int line)
{
    m_Message = strdup(message);
    if (file != NULL)
    {
        char Temp_str[16] = {0};
        itoa(line, Temp_str, 10);
        m_Location = static_cast<char*>(malloc(strlen(file) + strlen(Temp_str) + 2));
        if (m_Location != NULL)
        {
            strcat(m_Location, file);
            strcat(m_Location, ":");
            strcat(m_Location, Temp_str);
        }
    }
    else
    {
        m_Location = NULL;
    }
}


/**
 * @brief Exception::Exception : 构造函数
 * @param message
 */
Exception::Exception(const char* message)
{
    Init(message, NULL, 0);
}

/**
 * @brief Exception::Exception 构造函数
 * @param file
 * @param line
 */
Exception::Exception(const char* file, int line)
{
    Init(NULL, file, line);
}

/**
 * @brief Exception::Exception 构造函数
 * @param message
 * @param file
 * @param line
 */
Exception::Exception(const char* message, const char* file, int line)
{
    Init(message, file, line);
}

/**
 * @brief Exception::Exception :拷贝构造，需要深拷贝
 * @param e
 */
Exception::Exception(const Exception& e)
{
    m_Message = strdup(e.m_Message);
    m_Message = strdup(e.m_Location);
}

/**
 * @brief Exception::operator = : 赋值操作 深拷贝
 * @param e
 * @return
 */
Exception& Exception::operator=(const Exception& e)
{
    if (this != &e)
    {
        // 1: 释放原始数据
        free(m_Message);
        free(m_Location);

        // 2： 拷贝新的数据
        m_Message = strdup(e.m_Message);
        m_Message = strdup(e.m_Location);
    }
    return *this;
}

/**
 * @brief Exception::message
 * @return
 */
const char* Exception::message() const
{
    return m_Message;
}

/**
 * @brief Exception::location
 * @return
 */
const char* Exception::location() const
{
    return m_Location;
}

/**
 * @brief Exception::~Exception : 析构函数，即使是纯虚函数，再父类中也需要实现，子类的析构会调用到父类的析构函数
 */
Exception::~Exception()
{
    free(m_Message);
    free(m_Location);
}


}
