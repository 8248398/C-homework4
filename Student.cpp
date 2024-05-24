#include <iostream>
#include <vector>
using namespace std;

//7.	先定义一个成员类student，里面有两个成员变量，int型的班级序号，int型的成绩；再定义一个用于查找的类 score_recorder ，用于记录班级所有成员的得分
//类成员变量：
//成员表(member_table)，类型为： student数组
//班级人数，类型为 int
//类成员函数：
//（1）排序：将成员表按照成绩从高到低排序，即成绩最高的学生为 student[0]
//（2）查找：输入学生的班级序号，查找对应的成绩
//（3）修改操作：输入学生的班级序号，和新成绩，修改成员表对应学生的成绩
//（4）输出前10名（rank_10） : 输出成绩最高的前十名的班级序号和相对应的成绩
//要求：
//（1）班级序号必须合法，也就是大于0小于班级人数值
//（2）成绩用float数来存储，且只保留小数点后2位
//在主函数中，完成以下的操作：
//（1）	自定义班级人数，然后录入第一次月考成绩，月考成绩同样自定义
//（2）	输出第一次月考成绩排名最高的10位同学成绩
//（3）	录入第二次月考成绩，月考成绩同样自定义
//（4）	输出第二次月考成绩排名最高的10位同学成绩
//（5）	有两名同学（班级序号自定义）想要查成绩，请你帮助他们查找成绩

class Student {
public:
    int score;
};

class Recorder {
public:
    Recorder(int n) : num(n), table(n) {}

    void sequence() {
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - i - 1; j++) {
                if (table[j].score < table[j + 1].score) {
                    swap(table[j], table[j + 1]);
                }
            }
        }
    }

    void find(int i) {
        cout << "第" << i << "名的成绩为： " << table[i - 1].score << endl;
    }

    void revise(int a, int b) {
        table[a - 1].score = b;
        cout << "成绩修改成功" << endl;
    }

    void rank_10() {
        for (int i = 0; i < 10 && i < num; i++) {
            cout << "第" << i + 1 << "名的成绩为： " << table[i].score << endl;
        }
    }

    int num;
    vector<Student> table;
};

int main7() {
    Recorder p(20);
    for (int i = 0; i < 20; i++) {
        int a;
        cin >> a;
        p.table[i].score = a;
    }
    p.sequence();
    p.find(5);
    p.revise(4, 99);
    p.sequence();
    p.rank_10();
    p.find(2);
    p.find(1);
    return 0;
}
