#include <iostream>

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue overflow. Cannot enqueue " << item << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        std::cout << "Enqueued " << item << " to queue." << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow. Cannot dequeue." << std::endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        std::cout << "Dequeued " << item << " from queue." << std::endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6); 

    std::cout << "Front element is " << queue.peek() << std::endl;

    std::cout << "Queue size is " << queue.size() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Front element is " << queue.peek() << std::endl;

    std::cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}
