#include <iostream>
using namespace std;



int main()
{
	int N;
	scanf("%d", &N);
	unsigned int A[N];
	for(int i = 0; i < N; i++)scanf("%u", &A[i]);
	double min = 700000000;
	int min_index = 0;
	double sum;
	for(int i = 0; i < N-2; i++){
		sum = (double)A[i];
		sum += (double)A[i+1];
		if(min > sum/2){
			min = sum/2;
			min_index = i;
		}
		sum += (double)A[i+2];
		if(min > sum/3){
			min = sum/3;
			min_index = i;
		}
	}
	sum = (double)A[N-2];
	sum += (double)A[N-1];
	if(min > sum/2){
		min = sum/2;
		min_index = N-2;
	}
	printf("%d", min_index);
}
