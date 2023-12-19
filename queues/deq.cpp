#include <iostream>
using namespace std;

class CustomNode {
public:
    int value;
    CustomNode* next;
    CustomNode* prev;

    CustomNode(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class CustomDeque {
private:
    CustomNode* customFront;
    CustomNode* customRear;

public:
    CustomDeque() {
        customFront = nullptr;
        customRear = nullptr;
    }

    ~CustomDeque() {
        while (customFront != nullptr) {
            CustomNode* tempNode = customFront;
            customFront = customFront->next;
            delete tempNode;
        }
        customRear = nullptr;
    }

    bool customIsEmpty() {
        return customFront == nullptr;
    }

    void customEnqueueFront(int item) {
        CustomNode* newNode = new CustomNode(item);
        if (customIsEmpty()) {
            customFront = customRear = newNode;
        } else {
            newNode->next = customFront;
            customFront->prev = newNode;
            customFront = newNode;
        }
        cout << "Enqueued at front: " << item << endl;
    }

    void customEnqueueRear(int item) {
        CustomNode* newNode = new CustomNode(item);
        if (customIsEmpty()) {
            customFront = customRear = newNode;
        } else {
            customRear->next = newNode;
            newNode->prev = customRear;
            customRear = newNode;
        }
        cout << "Enqueued at rear: " << item << endl;
    }

    int customDequeueFront() {
        if (customIsEmpty()) {
            cout << "Deque is empty. Cannot dequeue from front." << endl;
            return -1;
        } else {
            int item = customFront->value;
            CustomNode* tempNode = customFront;
            if (customFront == customRear) {
                customFront = customRear = nullptr;
            } else {
                customFront = customFront->next;
                customFront->prev = nullptr;
            }
            delete tempNode;
            cout << "Dequeued from front: " << item << endl;
            return item;
        }
    }

    int customDequeueRear() {
        if (customIsEmpty()) {
            cout << "Deque is empty. Cannot dequeue from rear." << endl;
            return -1;
        } else {
            int item = customRear->value;
            CustomNode* tempNode = customRear;
            if (customFront == customRear) {
                customFront = customRear = nullptr;
            } else {
                customRear = customRear->prev;
                customRear->next = nullptr;
            }
            delete tempNode;
            cout << "Dequeued from rear: " << item << endl;
            return item;
        }
    }
};

int main() {
    CustomDeque customDeque;

    customDeque.customEnqueueFront(1);
    customDeque.customEnqueueRear(2);
    customDeque.customEnqueueFront(3);
    customDeque.customEnqueueRear(4);

    customDeque.customDequeueFront();
    customDeque.customDequeueRear();

    return 0;
}
