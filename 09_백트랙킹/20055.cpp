#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int durability[200]; // 컨베이어 벨트의 내구도
bool isRobots[200]; // 로봇의 유무


int main()
{
    int cnt = 0; //durability = 0 count

    cin >> n >> k;

    //내구도 입력받음
    for(int i= 0; i < 2 * n; i++){
        cin >> durability[i];

        if(durability[i] == 0){
            cnt++;
        }
    }

    int idx = 0; // step 카운트

    while(true){

        // Step 1. 벨트 한 칸씩 회전
        
        //맨 뒤의 인덱스
        int tmpD = durability[2*n-1];
        int tmpR = isRobots[2*n-1];

        if(isRobots[n-1]){
            isRobots[n-1] = 0;
        }

        //벨트 회전에 따른 로봇의 이동과 내구도 업데이트
        for(int i= 2*n-1; i > 0; i--){

            durability[i] = durability[i-1];
            isRobots[i] = isRobots[i-1];
        }

        if(isRobots[n-1]){
            isRobots[n-1] = 0;
        }
    
        //새로 올리는 첫번째 칸 업데이트
        durability[0] = tmpD;
        isRobots[0] = tmpR;

        //Step 2. 벨트의 회전 방향으로 한 칸 이동
        for(int i= n-2; i >= 0; i--){
            // 현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며, 다음 벨트의 내구성이 0 이상
            if(isRobots[i] && !isRobots[i+1] && durability[i+1] > 0){
                swap(isRobots[i], isRobots[i+1]);
                durability[i+1]--; // 내구도 감소

                if(durability[i+1] == 0){ //내구도가 0이면 내구도 0 count +1
                    cnt++;
                }
            }
        }

        //Step 3. 로봇이 없다면 로봇 추가
        if(!isRobots[0] && durability[0] > 0){
            isRobots[0] = true;
            durability[0]--;

            if(durability[0] == 0){
                cnt++;
            }
        }

        idx++;
        //Step 4. 종료 조건에 부합하는지 확인
        if(cnt >= k){
            break;
        }
    }

    cout << idx << endl;


    return 0;
}