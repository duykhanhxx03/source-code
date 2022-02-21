#include <iostream>
using namespace std;
struct Node{
    int value;
    Node *nextNode;
};
Node *KhoiTaoNode(int x)
{
	Node *p = new Node;
	p->value = x; // gán x cho data
	p->nextNode = NULL;
	return p;
}
void addLastNode (Node *head, int value)
{
    if (head==NULL) head=KhoiTaoNode(value); else
    for (Node *k=head; k!=NULL; k=k->nextNode){
        if (k->nextNode==NULL){
            k->nextNode=KhoiTaoNode(value);
            break;
        }
    }
}
void addFirstNode(Node *head, int value){
    if (head==NULL) head=KhoiTaoNode(value); else
    {
        Node *p=KhoiTaoNode(value);
        p->nextNode=head;
        head=p;
    }
}
Node* addNode(Node* head, int index, int value){
    int n=0;
    for (Node *k=head; k!=NULL; k=k->nextNode) n++;
    // dem so phan tu
    if (head==NULL||index==0){
        addFirstNode(head,value);
        return head;
    }
    if(index==n){
        addLastNode(head,value);
        return head;
    }
    int count=-1;
    Node *g= new Node;
    for (Node *k=head; k!=NULL; k=k->nextNode){
        count++;
        if (count==index){
            Node *p= KhoiTaoNode(value);
            p->nextNode=k->nextNode;
            k->nextNode=p;
            break;
        }
        g=k;
    }
    return head;
}
Node* deleteNode(Node* head, int index){
    int n=0;
    for (Node *k=head; k!=NULL; k=k->nextNode) n++;
    if (index==0){
        Node *k=head;
        head=head->nextNode;
        delete k;
        return head;
    }
    if(index==n-1){
        for (Node *k=head; k!=NULL; k=k->nextNode){
            if ((k->nextNode)->nextNode==NULL){
                Node *g=k->nextNode;
                delete g;
                return head;
            }
        }
    }
        int count=-1;
        Node *g=new Node;
        for (Node *k=head; k!=NULL; k=k->nextNode){
            count++;
            if (count==index){
                g->nextNode=k->nextNode;
                delete k;
                return head;
            }
            g=k;
        }
}