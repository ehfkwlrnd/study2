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

//Ǯ��  
/*
�� : 
���� ���� ������ ������ BFS�� �ذ��� �� ������ �ݼ� �� �� �ִ�.
���� visited�迭�� ���� ���� �湮�ߴ� �����̶�� ť�� �߰� ���� �ʵ��� ��Ʈ�� ����� ���� �� �� �ִ�.
������ �� �������� ������ ����Ѵٴ� ���̴�. 

������� �Ʒ��� ���� �̷ΰ� �ԷµǾ��ٰ� ����. 
	0 * * * 0 0
	0 * * 0 0 0
	0 * 0 * * 0
	0 * 0 * * 0
	0 0 0 * * 0
ī��Ʈ�� ǥ���ϱ� ���� ���ǻ� 1�� �� ���ڷ� ��ü�ߴ�.

���� �� ������ ���� �ִ� ��δ� ������ ���� ���̴�.
	0  *  *  *  0  0
	1  *  9 10 11 12
	2  *  8  *  * 13
	3  *  7  *  * 14
	4  5  6  *  * 15
	
���� ���� ��θ� ��� ���ؼ��� �Ʒ��� ���� (3, 3)���� ������ ������� �ʰ� �������� �Ѵ�. 
	0 * * * 0 0
	1 * * 0 0 0
	2 * 8 * * 0
	3 * 7 * * 0
	4 5 6 * * 0	

���� (3, 2)���� ������ ����Ͽ� ������ ���� �̵��ϸ� (5, 6)�� ������ �� ����.
  	0 * * * 0 0
	1 * * 0 0 0
	2 3 4 * * 0
	0 * 0 * * 0
	0 0 0 * * 0
 
������ ���ٽ��� ������ ����� ��쿣 (3, 3)�� ī��Ʈ�� 4�̰�, 
������ ������� ������ (3, 3)�� ī��Ʈ�� 8�̴�.
��, ������ ������� �ʰ� (3, 3)�� �����ϱ� ����, �̹� ������ ����Ͽ� �����Ͽ� 
visited(3, 3)�� true�� �Ǿ� �ִ� ���� �����̴�.

���� �츮�� visited�迭�� �ϳ� �� �־�� ���� ������ �� �ִ�. 
������ ������� �ʾ��� ���� �湮�ߴ��� visited[i][j][0]�� Ȯ��������,
������ ����� �Ŀ��� visited[i][j][1]�� Ȯ���ϸ� �ذ�ȴ�.

���� ������ ����ߴ��ص� �Դ� ���� �ǵ��� �� ���� �����Ƿ�
visited[i][j][0]�� true����  ���� ��, visited[i][j][1]���� true���� �־��ָ� �ȴ�. 
*/ 
