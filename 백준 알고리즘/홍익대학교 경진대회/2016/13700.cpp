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

//�ؼ� 
/*
�� :
1ȸ���� ������ �� ���� �ְ�, �ڷ� �� ���� �ִ�. 
���� 2ȸ������ �ش� �ڸ����� ������ �� ���� �ְ�, �ڷ� �� ���� �ִ�.
�̷��� ��� ����� ���� ������ ����� �ð� ���⵵�� O(2^n)�̹Ƿ� �ð��ʰ��� �ȴ�.

���⼭ �ָ��� ����Ʈ�� �� �� �湮�� �ǹ��� �ٽ� �湮�� �ʿ䰡 ���ٴ� ���̴�.
	def : ��� C = c1c2...ck (c(i+1)=ci+F or ci-B),  ���� ��� C = {1, 3, 2, 4, 6, ..., 20}  
	claim : �ּҰ�� C ���� �� �� �̻��� ���� �ǹ��� �������� �ʴ´�.
	proof : 
	�ͷ����� ���� �����ϵ��� �Ѵ�. ������ ���� �����غ���.
	� �ǹ� a�� �����Ͽ� a=ci=cj in C �̴�. (i < j)
	cj = c(i-1)+F or c(i-1)-B �̹Ƿ� 
	C' = c1c2...c(i-1)cjc(j+1)...ck �� ����̰� �������� �����ϹǷ�, C���� �� ª�� ����̴�.
	�̰��� C�� �ּ� ��ζ�� ������ ����̴�.
	���� �ּҰ�� C���� �� �� �̻��� ���� �ǹ��� �������� �ʴ´�.
	
�湮�� ���� �ٽ� ������ �ʿ䰡 ���ٸ� ���ƺ��� N���� ���縦 ���� �ּҰ�θ� ã�� �� �ִ�.
�湮�� �� �Ӹ� �ƴ϶� �湮�� �� ���� ���� visited�迭�� true���� �������ν� �湮�� �ʿ䰡 ������ �Ѵ�.
��, police�� ��ġ�� visited�� true������ �������ν� �ڵ带 �ܼ�ȭ �Ͽ���. 
*/






