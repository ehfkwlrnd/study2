#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	unsigned int A[N];
	for(int i = 0; i < N; i++)scanf("%u", &A[i]);
	unsigned int min = 1 << 31;
	int min_index = 0;
	for(int i = 0; i < N-1; i++){
		if(min > A[i] + A[i+1]){
			min = A[i] + A[i+1];
			min_index = i;
		}
	}
	printf("%d", min_index);
}
