#include<iostream>
using namespace std;
int main(){
	int size= 4;  // 0-999
	int hash[size];
	for (int x=0; x<size;x++)
		hash[x]= -1;

	int index = 100%size;  //[0-3] 0
	hash[index]= 100;  //0
	
	
	index = 200%size;    
	hash[index]= 200;  //0
	index = 300%size;
	hash[index]= 300; //0
	index = 400%size; 
	hash[index]= 400;  //0
	// search 400
	
	int x= 400;
	index = x%size;
	if (hash[index]!= -1 && hash[index]== x)
		cout<< " Record found"<<endl;
	else 
		cout<< " Record not  found"<<endl;
	
	return 0;
}
