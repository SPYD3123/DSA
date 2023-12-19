#include <iostream>
using namespace std;

class CustomCircularQueue {
private:
    int customSize;
    int *customArray;
    int customFront, customRear;

public:
    CustomCircularQueue(int size) {
        customSize = size;
        customArray = new int[size];
        customFront = customRear = -1;
    }

    ~CustomCircularQueue() {
        delete[] customArray;
    }

    bool customIsEmpty() {
        return customFront == -1;
    }

    bool customIsFull() {
        return (customRear + 1) % customSize == customFront;
    }

    void customEnqueue(int item) {
        if (customIsFull()) {
            cout << "Queue is full. Cannot enqueue item." << endl;
        } else {
            if (customIsEmpty()) {
                customFront = customRear = 0;
            } else {
                customRear = (customRear + 1) % customSize;
            }
            customArray[customRear] = item;
            cout << "Enqueued: " << item << endl;
        }
    }

    int customDequeue() {
        int item = -1;
        if (customIsEmpty()) {
            cout << "Queue is empty. Cannot dequeue item." << endl;
        } else {
            item = customArray[customFront];
            if (customFront == customRear) {
                customFront = customRear = -1;
            } else {
                customFront = (customFront + 1) % customSize;
            }
            cout << "Dequeued: " << item << endl;
        }
        return item;
    }

    void customDisplay() {
        if (customIsEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue: ";
            int i = customFront;
            do {
                cout << customArray[i] << " ";
                i = (i + 1) % customSize;
            } while (i != (customRear + 1) % customSize);
            cout << endl;
        }
    }
};

int main() {
    CustomCircularQueue customQueue(5);

    customQueue.customEnqueue(1);
    customQueue.customEnqueue(2);
    customQueue.customEnqueue(3);
    customQueue.customEnqueue(4);
    customQueue.customEnqueue(5);
    customQueue.customDisplay();

    customQueue.customDequeue();
    customQueue.customDequeue();
    customQueue.customDisplay();

    customQueue.customEnqueue(6);
    customQueue.customDisplay();

    return 0;
}
