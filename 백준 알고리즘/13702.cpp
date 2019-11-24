#include <iostream>
using namespace std;

const int INT_MAX = ~(1 << 31);

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int bottle[N];
	int sum = 0;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &bottle[i]);
		sum += bottle[i];
	}
	
	int p = 0;
	int q;
	int r = INT_MAX;
	int count;
	
	while(p<=r && r>0){
		count = 0;
		q = (p+r)/2;
		if(q == 0)break;
		for(int i = 0; i < N; i++)count += bottle[i]/q;
		if(count < K) r = q-1;
		else p = q+1;
	}
	printf("%d", r);
}

