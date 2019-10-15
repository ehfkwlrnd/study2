#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int p, q=1, r=1;
	for(int i = 2; i <= n; i++){
		p = q;
		q = r;
		r = (p + q)%10007;
	}
	cout << r << endl;
	
	return 0;
}
