#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

// Max Heap ����
// ������ ���� �ϱ� ���ؼ� ������ ��� ������ ����!
// �迭���� �� 0�� ��������� �ǹ��Ѵٰ� ��������!
// heap�� �迭�� �ε����� 1���� �����մϴ�!

int heap[HEAP_SIZE]; // max heap
int heap_count = 0; // heap�� ������ ������ ��Ÿ���� ���ÿ� �迭�� ���� �� ���Ҹ� ��Ÿ���� heap�� ���� ��Ÿ���⵵ �մϴ�.

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

	// ���� ���� ���� ������ �߰�
	heap[++heap_count] = data;

	// �Ʒ��� ������ child�� parent�� ���ϸ鼭 �˸��� ��ġ�� �ϳ��� �ø��� �κ�
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop() {

	// ���� ���� ù��° ���Ҹ� ��ȯ
	// ���� ���� �ո� ���� �ִ�!
	int result = heap[1];

	// ù��° ���Ҹ� ���� ���� ���� ���ҿ� �ٲٰ�
	// ���� ���� ���� ���� ���� �����̴� heap_count�� �����ش�.
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// �Ʒ��� ������ child�� parent�� ���ϸ鼭 �˸��� ��ġ�� �ϳ��� ������ �κ�
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

	// �����Լ��� ���� srand�� seed
	srand(time(NULL));

	// �迭 �ʱ�ȭ
	for (int i = 0; i < ARRAY_SIZE; i++) {
		// 1 ~ 50������ ���� ����
		arr[i] = rand() % 50 + 1;
	}

	// ����
	for (int i = 0; i < ARRAY_SIZE; i++) {
		push(arr[i]);
	}

	// pop �ϸ鼭 ���� �ϳ��� Ȯ��
	// Max Heap�̱� ������ ������ ������������ ���ĵ� -> Heap Sort
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", pop());
	}
	printf("\n");

	return 0;
}