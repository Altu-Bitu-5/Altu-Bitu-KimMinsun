#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int minFact[MAX];
vector<int> prime;

//에라토스테네스의 체

void isPrime(void)

{

    minFact[0] = minFact[1] = -1;
    
    for (int i = 2; i < MAX; i++)
         minFact[i] = i;

    for (int i = 2; i*i < MAX; i++)
         if (minFact[i] == i)
             for (int j = i * i; j < MAX; j += i)
                 if (minFact[j] == j)
                      minFact[j] = i;

    for (int i = 3; i < MAX; i++)
         if (minFact[i] == i)
             prime.push_back(i);

}



int main(void)

{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    isPrime();


    while (1)

    {
         int N;
         cin >> N;

         if (N == 0)
             break;

         for(int i=0; i<prime.size(); i++)
             if (minFact[N - prime[i]] == N - prime[i])
             {
                 cout << N << " = " << prime[i] << " + " << N - prime[i] << "\n";
                 break;
             }
    }

    return 0;

}