#include<iostream>
using namespace std;
int main(){
	//4  range (0-3)  
	int Array= int [4];	
	for (int x=0; x<4;x++)
		Array[x]=-1;	
//	insert  O(1)
		Array[1]=1;	
		Array[0]=0;
		Array[2]=2;
		Array[3]=3;
	// Searching O(1)
	int val= 3;
	if (Array[val]!=-1)
			cout<<" Found"<<endl;
	else 
	
			cout<<"Not Found"<<endl; 
//	Deletion O(1)
//	val=	2 
	Array[2]= -1;
	
	
	
	
	
	
	
	
	
	
	
	
	
	int size= 1000; //0-999 ;; record 4
	int hash[size];
	for (int x=0; x<size;x++)
		hash[x]= -1;
		
	hash[100]= 100; // O(1); Insertion
	hash[200]= 200;
	hash[300]= 300;
	hash[400]= 400;// 
	// search 400
	int x= 400;
	if (hash[x]!= -1)
		cout<< " Record found"<<endl;
	else 
		cout<< " Record not  found"<<endl;
	hash[400]=-1;
	return 0;
}
