#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    while(true){

        string str;
        getline(cin, str);
        stack<char> balance;
        bool flag = true;

        if (str == "."){
            break;
        }

        for (int i= 0; i < str.length(); i++){

            if (str[i] == '[' || str[i] == '('){
                    balance.push(str[i]);
            }

            else if (str[i] == ']'){
                if (balance.empty() || balance.top() == '('){
                    flag = false;
                    break;
                }
                else if (balance.top() == '['){
                    balance.pop();
                }
            }

            else if (str[i] == ')'){
                if (balance.empty() || balance.top() == '['){
                    flag = false;
                    break;
                }
                else if (balance.top() == '('){
                    balance.pop();
                }
            }

        }

        if (balance.empty() && flag == true){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

    return 0;
}