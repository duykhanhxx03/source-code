#include <iostream>
using namespace std;
struct NODE{
	int data;
	NODE *pNext;
};
struct LIST{
	NODE *pHead;
	NODE *pTail;
};
void KhoiTaoList(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE *KhoiTaoNode (int x){
	NODE *p= new NODE;
	if (p==NULL){
		cout<<"KHONG THE KHOI TAO!";
		return NULL;
	}
	p->data=x;
	p->pNext=NULL;
}
void ThemVaoDau(LIST &l,NODE *p){
	if (l.pHead==NULL)
	{
		l.pHead=l.pTail=p;
	}
	p->pNext=l.pHead;
	l.pHead=p;
}
void ThemVaoCuoi(LIST &l,NODE *p){
	if (l.pHead==NULL)
	{
		l.pHead=l.pTail=p;
	}
	l.pTail->pNext=p;
	l.pTail=p;
}
void XuatDanhSach(LIST l){
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<k->data<<" ";
	}
}
int main(){
	LIST l;
	KhoiTaoList(l);
	cout<<"Nhap so NODE: "; int n; cin>>n;
	for (int i=0;i<n;i++){
		int x; cin>>x;
		NODE *p=KhoiTaoNode(x);
		ThemVaoCuoi(l,p);
	}
	XuatDanhSach(l);
	return 0;
}