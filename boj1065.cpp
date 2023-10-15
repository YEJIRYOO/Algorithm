#include <iostream>

using namespace std;

int arithmetic_sequence(int num) {
	int cnt = 0; // �Ѽ� ī����

	if (num < 100) {
		return num;
	}
	else {
		cnt = 99;

		for (int i = 100; i <= num; i++) {
			int hun = i / 100;		 // ���� �ڸ���
			int ten = (i / 10) % 10; // ���� �ڸ���
			int one = i % 10;

			if ((hun - ten) == (ten - one)) { // �� �ڸ����� ������ �̷��
				cnt++;
			}
		}
	}
	return cnt;
}

int main(int argc, char const* argv[]) {

	int N;
	cin >> N;

	int result = arithmetic_sequence(N);
	cout << result;
	return 0;
}