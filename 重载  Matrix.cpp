#include <iostream>
#include <vector>
using namespace std;
//2.	���һ����ΪMatrix���֧࣬�����������������
//��1�� + : ����ӷ�
//��2�� - : �������
//��3�� * : ����˷�
//��4�� << : �����ӡ���
//���У����������Ϊ��άfloat�������飬�ӷ����������˷��ļ��㷽ʽ�ֱ�Ϊ��
//��1���ӷ���������������Ӧλ��Ԫ����ӡ����
//��2���˷�������������ˣ�����Ϊ���������������Ҿ����������֮����

class Matrix
{
	friend ostream& operator<<(ostream& cout, Matrix& p);
public:
	Matrix() = default;

	// ��ʼ���̶�ֵ�Ĺ��캯��
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
////2.1  ���ŷ������� 
//Person p1(10);
////ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ���������� 
////Person p2(); 
////2.2 ��ʽ�� 
//Person p2 = Person(10);
//Person p3 = Person(p2);
////Person(10)����д������������  ��ǰ�н���֮���������� 
////2.3 ��ʽת���� 
//Person p4 = 10; // Person p4 = Person(10);  
//Person p5 = p4; // Person p5 = Person(p4);  
////ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ������� 
////Person p5(p4); 