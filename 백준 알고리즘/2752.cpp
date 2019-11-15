#include <iostream>
#define max(a, b) ((a)>(b))?(a):(b)
#define min(a, b) ((a)<(b))?(a):(b)
using namespace std;

int main()
{
	int a, b, c;
	cin >> 	a >> b >> c;
	int M = max(max(a, b), c);
	int m = min(min(a, b), c);
	int mid = a + b +c - M - m;
	printf("%d %d %d", m, mid, M);
}
