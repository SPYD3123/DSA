#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* rearNode;

public:
    CircularQueue() {
        rearNode = nullptr;
    }

    ~CircularQueue() {
        if (rearNode != nullptr) {
            Node* tempNode = rearNode->next;
            while (tempNode != rearNode) {
                Node* toDelete = tempNode;
                tempNode = tempNode->next;
                delete toDelete;
            }
            delete rearNode;
        }
    }

    bool isEmpty() {
        return rearNode == nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rearNode == nullptr) {
            rearNode = newNode;
            rearNode->next = rearNode; // Point back to itself for circularity
        } else {
            newNode->next = rearNode->next;
            rearNode->next = newNode;
            rearNode = newNode;
        }
        cout << "Enqueued: " << item << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue item." << endl;
            return -1;
        } else {
            int item;
            if (rearNode->next == rearNode) {
                item = rearNode->value;
                delete rearNode;
                rearNode = nullptr;
            } else {
                Node* frontNode = rearNode->next;
                item = frontNode->value;
                rearNode->next = frontNode->next;
                delete frontNode;
            }
            cout << "Dequeued: " << item << endl;
            return item;
        }
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.dequeue();
    queue.dequeue();

    queue.enqueue(6);

    return 0;
}
