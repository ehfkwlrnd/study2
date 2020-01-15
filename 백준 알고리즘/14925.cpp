#include <iostream>
using namespace std;

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	int B[M][N];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &B[i][j]);
		}
	}
	int max = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(B[i][j] == 0){
				int v = 0;
				for(;j+v < N && B[i][j+v] == 0; v++);
				int u = 0;
				for(;u < M && B[u][v] != 0; u++){
					for(v = j;v < N && B[u][v] != 0, v++){
						
					}
				}
			}
		}
	}
	printf("%d", max);
}
