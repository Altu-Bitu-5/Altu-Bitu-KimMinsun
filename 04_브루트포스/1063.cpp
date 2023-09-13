#include <iostream>
#include <string>

using namespace std;

// 움직임에 따라 바뀌는 x, y 좌표의 크기
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int moving(string str) {

    if (str == "R"){
        return 0;
    }
    else if (str == "L"){
        return 1;
    }
    else if (str == "B"){
        return 2;
    }
    else if (str == "T"){
        return 3;
    }
    else if (str == "RT"){
        return 4;
    }
    else if (str == "LT"){
        return 5;
    }
    else if (str == "RB"){
        return 6;
    }
    else if (str == "LB"){
        return 7;
    }


}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string king, stone;
    string dir;
    int cnt;

    cin >> king >> stone >> cnt;

    int kx, ky, sx, sy;

    // 좌표를 숫자로 변환.
    ky = king[0] - 'A';
    kx = '8' - king[1];
    sy = stone[0] - 'A';
    sx = '8' - stone[1];

    for ( int i =0; i < cnt; i++){
        cin >> dir;
        int num = moving(dir);

        int kx2 = kx + dx[num];
        int ky2 = ky + dy[num];

        if ( kx2 < 0 || kx2 >= 8 || ky2 < 0 || ky2 >= 8){
            continue;
        }

        // 돌과 킹의 위치가 같은 경우
        if ( kx2 == sx && ky2 == sy){
            int sx2 = sx + dx[num];
            int sy2 = sy + dy[num];
            if ( sx2 < 0 || sx2 >= 8 || sy2 < 0 || sy2 >= 8){
                continue;
            }
            sx = sx2;
            sy = sy2;

        }

        kx = kx2;
        ky = ky2;
    }

    // 다시 문자로 만들어준다
    cout << char(ky + 'A') << 8 - kx << endl;
    cout << char(sy + 'A') << 8 - sx << endl;
    return 0;
}