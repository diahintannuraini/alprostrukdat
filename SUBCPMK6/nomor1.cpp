#include <iostream>

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack overflow. Cannot push " << x << std::endl;
            return;
        }
        arr[++top] = x;
        std::cout << "Pushed " << x << " to stack." << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow. Cannot pop." << std::endl;
            return -1;
        }
        std::cout << "Popped " << arr[top] << " from stack." << std::endl;
        return arr[top--];
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6); 

    std::cout << "Top element is " << stack.peek() << std::endl;

    std::cout << "Stack size is " << stack.size() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element is " << stack.peek() << std::endl;

    std::cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}
