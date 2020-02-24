#include <cstdio>

int A[1048576] = {0, };

bool contains(int value)
{
	int* pt = A+value/32;
	int adj = 1 << (value % 32);
	if(*pt & adj){
		return true;
	}
	else{
		*pt |= adj;
		return false;
	}
}

int main()
{
	while(true){
		int temp;
		temp = getc(stdin);
		if(temp == 10){
			if(!contains(value)) printf("%d ", value);	
			break;
		}
		else if(temp == 32){
			if(!contains(value)) printf("%d ", value);
			value = 0;
		}
		else{
			value = 10*value + (temp-48);
		}
	}
}

