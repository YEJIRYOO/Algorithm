/*
#include<iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {//멤버 변수 값들 받는 함수
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;//지역변수 넘길 일 있으면 값 넘기기 위해
	}

	void ShowSalesResult() {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익" << myMoney << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;//해당 클래스에만 적용되는 변수- 프룻셀러 클래스와 분리되어있어 변수명 충돌 일어나지 않음

public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 2, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);//seller에 접근하여 구매의 대상과 구매 금액 받아

}
*/

//캡슐화의 이해
/*
#include<iostream>
using namespace std;

class SinivelCap {//콧물 처치용 캡슐
public:
	void Take() const { cout << "콧물이 싹 납니다"<<endl; }
};

class SneezeCap {//재채기 처치용 캡슐
public:
	void Take()const { cout << "재채기 멎어" << endl; }
};

class SnuffleCap {//코막힘 처치용 캡슐
public:
	void Take()const { cout << "코가 뚫려" << endl; }
};

class CONTAC600 {
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const {
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient {
public:
	void TakeCONTAC600(const CONTAC600& cap) { cap.Take(); };
};

int main(void) {
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}
*/
/*
#include<iostream>
using namespace std;

class SimpleClass {
private:
	int num1;
	int num2;
public:
	SimpleClass() {
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n) {
		num1 = 1;
		num2 = 0;
	}
};
*/
/*
#include<iostream>
using namespace std;

class SimpleClass {
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0) {
		num1 = n1;
		num2 = n2;
	}
	void ShowData()const {
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void) {
	SimpleClass sc1();//함수의 원형 선언
	SimpleClass mysc = sc1();
	mysc.ShowData();
	return 0;
}

SimpleClass sc1() {
	SimpleClass sc(20, 30);
	return sc;
}
#include<iostream>
#include<algorithm>
using namespace std;

class Polynomial;
void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	//새로운 항목을 termArray에 추가
	if (terms == capacity) {
		capacity *= 2;
		Term* temp = new Term[capacity]; //새로운 배열
		copy(termArray, termArray + terms, temp);//temp로 복사 받아
		//algorithm헤더 copy 메서드 copy(원본 시작 이터레이터,원본 끝 이터레이터, 복사받는 시작 이터레이터);
		delete[]termArray;//그전 메모리 반환
		termArray = temp;
	}
	termArray[terms].coef = theCoef;
	termArray[terms++].exp = theExp;

}
Polynomial Polynomial::ADD(Polynomial b) {
	Polynomial c;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < terms)) {
		if (termArray[aPos].exp == b.termArray[bPos].exp){
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.term[bPos].exp);
			bPos++
		}
	}
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < terms; bPos++)
		c.NewTerm(termArray[bPos].coef, termArray[bPos].exp); //남아있는 것들 복사하여 새로운 term
	return c;
}

class SparseMatrix;
class MatrixTerm {
friend class SparseMatrix; //SparseMatrix, 해당 클래스의 private 까지 접근 가능
private:
	int row, col, value;
};
class SparseMatrix {
private:
	int rows, cols, terms, capacity;
	//terms: 0이 아닌 항의 총 수
	//capacity: smArray의 크기
	MatrixTerm* smArray;
};
*/
class SparseMatrix {};

class MatrixTerm {
friend class SparseMatrix;
private:
	int row, col, vlaue;
};
class SparseMatrix {
private:
	int rows, cols, terms, capacity;
	MatrixTerm* smArray;
};

SparseMatrix SparseMatrix::Transpose() {
	//return the transpose of *this
	SparseMatrix
}