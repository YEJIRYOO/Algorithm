#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

// Max Heap 구현
// 구현을 쉽게 하기 위해서 값들은 모두 양수라고 가정!
// 배열에서 값 0은 비어있음을 의미한다고 가정하자!
// heap은 배열의 인덱스가 1부터 시작합니다!

int heap[HEAP_SIZE]; // max heap
int heap_count = 0; // heap의 원소의 갯수를 나타냄과 동시에 배열의 가장 끝 원소를 나타내며 heap의 끝을 나타내기도 합니다.

void swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

void init() {
	heap_count = 0;
}

int size() {
	return heap_count;
}

void push(int data) {

	// 힙의 가장 끝에 데이터 추가
	heap[++heap_count] = data;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 올리는 부분
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop() {

	// 힙의 가장 첫번째 원소를 반환
	// 힙의 가장 앞만 보고 있다!
	int result = heap[1];

	// 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고
	// 가장 끝은 이제 쓰지 않을 예정이니 heap_count를 내려준다.
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap_count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}

int main() {

	int arr[ARRAY_SIZE];

	// 랜덤함수를 위한 srand와 seed
	srand(time(NULL));

	// 배열 초기화
	for (int i = 0; i < ARRAY_SIZE; i++) {
		// 1 ~ 50까지의 난수 생성
		arr[i] = rand() % 50 + 1;
	}

	// 삽입
	for (int i = 0; i < ARRAY_SIZE; i++) {
		push(arr[i]);
	}

	// pop 하면서 값들 하나씩 확인
	// Max Heap이기 때문에 값들이 내림차순으로 정렬됨 -> Heap Sort
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", pop());
	}
	printf("\n");

	return 0;
}