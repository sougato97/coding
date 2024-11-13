#include <iostream>
using namespace std;

// Node structure
struct Node {
    int* data;
    Node* next;
    Node(int* val) : data(val), next(nullptr) {}
};

// LinkedList class
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Method to add a new node at the end
    void append(int* data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Method to find the middle element
    int* findMiddle() {
        if (!head) return nullptr; // List is empty

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow->data == nullptr && prev != nullptr) {
            return prev->data;
        }

        return slow->data;
    }

    // Method to print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            if (temp->data == nullptr) {
                cout << "NULL ";
            } else {
                cout << *(temp->data) << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int a = 1, b = 2, d = 4, e = 5;
    list.append(&a);
    list.append(&b);
    list.append(nullptr); // Representing NULL
    list.append(&d);
    list.append(&e);

    cout << "Linked List: ";
    list.printList();

    int* middle = list.findMiddle();
    if (middle != nullptr) {
        cout << "Middle Element: " << *middle << endl;
    } else {
        cout << "The middle element is NULL, and the element before it is: " << *middle << endl;
    }

    return 0;
}