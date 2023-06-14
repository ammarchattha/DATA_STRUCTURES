#include<iostream>
using namespace std;
void Number_of_ways(int numner_of_stairs,int n, int a[]);
int main(){
	int number_of_stairs;  
    cout<<"Enter number of stairs:"; 
	cin>>number_of_stairs;
	int  a[number_of_stairs]; 
	Number_of_ways(number_of_stairs, 0, a);
	return 0;
}
void Number_of_ways(int number_of_stairs,int n, int a[]){
	if(number_of_stairs == 0 || n > number_of_stairs) {
    	return;
    }
	if(n == number_of_stairs){ 
		for(int i = 0 ; i < number_of_stairs; i++) {
			if(a[i] != 0){
				cout<<a[i]<<" ";
			}		}
		cout<<endl;	}
	for (int i = 1; i < number_of_stairs + 1; i++){
        a[n] = i;
	    Number_of_ways(number_of_stairs, n + i, a);
	    a[n] = 0; 
    }   
}