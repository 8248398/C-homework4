#include <iostream>
#include <vector>
using namespace std;

//7.	�ȶ���һ����Ա��student��������������Ա������int�͵İ༶��ţ�int�͵ĳɼ����ٶ���һ�����ڲ��ҵ��� score_recorder �����ڼ�¼�༶���г�Ա�ĵ÷�
//���Ա������
//��Ա��(member_table)������Ϊ�� student����
//�༶����������Ϊ int
//���Ա������
//��1�����򣺽���Ա���ճɼ��Ӹߵ������򣬼��ɼ���ߵ�ѧ��Ϊ student[0]
//��2�����ң�����ѧ���İ༶��ţ����Ҷ�Ӧ�ĳɼ�
//��3���޸Ĳ���������ѧ���İ༶��ţ����³ɼ����޸ĳ�Ա���Ӧѧ���ĳɼ�
//��4�����ǰ10����rank_10�� : ����ɼ���ߵ�ǰʮ���İ༶��ź����Ӧ�ĳɼ�
//Ҫ��
//��1���༶��ű���Ϸ���Ҳ���Ǵ���0С�ڰ༶����ֵ
//��2���ɼ���float�����洢����ֻ����С�����2λ
//���������У�������µĲ�����
//��1��	�Զ���༶������Ȼ��¼���һ���¿��ɼ����¿��ɼ�ͬ���Զ���
//��2��	�����һ���¿��ɼ�������ߵ�10λͬѧ�ɼ�
//��3��	¼��ڶ����¿��ɼ����¿��ɼ�ͬ���Զ���
//��4��	����ڶ����¿��ɼ�������ߵ�10λͬѧ�ɼ�
//��5��	������ͬѧ���༶����Զ��壩��Ҫ��ɼ�������������ǲ��ҳɼ�

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
        cout << "��" << i << "���ĳɼ�Ϊ�� " << table[i - 1].score << endl;
    }

    void revise(int a, int b) {
        table[a - 1].score = b;
        cout << "�ɼ��޸ĳɹ�" << endl;
    }

    void rank_10() {
        for (int i = 0; i < 10 && i < num; i++) {
            cout << "��" << i + 1 << "���ĳɼ�Ϊ�� " << table[i].score << endl;
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
