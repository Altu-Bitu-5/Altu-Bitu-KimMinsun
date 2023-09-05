#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k, tmp;
    queue<int> q;

    cin >> n >> k;

    for (int i = 1; i <= n; i++ ){
        q.push(i);
    }

    cout << '<';

    while (q.size() > 1){
        for (int i = 1; i < k; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << '>' << endl;

    return 0;
}