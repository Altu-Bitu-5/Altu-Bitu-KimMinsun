#include <iostream>
#include<string>

using namespace std;


int main() {
    int nth;
    cin >> nth;

    int devil = 666;
    string s;

    int count = 1;

    while (count != nth) {
        devil++;

        // 숫자를 문자열로 바꿔서 문자열에 666이 있으면 count+=1
        s = to_string(devil);
        if (s.find("666") != std::string::npos) {
            count++;
        }
    }

    cout << devil;
    return 0;
}