#include <iostream>
using namespace std;

typedef struct Node{
    int num;
    char * username;
    char * password;
    Node * next;
} Node,List;

Node * head=NULL;
Node * tail=NULL;

int add_Node(int num,char* username,char* password)
{
    Node * select=head;
    while(1){
        if (select==NULL){
            break;
        }
        if(select->num==num){
            return -1;
        }
        select=select->next;
    }
    if(head==NULL){
        Node * p=(Node *)malloc(sizeof(Node));
        p->num=num;
        p->username=username;
        p->password=password;
        p->next=NULL;
        head=p;
        tail=p;
        return 1;
    }else{
        Node * p=(Node *)malloc(sizeof(Node));
        p->num=num;
        p->username=username;
        p->password=password;
        p->next=NULL;
        tail->next=p;
        tail=p;
        return 1;
    }
}
int delete_node(int num)
{
    Node * t=head;
    Node * tt;
    while(1){
        if (t==NULL){
            return -1;
        }
        if(t->num==num) {
            if (t == head) {
                head = t->next;
                free(t);
                return 1;
            }else if(t == tail){
                tail=tt;
                free(t);
                return 1;
            }else{
                tt->next=t->next;
                free(t);
                return 1;
            }
        }
        tt=t;
        t=t->next;
    }
}
Node * select_num(int num){
    Node * t=head;
    while(1){
        if (t==NULL){
            return NULL;
        }
        if(t->num==num) {
            return t;
        }
        t=t->next;
    }
}
Node * select_up(char * username,char * password){
    Node * t=head;
    while(1){
        if (t==NULL){
            return NULL;
        }
        if(t->username==username&&t->password==password) {
            return t;
        }
        t=t->next;
    }
}
int update_num(int num,Node * update){
    Node * t=head;
    while(1){
        if (t==NULL){
            return -1;
        }
        if(t->num==num) {
            if(update->num!=0)
                t->num=update->num;
            if(update->username!=0)
                t->username=update->username;
            if(update->password!=0)
                t->password=update->password;
            return 1;
        }
        t=t->next;
    }
}
void select_all(){
    Node *p=head;
    while(p!=0){
        cout<<"id:"<<p->num<<"  "<<"username:"<<p->username<<"  "<<"password:"<<p->password<<endl;
        p=p->next;
    }
}
int main() {
    int a=add_Node(1,"yu","123");
    cout<<"run over:"<<a<<endl;
    a=add_Node(2,"liu","456");
    cout<<"run over:"<<a<<endl;
    a=add_Node(3,"wang","789");
    cout<<"run over:"<<a<<endl;
    a=add_Node(4,"zhang","147");
    cout<<"run over:"<<a<<endl;
    a=add_Node(5,"gao","258");
    cout<<"run over:"<<a<<endl;
    a=add_Node(6,"ren","369");
    cout<<"run over:"<<a<<endl;
    a=add_Node(1,"qwe","234");
    cout<<"run over:"<<a<<endl;
    select_all();
    a=delete_node(4);
    cout<<"run over:"<<a<<endl;
    a=delete_node(4);
    cout<<"run over:"<<a<<endl;
    select_all();
    Node * aa=select_num(2);
    cout<<"run over:"<<"id:"<<aa->num<<"  "<<"username:"<<aa->username<<"  "<<"password:"<<aa->password<<endl;
    aa=select_up("yu","123");
    cout<<"run over:"<<"id:"<<aa->num<<"  "<<"username:"<<aa->username<<"  "<<"password:"<<aa->password<<endl;
    Node * update=(Node *)malloc(sizeof(Node));
    update->username="yxl";
    update->password="123456";
    a=update_num(1,update);
    cout<<"run over:"<<a<<endl;
    select_all();
}
