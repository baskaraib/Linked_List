#include<iostream>
using namespace std;

/*IDA BAGUS GEDE BASKARA
2101020026
TEKNIK INFORMATIKA*/

struct node{
    int data;
    struct node *next; 
    struct node *prev;
};

struct node *head;
struct node *tail;
struct node *current;
struct node *previous;
int jumlah=0;
//FUNGSI INPUT NODE PERTAMA
void First(int a){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->prev = NULL;
    newNode->next = NULL;
    head = newNode;
    tail = newNode;
    jumlah++;
}

//FUNGSI INPUT NODE DARI HEAD
void InsertAtHead(int a){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
    jumlah++;
}

//FUNGSI INPUT NODE DI MIDDLE
void InsertAtMiddle(int a){
    int tunjuk;
    struct node *newNode;
    previous = head;
    current = head->next;
    tunjuk = jumlah/2;
    for(int i=1; i<tunjuk; i++){
        previous = current;
        current = current->next;
    }
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = current;
    newNode->prev = previous;
    current->prev = newNode;
    previous->next = newNode;
    jumlah++;
}

//FUNGSI INPUT NODE DARI TAIL
void InsertAtTail(int a){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    jumlah++;
}

//FUNGSI UNTUK MENCARI NODE->DATA
void Search(int a){
    struct node *current;
    int i = 1, found;
    current = head;
    system("clear");
    do{
        if(current->data == a){
            cout<<"Data "<<a<<" found at node "<<i<<" from head\n\n";
            found = 1;
        }else{
            i++;
        }
        current = current->next;
    }while(current != head);
    
    if(found != 1){
        cout<<"Data not found!\n\n";
    }
}

//FUNGSI UNTUK MENGHAPUS DATA
void Delete_node(int a){
    struct node *current = head;
    struct node *previous = tail;
    int del;
    
    do{
        if(current->data == a){
            previous->next = current->next;
            if(head->data == a){
                head = current->next;
            }else if(tail->data == a){
                tail = current->prev;
            }
            current = current->next;
            current->prev = previous;
            del = 1;
        }else{
            previous = current;
            current = current->next;  
        }
        system("clear");
        if(del != 1){
            cout<<"Data not found!\n\n";
        }else{
            cout<<"Delete success!\n\n";
            jumlah--;
        }
    }while (current != head);
}

//FUNGSI UNTUK MENAMPILKAN NODE->DATA
void Traverse(){
    struct node *newNode;
    newNode = head;
    
    if(newNode != NULL){
        do{
            cout<<"node : "<<newNode->data<<endl;
            newNode = newNode->next;
        }while(newNode != head);
    }else{
        cout<<"Linked list empty!\n";
    }
    cout<<endl;
}

int main(){
    int data_1, data_2, data_3, pil, pil2;
    menu:
    cout<<"DOUBLY LINKD LIST\n";
    cout<<"1. Insert Node\n";
    cout<<"2. Search Node\n";
    cout<<"3. Delete Node\n";
    cout<<"4. Traverse\n";
    cout<<"5. Exit\n";
    cout<<"Input choice : ";
    cin>>pil;
    
    //INSERT NODE->DATA
    if(pil == 1){
        if(head == NULL){
            cout<<"Insert the first data : ";
            cin>>data_1;
            First(data_1);
            system("clear");
            cout<<"Input Success!\n\n"; 
            goto menu;
        }else{
            loop:
            cout<<"\nChoose : \n";
            cout<<"1. Insert at begin\n";
            cout<<"2. Insert at middle\n";
            cout<<"3. Insert at end\n";
            cout<<"Choose : ";
            cin>>pil2;
            if(pil2==1){
                cout<<"Insert data : ";
                cin>>data_1;
                InsertAtHead(data_1);
                system("clear");
                cout<<"Input Success!\n\n";
                goto menu; 
            }else if(pil2==2){
                cout<<"Insert data : ";
                cin>>data_1;
                InsertAtMiddle(data_1);
                system("clear");
                cout<<"Input Success!\n\n";
                goto menu;
            }else if(pil2==3){
                cout<<"Insert data : ";
                cin>>data_1;
                InsertAtTail(data_1);
                system("clear");
                cout<<"Input Success!\n\n";
                goto menu;
            }else{
                system("clear");
                cout<<"Invalid!\n";
                goto loop;
            }
        }
    //MENCARI NODE->DATA
    }else if(pil == 2){
        if(head == NULL){
            cout<<"Linked list empty!\n";
        }else{
            cout<<"Value to search : ";
            cin>>data_2;
            Search(data_2);
            goto menu;
        }
    //MENGHAPUS NODE       
    }else if(pil == 3){
        cout<<"Value to delete : ";
        cin>>data_3;
        Delete_node(data_3);
        goto menu;    
    }
    //MENAMPILKAN NODE->DATA YANG ADA
    else if(pil == 4){
        system("clear");
        Traverse();
        goto menu;
    }
    //EXIT
    else if(pil == 5){
        system("clear");
        do{
            break;
        }while(pil==5);
    }
    //INVALID INPUT
    else{
        system("clear");
        cout<<"Invalid input!\n\n";
        goto menu;
    }

    return 0;
}