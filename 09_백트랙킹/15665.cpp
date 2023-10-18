#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> res;
vector<int> nums;

void dfs(int x){

    //output
    if(x == m){
        for(int i= 0; i < x; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    //
    else{
        int tmp = -1;
        for(int i= 0; i < n; i++){
            if(tmp == nums[i]) continue;
            tmp = nums[i]; // 바로 이전에 선택한 숫자
            res.push_back(nums[i]);
            dfs(x+1);
            res.pop_back();
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    for(int i= 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    dfs(0);

    return 0;
}