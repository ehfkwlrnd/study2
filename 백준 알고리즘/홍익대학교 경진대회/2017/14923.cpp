#include <iostream>
#include <list>
using namespace std;

int A[1002][1002];
list<int*> queue;
bool visited[1002][1002];

void pushQueue(int i, int j, int count, bool hasMagic){
	if(!visited[i][j]){
		if(A[i][j] == 0){
			queue.push_back(new int[4]{i, j, count+1, hasMagic});
			visited[i][j] = true;
		}
		else if(hasMagic){
			queue.push_back(new int[4]{i, j, count+1, 0});
			visited[i][j] = true;
		}
	}
}

int main()
{
	int N, M;
	int Hx, Hy;
	int Ex, Ey;
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
	for(int i = 0; i <= N+1; i++){
		visited[i][0] = visited[i][M+1] = true;
	}
	for(int j = 0; j <= M+1; j++){
		visited[0][j] = visited[N+1][j] = true;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> A[i][j];
		}
	}
	
	int i = Hx;
	int j = Hy;
	visited[i][j] = true;
	queue.push_back(new int[4]{i, j, 0, 1});
	int m = -1;
	while(true){
		if(queue.size() == 0)break;
		int* temp = queue.front();
		queue.pop_front();
		i = temp[0];
		j = temp[1];
		int count = temp[2];
		bool hasMagic = temp[3];
		
//		printf("i : %d, j : %d, count : %d, hasMagic : %d\n", i, j, count, hasMagic);
		
		if(i == Ex && j == Ey) {
			m = count;
			break;
		}
		
		pushQueue(i+1, j, count, hasMagic);
		pushQueue(i-1, j, count, hasMagic);
		pushQueue(i, j+1, count, hasMagic);
		pushQueue(i, j-1, count, hasMagic);
	}
	
	cout << m;
}
