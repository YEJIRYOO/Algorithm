//알고리즘 5-1
//평균 선형시간 선택 알고리즘

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
    if (p == r) return A[p]; // 원소 하나

    int q = partition(A, p, r);
    int k = q - p + 1;

    if (i == k) return A[q]; // 기준원소 == 찾는 원소
    else if (i < k) return select(A, p, q - 1, i); // 왼쪽 그룹으로 범위 좁힘
    else return select(A, q + 1, r, i - k); // 오른쪽 그룹으로 범위 좁힘
}

int A[100000];

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    time_t start, finish;
    double duration;

    start = time(NULL);

    for (int i = 0; i < 100; i++) { 
        for (int i = 0; i < 100000; i++) {
            A[i] = rand() % 100000; // 0에서 999999 사이의 랜덤한 값으로 배열 초기화
        }
        cout<<"반복횟수:" << i + 1<<" " << select(A, 0, 99999, 50000) << "\n"; }

    finish = time(NULL);

    duration = difftime(finish, start);

    cout << "소요 시간: " << duration << "초" << endl;

    return 0;
}
