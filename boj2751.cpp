//boj2751
//���ڿ� ��������
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int num, tmp;
    vector<int> a;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < num; i++)
        cout << a[i] << '\n';
}

*/

//boj10989
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int arr[10001] = { 0 };

    // ���� ���� ī��Ʈ
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }

    // �� ���ڸ� ������ŭ ������ֱ�
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "\n";
}