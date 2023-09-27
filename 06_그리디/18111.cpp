#include <iostream>

using namespace std;

int main()
{
    int n, m, b;
    int t= 0, height= 0;
    int maxt = 987654321;

    int map[500][500];

    cin >> n >> m >> b;

    for ( int i= 0; i < n; i++){
        for (int j= 0; j < m; j++){
            cin >> map[i][j];

        }
    }

    for( int k= 0; k <= 256; k++){
        int add= 0; // inventory에서 꺼내기 +1초
        int sub= 0; // block 캐서 제거 +2초

        for(int i= 0; i < n; i++){
            for (int j= 0; j < m; j++){

                // inventory에서 꺼내야 함
                if (map[i][j] < k){
                    add += k - map[i][j];
                    t += k - map[i][j];
                }
                // block을 제거해야 함
                else if (map[i][j] >= k){
                    sub += map[i][j] - k;
                    t += (map[i][j] - k) * 2;
                }
            }
        }

        // inventory에 있던 것 + 캐서 얻은 것 - 꺼내 쓴 것 >= 0이어야 함
        if (b + sub >= add){
            // time은 2 * 캐는 동작 + 꺼내서 넣는 동작
            t = 2 * sub + add;

            if ( maxt >= t){
                maxt = t;
                height = k;
            }
        }
    }

    cout << maxt << " " << height << endl;

    return 0;
}