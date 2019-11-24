#include <iostream>
using namespace std;

long long S[127][64] = {1,};

int main()
{
	int k, n;
	scanf("%d %d", &k, &n);
	
	for(int j = 1; j <= n; j++){
		for(int i = 0; i <= k+n-j; i++){
			if(i == 0){
				S[i][j] = (long long)1 << j;
			}
			else{
				S[i][j] = S[i-1][j-1] + S[i+1][j-1];
			}
		}
	}
	printf("%lld", ((long long)1 << n) - S[k][n]);
	
	return 0;
}
