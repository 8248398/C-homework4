#include <iostream>
using namespace std;
//1.	请设计一个C++的类MyVector，用于表示三维空间中的向量，使得可以通过操作符重载实现如下运算：
//（1）MyVector对象之间的相加、相减运算符重载（对应三位空间中向量的相加、相减操作）
//（2）MyVector对象之间相乘的运算符重载（这里的相乘指的是向量点乘）
//（3）MyVector对象的输出运算符 << 重载，用于打印三维向量的坐标
//要求：
//（1）重载运算符时应该用成员函数实现
//（2）MyVector类应该包含三个 float 型的私有数据成员，表示三个坐标轴上的分量
//（3）请注意操作符的优先级

class MyVector
{
	friend ostream& operator<<(ostream& cout, MyVector& p);
public:
	MyVector()
	{

	}
	MyVector(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
	MyVector operator+(MyVector p)
	{
		MyVector t;
		t.x = this->x + p.x;
		t.y = this->y + p.y;
		t.z = this->z + p.z;
		return t;
	}
	MyVector operator-(MyVector p)
	{
		MyVector t;
		t.x = this->x - p.x;
		t.y = this->y - p.y;
		t.z = this->z - p.z;
		return t;
	}
	MyVector operator*(MyVector p)
	{
		MyVector t;
		t.x = this->x * p.x;
		t.y = this->y * p.y;
		t.z = this->z * p.z;
		return t;
	}
private:
	float x;
	float y;
	float z;
};
ostream& operator<<(ostream& cout, MyVector& p)
{
	cout << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
	return cout;
}
void test1()
{
	MyVector p1(1,2,3);
	MyVector p2(4,5,6);
	MyVector p3;
	MyVector p4;
	MyVector p5;
	p3 = p1 + p2;
	p4 = p1 - p2;
	p5 = p1 * p2;
	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
}
int main1()
{
	test1();
	return 0;
}