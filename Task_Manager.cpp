#include <iostream>
#include <vector>
#include <algorithm>
//8.	����򵥵ĵ���ģ�ͣ�task_manager���࣬�������ĸ����У����е�����Ϊ��������д������
//���Ա������
//Queue1��Queue2��Queue3��Queue4
//Order1, Order2, Order3, Order4
//���Ա������
//Insert_element : ��task_manager����һ����Ԫ�ء�
//Pop_element : �Ƴ�task_managerĿǰ��ǰ���Ԫ�ز���������
//Peek : ����task_manager��Ŀǰ��ǰ���Ԫ�أ�����������ӡ�
//IsFull : ���task_manager�Ƿ��Ѳ��ܲ��롣
//Size : ����task_manager�д��ڵ�Ԫ��������
//Ҫ��
//���ȸ��� 4 ������һ����ʼ˳�򣬵�����Ϊ1�Ķ�����֮�󣬽��Ų�������Ϊ2 �Ķ��У��Դ����ƣ�������Ϊ1�Ķ���ȫ�����������2�Ŷ��в��գ���1�Ŷ��б�4�Ŷ��У�2�Ŷ��б�1�Ŷ��У�3�Ŷ��б�2�Ŷ��У�4�Ŷ��б�3�Ŷ���.

class Queue {
public:
    // �ڶ���β������һ����Ԫ��
    void Enqueue(int value) {
        elements.push_back(value);
    }

    // �Ƴ�������ǰ���Ԫ�ز�������
    int Dequeue() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }
        int frontValue = elements.front();
        elements.erase(elements.begin());
        return frontValue;
    }

    // ���ض�����ǰ���Ԫ�أ����Ƴ�
    int Peek() const {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }
        return elements.front();
    }

    // �������Ƿ�Ϊ��
    bool IsEmpty() const {
        return elements.empty();
    }

    // �������Ƿ��������˴�δ������е������������Ĭ��Ϊ������
    bool IsFull() const {
        // ʵ��Ӧ���пɸ�����������е�����������ڴ˴����
        return false;
    }

    // ���ض�����Ԫ�ص�����
    size_t Size() const {
        return elements.size();
    }

private:
    std::vector<int> elements;
};
class TaskManager {
public:
    TaskManager(size_t capacity) : capacity(capacity) {
        queues.resize(4);
        order = { 0, 1, 2, 3 };  // ��ʼ����˳��
    }

    // ������Ԫ�أ����ݵ�ǰ����˳��
    void InsertElement(int value) {
        for (size_t i = 0; i < 4; ++i) {
            size_t queueIndex = order[i];
            if (!queues[queueIndex].IsFull()) {
                queues[queueIndex].Enqueue(value);
                break;
            }
        }
    }

    // �Ƴ������ص�ǰ��ǰ���Ԫ�أ�ͬʱ���¶���˳��
    int PopElement() {
        for (size_t i = 0; i < 4; ++i) {
            size_t queueIndex = order[i];
            if (!queues[queueIndex].IsEmpty()) {
                int frontValue = queues[queueIndex].Dequeue();
                // �����ǰ����Ϊ���Ҳ������һ�����У����������ж���˳��
                if (queues[queueIndex].IsEmpty() && i != 3) {
                    RotateQueues();
                }
                return frontValue;
            }
        }
        throw std::out_of_range("All queues are empty.");
    }

    // ���ص�ǰ��ǰ���Ԫ�أ����Ƴ�
    int Peek() const {
        for (size_t i = 0; i < 4; ++i) {
            if (!queues[order[i]].IsEmpty()) {
                return queues[order[i]].Peek();
            }
        }
        throw std::out_of_range("All queues are empty.");
    }

    // ����Ƿ����ж��ж�����
    bool IsFull() const {
        for (const auto& q : queues) {
            if (!q.IsFull()) return false;
        }
        return true;
    }

    // �������ж�����Ԫ�ص�����
    size_t Size() const {
        size_t totalSize = 0;
        for (const auto& q : queues) {
            totalSize += q.Size();
        }
        return totalSize;
    }

private:
    void RotateQueues() {
        std::rotate(order.begin(), order.begin() + 1, order.end());  // ��ת����˳��
    }

    size_t capacity;
    std::vector<Queue> queues;
    std::vector<size_t> order;  // ���еĵ�ǰ˳��
};
int main8() {
    try {
        // ��ʼ��һ�� TaskManager ���󣬼���ÿ�������������Ϊ 10
        TaskManager taskManager(10);

        // ����Ԫ�ص�����
        for (int i = 1; i <= 20; ++i) {
            std::cout << "Inserting element: " << i << std::endl;
            taskManager.InsertElement(i);
            // ÿ���� 5 ��Ԫ�غ���״̬����ʾ��;
            if (i % 5 == 0) {
                std::cout << "Current front element: " << taskManager.Peek() << std::endl;
                std::cout << "Total elements: " << taskManager.Size() << std::endl;
                std::cout << "Is Full? " << (taskManager.IsFull() ? "Yes" : "No") << std::endl << std::endl;
            }
        }

        // �Ƴ�Ԫ�ز���ӡ
        for (int i = 0; i < 20; ++i) {
            std::cout << "Popped element: " << taskManager.PopElement() << std::endl;
            std::cout << "Total elements after pop: " << taskManager.Size() << std::endl;
            if (i % 4 == 0 && i != 0) {
                std::cout << "Order of queues rotated." << std::endl;
            }
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}