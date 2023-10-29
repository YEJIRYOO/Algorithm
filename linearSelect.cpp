//1-1 알고리즘 5-1
//평균 선형시간 선택 알고리즘
/*
#include<iostream>
#include<ctime>
using namespace std;

void swap(int A[], int a, int b) {
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {
		if (A[j] < x) {
			i++;
			swap(A, i, j);
		}
	}

	swap(A, i + 1, r);

	return i + 1;
}

int select(int A[], int p, int r, int i) {
	if (p == r) return A[p];//원소 하나

	int q = partition(A, p, r);
	int k = q - p + 1;

    if (i == k) return A[q]; // 기준원소 == 찾는 원소
    else if (i < k) return select(A, p, q - 1, i); // 왼쪽 그룹으로 범위 좁힘
    else return select(A, q + 1, r, i - k); // 오른쪽 그룹으로 범위 좁힘
}

int main(void) {
	time_t start, finish;
	double duration;

	start = time(NULL);

	int A[100000];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100000; i++) {
		A[i] = rand()%10000;
	}

	for (int k = 1; k < 50001; k++) {
		select(A, 0, 99999,k);
	}

	finish = time(NULL);

	duration = (double)(finish - start);
	cout << duration << "초" << endl;

	return 0;
}
*/
/*
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<random>
using namespace std;

void swap(int A[], int a, int b) {
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            i++;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, r);

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

int main() {
    int A[100000];
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < 100000; i++) {
        A[i] = rand() % 1000000; // 0에서 999999 사이의 랜덤한 값으로 배열 초기화
    }

    time_t start, finish;
    double duration;

    start = time(NULL);

    int k = 50000; // 찾을 작은 값의 위치 (1부터 50,000까지)

    int result = select(A, 0, 99999, k);

    finish = time(NULL);

    duration = difftime(finish, start);

    cout << "1부터 " << k << "번째 작은 값: " << result << endl;
    cout << "소요 시간: " << duration << "초" << endl;

    return 0;
}
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int A[], int a, int b) {
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            i++;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, r);

    return i + 1;
}

int select(int A[], int p, int r, int i) {
    while (p < r) {
        int q = partition(A, p, r);
        int k = q - p + 1;

        if (i == k) return A[q];
        else if (i < k) r = q - 1;
        else {
            p = q + 1;
            i -= k;
        }
    }

    return A[p];
}

int main() {
    int A[100000];
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < 100000; i++) {
        A[i] = rand() % 1000000;
    }

    time_t start, finish;
    double duration;

    start = time(NULL);

    for (int i = 1; i <= 50000; i++) {
        int result = select(A, 0, 99999, i);
    }

    finish = time(NULL);

    duration = difftime(finish, start);

    cout << "소요 시간: " << duration << "초" << endl;

    return 0;
}
