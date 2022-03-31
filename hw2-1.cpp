// hw2-1: implementation of doubly linked list
// environment: Notepad++ 8.2.1(64bits X64)
// C++ type: C++ 11
// g++ type: g++ version 6.3.0
#include <iostream>
#include <string>

using namespace std;

// node class def
class Node{
public:
    Node* prev;
    Node* next;
    char data;
};

// get current node count (single element is counted by 1)
int GetNodeCount(Node* head){
    int node_count=0;
    Node* current=head;
    while(current!=nullptr){ 
        node_count++;
        current=current->next;
    }
    return node_count;
}

// insert node function (need to restore head address after operation)
void InsertNode(Node*& head, char data, int pos){
    if(data>126||data<32)cout<<"Insert wrong data\n";        
    else if(head==nullptr&&pos!=0)cout<<"Insert wrong position\n";
    else if(pos<0||pos>GetNodeCount(head))cout<<"Insert wrong position\n"; 
    else{
        // no head
        if(head==nullptr&&pos==0){
            head=new Node();
            head->next=nullptr;
            head->prev=nullptr;
            head->data=data;
        }
        // head exist (front middle end)
        else{
            Node* restore_head=head;   // for head restore address   
            //front
            if(pos==0){                
                Node* new_node=new Node();
                new_node->data=data;
                new_node->next=head;
                new_node->prev=head->prev;
                head->prev=new_node;
                head=new_node;
            }            
            //end
            else if(pos==GetNodeCount(head)){
                while(head->next!=nullptr)head=head->next;
                Node* new_node=new Node();
                new_node->data=data;
                new_node->next=head->next;
                new_node->prev=head;
                head->next=new_node;
                head=restore_head;
            }
            //middle
            else{
                for(int i=0;i<pos;i++)head=head->next;
                Node* new_node=new Node();
                new_node->data=data;
                new_node->next=head;
                new_node->prev=head->prev;
                (head->prev)->next=new_node;                
                head->prev=new_node;        
                head=restore_head;
            }            
        }
    }
    return;
}

// delete node in specified position
void DeleteNode(Node*& head, int pos){
    if(head==nullptr)cout<<"Linked list is empty\n";
    else if(pos<0||pos>=GetNodeCount(head))cout<<"Delete wrong position\n";
    else{
        Node* restore_head=head;
        // front
        if(pos==0){
            (head->next)->prev=nullptr;                        
            head=head->next;
        }
        // end
        else if(pos==GetNodeCount(head)-1){
            while(head->next!=nullptr)head=head->next;                
            (head->prev)->next=nullptr;            
            head=restore_head;
        }
        // middle
        else{
            for(int i=0;i<pos;i++)head=head->next;
            (head->prev)->next=head->next;
            (head->next)->prev=head->prev;            
            head=restore_head;
        }
    }
    return;
}

// delete all nodes with same data
void DeleteData(Node*& head, char data){
	if(head==nullptr)cout<<"Linked list is empty\n";
    else if(data>126||data<32)cout<<"Delete wrong data\n";
    else{
        Node* current=head;
        while(current!=nullptr){
            if(current->data==data)DeleteGivenNode(head, current);
            current=current->next;
        }
    }
    return;
}

// print all nodes data in list
void PrintList(Node* head){
    if(head==nullptr){
        cout<<"Linked list is empty\n";
        return;
    }
    Node* current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
    return;
}

// find node counts with specified data with return count result
int NumOfOccur(Node* head, char data){
    // prevent invalid condition
    if(data>126||data<32){
        cout<<"Search wrong data\n";
        return -1;
    }
    else if(head==nullptr){
        cout<<"Linked list is empty\n";
        return -1;
    }
    int count=0;
    Node* current=head;
    while(current!=nullptr){
        if(current->data==data)count++;
        current=current->next;
    }
    return count;
}

// find most nodes with same type
void MaxNumOfOccur(Node* head){
    if(head==nullptr){
        cout<<"Linked list is empty\n";
        return;
    }
    int node_count=GetNodeCount(head);
    int max_occur=0, idx=0;
    char* arr=new char[node_count]{0}; // initialize an array(prevent all elements're max occur)
    Node* current=head;
    while(current!=nullptr){
        int current_node_occur=NumOfOccur(current, current->data);
        if(current_node_occur>max_occur){  // refresh arr since max occur appear
            max_occur=current_node_occur;  // update max count
            for(int i=0;i<node_count;i++){
                arr[i]=0;
            }
            idx=0;
            arr[idx]=current->data;
            idx++;
        }
        else if(current_node_occur==max_occur){ // check if data already in result arr(if not, add it to arr)
            for(int i=0;i<node_count;i++){
                if(arr[i]==current->data)break; // already exist
                else if(arr[i]==0){
                    arr[idx]=current->data;
                    idx++;
                    break;
                }
            }
        }
        else;
        current=current->next;
    }
    // print out result
    for(int i=0;i<node_count;i++){
        if(arr[i]==0);
        else cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    return;
}

// search if the given word exist in list
void SearchWord(Node* head, char* word){
    if(head==nullptr){
        cout<<"Linked list is empty\n";
        return;
    }
    Node* current=head;
    while(current!=nullptr){
        if(!(*word)){
            cout<<"found\n";
            return;
        }
        if(current->data==(*word))word++;
        current=current->next;
    }
    if(*word)cout<<"not found\n";
    else cout<<"found \n";
    return;
}

// read file & combine all function together(only allowed for string reading file)
void execute(){
    string action, data, pos; 
    Node* head=nullptr;
    while(cin>>action){        
        // start doing things based on its action
        if(action=="InsertNode"){
            cin>>data;
            char c=data[0];
            cin>>pos;
            InsertNode(head, c, stoi(pos));
        }
        else if(action=="DeleteNode"){
            cin>>pos;
            DeleteNode(head, stoi(pos));
        }
        else if(action=="DeleteData"){
            cin>>data;
            char c=data[0];
            DeleteData(head, c);
        }
        else if(action=="PrintList"){
            PrintList(head);
        }
        else if(action=="NumOfOccur"){
            cin>>data;
            char c=data[0];
            int count=NumOfOccur(head, c);
            if(count!=-1)cout<<count<<endl; // no error then output return value
        }
        else if(action=="MaxNumOfOccur"){
            MaxNumOfOccur(head);           
        }
        else if(action=="SearchWord"){
            cin>>data;
            SearchWord(head, &data[0]);
        }
        else cout<<"> No corresponding function\n";                        
    }
    return;
}

int main(){
        
    execute();
    
    system("pause");
    return 0;
}