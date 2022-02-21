// Stack là 1 cấu trúc trừu tượng, các đối tượng trong stack phải làm việc theo 1 cơ chế
// LIFO(LAST IN FIRST OUT) - đối tượng nào vào sau thì sẽ ra trước

// IsEmpty: kiểm tra xem stack có rỗng hay không
// Push: thêm 1 đối tượng vào đầu stack <=> theo cơ chế LIFO
// Pop: lấy phần tử đầu stack và trả về giá trị của đối tượng đầu stack
// đồng thời phải hủy nó đi
// Top: xem thông tin của phần tử đầu stack và không hủy nó đi
#include <iostream>
using namespace std;
struct NODE{
    int data;
    NODE *pNext;
};
struct STACK{
    NODE *pTop;
};
void KhoiTaoStack(STACK &st){
    st.pTop=NULL;
}
NODE *KhoiTaoNode(int x){
    NODE *p= new NODE;
    p->data=x;
    p->pNext=NULL;
    return p;
}
bool Is_Empty(STACK &st){
    if (st.pTop==NULL){
        return true;
    }
    return false;
}
void Push(STACK &st, NODE *p){
    if (Is_Empty(st)==true){
        st.pTop=p;
    } else {
        p->pNext=st.pTop;
        st.pTop=p;    
    }
}
void Pop (STACK &st, int &x){
    if (Is_Empty(st)==false){
        x=st.pTop->data;
        NODE *p= st.pTop;
        st.pTop=st.pTop->pNext;
        delete p;
    }
}
void Top (STACK &st, int &x){
    if (Is_Empty(st)==false){
        x=st.pTop->data;
    }
}
void DEC_to_BIN_HEX_OCT (STACK &st, int DEC_numberin, int BIN_HEX_OCT){
    while (DEC_numberin!=0)
    {
        int temp=DEC_numberin%BIN_HEX_OCT;
        NODE *p= KhoiTaoNode(temp);
        Push(st,p);
        DEC_numberin/=BIN_HEX_OCT;
    }
    
}
int main(){
    STACK st; KhoiTaoStack(st);
    cout<<"Nhap so he co so 10: "; int DEC_numberin; cin>>DEC_numberin;
    cout<<"DEC, BIN, OCT ?: "; int BIN_HEX_OCT; cin>>BIN_HEX_OCT;
    DEC_to_BIN_HEX_OCT(st, DEC_numberin, BIN_HEX_OCT);
    while (Is_Empty(st)==false)
    {
        int x;
        Pop(st,x);
        if (x<10) cout<<x; 
            else if (x==10) cout<<"A";
            else if (x==11) cout<<"B";
            else if (x==12) cout<<"C";
            else if (x==13) cout<<"D";
            else if (x==14) cout<<"E";
            else if (x==15) cout<<"F"; 
    }
    cout<<endl;
    system("pause");
    return 0;
}