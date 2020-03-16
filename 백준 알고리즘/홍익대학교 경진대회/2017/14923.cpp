#include <iostream>
#include <queue>
using namespace std;

int N, M, Hx, Hy, Ex, Ey;
bool map[1002][1002];
bool visited[1002][1002][2];
queue<int*> q;

void pushQueue(int i, int j, int c, int m){
	if(!visited[i][j][m]){
		if(map[i][j] == 0){
			q.push(new int[4]{i, j, c, m});
		}
		else if(m == 0){
			q.push(new int[4]{i, j, c, 1});
		}
		visited[i][j][m] = visited[i][j][1] = true;
	}
}

int BFS(){
	q.push(new int[4]{Hx, Hy, 0, 0});
	visited[Hx][Hy][0] = visited[Hx][Hy][1] = true;
	do{
		int* temp = q.front();
		q.pop();
		int i = temp[0];
		int j = temp[1];
		int c = temp[2];
		int m = temp[3];
		if(i == Ex && j == Ey) return c;
		
		pushQueue(i+1, j, c+1, m);
		pushQueue(i-1, j, c+1, m);
		pushQueue(i, j+1, c+1, m);
		pushQueue(i, j-1, c+1, m);
	}while(!q.empty());
	return -1;
}

int main()
{
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
	for(int i = 0; i <= N+1; i++) visited[i][0][0] = visited[i][M+1][0] = visited[i][0][1] = visited[i][M+1][1] = true;
	for(int j = 0; j <= M+1; j++) visited[0][j][0] = visited[N+1][j][0] = visited[0][j][1] = visited[N+1][j][1] = true;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> map[i][j];
		}
	}
	cout << BFS();
} 

//풀이  
/*
논리 : 
위와 같은 유형의 문제는 BFS로 해결할 수 있음을 금세 알 수 있다.
따라서 visited배열을 통해 만약 방문했던 지점이라면 큐에 추가 하지 않도록 컨트롤 해줘야 함을 알 수 있다.
문제는 위 문제에서 마법을 사용한다는 것이다. 

예를들어 아래와 같이 미로가 입력되었다고 하자. 
	0 * * * 0 0
	0 * * 0 0 0
	0 * 0 * * 0
	0 * 0 * * 0
	0 0 0 * * 0
카운트를 표시하기 위해 편의상 1을 별 문자로 대체했다.

먼저 위 문제에 대한 최단 경로는 다음과 같을 것이다.
	0  *  *  *  0  0
	1  *  9 10 11 12
	2  *  8  *  * 13
	3  *  7  *  * 14
	4  5  6  *  * 15
	
위와 같은 경로를 얻기 위해서는 아래와 같이 (3, 3)까지 마법을 사용하지 않고 움직여야 한다. 
	0 * * * 0 0
	1 * * 0 0 0
	2 * 8 * * 0
	3 * 7 * * 0
	4 5 6 * * 0	

만약 (3, 2)에서 마법을 사용하여 다음과 같이 이동하면 (5, 6)에 도달할 수 없다.
  	0 * * * 0 0
	1 * * 0 0 0
	2 3 4 * * 0
	0 * 0 * * 0
	0 0 0 * * 0
 
하지만 보다시피 마법을 사용할 경우엔 (3, 3)의 카운트가 4이고, 
마법을 사용하지 않으면 (3, 3)의 카운트는 8이다.
즉, 마법을 사용하지 않고 (3, 3)에 도달하기 전에, 이미 마법을 사용하여 도달하여 
visited(3, 3)이 true가 되어 있는 점이 문제이다.

따라서 우리는 visited배열이 하나 더 있어야 함을 직감할 수 있다. 
마법을 사용하지 않았을 때는 방문했는지 visited[i][j][0]을 확인하지만,
마법을 사용한 후에는 visited[i][j][1]을 확인하면 해결된다.

또한 마법을 사용했다해도 왔던 길을 되돌아 갈 일은 없으므로
visited[i][j][0]에 true값을  넣을 땐, visited[i][j][1]에도 true값을 넣어주면 된다. 
*/ 
