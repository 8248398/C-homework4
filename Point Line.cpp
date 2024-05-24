#include <iostream>
using namespace std;
//6.	定义两个类 Point 和Line，使得
//（1）	Point类有两个 float 成员变量 x和y 表示二维平面上的坐标，以及一个打印函数 print 输出坐标
//（2）	Line类有两个float 成员变量a和b，表示一条直线 y = ax + b，Line类重载运算符 << 输出直线的方程
//（3）	定义Line类的友元函数Point setPoint(Line & 11, Line & 12); 用于求两条直线的交点。
//你需要定义两条直线，分别打印直线方程，然后求出两条直线的交点，打印交点（注意处理直线平行的情况）。

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
        cout << "直线平行，无交点" << endl;
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
    cout << "直线1: " << l1 << endl;
    cout << "直线2: " << l2 << endl;
    Point intersection = setPoint(l1, l2);
    cout << "交点： ";
    intersection.print();
    return 0;
}
