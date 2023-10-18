#include <iostream>
using namespace std;

int n;
int nums[11]; //숫자들
int operators[4]; //연산자
int minRes = 1000000001;
int maxRes = -1000000001;

void calc(int result, int idx)
{
    if(idx == n)
    {
        if(result > maxRes){
            maxRes = result;
        }
        if(result < minRes){
            minRes = result;
        }
        return;
    }
    for(int i = 0; i < 4; i++)
    {

        if(operators[i] > 0)
        {
            operators[i]--; // 사용했으니 -1
            if(i == 0){
                calc(result + nums[idx], idx+1);
            }
            else if(i == 1){
                calc(result - nums[idx], idx+1);
            }
            else if(i == 2){
                calc(result * nums[idx], idx+1);
            }
            else{
                calc(result / nums[idx], idx+1);
            }
            operators[i]++; // 복구 +1
        }
    }
    return;
}
int main() {

    //input
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    for(int i = 0; i < 4; i++)
        cin >> operators[i];

    //calculation
    calc(nums[0],1);
    
    //output
    cout << maxRes << '\n';
    cout << minRes << endl;
}
