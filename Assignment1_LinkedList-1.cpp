#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

public:
    List() {
        head = nullptr;
    }

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addToHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addToTail(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    int findNode(int value) {
        Node* current = head;
        int position = 1;

        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }

        return -1;
    }

    int deleteFromHead() {
        if (head == nullptr) {
            return -1;
        }

        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }

    int deleteFromTail() {
        if (head == nullptr) {
            return -1;
        }

        if (head->next == nullptr) {
            int value = head->data;
            delete head;
            head = nullptr;
            return value;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        int value = current->next->data;
        delete current->next;
        current->next = nullptr;
        return value;
    }

    void printList() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int countList() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    int getMinimum() {
        if (head == nullptr) {
            return -1;
        }

        int minimum = head->data;
        Node* current = head->next;

        while (current != nullptr) {
            if (current->data < minimum) {
                minimum = current->data;
            }
            current = current->next;
        }

        return minimum;
    }

    int sumOdd() {
        int sum = 0;
        Node* current = head;

        while (current != nullptr) {
            if (current->data % 2 != 0) {
                sum += current->data;
            }
            current = current->next;
        }

        return sum;
    }

    void copyList(List& other) {
        Node* current = other.head;

        while (current != nullptr) {
            addToTail(current->data);
            current = current->next;
        }
    }
};
