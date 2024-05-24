//#include <iostream>
//#include <cstring> // ����strlen
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//3.	���һ�� C++ �࣬ʵ��һ���򵥵��ַ����� String��������������ݣ�
//��Ա������
//���캯�� String(const char*)����һ�� C �����ַ�������һ�� String ����
//���캯�� String(const String&)������һ�� String ������һ���µ� String ����
//�������� ~String()���ͷ� String ������ռ�õ��ڴ档
//��Ա���� size()�������ַ����ĳ��ȡ�
//��Ա���� c_str()������ָ���ڲ� C ����ַ�����ָ�롣
//��������أ�
//��Ա���� operator=()��ʵ�� String ����֮��ĸ�ֵ���㡣
//��Ա���� operator+()��ʵ�� String ����֮���ƴ�Ӳ���������һ���µ� String ����
//
//֧��ʹ������� << ��ӡ�� String �����е��ַ�����
//Ҫ����ʵ���������ܵ�ͬʱ����ѭ����ԭ��
//��1�����е�String������Զ�̬�ڴ����ķ�ʽ�洢��������ʹ�� C++ ��׼���ṩ���ַ�����������
//��2�������String��ʱ��Ӧ��������α����ڴ�й©������ָ������⡣������˵����Ӧ�ñ����������ڴ�֮���ͷţ����������ָ��ָ����ڴ�󣬲���ָ�븳ֵΪ NULL��
//
//class String
//{
//    friend ostream& operator<<(ostream& cout, const String& p); // �޸�Ϊ��������
//
//public:
//    String(const char* p = nullptr) // Ĭ�ϲ���Ϊnullptr
//    {
//        if (p)
//        {
//            len = strlen(p);
//            s = new char[len + 1]; // �����㹻�Ŀռ����������
//            strncpy(s, p, len); // ʹ��strncpy�����ַ���
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
//        strncpy(s, p.s, len); // ���
//        s[len] = '0';
//    }
//
//    ~String() // �����������
//    {
//        delete[] s;
//    }
//
//    int size() const { return len; } // ���const
//
//    const char* c_str() const { return s; } // ���const
//
//    String& operator=(String p) // ���������Ϊֵ����
//    {
//        swap(*this, p);
//        return *this;
//    }
//
//    String operator+(const String& p) const // �������������ֵ�����������Ϊconst
//    {
//        String t;
//        t.len = len + p.len;
//        t.s = new char[t.len + 1];
//        strncpy(t.s, s, len);
//        strncat(t.s, p.s, p.len); // ʹ��strncat�����ַ���
//        return t;
//    }
//
//private:
//    char* s;
//    int len;
//};
//
//ostream& operator<<(ostream& cout, const String& p) // ���������Ϊconst����
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
//    cout << s3 << endl; // ����� Hello, World!
//    cout << s1.size() << endl; // ����� 6
//    cout << s2.c_str() << endl; // ����� World!
//
//    return 0;
//}
