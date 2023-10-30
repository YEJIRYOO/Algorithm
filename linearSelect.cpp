//최악 경우 선형시간 선택 알고리즘

#include<iostream>
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

void heapify(int A[], int k, int n) {
    int left = 2*k;
    int right = 2 * k + 1;
    int smaller = 0;

    if (right <= n) {
        smaller = A[left] < A[right] ? left : right;
    }
    else if (left <= n)smaller = left;
    else return;

    if (A[smaller] < A[k]) {
        swap(A, k, smaller);
        heapify(A, smaller, n);
    }
}

void buildHeap(int A[], int n) {//배열A를 힙구조로 만든다
	for (int i = n / 2; i >= 1; i--) {
		heapify(A, i, n);
	}
}

void linearSelect(int A[], int p, int r, int i) {

}

int main(void) {

	return 0;
}
