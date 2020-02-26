#include <iostream>
using namespace std;

int N, K;
int A[10000];

bool possible(int q){
	int count = 0;
	for(int i = 0; i < N; i++)count += A[i]/q;
	return count >= K;
}

int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> A[i];
	long long p = 1;
	long long q = ~(1 << 31);
	long long r = q;
	
	while(p < q){
		if(possible(q)) p = q;
		else r = q;
		q = (p+r)/2;
	}
	cout << q;
}

//해설
/*
논리 :
임의의 용량 w로 K명에게 나눠줄 수 있는지 어떻게 확인할 수 있을까.
각 주전자를 Ai으로 표현해보자.
w씩 나눠줬을 때 최대 나눠줄 수 있는 인원수 y를 구하는 방법은 다음과 같다.
	y = [A1/w] + [A2/w] + ... + [A3/w]   ([x]는 x보다 크지 않은 최대 정수) 
y >= K 이면 나눠줄 수 있음을 알 수 있다.
또, 이 판정 알고리즘은 O(n)임을 알 수 있다. 
이제 이 논리를 사용하여 용량 w로 나눠줄 수 있는지 판정하는 함수를 possible(w)로 정의하겠다. 

K명에게 나눠줄 수 있는 최대의 막걸리 용량을 x라고 하자.
각 주전자를 배열 A으로 표현해보자. (각 A[i] <= 2^31-1 = MAX) 
	x*K <= A[1]+A[2]+...+A[N] <= N*MAX
이므로 x <= MAX 이다. (왜냐하면 N <= K) 
즉, 간단히 생각해보면 1부터 MAX까지 1씩 증가시키며 possible(x)로 조사하면 
처음으로 false값이 되는 x보다 1작은 값이 해가 됨을 알 수 있다.
그런데 이렇게 하면 시간복잡도가 O(n*m)인데 1 <= m < 2^31 이므로 시간초과 에러가 뜨게 된다. 

생각을 다시 해보면 x보다 작은 숫자에 대해서는 possible(x)는 true지만
x보다 큰 숫자에 대해서는 false임을 알 수 있다.
이 문제는 무엇과 닮았는가. 바로 업-다운(up-down) 문제와 닮았다. 
업다운 문제에서 해를 찾는 가장 빠른 방법은 바로 이진탐색이다.
따라서 이진탐색을 통해 시간복잡도를 O(n*log(m))으로 향상 시킬 수 있다.

컴퓨팅적 문제 :
이진탐색을 작성하는데 자주 곤란을 겪는 경우를 볼 수 있다.
	1. p, q, r 중 누구를 possible에 검사를 할 것 인가.
	2. 언제 이진탐색에서 빠져 나와야 하는가. p가 q와 같을 때? q가 r과 같을 때?
 
*/ 
