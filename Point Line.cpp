#include <iostream>
using namespace std;
//6.	���������� Point ��Line��ʹ��
//��1��	Point�������� float ��Ա���� x��y ��ʾ��άƽ���ϵ����꣬�Լ�һ����ӡ���� print �������
//��2��	Line��������float ��Ա����a��b����ʾһ��ֱ�� y = ax + b��Line����������� << ���ֱ�ߵķ���
//��3��	����Line�����Ԫ����Point setPoint(Line & 11, Line & 12); ����������ֱ�ߵĽ��㡣
//����Ҫ��������ֱ�ߣ��ֱ��ӡֱ�߷��̣�Ȼ���������ֱ�ߵĽ��㣬��ӡ���㣨ע�⴦��ֱ��ƽ�е��������

class Point {
public:
    float x, y;
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

class Line {
public:
    Line(float a, float b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& out, const Line& line);
    friend Point setPoint(Line& l1, Line& l2);
private:
    float a, b;
};

ostream& operator<<(ostream& out, const Line& line) {
    out << "y = " << line.a << "x + " << line.b;
    return out;
}

Point setPoint(Line& l1, Line& l2) {
    Point p;
    if (l1.a == l2.a) {
        cout << "ֱ��ƽ�У��޽���" << endl;
        p.x = 0;
        p.y = 0;
    }
    else {
        p.x = (l2.b - l1.b) / (l1.a - l2.a);
        p.y = l1.a * p.x + l1.b;
    }
    return p;
}

int main6() {
    Line l1(2, 3);
    Line l2(-1, 4);
    cout << "ֱ��1: " << l1 << endl;
    cout << "ֱ��2: " << l2 << endl;
    Point intersection = setPoint(l1, l2);
    cout << "���㣺 ";
    intersection.print();
    return 0;
}
