#include <iostream>
#define abs(x) ((x > 0)?(x):((-1)*(x)))
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int A[N];
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	int min = 200000000;
	int s = 0;
    int e = N-1;
	while(A[s] < 0 && s < e){
		while(A[s]+A[e]>0)e--;
		if(abs(min) > abs(A[s]+A[e]))min = A[s]+A[e];
		if(e < N-1)e++;
		if(abs(min) > abs(A[s]+A[e]))min = A[s]+A[e];
        s++;
	}
	if(s < N-1)if(abs(min) > abs(A[s]+A[s+1]))min = A[s]+A[s+1];
	printf("%d", min);
}







