#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(void) {
	vector<int> c = { 1,1,2,2,2,8 };
	vector<int> input;
	string get;

	getline(cin, get);//get a line
	istringstream iss(get);//���ڿ� ������ ����
	
	int flag;
	while (iss >>flag) {
		//���ڿ� �� �о� number�� ����
		//���� �о���� bool������ ��
		//���� �� ���̻� ������ false ��ȯ , ����
		input.push_back(flag);
	}
	
	for (int i = 0; i < 6; i++) {
		cout << c[i] - input[i] << " ";
	}
	return 0;
}