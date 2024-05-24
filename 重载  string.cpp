//#include <iostream>
//#include <cstring> // 用于strlen
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//3.	设计一个 C++ 类，实现一个简单的字符串类 String，类包含以下内容：
//成员函数：
//构造函数 String(const char*)：从一个 C 风格的字符串构造一个 String 对象。
//构造函数 String(const String&)：从另一个 String 对象构造一个新的 String 对象。
//析构函数 ~String()：释放 String 对象所占用的内存。
//成员函数 size()：返回字符串的长度。
//成员函数 c_str()：返回指向内部 C 风格字符串的指针。
//运算符重载：
//成员函数 operator=()：实现 String 对象之间的赋值运算。
//成员函数 operator+()：实现 String 对象之间的拼接操作，返回一个新的 String 对象。
//
//支持使用运算符 << 打印出 String 对象中的字符串。
//要求：在实现上述功能的同时，遵循以下原则：
//（1）所有的String类对象都以动态内存分配的方式存储，不允许使用 C++ 标准库提供的字符串处理函数。
//（2）在设计String类时，应当考虑如何避免内存泄漏和悬空指针等问题。具体来说，你应该避免申请了内存之后不释放，或者清空了指针指向的内存后，不将指针赋值为 NULL。
//
//class String
//{
//    friend ostream& operator<<(ostream& cout, const String& p); // 修改为常量引用
//
//public:
//    String(const char* p = nullptr) // 默认参数为nullptr
//    {
//        if (p)
//        {
//            len = strlen(p);
//            s = new char[len + 1]; // 分配足够的空间包括结束符
//            strncpy(s, p, len); // 使用strncpy复制字符串
//            s[len] = '\0';
//        }
//        else
//        {
//            len = 0;
//            s = nullptr;
//        }
//    }
//
//    String(const String& p)
//    {
//        len = p.len;
//        s = new char[len + 1];
//        strncpy(s, p.s, len); // 深拷贝
//        s[len] = '0';
//    }
//
//    ~String() // 添加析构函数
//    {
//        delete[] s;
//    }
//
//    int size() const { return len; } // 添加const
//
//    const char* c_str() const { return s; } // 添加const
//
//    String& operator=(String p) // 输入参数改为值传递
//    {
//        swap(*this, p);
//        return *this;
//    }
//
//    String operator+(const String& p) const // 连接运算符返回值和输入参数改为const
//    {
//        String t;
//        t.len = len + p.len;
//        t.s = new char[t.len + 1];
//        strncpy(t.s, s, len);
//        strncat(t.s, p.s, p.len); // 使用strncat连接字符串
//        return t;
//    }
//
//private:
//    char* s;
//    int len;
//};
//
//ostream& operator<<(ostream& cout, const String& p) // 输入参数改为const引用
//{
//    cout << p.s;
//    return cout;
//}
//
//void swap(String& a, String& b)
//{
//    String t = a;
//    a = b;
//    b = t;
//}
//
//int main3()
//{
//    String s1("Hello,");
//    String s2(" World!");
//    String s3 = s1 + s2;
//    cout << s3 << endl; // 输出： Hello, World!
//    cout << s1.size() << endl; // 输出： 6
//    cout << s2.c_str() << endl; // 输出： World!
//
//    return 0;
//}
