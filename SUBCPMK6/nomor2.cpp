#include <iostream>
#include <stack>

void sortStack(std::stack<int> &mainStack) {
    std::stack<int> tempStack;

    while (!mainStack.empty()) {
        int temp = mainStack.top();
        mainStack.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    std::cout << "Original Stack:" << std::endl;
    printStack(s);

    sortStack(s);

    std::cout << "Sorted Stack:" << std::endl;
    printStack(s);

    return 0;
}
