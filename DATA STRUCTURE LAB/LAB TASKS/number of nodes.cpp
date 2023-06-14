#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data=  data;
        left= right= NULL;
        }
    };
   
class BinarySearchTree{
    private:
    //node class

    //private data members and methods
    node* root;
    int NoOfParents;
    int nodes;
    int h;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    node* InOrderTraversal( node* root);
    node* PreOrderTraversal( node* root);
    node* PostOrderTraversal( node* root);
    node* FindMax(node* root);
    int Parents(node* root);
    int Nodes(node* root, int height);
    public:
    BinarySearchTree(){
        root= NULL;
        NoOfParents = 0;
        h = 0;
        nodes = 0;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   
    void    Delete(int val){
   Delete(this->root, val);
   }
    void InOrderTraversal(){
        InOrderTraversal( this->root);
    }
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
    }
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
    }
    
    void NumberOfParents(){
        int res = Parents(this->root);
        cout<<"Number of parents in bst are:  "<<res<<endl;
    }
    
    void NumberOfNodes(int height){
        int res = Nodes(this->root,height);
        cout<<"Number of nodes "<<res<<endl; 
    }
};
int main (){
    BinarySearchTree tree1, tree2;
       tree1.Insert(10);
    tree1.Insert(8);
    
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
//    tree1.Insert(19);
//    tree1.Insert(18);
//    tree1.Insert(17);
    tree1.Insert(6);
    //tree1.Delete(10);
    cout<<"In Order Print (left--Root--Right)"<<endl;
    tree1.InOrderTraversal();
    cout<<"\n-----------------------"<<endl;
    // cout<<"Pre Order Print (Root--left--Right)"<<endl;
    // tree1.PreOrderTraversal();    
    // cout<<"\n-----------------------"<<endl;
    // cout<<"Post Order Print (left--Right--Root)"<<endl;
    // tree1.PostOrderTraversal();
//    tree1.NumberOfParents();
    tree1.NumberOfNodes(0);
    return 0;
}
node* BinarySearchTree::Insert(node* r, int val){
 if (r==NULL)
    {
        node* t= new node(val);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}
node * BinarySearchTree::Delete(node* r, int data)
{
//    node * r= root1;
    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        //No child
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        //One child on left
        else if(r->right == NULL)
        {
            node* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
node * BinarySearchTree::InOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    //first recur on left child
    InOrderTraversal(r->left);
   //then print the data of node
    cout << " "<< r->data << " -> ";
  // now recur on right child
    InOrderTraversal(r->right);
}

node* BinarySearchTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}
node* BinarySearchTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
node* BinarySearchTree::PostOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
}

int BinarySearchTree::Parents(node* temp){
    //cout<<"Parent function"<<endl;
    if(temp == NULL){
        return 0;
    }
            
    if(temp->left != NULL && temp->right != NULL){
        NoOfParents++;
    }
            
    if(temp->left != NULL)
        Parents(temp->left);
                
    if(temp->right != NULL)  
        Parents(temp->right);
        
    return NoOfParents;
}

int BinarySearchTree::Nodes(node* temp, int height){
    if(temp == NULL){
        return 0;
    }
    
    if(height == 0){
        return 1;
    }
    
    if(h == height){
        cout<<"node at given Height"<<endl;
        cout<<temp->data<<endl;
        nodes++;
    }  
    
   if(temp->left != NULL){
        h++;
        Nodes(temp->left, height);
   }
                
    if(temp->right != NULL){
        Nodes(temp->right, height);
        h--;
    }
   return nodes;
}