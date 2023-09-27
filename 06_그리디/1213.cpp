#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alphabet[26];

// Palindrome을 만들 수 있는지 확인
// 홀수개의 알파벳이 두개 이상이면 만들 수 없다.
bool isPalin(string str){

    int odd_cnt= 0;

    for (int i= 0; i < str.size(); i++){
        alphabet[str[i]-'A']++;
    }

    for (int i= 0; i < 26; i++){
        if (alphabet[i] % 2 != 0){
            odd_cnt++;
        }
    }

    return odd_cnt > 1;
}

int main()
{
    string s;
    string palin, reverse_palin;

    cin >> s;

    if (isPalin(s)) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // Palindrome 만들기
    for (int i= 0; i < 26; i++){
        for (int j= 0; j < alphabet[i]/2; j++){
            palin += i + 'A';
        }
    }

    // 뒤집어서 홀수인 알파벳 더한 이후에 더하기
    reverse_palin = palin;
    reverse(reverse_palin.begin(), reverse_palin.end());

    for (int i= 0; i < 26; i++){
        if (alphabet[i]%2 !=0){
            palin += i + 'A';
        }
    }

    palin += reverse_palin;

    cout << palin << endl;

}
