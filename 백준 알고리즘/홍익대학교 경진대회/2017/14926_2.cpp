#include <iostream>
using namespace std;

int N;
bool visit[500][500];

bool getNext(int p, int q){
	for(int i = 0; i < N; i++){
		if(i != p && !visit[q][i]){
			return true;
		}
	}
	return false;
}

void printNext(int p){
	for(int i = 0; i < N; i++){
		if(!visit[p][i] && getNext(p, i)){
			visit[p][i] = true;
			visit[i][p] = true;
			cout << "a" << i+1 << " ";
			return printNext(i);
		}
	}
	cout << "a1";
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++){
		visit[i][i] = true;
	}
	cout << "a1 ";
	printNext(0);
}
