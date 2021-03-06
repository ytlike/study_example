#include <string>
#include <sstream> // stringstream header file
#include <iostream>


/************************************************************************/
/* http://blog.csdn.net/willtom/article/details/24740305                */
/* 使用stringstream对象简化类型转换                                     */
/*C++标准库中的<sstream>提供了比ANSI C的<stdio.h>更高级的一些功能，     */
/*即单纯性、类型安全和可扩展性。在本文中，我将展示怎样使用这些库来实现  */
/*安全和自动的类型转换。                                                */
/*如果你打算在多次转换中使用同一个stringstream对象，                    */
/*记住再每次转换前要使用clear()方法；                                   */
/************************************************************************/

// g++ -o main main.cpp

template <class T>
std::string to_string(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template <class out_type,class in_value>
out_type convert(const in_value & t)
{
    std::stringstream stream;
    stream << t;
    out_type result;
    stream >> result;//向result中写入值
    return result;
}


int main(int argc, char *argv[])
{
    //stringstream通常是用来做数据转换的。
    //int 与 string的转换

    std::stringstream m_sstream;
    std::string result;
    int i = 1000;
    m_sstream << i;
    m_sstream >> result;
    std::cout << result << "\n";

    m_sstream.clear();
    char res[8];
    m_sstream << 8888;
    m_sstream >> res;
    std::cout<< res << "\n";

    m_sstream.clear();
    int first, second;
    m_sstream << "666";
    m_sstream >> first;
    std::cout << first << std::endl;

    m_sstream.clear();
    m_sstream << true;
    m_sstream >> second;
    std::cout << second << std::endl;

    // Get data from sstream
    m_sstream.clear(); // just rest stream flag
    i = 999;
    m_sstream << "test" << i;
    std::cout << "Call clear(): " << m_sstream.str() << std::endl;

    // Get data
    m_sstream.str(""); // !!! clear string buffer
    std::cout << "After str('') lenght " << m_sstream.str().length() << std::endl;
    m_sstream << "test" << i;
    std::string str = m_sstream.str();
    std::cout << "\n" <<  str << std::endl;

    // Get data
    m_sstream.str(str);
    std::cout << "\n" <<  str << std::endl;

    // Get data
    m_sstream >> str;
    std::cout << "\n" <<  str << std::endl;

    return 0;
}

