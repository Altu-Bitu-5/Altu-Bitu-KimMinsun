#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str = "";
    int m, num, s=0;

    cin >> m;

    // 비트마스크
    // and t|= (1<<i)
    // remove t &= ~(i<<i)
    // check t & (1<<i) 
    // toggle t ^= ~(1<<i)

    while(m--) {
        cin >> str;

        if (!(str == "all" || str == "empty")){
            cin >> num;
        }

        if (str == "add"){
            s |= (1 << num);
        }
        else if (str == "remove"){
            s &= ~(1 << num);
        }
        else if (str == "check"){
            if(s & (1<<num)){
                cout << "1\n";
            } else{
                cout << "0\n";
            }
            // cout << ((s & (1 << num)) ? 1 : 0) << "\n"; 사용했더니 시간초과 발생
        }
        else if (str == "toggle"){
            s ^= (1 << num);
        }
        else if (str == "all"){
            s = ~(0<<19);
        }
        else if (str == "empty"){
            s = 0;
        }
    }
    return 0;
}