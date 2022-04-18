// hw3-1: binary search tree implementation
// environment: Notepad++ 8.2.1(64bits X64)
// C++ type: C++ 14
// g++ type: g++ version 6.3.0
#include <iostream>
#include <string>

using namespace std;

// tree node initializtion
class Node{
public:
	int data=-1;
	Node* left=nullptr;
	Node* right=nullptr;
};

// insert function
void Insert(Node*& root, string data){
	
}

// delete function
void Delete(Node*& root, string data){
	
}

// height of tree
int Height(Node*& root){
	
}

// print out tree by level order
void Print(Node*& root){
	
}

// Search function
void Search(Node*& root, string data){
	
}

// Number function
int Number(Node*& root){
	
}

// combination of all instructions
void bst(){
	Node* root=new Node();
	string action, data;
	while(cin>>action){
		if(action=="Insert"){
			cin>>data;
			Insert(root, data);
		}
		else if(action=="Delete"){
			cin>>data;
			Delete(root, data);
		}
		else if(action=="Height"){
			Height(root);
		}
		else if(action=="Print"){
			Print(root);
		}
		else if(action=="Search"){
			cin>>data;
			Search(root, data);
		}
		else if(action=="Number"){
			Number(root);
		}
		else{
			cout<<"Wrong instruction"<<endl;
		}
	}
	return;
}

int main(){
	
	bst();
	
	system("pause");
	return 0;
}