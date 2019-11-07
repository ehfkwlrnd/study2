#include <iostream>
//#define min(a, b) (a < b? a : b)
using namespace std;

int gcd(int n, int m)
{
	int a = min(n, m);
	int b = m+n-a;
	int r = b%a;
	while(r != 0){
		b = a;
		a = r;
		r = b%a;
	}
	return a;
}

bool contains(int* array, int length, int value)
{
	for(int i = 0; i < length; i++){
		if(array[i] == value) return true;
	}
	return false;
}

int main()
{
	int N, S, D, F, B, K;
	scanf("%d %d %d %d %d %d", &N, &S, &D, &F, &B, &K);
	B *= -1;
	int pos[100000][100000] = {S, };
	int police[K];
	
//	if((D-S)%gcd(F, B)!=0){
//		printf("BUG FOUND\n");
//	}
	
	for(int i = 0 ; i < K; i++) scanf("%d", &police[i]);
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			if(i!=0 || j!=0){
				if(i > 0 && pos[i-j-1][j] > 0) {
					
					pos[i-j][j] = pos[i-j-1][j] + F;
//					printf("first : %d, %d [%d]\n", i, j, pos[i][j]);
				}
				else if(j > 0 && pos[i-j][j-1] > 0){
					
					pos[i-j][j] = pos[i-j][j-1] + B;
//					printf("second : %d, %d [%d]\n", i, j, pos[i][j]);
				}
				else {
					
					pos[i-j][j] = 0;
//					printf("third : %d, %d [%d]\n", i, j, pos[i][j]);	
				}
			}
			if(pos[i-j][j] == D){
				printf("min : %d\n", i);
				return 0;
			}
			if(pos[i-j][j] < 1 || pos[i-j][j] > N || contains(police, K, pos[i-j][j])) pos[i-j][j] = 0;
		}
	}
	printf("BUG FOUND\n");
	return 0;
	
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < N; j++){
//			printf("%2d ", pos[i][j]);
//		}
//		cout << endl;
//	}
	
}
