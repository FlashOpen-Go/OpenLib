#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace OpenLib
{

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception : public Object
{
protected:
    char* m_Message;
    char* m_Location;
    void Init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);
    Exception& operator=(const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

//    virtual ~Exception() = 0;
    virtual ~Exception();
};

class ArithmeticException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    ArithmeticException(const char* message) : Exception(message){}
    ArithmeticException(const char* file, int line) : Exception(file, line){}
    ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line){}
    ArithmeticException(const ArithmeticException& e) : Exception(e){}
    ArithmeticException& operator=(const ArithmeticException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class NullPointerException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    NullPointerException(const char* message) : Exception(message){}
    NullPointerException(const char* file, int line) : Exception(file, line){}
    NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line){}
    NullPointerException(const NullPointerException& e) : Exception(e){}
    NullPointerException& operator=(const NullPointerException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class IndexOutOfBoundsException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    IndexOutOfBoundsException(const char* message) : Exception(message){}
    IndexOutOfBoundsException(const char* file, int line) : Exception(file, line){}
    IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line){}
    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e){}
    IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};
class NoEnonghMemoryException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    NoEnonghMemoryException(const char* message) : Exception(message){}
    NoEnonghMemoryException(const char* file, int line) : Exception(file, line){}
    NoEnonghMemoryException(const char* message, const char* file, int line) : Exception(message, file, line){}
    NoEnonghMemoryException(const NoEnonghMemoryException& e) : Exception(e){}
    NoEnonghMemoryException& operator=(const NoEnonghMemoryException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    InvalidParameterException(const char* message) : Exception(message){}
    InvalidParameterException(const char* file, int line) : Exception(file, line){}
    InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line){}
    InvalidParameterException(const InvalidParameterException& e) : Exception(e){}
    InvalidParameterException& operator=(const InvalidParameterException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidOperationException : public Exception
{
public:
//    ArithmeticException() : Exception(NULL){};
    InvalidOperationException(const char* message) : Exception(message){}
    InvalidOperationException(const char* file, int line) : Exception(file, line){}
    InvalidOperationException(const char* message, const char* file, int line) : Exception(message, file, line){}
    InvalidOperationException(const InvalidOperationException& e) : Exception(e){}
    InvalidOperationException& operator=(const InvalidOperationException& e)
    {
        Exception::operator=(e);
        return *this;
    }
};

}

#endif // EXCEPTION_H
