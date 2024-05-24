#include <iostream>
#include <stdexcept>
using namespace std;
//5.	设计一个元素为int型值的队列Queue类。队列满足先进先出的原则。
//实现以下操作：
//Enqueue : 在Queue的尾部插入一个新元素。
//Dequeue : 移除Queue的最前面的元素并返回它。
//Peek : 返回Queue中存在的最前面的元素，而不将其出队。
//IsEmpty : 检查Queue是否为空。
//IsFull : 检查Queue是否已满。
//Size : 返回Queue中存在的元素总数。
//要求：
//（1）	所有的Queue类对象都以动态内存分配的方式存储，不允许使用 C++ 标准库中的 queue 类。

template<typename T>
class Queue {
private:
    T* data;      // 动态数组，用于存储队列元素
    int front;    // 队首指针
    int rear;     // 队尾指针
    int capacity; // 队列容量
    int count;    // 当前队列中元素的数量

public:
    // 构造函数，初始化队列
    Queue(int size = 10) {
        data = new T[size];
        front = rear = 0;
        capacity = size;
        count = 0;
    }

    // 析构函数，释放动态内存
    ~Queue() {
        delete[] data;
    }

    // 在队尾插入元素
    void Enqueue(T value) {
        if (IsFull()) {
            throw overflow_error("Queue is full.");
        }
        data[rear] = value;
        rear = (rear + 1) % capacity; // 循环队列
        ++count;
    }

    // 移除队首元素并返回
    T Dequeue() {
        if (IsEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        T value = data[front];
        front = (front + 1) % capacity; // 循环队列
        --count;
        return value;
    }

    // 查看队首元素
    T Peek() const {
        if (IsEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return data[front];
    }

    // 检查队列是否为空
    bool IsEmpty() const {
        return count == 0;
    }

    // 检查队列是否已满
    bool IsFull() const {
        return count == capacity;
    }

    // 返回队列中的元素总数
    int Size() const {
        return count;
    }
};

int main5() {
    Queue<int> q(5); // 初始化一个容量为5的队列

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