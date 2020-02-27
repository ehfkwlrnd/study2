#include <iostream>
using namespace std;

int main()
{
	int c1;
	cin >> c1;
	int n = 1;
	while(c1 != 1){
		if(c1%2) c1 = 3*c1+1;
		else c1 /= 2;
		n++;
	} 
	cout << n;
}
