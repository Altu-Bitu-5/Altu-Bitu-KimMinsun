#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;

int main()
{
    int N, M, cnt= 0;
    string tmp;

    cin >> N >> M;

    for (int i= 0; i < N; i++){
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i= 0; i < M; i++){
        cin >> tmp;
        if (s.find(tmp) != s.end())
            cnt++;
    }

    cout << cnt;

    return 0;
}