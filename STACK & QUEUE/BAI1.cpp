#include <iostream>
using namespace std;
struct NODE{
    int data;
    NODE *pNext;
};
struct QUEUE
{
    NODE *pTop;
};
NODE *KhoiTaoNode(int x){
    NODE *p= new NODE;
    p->data=x;
    p->pNext=NULL;
    return p;
}
void KhoiTaoStack(QUEUE &qu){
    qu.pTop=NULL;
}
void ThemVaoCuoi(NODE *p, QUEUE &qu){
    if (qu.pTop==NULL){
        qu.pTop=p;
    } else
        for (NODE *k= qu.pTop;;k=k->pNext){
            if (k->pNext==NULL){
                k->pNext=p;
                break;
            }
        }
}
void LayPhanTuDau (QUEUE &qu){
    if (qu.pTop!=NULL){
        cout<<qu.pTop->data<<endl;
    }
}
void XoaPhanTuDau (QUEUE &qu){
    if (qu.pTop!=NULL){
        NODE *p=qu.pTop;
        qu.pTop=qu.pTop->pNext;
        delete p;
    }
}
int main(){
    QUEUE qu;
    KhoiTaoStack(qu);
    int n; cin>>n;
    for (int i=0; i<n; i++){
        int temp; cin>>temp;
        switch (temp){
            case 1:
                {int x; cin>>x;
                NODE *p= KhoiTaoNode(x);
                ThemVaoCuoi(p,qu);
                break;}
            case 2:
                {XoaPhanTuDau(qu);
                break;}
            case 3:
                {LayPhanTuDau(qu);
                break;}
            }
    }
    return 0;
}
