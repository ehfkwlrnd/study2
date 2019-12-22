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
				bool allzero = true;
				for(int u = i; i <= i+max; i++){
					for(int v = j; j <= j+max; j++){
						if(u >= M || v >= N || B[u][v] != 0){
							allzero = false;
						}
					}
				}
				while(allzero){
					max++;
					if(i+max >= M || j+max >= N){
						allzero = false;
					}
					else{
						for(int k = 0; k <= i+max; k++){
							if(B[k][j+max] != 0 || B[i+max][k] != 0){
								allzero = false;
							}
						}
					}
					
				}
				max--;
			}
		}
	}
	printf("%d", max);
}
