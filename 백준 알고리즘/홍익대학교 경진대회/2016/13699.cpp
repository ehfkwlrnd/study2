#include <iostream>
using namespace std;

int main()
{
	long long t[36] = {1,};
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			t[i] += t[j]*t[i-1-j];
		}
	}
	
	printf("%lld\n", t[n]);
}

//해설
/*
논리 :
만약 함수를 재귀적으로 구성한다면 아래와 같다. 
int t(n)
{
	if(n==0) return 1;
	int s = 0;
	for(int i = 0; i < n; i++){
		s += t(i)*t(n-1-i);
	}
	return s;
}
이 함수의 시간복잡도는 O(2^n) 이므로 시간초과가 된다. 

그렇기 때문에 풀이와 같이 동적프로그래밍을 사용해야 한다.
이 코드의 시간복잡도는 O(n^2)이다.

컴퓨팅적 문제 :
만약 배열 t를 int배열로 선언한다면, n이 어느정도 커졌을 때
오버플로우로 인해 정확한 값을 도출해내지 못 한다. 
따라서 long long배열로 선언하여 오버플로우로 인한 문제를 해결한다.
*/ 
