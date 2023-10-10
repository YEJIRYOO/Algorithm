#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cmp(string a, string b) {
	int asize = a.size();
	int bsize = b.size();
	int asum = 0;
	int bsum = 0;

	// 1. 길이가 다르면, 짧은 순서대로 정렬
	if (asize != bsize) {
		return asize < bsize;
	}

	// 2. 길이가 같다면, 합을 이용해 작은 순서대로 정렬
	for (int i = 0; i < a.size(); i++) {
		// 문자열 a에 포함된 숫자들의 합 계산
		if (a[i] >= '0' && a[i] <= '9') {
			asum += int(a[i]) - 48;
		}

		// 문자열 b에 포함된 숫자들의 합 계산
		if (b[i] >= '0' && b[i] <= '9') {
			bsum += int(b[i]) - 48;
		}
	}

	if (asum != bsum) {
		return asum < bsum;
	}


	// 3. 1,2 로 비교 불가능하다면, 사전순으로 비교
	return a < b;

}

int main() {
	int N;
	string serial[50];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	// 위에서 정의한 조건함수 cmp에 따라 정렬
	sort(serial, serial + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << serial[i] << "\n";
	}

	return 0;
}