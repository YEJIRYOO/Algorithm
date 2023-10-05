#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//##6) LinkedList ##
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

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        // ##(2) �� ���Ḯ��Ʈ�� ���� ������ �������ִ� ##
        head = nullptr;
        tail = nullptr;
    }

    // ���� ����Ʈ�� ��� �߰�
    void append(int val) {
        Node* newNode = new Node(val); //��� ���� �Ҵ�
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
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
        tail = nullptr;
    }
};

// �� �ڸ��� ���� ����
void countingSort(LinkedList& arr, int exp) {
    LinkedList* output[10] = { nullptr }; // output �迭 �ʱ�ȭ
    Node* current = arr.head;

    while (current != nullptr) {
        int digit = (current->data / exp) % 10;
        if (output[digit] == nullptr) {
            output[digit] = new LinkedList;
        }
        output[digit]->append(current->data);
        current = current->next;
    }

    arr.clear();

    for (int i = 0; i < 10; i++) {
        if (output[i] != nullptr) {
            Node* current = output[i]->head;
            while (current != nullptr) {
                arr.append(current->data);
                current = current->next;
            }
            delete output[i]; // ��� �޸� �Ҵ� ����
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
    int n,m;
    cout << "������ ������ ���� n�� �Է��ϼ���:";
    cin >> n;
    cout << "���� Ƚ�� m�� �Է��ϼ���:";
    cin>> m;

    srand((unsigned int)time(NULL));// ##7)������ ������ ���ο� ������ ����##

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            arr.append(rand() % 10000);
        }
        cout << "���� �� :";
        arr.display();

        // ##(3) �� ���Ḯ��Ʈ�� ��� �����ϴ� ũ�� 10 ������ �迭##
        LinkedList** headPointers = new LinkedList * [10];
        // ##(4) �� ���Ḯ��Ʈ�� ���� �����ϴ� ũ�� 10 ������ �迭##
        LinkedList** tailPointers = new LinkedList * [10];

        // ���� �Ҵ��� �迭 �ʱ�ȭ
        for (int i = 0; i < 10; i++) {
            headPointers[i] = new LinkedList;
            tailPointers[i] = headPointers[i];
        }

        radixSort(arr);

        // ��� ���
        cout << "���� ��:";
        arr.display();

        // ���� �Ҵ��� �迭 ����
        for (int i = 0; i < 10; i++) {
            delete headPointers[i];
        }

        delete[] headPointers;
        delete[] tailPointers;
    }

    return 0;
}

/*
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
    int n;
    cin >> n;
    srand((unsigned int)time(NULL));
    for (int i = 0;i < n; i++) {
        arr.append(rand()%10000);
    }

    radixSort(arr);

    // ��� ���
    arr.display();

    return 0;
}
*/