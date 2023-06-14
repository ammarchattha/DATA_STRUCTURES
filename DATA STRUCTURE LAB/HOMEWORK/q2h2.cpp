#include<iostream>
using namespace std;

class BST {
public:
    int size;
    int* array;
    
void deletion ()
{

    for (int i=size-1;i>=0;i--)
    {
      if(array[i]!='\0')
      {
     
          cout<<array[i]<<" is deleted"<<endl;
          array[i]='\0';
          return ;
      }
    }
}
int  node_at_height(int root,int gheight,int bstheight,int height){
    
    
    if(height==gheight)
    {
         
        if(array[root]!='\0'){
           
            return 1;
        }
        else return 0;
    }
    if (height>bstheight)
    {
        return 0;
    }
     int  leftchild=2*root+1;
     int  rightchild=2*root+2;
  
   int left= node_at_height(leftchild,gheight,bstheight,height+1);
   
int  right=node_at_height(rightchild,gheight,bstheight,height+1);
     return left+right;
    
    
}
int Height(int root)
{

if (array[root]=='\0'){
    
    return 0;
    }
 int  leftchild=2*root+1;
  int  rightchild=2*root+2;
int leftheight=Height(leftchild);
int rightheight=Height(rightchild);
if(leftheight>rightheight){
   return leftheight+1;
} 
else{
   return rightheight+1;
}
}

void  leafnode()
{

    for (int i=0;i<size;i++)
    {
 int  leftchild=2*i+1;
  int  rightchild=2*i+2;
   
   
   if(leftchild<=size && rightchild<=size)
  {
      if(array[leftchild]=='\0' && array[rightchild]=='\0')
      {
          if(array[i]!='\0')
          {
          cout<<"Lead Node :"<<array[i]<<endl;
          }
      }
  }
    }
}
 int  extendSize(int x) {
    int value = 0;
    for(int y = 0; y < x + 1; y++) {
        value = (2 * value) + 2;
    }
    return value;
} 
  BST (int size) {
        this -> size = extendSize(size);
        this -> array = new int[this -> size];
        for(int x = 0; x < this -> size; x++){
            array[x] = '\0';
        }
    
  }
 
   void insertElement(int x) {
    int currentIndex = 0;
    cout << "Adding: " << x;
    while(true) {
        if(array[currentIndex] == '\0'){
            array[currentIndex] = x;
            cout << " Inserted at index: " << currentIndex << endl;
            break;
        }else if(array[currentIndex] <= x) {
            if(array[currentIndex] == x){
                cout << "Repeating element" << endl;
                break;
            }else
            cout << " Right ";
            currentIndex = (2 * currentIndex + 2);
        }else if(array[currentIndex] >= x) {
             if(array[currentIndex] == x){
                cout << "Repeating element" << endl;
                break;
            }else
            cout << " Left ";
            currentIndex = (2 * currentIndex + 1);
        }

    }
}

void  searchElement(int x){
    int currentIndex = 0;
    while (true) {
            if (array[currentIndex] == '\0') {
            cout << "Not Found" << endl;
            break;
            }
            if (array[currentIndex] == x) {
            cout << "Found at index: " << currentIndex << endl;
            break;
            }
            else if(array[currentIndex] < x) {
            currentIndex = (2 * currentIndex + 2);
        }
            else if(array[currentIndex] > x) {
            currentIndex = (2 * currentIndex + 1);
        }

    }

}
void parent(int x){
    while (x != 0) {
        x = (x-1) / 2;
    }}


void inOrder(int currentIndex){
    if(array[currentIndex] != '\0') {
            inOrder(2 * currentIndex + 1);
            parent(currentIndex);
            cout << array[currentIndex] << endl;
            inOrder(2 * currentIndex + 2);

    }
}

void  postOrder(int currentIndex) {
 
    if(array[currentIndex] != '\0'){
        postOrder(2 * currentIndex + 1);
        postOrder(2 * currentIndex + 2);
        parent(currentIndex);
        cout << array[currentIndex] << " " << endl;
    }

}

void preOrder(int currentIndex) {
    if(array[currentIndex] != '\0') {
        preOrder(2 * currentIndex + 1);
        parent(currentIndex);
        cout << array[currentIndex] << " " << endl;
        preOrder(2 * currentIndex + 2);
    }
}

};

int main () {
    BST arr_bst(5);
   int bst_height=0;  
    arr_bst.insertElement(9);
    arr_bst.insertElement(2);
       arr_bst.insertElement(10);
       arr_bst.insertElement(11);
       
       
     arr_bst.insertElement(3);
      arr_bst.insertElement(1);
    arr_bst.inOrder(0);
    arr_bst.leafnode();


    bst_height=arr_bst.Height(0);
   cout<<"Height is  "<< bst_height<<endl;
   cout<<"Node at given  height:"<<arr_bst.node_at_height(0,2,bst_height,0);
   
};