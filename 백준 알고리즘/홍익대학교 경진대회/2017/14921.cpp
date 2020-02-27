#include <iostream>
#include <algorithm>
#define abs(x) (((x)<0)?((-1)*(x)):(x))
using namespace std;

int N;
int A[100000];
int Min = ~(1 << 31);

bool compare(int a, int b){
	return abs(a) < abs(b);
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	sort(A, A+N, compare);
	for(int i = 1; i < N; i++){
		int x = A[i-1]+A[i];
		if(abs(x) < abs(Min)) Min = x;
	}
	cout << Min;
}

//풀이
/*
논리 :
만약 모든 원소의 쌍의 합을 조사한다면, 시간복잡도는 O(n^2)이 된다.
그리고 시간초과 에러를 띄우게 된다.

더 좋은 알고리즘은 다음과 같다. 
{Ai}를 절댓값 기준으로 정렬한 후, 각 이웃끼리의 합의 절댓값을 비교하여 최솟값을 찾는다.

어떻게 절댓값 기준으로 정렬된 배열의 이웃에서 최솟값이 발생할 것이라고 보장할 수 있는가. 
귀류법을 통해 증명하도록 하자.
	def : {Ci} = c1, c2, ..., cn ({Ai}를 절댓값 기준으로 오름차순 정렬한 배열) 
	assume : 어떤 ci, cj 가 존재하여 |ci + cj|가 최소이고, i+1 < j 이라고 가정하자. 
	그러면, 다음 3가지 케이스 중 적어도 하나는 참이다.  
	1) ci, cj가 부호가 같고, 어떤 i < k < j 인 ck가 존재하여 ci, cj와 부호가 같다.
	2) ci, cj가 부호가 같고, 어떤 i < k < j 인 ck가 존재하여 ci, cj와 부호가 다르다.
	3) ci, cj가 부호가 다르다. 
	
	1)	xy >= 0이면 |x + y| = |x| + |y| 임을 활용하자. 
		|ci + ck| < |ci + cj| 임을 알 수 있다.
	2)	삼각부등식 |x + y| <= |x| + |y| 를 활용하자.
		|ci + ck| <= |ci| + |ck| 이고
		|ci + cj| = |ci| + |cj| 를 통해 
		|ci + ck| < |ci + cj| 임을 알 수 있다.
	3)	임의의 i < k < j인 ck는 반드시 ci 또는 cj와 부호가 같다.
		일관성을 잃지 않고 ck가 cj와 부호가 같다고 가정하자.
		ck < cj 이므로 
		ci + cj의 부호와 ci + ck의 부호는 같음을 알 수 있다.
		따라서 |ci + ck|/|ci + cj| = (ci + ck)/(ci + cj) = (1 + ck/ci)/(1 + cj/ci)
		
		 
*/ 
