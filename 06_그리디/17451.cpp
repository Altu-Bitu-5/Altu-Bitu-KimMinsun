#include <iostream>
#include <vector>
#include <cmath> //ceil을 사용해보려고 했으나 실패함!

using namespace std;

int main()
{
    int n;
    long long speed;
    vector<long long> shuttle;

    cin >> n;
    for (int i= 0; i < n; i++){
        cin >> speed;
        shuttle.push_back(speed);
    }

    speed = shuttle[n-1];

    // 뒤에서부터 속도 탐색
    for (int i= n-2; i >= 0; i--){
        // speed가 더 작으면 바꿔준다
        if (speed < shuttle[i]){
            speed = shuttle[i];
        }
        else{
            // 2배, 3배를 해서 다음 행성 속도의 배수가 되도록
            if (speed % shuttle[i]){
                speed = (speed / shuttle[i] + 1) * shuttle[i];
            }
        }
    }

    cout << speed << endl;

    return 0;
}