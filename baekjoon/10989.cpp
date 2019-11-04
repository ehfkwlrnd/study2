#include <iostream>
using namespace std;

int main()
{
	int exist[10000] = {0,};
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		exist[temp-1]++;
	}
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < exist[i]; j++) cout << i+1 << endl;
	}
}
