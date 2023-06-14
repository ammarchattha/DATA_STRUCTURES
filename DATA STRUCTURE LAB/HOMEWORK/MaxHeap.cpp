#include<iostream>
#include<assert.h>

using namespace std;

class MaxHeap{
	private:
		struct node{
			int key;
			string msg;
			int date;
		
		};
		
			node *arr;
		int capacity;
		public:
		int totalItems;
		void doubleCapacity(){
			if(this->arr == NULL){
				this->arr = new node[1];
				this->capacity = 1;
				return;
			}
			
			int newCapacity = capacity * 2;
			node *newArr = new node[newCapacity];
			for(int i = 0; i < this->totalItems; i++){
				newArr[i] = this->arr[i];
			}
			
			delete this->arr;
			this->capacity = newCapacity;
			this->arr = newArr;
		}
		
		void shiftUp(int index){
			if(index < 1){
				return;
			}
			int parent = (index-1)/2;
			if(this->arr[index].key > this->arr[parent].key){
				swap(this->arr[index], this->arr[parent]);
				shiftUp(parent);
			}
			return;
		}
		
		void shiftDown(int index){
			int maxIndex = -1;
			
			int lChildIndex = index * 2+1;
			int rChildIndex = (index * 2) + 2;
			
			if(lChildIndex < totalItems){
				if(arr[index].key < arr[lChildIndex].key){
					maxIndex = lChildIndex;
				}
			}
			
			if(rChildIndex < totalItems){
				int newindex = (maxIndex == -1 ? index : maxIndex);
				if(arr[newindex].key < arr[rChildIndex].key){
					maxIndex = rChildIndex;
				}
			}
			
			if(maxIndex == -1){
				return;	
			}
			swap(arr[index], arr[maxIndex]);
			shiftDown(maxIndex);
		}
	public:
		
		MaxHeap(){
			this->arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;
		}
		
		MaxHeap(int _capacity){
			assert(_capacity >= 1);
			this->arr = new node[_capacity];
			this->capacity = _capacity;
			this->totalItems = 0;
		}
		
		void insert(int key,string msg,int date){
			if(this->totalItems == this->capacity){
				doubleCapacity();
			}
			this->arr[totalItems].key = key;
			this->arr[totalItems].msg = msg;
			this->arr[totalItems].date = date;
			shiftUp(totalItems);
			this->totalItems++;
//			cout<<this->totalItems;
		}
		
		void getMax(){
		
			if (totalItems != 0){
			cout<<endl<<"Higher number has high priority"<<endl<<endl;
			cout<<"Priority number is :"<<this->arr[0].key<<endl<<endl<<endl;
			cout<<" Message is :"<<this->arr[0].msg<<endl<<endl<<endl;
			cout<< "Date is  """<<this->arr[0].date<<endl<<endl<<endl;}
		}
		
	void deleteMax()
	{		
		assert(totalItems != 0);
		swap(arr[0], arr[this->totalItems-1]);
		totalItems--;
		shiftDown(0);
	}
	bool isEmpty() const
	{
		return (totalItems == 0);
	}
	void deleteAll()
	{
		if (this->arr != NULL)
		{
			delete[]arr;
			arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;
		}
	}
		
		~MaxHeap(){
			deleteAll();
		}
};

int main(){
	MaxHeap heap(40);

    heap.insert(24,"hello",29) ;
   	heap.insert(22,"hi",30);
    heap.insert(40,"hlo",30);
   heap.insert(37,"hlo",30);
   heap.insert(39,"hlo",30);
   heap.insert(38,"hlo",30);

    int i ;
    cout<<"Press 1 for getting online "<<endl;
    cin >> i;
    if (i==1){
    do 	{
    	if (heap.totalItems!=0){
		
    	heap.getMax();
    	heap.deleteMax();
    }
    cout<<endl<<"For closing the messenger Press 0 :";
    cin>>i;
    cout<<endl;
	}while(i==1);
    	
	}	
}
     

