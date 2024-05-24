#include <iostream>
#include <vector>
using namespace std;
//2.	设计一个名为Matrix的类，支持重载以下运算符：
//（1） + : 矩阵加法
//（2） - : 矩阵减法
//（3） * : 矩阵乘法
//（4） << : 矩阵打印输出
//其中，矩阵可以视为二维float类型数组，加法、减法、乘法的计算方式分别为：
//（1）加法、减法：矩阵相应位置元素相加、相减
//（2）乘法：两个矩阵相乘，定义为左矩阵的行向量与右矩阵的列向量之积。

class Matrix
{
	friend ostream& operator<<(ostream& cout, Matrix& p);
public:
	Matrix() = default;

	// 初始化固定值的构造函数
	explicit Matrix(int rows, int cols, float value = 0.0f)
		: a(rows, vector<float>(cols, value)) {}
	Matrix operator+(Matrix &p)
	{
		Matrix t(a.size(), p.a[0].size());
		for (int i = 0; i < p.a.size(); i++)
		{
			for (int j = 0; j < p.a[0].size(); j++)
			{
				t.a[i][j] = a[i][j] + p.a[i][j];
			}
		}
		return t;
	}
	Matrix operator-(Matrix &p)
	{
		Matrix t(a.size(), p.a[0].size());
		for (int i = 0; i < p.a.size(); i++)
		{
			for (int j = 0; j < p.a[0].size(); j++)
			{
				t.a[i][j] = a[i][j] - p.a[i][j];
			}
		}
		return t;
	}
	Matrix operator*(const Matrix& other) const {
		if (a[0].size() != other.a.size()) {
			throw invalid_argument("false");
		}
		Matrix result(a.size(), other.a[0].size(), 0.0f);
		for (size_t i = 0; i < a.size(); ++i) {
			for (size_t j = 0; j < other.a[0].size(); ++j) {
				for (size_t k = 0; k < a[0].size(); ++k) {
					result.a[i][j] += a[i][k] * other.a[k][j];
				}
			}
		}
		return result;
	}
private:
	vector<vector<float>> a;
};
ostream& operator<<(ostream& cout, Matrix &p)
{
	for (int i = 0; i < p.a.size(); i++)
	{
		for (int j = 0; j < p.a[0].size(); j++)
		{
			cout << p.a[i][j] << " ";
		}
		cout << endl;
	}
	return cout;
}
void test2()
{
	Matrix p1(3, 3, 2);
	Matrix p2(3, 3, 3);
	Matrix p3;
	Matrix p4;
	Matrix p5;
	p3 = p1 + p2;
	p4 = p1 - p2;
	p5 = p1 * p2;
	cout << "p1:\n" << p1 << endl;
	cout << "p2:\n" << p2 << endl;
	cout << "p1 + p2:\n" << p3 << endl;
	cout << "p1 - p2:\n" << p4 << endl;
	cout << "p1 * p2:\n" << p5 << endl;
}
int main2()
{
	test2();
	return 0;
}
////2.1  括号法，常用 
//Person p1(10);
////注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明 
////Person p2(); 
////2.2 显式法 
//Person p2 = Person(10);
//Person p3 = Person(p2);
////Person(10)单独写就是匿名对象  当前行结束之后，马上析构 
////2.3 隐式转换法 
//Person p4 = 10; // Person p4 = Person(10);  
//Person p5 = p4; // Person p5 = Person(p4);  
////注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明 
////Person p5(p4); 