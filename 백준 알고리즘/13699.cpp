#include <iostream>
using namespace std;

int main()
{
	long long t[36] = {1,};
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			t[i] += t[j]*t[i-1-j];
		}
	}
	
	printf("%lld\n", t[n]);
}
