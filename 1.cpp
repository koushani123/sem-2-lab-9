#include <iostream>
using namespace std;

class BST{
	struct node{
		int data;
		node* left;
		node* right;
	};
	
	node* root;
	int n=1;
	node* insert(int x, node* temp){
		if(temp==NULL){
			temp=new node;
			temp->data=x;
			temp->left=NULL;
			temp->right=NULL;
		}
		else if(x<temp->data){
			temp->left=insert(x,temp->left);
		}
		else if(x>temp->data){
			temp->right=insert(x,temp->right);
		}
    return temp;
	}
	
	void inorder(node *temp){
		if(temp==NULL){
			return ;
		}
		else{
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
		}

       int countnode(node *temp){
                if(temp==NULL){
                        return n;
                }
                if(temp->left!=NULL){
                        n=n+1;      
                        n=countnode(temp->left);
                }
                if(temp->right!=NULL){
                        n=n+1;
                        n=countnode(temp->right);
		}
                else if(temp->left==NULL || temp->right==NULL){
       	  	n=n+0;
       	  }
                return n;
                
       }
       
       void rangesearch(node* temp, int s1, int s2){
       	
       	if(temp==NULL){
       		return ;
       	}
       	if(s1<temp->data){
       		rangesearch(temp->left,s1,s2);
       	}
       	if(s2>temp->data){
       		rangesearch(temp->right,s1,s2);
       	}
       	if(s1<=temp->data && s2>=temp->data){
       		cout<<temp->data << " ";
       	}
       }
       
            int rcountnode(node *temp, int s1, int s2){
                if(temp==NULL){
                        return n;
                }
                if(s1<temp->data){
                        rcountnode(temp->left,s1,s2);
                }
                if(s2>temp->data){
                        rcountnode(temp->right,s1,s2);
		}
                if(s1<=temp->data && s2>=temp->data){
                	
                }
       	  }
                return n;
                
       }
   
		public:
		BST(){
			root=NULL;
		}
		
		void insert(int x){
			root=insert(x,root);
		}
		
		void inorder(){
			inorder(root);
			cout<<endl;
		}
                
                int count(){
                        int n= countnode(root);
                        return n;
                }
                
               void rsearch(int s1,int s2){
               	rangesearch(root,s1,s2);
               } 

};

int main(){
	BST bst;	
	bst.insert(10);
	bst.insert(30);
	bst.insert(50);
	bst.insert(24);
	bst.insert(56);
	bst.insert(45);
	bst.insert(35);
	bst.inorder();
	int n=bst.count();
	cout<<n<< endl;
	bst.rsearch(24,56);

	}
