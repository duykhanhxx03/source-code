#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE *pNext;
};
struct LIST{
    NODE *pHead; // con trỏ trỏ đến NODE đầu tiên
    NODE *pTail; // con trỏ trỏ đến NODE cuối cùng
};
void KhoiTaoList(LIST &l){
    // Cho hai con trỏ pHead và pTail trỏ đến NULL vì danh sách rỗng
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *KhoiTaoNODE(int x){
    NODE *p=new NODE; // Cấp phát bộ nhớ cho NODE p;
    if (p==NULL){
        cout<<"\nKhong du bo nho de cap phat!";
        return NULL;
    }
    (*p).data=x; //p->data, truyền giá trị của x vào cho p
    (*p).pNext=NULL; //p->pNext, đầu tiên khai báo NODE thì NODE đó chưa trỏ đến NODE nào hết, nên để NULL
    return p;
}
void ThemVaoDau(LIST &l, NODE *p){
    if (l.pHead==NULL){
        l.pHead=l.pTail=p;
    } else{
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
void ThemVaoCuoi (LIST &l, NODE *p){
    if (l.pHead==NULL){
        l.pHead=l.pTail=p;
    } else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void XuatDanhSach (LIST l){
    for (NODE *k= l.pHead; k !=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}
void TimMax (LIST l){
    int maxx=l.pHead->data;
    for (NODE *k=l.pHead->pNext; k!=NULL; k=k->pNext){
        if (k->data>maxx) maxx=k->data;
    }
    cout<<maxx;
}
int main(){
    LIST l; int n;
    KhoiTaoList(l);
    cout<<"Nhap so Node: "; cin>>n;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        NODE *p=KhoiTaoNODE(x);
        ThemVaoCuoi(l,p);
    }
    cout<<"Xuat danh sach lien ket don: "<<endl;
    XuatDanhSach(l);
    cout<<"\n";
    TimMax(l);
    return 0;
}
