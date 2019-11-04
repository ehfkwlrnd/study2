#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if(s1.length() == s2.length()) return s1 < s2;
	else return s1.length() < s2.length();
}

int main()
{
	int N;
	cin >> N;
	string array[N];
	for(int i = 0; i < N; i++) cin >> array[i];
	sort(array, array+N, compare);
	cout << array[0] << endl;
	for(int i = 1; i < N; i++) {
		if(array[i] != array[i-1])
			cout << array[i] << endl;	
	}
}
