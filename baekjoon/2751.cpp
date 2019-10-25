#include <stdio.h>

int array[1000000];
int sorted[1000000];

void merge_sort(int begin,  int end)
{
	if(begin >= end) return;
	int mid = (begin + end) /2;
	merge_sort(begin, mid);
	merge_sort(mid+1, end);
	int i = begin, j = mid+1, seq = 0;
	while(i <= mid && j <= end){
		if(array[i] < array[j]) sorted[seq++] = array[i++];
		else sorted[seq++] = array[j++];
	}
	while(i <= mid)sorted[seq++] = array[i++];
	while(j <= end)sorted[seq++] = array[j++];
	for(i = begin, seq=0; i <= end; i++, seq++){
		array[i] = sorted[seq];
	}
	return;
}

int main() 
{
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&array[i]);
	}
	merge_sort(0,N-1);
	for(int i = 0; i < N; i++){ 
		printf("%d\n",array[i]);
	} 
	return 0;
}

