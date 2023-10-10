#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cmp(string a, string b) {
	int asize = a.size();
	int bsize = b.size();
	int asum = 0;
	int bsum = 0;

	// 1. ���̰� �ٸ���, ª�� ������� ����
	if (asize != bsize) {
		return asize < bsize;
	}

	// 2. ���̰� ���ٸ�, ���� �̿��� ���� ������� ����
	for (int i = 0; i < a.size(); i++) {
		// ���ڿ� a�� ���Ե� ���ڵ��� �� ���
		if (a[i] >= '0' && a[i] <= '9') {
			asum += int(a[i]) - 48;
		}

		// ���ڿ� b�� ���Ե� ���ڵ��� �� ���
		if (b[i] >= '0' && b[i] <= '9') {
			bsum += int(b[i]) - 48;
		}
	}

	if (asum != bsum) {
		return asum < bsum;
	}


	// 3. 1,2 �� �� �Ұ����ϴٸ�, ���������� ��
	return a < b;

}

int main() {
	int N;
	string serial[50];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	// ������ ������ �����Լ� cmp�� ���� ����
	sort(serial, serial + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << serial[i] << "\n";
	}

	return 0;
}