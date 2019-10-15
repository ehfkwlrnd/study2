#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++){
		int min = arr[i];
		int index = i;
		for(int j = i; j < N; j++){
			if(min > arr[j]){
				min = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for(int i = 0; i < N; i++){
		cout << arr[i] << endl;
	}
}
