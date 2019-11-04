#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if(s1.length() == s2.length()){
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < s1.length(); i++){
			if(isdigit(s1[i])) sum1 += s1[i]-'0';
			if(isdigit(s2[i])) sum2 += s2[i]-'0';
		}
		if(sum1 == sum2) return s1 < s2;
		else return sum1 < sum2;
	}
	else return s1.length() < s2.length();
}

int main()
{
	int N;
	cin >> N;
	string array[N];
	for(int i = 0; i < N; i ++) cin >> array[i];
	sort(array, array+N, compare);
	for(int i = 0; i < N; i++) cout << array[i] << endl;
}
