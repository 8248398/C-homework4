#include <iostream>
using namespace std;
//4.	设计实现一个简易的银行账户类（Account），要求如下：
//【1】定义一个全局变量利率（interestRate）
//【2】类的私有成员变量：
//账户号码（accountNumber）、密码（passWord）、账户余额（balance）。
//【3】类的成员函数：
//构造函数、析构函数、存款（deposit）、取款（withdraw）和计算利息（calculateInterest）。
//【4】类的友元函数：
//转账（transfer）
//【5】要求：
//（1）所有金额以 long long 形式存储
//（2）存款和取款函数有3个参数，账号，密码，金额数，注意：如果金额不够需要报错
//（3）计算利息时，提供int参数存款年数，然后按照余额和存款年数计算利息，并修改账户余额，最后返回利息值
//（4）构造函数需要两个参数，账号和密码，均为 long 型值
//（5）转账时提供3个参数，两个Account对象，实现第一个账户将钱转到第二个账户，如果金额不够也需要报错。
//【6】在主函数中，完成以下的操作：
//（1）	创建两个银行账户，并分别存款相应数值
//（2）	实现账户存款，取款，计算利息操作
//（3）	实现两个账户之间的转账操作
//（4）	最后注销账户

float interestRate = 0.003;

class Account {
    friend void transfer(long a, long b, long long c, Account& p, Account& t);

public:
    Account(long a, long b) : accountNumber(a), passWord(b) {}
    ~Account() {}

    // 返回存款是否成功
    bool deposit(long a, long b, long long c) {
        if (accountNumber == a && passWord == b) {
            balance += c;
            cout << "存款成功" << endl;
            return true;
        }
        else {
            cout << "账号或密码错误，存款失败" << endl;
            return false;
        }
    }

    // 返回取款是否成功
    bool withdraw(long a, long b, long long c) {
        if (accountNumber == a && passWord == b) {
            if (c <= balance) {
                balance -= c;
                cout << "取款成功" << endl;
                return true;
            }
            else {
                cout << "账户余额不足，取款失败" << endl;
            }
        }
        else {
            cout << "账号或密码错误，取款失败" << endl;
        }
        return false;
    }

    // 计算并返回利息
    long long calculateInterest(long a, long b, int year) {
        if (accountNumber == a && passWord == b) {
            long long interest = balance * year * interestRate;
            balance += interest;
            cout << "利息为: " << interest << endl;
            return interest;
        }
        else {
            cout << "账号或密码错误，无法计算利息" << endl;
            return -1;
        }
    }

    // 模拟注销账户（此处仅为演示，实际应用中可能涉及更多逻辑）
    void closeAccount() {
        balance = 0;
        cout << "账户已注销" << endl;
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
            cout << "转账成功" << endl;
        }
        else {
            cout << "账户余额不足，转账失败" << endl;
        }
    }
    else {
        cout << "账号或密码错误，转账失败" << endl;
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

    // 模拟注销账户
    p1.closeAccount();
    p2.closeAccount();

    return 0;
}