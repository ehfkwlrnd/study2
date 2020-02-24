#include <iostream>
using namespace std;

bool array[500][500];

int printNext(int p){
	for(int i = 0; i < 500; i++){
		if(array[p][i]){
			array[p][i] = false;
			array[i][p] = false;
			cout << "a" << p+1 << " ";
			return printNext(i);
		}
	}
	cout << "a" << p+1;
	return -1;
}

int main()
{
	int N;
	cin >> 	N;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i != j){
				array[i][j] = true;	
			}
		}
	}
	array[0][N-1] = false;
	array[N-1][0] = false;
	
	printNext(0);
	cout << " a1";
}
