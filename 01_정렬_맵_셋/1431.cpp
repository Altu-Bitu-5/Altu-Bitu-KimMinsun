#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool sorting(string a, string b){

    int a_len = a.size();
    int b_len = b.size();
    int a_sum= 0, b_sum= 0;

    if (a_len == b_len){
        for (int i= 0; i < a_len; i++)
		    if (a[i] >= '0' && a[i] <= '9')
			    a_sum += a[i] - '0';

        for (int i= 0; i < b_len; i++)
            if (b[i] >= '0' && b[i] <= '9')
                b_sum += b[i] - '0';

        if (a_sum != b_sum)
            return a_sum < b_sum;

        else
            return a < b;
    }

    else return a_len < b_len;

}

int main(){

    int N;
    string serial[100];

    cin >> N;

    for (int idx= 0; idx < N; idx++){
        cin >> serial[idx];
    }

    sort(serial, serial+N, sorting);

    for (int idx= 0; idx < N; idx++){
        cout << serial[idx] << '\n';
    }

    return 0;
}