#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//##6) LinkedList ##
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

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        // ##(2) 각 연결리스트는 헤드와 테일을 가지고있다 ##
        head = nullptr;
        tail = nullptr;
    }

    // 연결 리스트에 노드 추가
    void append(int val) {
        Node* newNode = new Node(val); //노드 동적 할당
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
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
        tail = nullptr;
    }
};

// 각 자릿수 기준 정렬
void countingSort(LinkedList& arr, int exp) {
    LinkedList* output[10] = { nullptr }; // output 배열 초기화
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
            delete output[i]; // 노드 메모리 할당 해제
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
    int n,m;
    cout << "정렬할 정수의 개수 n을 입력하세요:";
    cin >> n;
    cout << "실행 횟수 m을 입력하세요:";
    cin>> m;

    srand((unsigned int)time(NULL));// ##7)실행할 때마다 새로운 임의의 정수##

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            arr.append(rand() % 10000);
        }
        cout << "정렬 전 :";
        arr.display();

        // ##(3) 각 연결리스트의 헤드 저장하는 크기 10 포인터 배열##
        LinkedList** headPointers = new LinkedList * [10];
        // ##(4) 각 연결리스트의 테일 저장하는 크기 10 포인터 배열##
        LinkedList** tailPointers = new LinkedList * [10];

        // 동적 할당한 배열 초기화
        for (int i = 0; i < 10; i++) {
            headPointers[i] = new LinkedList;
            tailPointers[i] = headPointers[i];
        }

        radixSort(arr);

        // 결과 출력
        cout << "정렬 후:";
        arr.display();

        // 동적 할당한 배열 해제
        for (int i = 0; i < 10; i++) {
            delete headPointers[i];
        }

        delete[] headPointers;
        delete[] tailPointers;
    }

    return 0;
}

/*
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
    int n;
    cin >> n;
    srand((unsigned int)time(NULL));
    for (int i = 0;i < n; i++) {
        arr.append(rand()%10000);
    }

    radixSort(arr);

    // 결과 출력
    arr.display();

    return 0;
}
*/