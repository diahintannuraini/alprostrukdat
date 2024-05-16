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

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; 
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    Node* secondHalf = reverseLinkedList(slowPtr->next);
    
    Node* firstHalf = head;
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; 
}

int main() {
    Node* head = nullptr;

    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 2);
    addNode(head, 1);

    std::cout << "Linked list: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        std::cout << "Linked list adalah palindrom." << std::endl;
    } else {
        std::cout << "Linked list bukan palindrom." << std::endl;
    }

    return 0;
}
