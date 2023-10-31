//�˰��� 5-1
//��� �����ð� ���� �˰���

#include <iostream>
#include <ctime>
#include <cstdlib>
#include<random>
#include<algorithm>
using namespace std;

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);

    return i + 1;
}

int select(int A[], int p, int r, int i) {
    if (p == r) return A[p]; // ���� �ϳ�

    int q = partition(A, p, r);
    int k = q - p + 1;

    if (i == k) return A[q]; // ���ؿ��� == ã�� ����
    else if (i < k) return select(A, p, q - 1, i); // ���� �׷����� ���� ����
    else return select(A, q + 1, r, i - k); // ������ �׷����� ���� ����
}

int A[100000];

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    time_t start, finish;
    double duration;

    start = time(NULL);

    for (int i = 0; i < 100; i++) { 
        for (int i = 0; i < 100000; i++) {
            A[i] = rand() % 100000; // 0���� 999999 ������ ������ ������ �迭 �ʱ�ȭ
        }
        cout<<"�ݺ�Ƚ��:" << i + 1<<" " << select(A, 0, 99999, 50000) << "\n"; }

    finish = time(NULL);

    duration = difftime(finish, start);

    cout << "�ҿ� �ð�: " << duration << "��" << endl;

    return 0;
}
