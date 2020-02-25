#include <iostream>
#include <queue>
using namespace std;

int N, S, D, F, B, K;
int count[100000];
bool visited[100000];
queue<int> q;

int main()
{
	cin >> N >> S >> D >> F >> B >> K;
	visited[S-1] = true;
	int pos;
	for(int i = 0; i < K; i++){
		cin >> pos;
		visited[pos-1] = true;
	}	
	
	q.push(S-1);
	while(!q.empty()){
		pos = q.front();
		q.pop();

		int nextF = pos+F;
		int nextB = pos-B;
		if(pos == D-1){
			cout << count[pos];
			return 0;
		}
		if(nextF < N && !visited[nextF]){
			visited[nextF] = true;
			count[nextF] = count[pos]+1;
			q.push(nextF);
		}
		if(nextB >= 0 && !visited[nextB]){
			visited[nextB] = true;
			count[nextB] = count[pos]+1;
			q.push(nextB);
		}
	}
	cout << "BUG FOUND";
}

//해설 
/*
논리 :
1회차에 앞으로 갈 수도 있고, 뒤로 갈 수도 있다. 
또한 2회차에도 해당 자리에서 앞으로 갈 수도 있고, 뒤로 갈 수도 있다.
이렇게 모든 경우의 수를 따지는 방법은 시간 복잡도로 O(2^n)이므로 시간초과가 된다.

여기서 주목할 포인트는 한 번 방문한 건물은 다시 방문할 필요가 없다는 점이다.
	def : 경로 C = c1c2...ck (c(i+1)=ci+F or ci-B),  예를 들어 C = {1, 3, 2, 4, 6, ..., 20}  
	claim : 최소경로 C 에는 두 개 이상의 같은 건물을 포함하지 않는다.
	proof : 
	귀류법을 통해 증명하도록 한다. 다음과 같이 가정해보자.
	어떤 건물 a가 존재하여 a=ci=cj in C 이다. (i < j)
	cj = c(i-1)+F or c(i-1)-B 이므로 
	C' = c1c2...c(i-1)cjc(j+1)...ck 은 경로이고 도착점에 도달하므로, C보다 더 짧은 경로이다.
	이것은 C가 최소 경로라는 가정에 모순이다.
	따라서 최소경로 C에는 두 개 이상의 같은 건물을 포함하지 않는다.
	
방문한 곳을 다시 조사할 필요가 없다면 많아봐야 N번의 조사를 통해 최소경로를 찾을 수 있다.
방문한 곳 뿐만 아니라 방문할 수 없는 곳을 visited배열에 true값을 넣음으로써 방문할 필요가 없도록 한다.
즉, police의 위치도 visited에 true값으로 넣음으로써 코드를 단순화 하였다. 
*/






