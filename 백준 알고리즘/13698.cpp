#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cups[4] = {1, 0, 0, 2};
	string orders;
	cin >> orders;
	for(int i = 0; i < orders.length(); i++){
		
//		for(int i = 0; i < 4; i++) cout << cups[i] << ' ';
//		cout << endl;
		
		char order = orders[i];
		int s, e;
		switch(order){
			case 'A':
				s = 0;
				e = 1;
				break;
			case 'B':
				s = 0;
				e = 2;
				break;
			case 'C':
				s = 0;
				e = 3;
				break;
			case 'D':
				s = 1;
				e = 2;
				break;
			case 'E':
				s = 1;
				e = 3;
				break;
			case 'F':
				s = 2;
				e = 3;	
				break;
		}
		int temp = cups[s];
		cups[s] = cups[e];
		cups[e] = temp;
	}
	
//	for(int i = 0; i < 4; i++) cout << cups[i] << ' ';
//	cout << endl;
//	
	int small, big;
	for(int i = 0; i < 4; i++){
		if(cups[i] == 1) small = i+1;
		else if(cups[i] == 2) big = i+1;
	}
	cout << small << endl << big << endl;
}
