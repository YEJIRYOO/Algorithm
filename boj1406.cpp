#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int M;
    string s = "";
    stack<char> left;
    stack<char> right;

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++)
    {
        left.push(s[i]);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            left.push(c);
        }
    }

    // left에 있는 원소들 모두 right로 이동!
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    // right에 있는 원소 출력
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}