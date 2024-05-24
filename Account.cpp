#include <iostream>
using namespace std;
//4.	���ʵ��һ�����׵������˻��ࣨAccount����Ҫ�����£�
//��1������һ��ȫ�ֱ������ʣ�interestRate��
//��2�����˽�г�Ա������
//�˻����루accountNumber�������루passWord�����˻���balance����
//��3����ĳ�Ա������
//���캯����������������deposit����ȡ�withdraw���ͼ�����Ϣ��calculateInterest����
//��4�������Ԫ������
//ת�ˣ�transfer��
//��5��Ҫ��
//��1�����н���� long long ��ʽ�洢
//��2������ȡ�����3���������˺ţ����룬�������ע�⣺���������Ҫ����
//��3��������Ϣʱ���ṩint�������������Ȼ�������ʹ������������Ϣ�����޸��˻�����󷵻���Ϣֵ
//��4�����캯����Ҫ�����������˺ź����룬��Ϊ long ��ֵ
//��5��ת��ʱ�ṩ3������������Account����ʵ�ֵ�һ���˻���Ǯת���ڶ����˻����������Ҳ��Ҫ����
//��6�����������У�������µĲ�����
//��1��	�������������˻������ֱ�����Ӧ��ֵ
//��2��	ʵ���˻���ȡ�������Ϣ����
//��3��	ʵ�������˻�֮���ת�˲���
//��4��	���ע���˻�

float interestRate = 0.003;

class Account {
    friend void transfer(long a, long b, long long c, Account& p, Account& t);

public:
    Account(long a, long b) : accountNumber(a), passWord(b) {}
    ~Account() {}

    // ���ش���Ƿ�ɹ�
    bool deposit(long a, long b, long long c) {
        if (accountNumber == a && passWord == b) {
            balance += c;
            cout << "���ɹ�" << endl;
            return true;
        }
        else {
            cout << "�˺Ż�������󣬴��ʧ��" << endl;
            return false;
        }
    }

    // ����ȡ���Ƿ�ɹ�
    bool withdraw(long a, long b, long long c) {
        if (accountNumber == a && passWord == b) {
            if (c <= balance) {
                balance -= c;
                cout << "ȡ��ɹ�" << endl;
                return true;
            }
            else {
                cout << "�˻����㣬ȡ��ʧ��" << endl;
            }
        }
        else {
            cout << "�˺Ż��������ȡ��ʧ��" << endl;
        }
        return false;
    }

    // ���㲢������Ϣ
    long long calculateInterest(long a, long b, int year) {
        if (accountNumber == a && passWord == b) {
            long long interest = balance * year * interestRate;
            balance += interest;
            cout << "��ϢΪ: " << interest << endl;
            return interest;
        }
        else {
            cout << "�˺Ż���������޷�������Ϣ" << endl;
            return -1;
        }
    }

    // ģ��ע���˻����˴���Ϊ��ʾ��ʵ��Ӧ���п����漰�����߼���
    void closeAccount() {
        balance = 0;
        cout << "�˻���ע��" << endl;
    }

private:
    long accountNumber;
    long passWord;
    long long balance;
};

void transfer(long a, long b, long long c, Account& p, Account& t) {
    if (p.accountNumber == a && p.passWord == b) {
        if (c <= p.balance) {
            p.balance -= c;
            t.balance += c;
            cout << "ת�˳ɹ�" << endl;
        }
        else {
            cout << "�˻����㣬ת��ʧ��" << endl;
        }
    }
    else {
        cout << "�˺Ż��������ת��ʧ��" << endl;
    }
}

int main4() {
    Account p1(123, 456);
    Account p2(456, 789);

    p1.deposit(123, 456, 888888);
    p2.deposit(456, 789, 999999);

    p1.withdraw(123, 456, 11111);
    p2.withdraw(456, 789, 11111);

    long long interest_p1 = p1.calculateInterest(123, 456, 5);
    long long interest_p2 = p2.calculateInterest(456, 789, 5);

    transfer(123, 456, 111111, p1, p2);

    // ģ��ע���˻�
    p1.closeAccount();
    p2.closeAccount();

    return 0;
}