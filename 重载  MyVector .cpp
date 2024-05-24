#include <iostream>
using namespace std;
//1.	�����һ��C++����MyVector�����ڱ�ʾ��ά�ռ��е�������ʹ�ÿ���ͨ������������ʵ���������㣺
//��1��MyVector����֮�����ӡ������������أ���Ӧ��λ�ռ�����������ӡ����������
//��2��MyVector����֮����˵���������أ���������ָ����������ˣ�
//��3��MyVector������������� << ���أ����ڴ�ӡ��ά����������
//Ҫ��
//��1�����������ʱӦ���ó�Ա����ʵ��
//��2��MyVector��Ӧ�ð������� float �͵�˽�����ݳ�Ա����ʾ�����������ϵķ���
//��3����ע������������ȼ�

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