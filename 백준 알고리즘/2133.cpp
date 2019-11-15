#include <iostream>
using namespace std;

int my_block(int n){
	long long A[30] = {0,};
	long long B[30] = {0,};
	A[1] = 3;
	B[0] = 1;
	for(int i = 2; i < n; i++){
		if(i%2==0)B[i] = A[i-1] + 2*B[i-2];
		else A[i] = 3*A[i-2] + 2*B[i-1];
	}
	return A[n-1];
}

int new_block(int n){
	if(n%2==1) return 0;
	else{
		long long p, q=3, r=19;
		for(int i = 4; i < n; i+=2){
			p = q;
			q = r;
			r = 2*p + 3*q;
		}
		return r;
	}
}

int d[1001];

int dp(int x) {
	if(x == 0) return 1;
	if(x == 1) return 0;
	if(x == 2) return 3;
	if(d[x] != 0) return d[x];
	int result = 3 * dp(x - 2);
	for(int i = 3; i <= x; i++) {
		if(i % 2 == 0)
			result += 2 * dp(x - i);
	}
	return d[x] = result;
}

int main()
{
	int n;
	cin >> n;
	
	cout << dp(n) <<endl;
	
	if(n%2==1) cout << 0;
	else if(n==2) cout << 3;
	else{
		int p, q=3, r=11;
		for(int i = 4; i < n; i+=2){
			p = q;
			q = r;
			r = 2*p + 3*q;
		}
		cout << r;
	}
	
	return 0;
}
