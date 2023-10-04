/*
#include<iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {//��� ���� ���� �޴� �Լ�
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;//�������� �ѱ� �� ������ �� �ѱ�� ����
	}

	void ShowSalesResult() {
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����" << myMoney << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;//�ش� Ŭ�������� ����Ǵ� ����- ������ Ŭ������ �и��Ǿ��־� ������ �浹 �Ͼ�� ����

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
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 2, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);//seller�� �����Ͽ� ������ ���� ���� �ݾ� �޾�

}
*/

//ĸ��ȭ�� ����
/*
#include<iostream>
using namespace std;

class SinivelCap {//�๰ óġ�� ĸ��
public:
	void Take() const { cout << "�๰�� �� ���ϴ�"<<endl; }
};

class SneezeCap {//��ä�� óġ�� ĸ��
public:
	void Take()const { cout << "��ä�� �ܾ�" << endl; }
};

class SnuffleCap {//�ڸ��� óġ�� ĸ��
public:
	void Take()const { cout << "�ڰ� �շ�" << endl; }
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
	SimpleClass sc1();//�Լ��� ���� ����
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
	//���ο� �׸��� termArray�� �߰�
	if (terms == capacity) {
		capacity *= 2;
		Term* temp = new Term[capacity]; //���ο� �迭
		copy(termArray, termArray + terms, temp);//temp�� ���� �޾�
		//algorithm��� copy �޼��� copy(���� ���� ���ͷ�����,���� �� ���ͷ�����, ����޴� ���� ���ͷ�����);
		delete[]termArray;//���� �޸� ��ȯ
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
		c.NewTerm(termArray[bPos].coef, termArray[bPos].exp); //�����ִ� �͵� �����Ͽ� ���ο� term
	return c;
}

class SparseMatrix;
class MatrixTerm {
friend class SparseMatrix; //SparseMatrix, �ش� Ŭ������ private ���� ���� ����
private:
	int row, col, value;
};
class SparseMatrix {
private:
	int rows, cols, terms, capacity;
	//terms: 0�� �ƴ� ���� �� ��
	//capacity: smArray�� ũ��
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