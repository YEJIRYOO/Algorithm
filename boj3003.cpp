#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(void) {
	vector<int> c = { 1,1,2,2,2,8 };
	vector<int> input;
	string get;

	getline(cin, get);//get a line
	istringstream iss(get);//문자열 데이터 추출
	
	int flag;
	while (iss >>flag) {
		//문자열 값 읽어 number에 저장
		//정수 읽어오며 bool값으로 평가
		//읽을 값 더이상 없으면 false 반환 , 종료
		input.push_back(flag);
	}
	
	for (int i = 0; i < 6; i++) {
		cout << c[i] - input[i] << " ";
	}
	return 0;
}