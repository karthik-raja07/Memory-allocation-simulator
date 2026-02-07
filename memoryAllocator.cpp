#include<iostream>
using namespace std;
struct Node{
    int id,size;
    bool free;
    Node* next;
};
Node* head=nullptr;
int blockcount=1;
void initializeMemory(int totalSize){
    head=new Node;
    head->id=blockcount++;
    head->size=totalSize;
    head->free=true;
    head->next=nullptr;
}
void displayMemory(){
    Node* temp=head;
    cout<<"\nID\tSIZE\tSTATUS"<<endl;
    while(temp){
        cout<<temp->id<<'\t'<<temp->size<<'\t';
        if(temp->free)
            cout<<"Free"<<endl;
        else
            cout<<"Used"<<endl;
        temp=temp->next;
    }
}
void allocateMemory(int reqsize){
    Node* temp=head;
    while(temp){
        if(temp->free && temp->size>=reqsize){
            if(temp->size==reqsize){
                temp->free=false;
            }
            else{
                Node* newblock=new Node;
                newblock->id=blockcount++;
                newblock->size=temp->size-reqsize;
                newblock->next=temp->next;
                newblock->free=true;
                temp->size=reqsize;
                temp->next=newblock;
                temp->free=false;
            }
            cout<<"Memory Allocated Successfully"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Not enough free memory"<<endl;
}
void mergeMemory(){
    Node* temp=head;
    while(temp && temp->next){
        if(temp->free && temp->next->free){
            Node* nextblock=temp->next;
            temp->size+=nextblock->size;
            temp->next=nextblock->next;
            delete nextblock;
        }
        else{
            temp=temp->next;
        }
    }
}
void freeMemory(int blockid){
    Node* temp=head;
    while(temp){
        if(temp->id==blockid){
            if(temp->free){
                cout<<"Block Already Free"<<endl;
            }
            else{
                temp->free=true;
                cout<<"Block freed successfully"<<endl;
                mergeMemory();
            }
            return;
        }
        temp=temp->next;
    }
    cout<<"Invalid block id"<<endl;
}
int main(){
    int totalSize;
    cout<<"Enter Total Memory Size:";
    cin>>totalSize;
    initializeMemory(totalSize);
    int choice,size,id;
    do{
        cout << "\n---- Memory Management Menu ----\n";
        cout << "1. Allocate Memory\n";
        cout << "2. Free Memory\n";
        cout << "3. Display Memory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter size to allocate:"<<endl;
                cin>>size;
                allocateMemory(size);
                break;
            case 2:
                cout<<"Enter Block Id to Free:"<<endl;
                cin>>id;
                freeMemory(id);
                break;
            case 3:
                displayMemory();
                break;
            case 4:
                cout<<"Exiting Program!"<<endl;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }while(choice!=4);
    return 0;
}