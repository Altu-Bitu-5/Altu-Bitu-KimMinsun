#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){

    string n1, n2;
    cin >> n1 >> n2;

    int len = max(n1.length(), n2.length());
    n1 = string(len - n1.length(), '0') + n1;
    n2 = string(len - n2.length(), '0') + n2;

    string rslt = "";
    int tmp, carry = 0;

    // 문자를 숫자로 변환하려면 '0'을 뺀다
    for (int i = len - 1; i >= 0; i--){
        tmp = n1[i] - '0' + n2[i] - '0' + carry;
        carry = tmp / 10;
        rslt += (char)(tmp % 10 + '0');
    }

    if (carry > 0){
        rslt += (char)(carry + '0');
    }

    reverse(rslt.begin(), rslt.end());

    cout << rslt << endl;

    return 0;
}
