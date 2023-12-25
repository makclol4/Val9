#include <iostream>

class stack1 {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* top;
public:
    stack1() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "Стек пуст" << std::endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return value;
    }
};

class stack2 {
private:
    int* arr;
    int size;
    int count;
    int topIndex;
public:
    stack2(int stackSize) {
        size = stackSize;
        arr = new int[size];
        count = 0;
        topIndex = -1;
    }

    void push(int value) {
        if (count == size) {
            std::cout << "Стек переполнен" << std::endl;
            return;
        }

        topIndex = (topIndex + 1) % size;
        arr[topIndex] = value;
        count++;
    }

    int pop() {
        if (count == 0) {
            std::cout << "Стек пуст" << std::endl;
            return -1;
        }

        int value = arr[topIndex];
        topIndex = (topIndex - 1 + size) % size;
        count--;

        return value;
    }

    ~stack2() {
        delete[] arr;
    }
};

int main() {
    stack1 s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;

    stack2 s2(3);

    s2.push(1);
    s2.push(2);

    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;

    return 0;
}