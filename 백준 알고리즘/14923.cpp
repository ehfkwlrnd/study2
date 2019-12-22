#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int A[N][M];
	int Hx, Hy;
	int Ex, Ey;
	scanf("%d %d", &Hx, &Hy);
	scanf("%d %d", &Ex, &Ey);
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			int temp;
			scanf("%d", &temp);
			A[i][j] = temp==1?-1:temp;
		}
	}
	
}
