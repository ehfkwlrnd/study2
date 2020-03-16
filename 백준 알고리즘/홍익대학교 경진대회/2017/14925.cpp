#include <iostream>
using namespace std;

int N, M;
int A[1000][1000];
int Max = -1;

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; i+k < N && j+k < M; k++){
				bool allzero = true;
				for(int l = 0; l <= k; l++){
					if(A[i+k][j+l] != 0 || A[i+l][j+k] != 0) {
						allzero = false;
						break;	
					}
				}
				if(!allzero) break;
				else if(k > Max) Max = k;
			}
		}
	}
	cout << Max+1;
}

//Ǯ��
/*
�� : 
������ ��ġ���� �ִ� ũ�⸦ ã���� �ȴ�. 
�ð� ���⵵�� O((NM)^2) 
*/ 
