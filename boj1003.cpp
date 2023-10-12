#include <iostream>
using namespace std;
int main() {
	int testcase = 0, a = 0;
	cin >> testcase;
	int* arr;
	while (testcase--) {
		cin >> a;
		if (a < 2) {
			if (a == 0) {
				cout << "1 0" << endl;
			}
			else {
				cout << "0 1" << endl;
			}
		}
		else {
			arr = new int[41];
			arr[0] = 1, arr[1] = 1;
			for (int i = 2; i <= a; i++) {
				arr[i] = arr[i - 1] + arr[i - 2];
			}
			cout << arr[a - 2] << " " << arr[a - 1] << endl;
		}
	}
	return 0;
}