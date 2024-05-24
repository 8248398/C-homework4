#include <iostream>
#include <stdexcept>
using namespace std;
//5.	���һ��Ԫ��Ϊint��ֵ�Ķ���Queue�ࡣ���������Ƚ��ȳ���ԭ��
//ʵ�����²�����
//Enqueue : ��Queue��β������һ����Ԫ�ء�
//Dequeue : �Ƴ�Queue����ǰ���Ԫ�ز���������
//Peek : ����Queue�д��ڵ���ǰ���Ԫ�أ�����������ӡ�
//IsEmpty : ���Queue�Ƿ�Ϊ�ա�
//IsFull : ���Queue�Ƿ�������
//Size : ����Queue�д��ڵ�Ԫ��������
//Ҫ��
//��1��	���е�Queue������Զ�̬�ڴ����ķ�ʽ�洢��������ʹ�� C++ ��׼���е� queue �ࡣ

template<typename T>
class Queue {
private:
    T* data;      // ��̬���飬���ڴ洢����Ԫ��
    int front;    // ����ָ��
    int rear;     // ��βָ��
    int capacity; // ��������
    int count;    // ��ǰ������Ԫ�ص�����

public:
    // ���캯������ʼ������
    Queue(int size = 10) {
        data = new T[size];
        front = rear = 0;
        capacity = size;
        count = 0;
    }

    // �����������ͷŶ�̬�ڴ�
    ~Queue() {
        delete[] data;
    }

    // �ڶ�β����Ԫ��
    void Enqueue(T value) {
        if (IsFull()) {
            throw overflow_error("Queue is full.");
        }
        data[rear] = value;
        rear = (rear + 1) % capacity; // ѭ������
        ++count;
    }

    // �Ƴ�����Ԫ�ز�����
    T Dequeue() {
        if (IsEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        T value = data[front];
        front = (front + 1) % capacity; // ѭ������
        --count;
        return value;
    }

    // �鿴����Ԫ��
    T Peek() const {
        if (IsEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return data[front];
    }

    // �������Ƿ�Ϊ��
    bool IsEmpty() const {
        return count == 0;
    }

    // �������Ƿ�����
    bool IsFull() const {
        return count == capacity;
    }

    // ���ض����е�Ԫ������
    int Size() const {
        return count;
    }
};

int main5() {
    Queue<int> q(5); // ��ʼ��һ������Ϊ5�Ķ���

    try {
        q.Enqueue(1);
        q.Enqueue(2);
        q.Enqueue(3);

        cout << "Front element is: " << q.Peek() << endl;
        cout << "Dequeued element is: " << q.Dequeue() << endl;
        cout << "After dequeue, front element is: " << q.Peek() << endl;
        cout << "Queue size is: " << q.Size() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}