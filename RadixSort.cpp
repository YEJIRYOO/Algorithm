#include <iostream>
using namespace std;

// ���� ����Ʈ ��� Ŭ���� ����
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ���� ����Ʈ Ŭ���� ����
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // ���� ����Ʈ�� ��� �߰�
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // ���� ����Ʈ ���
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // ���� ����Ʈ ����
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

// �� �ڸ��� ���� ����
void countingSort(LinkedList& arr, int exp) {
    LinkedList output[10];
    Node* current = arr.head;

    while (current != nullptr) {
        int digit = (current->data / exp) % 10;
        output[digit].append(current->data);
        current = current->next;
    }

    arr.clear();

    for (int i = 0; i < 10; i++) {
        current = output[i].head;
        while (current != nullptr) {
            arr.append(current->data);
            current = current->next;
        }
    }
}

// ��� ���� �Լ�
void radixSort(LinkedList& arr) {
    int maxVal = 0;
    Node* current = arr.head;

    // �ִ밪 ã��
    while (current != nullptr) {
        if (maxVal < current->data) maxVal = current->data;
        current = current->next;
    }

    // ���� ū �ڸ������� �ݺ������� ����
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main(void) {
    LinkedList arr;
    arr.append(170);
    arr.append(45);
    arr.append(75);
    arr.append(90);
    arr.append(802);
    arr.append(24);
    arr.append(3000);

    radixSort(arr);

    // ��� ���
    arr.display();

    return 0;
}
