#include <iostream>
using namespace std;

int main()
{
	int exist[10000] = {0,};
	int N;
    scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		exist[temp-1]++;
	}
	for(int i = 0; i < 10000; i++){
        int count = exist[i];
		for(int j = 0; j < count; j++) printf("%d\n", i+1);
	}
}
