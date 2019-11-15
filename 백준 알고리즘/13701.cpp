#include <iostream>
#include <vector>
using namespace std;

bool contains(vector<int> tree, int value)
{
	if(tree.empty()){
		tree.push_back(value);
		return false;
	}
	else{
		int i = 0;
		int size = tree.size();
		while(i < size){
			if(tree[i] == value){
				return true;
			}
			else if(tree[i] == -1){
				tree[i] = value;
				return false;
			}
			else if(tree[i] > value){
				i = 2*i + 1;
			}
			else{
				i = 2*i + 2;
			}
		}
		for(int j = 0; j < i-size; j++){
			tree.push_back(-1);
		}
		tree.push_back(value);
		return false;
	}
	
}

int main()
{
	vector<int> tree;
	int value = 0;
	while(true){
		int temp;
		temp = getc(stdin);
		if(temp == 10){
			if(!contains(tree, value)) cout << value;	
			break;
		}
		else if(temp == 32){
			if(!contains(tree, value)) {
				cout << value << ' ';	
			}
			value = 0;
		}
		else{
			value = 10*value + (temp-48);
		}
	}
	cout << endl;
	for(vector<int>::iterator iter = tree.begin(); iter != tree.end(); iter++){
		cout << *iter << " ";
	}

}

