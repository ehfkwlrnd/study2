#include <iostream>
using namespace std;

int N, M;
int A[1001][1001];
int L[1001][1001];
int Max = 0;

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> A[i][j];
			if(A[i][j] == 0){
				L[i][j] = min(min(L[i-1][j], L[i][j-1]), L[i-1][j-1]) + 1;
				Max = max(Max, L[i][j]);
			}
		}
	}
	cout << Max;
}
