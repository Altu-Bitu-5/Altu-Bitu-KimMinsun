#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {

    int N, K;
    cin >> N >> K;

    char wheel[25];
    memset(wheel, '?', 25);

    int index = 0;
    for(int i = 0; i < K; i++) {
        int cnt;
        char c;
        cin >> cnt >> c;

        cnt %= N;
        if(index - cnt < 0){
            index = index - cnt + N;
        }
        else{
            index -= cnt;
        }

        if(wheel[index] != '?' && wheel[index] != c) {
            cout << "!\n";
            return 0;
        }

        else{
            wheel[index] = c;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << wheel[(i+index) % N];
    }

    cout << "\n";

    return 0;
}