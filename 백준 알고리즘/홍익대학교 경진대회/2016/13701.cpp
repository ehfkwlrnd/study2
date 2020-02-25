#include <cstdio>

int A[1048576] = {0, };

int main()
{
	int value;
	while(scanf("%d", &value) != EOF){
		int* pt = A+value/32;
		int adj = 1 << (value % 32);
		
		if(!(*pt & adj)){
			*pt |= adj;
			printf("%d ", value);
		}
	}
}


