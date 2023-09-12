#include <iostream>

int gcd(int x, int y){

    if(y == 0){

        return x;

    } else {

        return gcd(y, x%y);

    }

}

using namespace std;

int main()
{
    int up1, down1, up2, down2, a, b;

	cin >> up1 >> down1 >> up2 >> down2;
	a = (up1 * down2 + down1 * up2);
	b = down1 * down2;

	int GDC = gcd(a, b);

	cout << a / GDC << " " << b / GDC;
	return 0;
}