#include <iostream>
#include <vector>
#include <algorithm>
//8.	定义简单的调度模型（task_manager）类，里面有四个队列，队列的类型为第五题你写的类型
//类成员变量：
//Queue1，Queue2，Queue3，Queue4
//Order1, Order2, Order3, Order4
//类成员函数：
//Insert_element : 在task_manager插入一个新元素。
//Pop_element : 移除task_manager目前最前面的元素并返回它。
//Peek : 返回task_manager中目前最前面的元素，而不将其出队。
//IsFull : 检查task_manager是否已不能插入。
//Size : 返回task_manager中存在的元素总数。
//要求：
//首先赋给 4 个队列一个初始顺序，当排名为1的队满了之后，接着插入排名为2 的队列，以此类推；当排名为1的队列全部出队完后，若2号队列不空，则1号队列变4号队列，2号队列变1号队列，3号队列变2号队列，4号队列变3号队列.

class Queue {
public:
    // 在队列尾部插入一个新元素
    void Enqueue(int value) {
        elements.push_back(value);
    }

    // 移除队列最前面的元素并返回它
    int Dequeue() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }
        int frontValue = elements.front();
        elements.erase(elements.begin());
        return frontValue;
    }

    // 返回队列最前面的元素，不移除
    int Peek() const {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }
        return elements.front();
    }

    // 检查队列是否为空
    bool IsEmpty() const {
        return elements.empty();
    }

    // 检查队列是否已满（此处未定义队列的最大容量，故默认为不满）
    bool IsFull() const {
        // 实际应用中可根据需求定义队列的最大容量并在此处检查
        return false;
    }

    // 返回队列中元素的总数
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
        order = { 0, 1, 2, 3 };  // 初始队列顺序
    }

    // 插入新元素，根据当前队列顺序
    void InsertElement(int value) {
        for (size_t i = 0; i < 4; ++i) {
            size_t queueIndex = order[i];
            if (!queues[queueIndex].IsFull()) {
                queues[queueIndex].Enqueue(value);
                break;
            }
        }
    }

    // 移除并返回当前最前面的元素，同时更新队列顺序
    int PopElement() {
        for (size_t i = 0; i < 4; ++i) {
            size_t queueIndex = order[i];
            if (!queues[queueIndex].IsEmpty()) {
                int frontValue = queues[queueIndex].Dequeue();
                // 如果当前队列为空且不是最后一个队列，则重新排列队列顺序
                if (queues[queueIndex].IsEmpty() && i != 3) {
                    RotateQueues();
                }
                return frontValue;
            }
        }
        throw std::out_of_range("All queues are empty.");
    }

    // 返回当前最前面的元素，不移除
    int Peek() const {
        for (size_t i = 0; i < 4; ++i) {
            if (!queues[order[i]].IsEmpty()) {
                return queues[order[i]].Peek();
            }
        }
        throw std::out_of_range("All queues are empty.");
    }

    // 检查是否所有队列都已满
    bool IsFull() const {
        for (const auto& q : queues) {
            if (!q.IsFull()) return false;
        }
        return true;
    }

    // 返回所有队列中元素的总数
    size_t Size() const {
        size_t totalSize = 0;
        for (const auto& q : queues) {
            totalSize += q.Size();
        }
        return totalSize;
    }

private:
    void RotateQueues() {
        std::rotate(order.begin(), order.begin() + 1, order.end());  // 旋转队列顺序
    }

    size_t capacity;
    std::vector<Queue> queues;
    std::vector<size_t> order;  // 队列的当前顺序
};
int main8() {
    try {
        // 初始化一个 TaskManager 对象，假设每个队列最大容量为 10
        TaskManager taskManager(10);

        // 插入元素到队列
        for (int i = 1; i <= 20; ++i) {
            std::cout << "Inserting element: " << i << std::endl;
            taskManager.InsertElement(i);
            // 每插入 5 个元素后检查状态，演示用途
            if (i % 5 == 0) {
                std::cout << "Current front element: " << taskManager.Peek() << std::endl;
                std::cout << "Total elements: " << taskManager.Size() << std::endl;
                std::cout << "Is Full? " << (taskManager.IsFull() ? "Yes" : "No") << std::endl << std::endl;
            }
        }

        // 移除元素并打印
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