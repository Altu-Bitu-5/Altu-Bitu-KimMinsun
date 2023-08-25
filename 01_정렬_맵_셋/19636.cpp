#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int w0, bmr, t, day, e_in, amr;

    cin >> w0 >> bmr >> t; // 체중, 기초대사랑, T(역치)
    cin >> day >> e_in >> amr; // 기간, 일일에너지섭취량, 일일활동대사량

    int w1 = w0; // 기초대사량 변화 반영 X
    int w2 = w0; // 기초대사량 변화 반영 O
    int bmr2= bmr;

    for (int i= 0; i < day; i++){
        w1 += e_in - (bmr + amr);
        w2 += e_in - (bmr2 + amr);

        if (abs(e_in - (bmr2 + amr)) > t)
            bmr2 += floor((e_in - (bmr2 + amr)) / 2.);
    }

    if (w1 <= 0) // 기초대사랑 변화 반영X 
        cout << "Danger Diet" << endl;
    else
        cout << w1 << " " << bmr << endl;
    
    if (w2 <= 0 || bmr2 <= 0) // 기초대사랑 변화 반영o, 체중 또는 일일기초대사량이 0이하가 되면 Danger Diet를 출력해주어야 한다.
        cout << "Danger Diet" << endl;
    else{
        cout << w2 << " " << bmr2 << " ";
        if (bmr - bmr2 > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }

    return 0;
}