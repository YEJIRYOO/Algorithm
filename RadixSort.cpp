#include <iostream>
using namespace std;

// 연결 리스트 노드 클래스 정의
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// 연결 리스트 클래스 정의
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // 연결 리스트에 노드 추가
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

    // 연결 리스트 출력
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 연결 리스트 비우기
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

// 각 자릿수 기준 정렬
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

// 기수 정렬 함수
void radixSort(LinkedList& arr) {
    int maxVal = 0;
    Node* current = arr.head;

    // 최대값 찾기
    while (current != nullptr) {
        if (maxVal < current->data) maxVal = current->data;
        current = current->next;
    }

    // 가장 큰 자릿수까지 반복적으로 정렬
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

    // 결과 출력
    arr.display();

    return 0;
}
