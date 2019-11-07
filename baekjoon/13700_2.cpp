#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, S, D, F, B, K;
	scanf("%d %d %d %d %d %d", &N, &S, &D, &F, &B, &K);
	
	int police[N+1] = {0, };
	for(int i = 0; i < K; i++){
		int loc;
		scanf("%d", &loc);
		police[loc] = 1;
	}
	
	queue<int> q;
	q.push(S);
	
	int visited[N+1] = {0, };
	visited[S] = 1;
	
	while(q.size() != 0){
		int loc = q.front();
		q.pop();
		
		int forward = loc + F;
		int backward = loc - B;
		int count = visited[loc];
		
		if(forward == D || backward == D){
			printf("%d\n", count);
			return 0;
		}
		if(police[forward] == 0 && forward <= N && visited[forward] == 0){
			q.push(forward);
			visited[forward] = count + 1;
		}
		if(police[backward] == 0 && backward >= 1 && visited[backward] == 0){
			q.push(backward);
			visited[backward] = count + 1;
		}
	}
	printf("BUG FOUND\n");
}
