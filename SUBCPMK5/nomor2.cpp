#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void addNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void deleteMiddleNode(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "Linked list tidak memiliki node di tengah." << std::endl;
        return;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    Node* prev = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    prev->next = slowPtr->next;
    delete slowPtr;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = nullptr;

    addNode(head, 6);
    addNode(head, 5);
    addNode(head, 4);
    addNode(head, 3);
    addNode(head, 2);
    addNode(head, 1);

    std::cout << "Linked list sebelum penghapusan: ";
    printLinkedList(head);

    deleteMiddleNode(head);

    std::cout << "Linked list setelah penghapusan: ";
    printLinkedList(head);

    return 0;
}
