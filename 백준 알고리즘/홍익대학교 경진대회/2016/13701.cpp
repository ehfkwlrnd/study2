#include <cstdio>

int A[1048576] = {0, };

int main()
{
	int value;
	while(~scanf("%d", &value)){
		int* pt = A+value/32;
		int adj = 1 << (value % 32);
		
		if(!(*pt & adj)){
			*pt |= adj;
			printf("%d ", value);
		}
	}
}

//해설
/*
논리 : 
논리는 굉장히 간단하다.
입력을 받은 후, 과거의 입력을 받은 값이면 아무 동작도 하지 않고
과거의 입력을 받지 않은 값이면 즉시 출력하면 된다.

컴퓨팅적 문제 :
해당 문제를 bool exist[2^25] 를 사용하여 해결 할 수 있을까? 
bool은 1byte 이므로 exist[2^25]는 2^25byte. 즉 32MB의 메모리를 사용하게 된다.
문제에서 제한한 메모리는 8MB이므로 bool배열을 이용하여 해결할 수 없다.
따라서 이 문제는 비트마스킹 기법을 이용해 해결해야 한다.

예를 들어 bool변수 existA와 bool배열 existB[8]을 비교해보자.
만약 0~7값 중 3을 입력 했다면,
	existA = 00010000 
	existB = {0, 0, 0, 1, 0, 0, 0, 0} 
으로 3의 존재를 체크할 수 있다.
existA는 단지 1byte이지만, existB는 8byte를 차지하게 된다. 

이와 같은 방법으로 int를 사용해보자. 
int타입은 32bit이므로 하나의 int만으로도 2^5개의 존재를 체크 할 수 있다. 
따라서 2^25개의 존재를 체크하기 위해서는 int가 2^20개 있으면 된다.
int하나는 2^2byte이므로 int exist[2^20]의 크기는 2^22byte이고 4MB에 해당한다. 
메모리 제한에 걸리지 않으므로 해당 방법을 이용해서 존재를 체크하면 된다. 
*/ 
