#include <iostream>
using namespace std;

int A[20][20];
int B[20][20];
bool F[20];
int Min = 20*20;
int N;

void copyAtoB(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			B[i][j] = A[i][j];
		}
	}
}

bool isClear(){
	for(int j = 1; j <= N; j++){
		if(B[N][j] == 1){
			return false;
		}
	}
	return true;
}

void toggleBulb(int x, int y){
	B[x][y] ^= 1;
	B[x-1][y] ^= 1;
	B[x+1][y] ^= 1;
	B[x][y-1] ^= 1;
	B[x][y+1] ^= 1;
}

void setMin(int x, bool t){
	F[x] = t;
	if(x < N-1){
		setMin(x+1, false);
		setMin(x+1, true);
	}
	else{
		int m = 0;
		copyAtoB();
		for(int i = 0; i < N; i++){
			if(F[i]){
				m++;
				toggleBulb(1, i+1);
			}
		}
		for(int i = 1; i <= N-1; i++){
			for(int j = 1; j <= N; j++){
				if(B[i][j] == 1){
					m++;
					toggleBulb(i+1, j);
				}
			}
		}
		if(isClear() && m < Min){
			Min = m;
		}
	}
}

int main()
{
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> A[i][j];
		}
	}
	
	setMin(0, false);
	setMin(0, true);
	
	if(Min < 20*20){
		cout << Min;	
	}
	else{
		cout << -1;
	}
}
