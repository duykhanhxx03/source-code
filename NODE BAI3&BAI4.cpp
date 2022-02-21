// Kĩ thuật thêm 1 node p vào sau node q
#include<iostream>
using namespace std;

// Nhập danh sách kiên kết đơn các số nguyên
// ============ KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN ============
struct node
{
	int data; // dữ liệu của 1 node
	struct node *pNext; // con trỏ dùng để liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc danh sách liên kết đơn
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node đầu và cuối trỏ đến vùng nhớ rỗng
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // gán x cho data
	p->pNext = NULL;
	return p;
}


// hàm thêm node p vào đầu danh sách
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // dùng con trỏ của node p liên kết với l.pHead
		l.pHead = p; // cập nhật lại l.pHead là p
	}
}

// hàm thêm node p vào cuối danh sách
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // cập nhật lại l.pTail là p
	}
}

// xuất danh sách liên kết đơn
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Thêm node p vào sau node q(nằm trong danh sách liên kết đơn)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q ==> bài toán trở thành kĩ thuật thêm vào cuối danh sách
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duyệt từ đầu danh sách đến cuối danh sách để tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// nếu node q có tồn tại thì....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // khởi tạo node h mới để thêm vào sau node q 
				h->pNext = k->pNext; // Bước 1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
				k->pNext = h; // Bước 2: Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h
			}
		}
	}
}
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p){
    int x; 
    cout<<"Nhap gia tri node q:"; 
    cin>>x;
    NODE *q=KhoiTaoNode(x);
    if (q->data==l.pHead->data){
        ThemVaoDau(l,p);} 
    else{
            NODE *g=new NODE;
            for (NODE *k=l.pHead; k!=NULL; k=k->pNext){
                if (q->data== k->data){
                    NODE *h= KhoiTaoNode(p->data);
                    h->pNext=k;
                    g->pNext=h;
                }
                g=k;
            }
        }
}
// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
        cout << "\n\t4. Them node p vao truoc node q trong danh sach";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // dừng màn hình
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // khởi tạo 1 cái node
			ThemVaoCuoi(l, p); // thêm node vào cuối danh sách
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // thêm node p vào sau node q trong danh sách l
		}
        else if (luachon==4){
            int x;
            cout<<"\nNhap gia tri node p can them vao truoc: ";
            cin>>x;
            NODE *p=KhoiTaoNode(x);
            ThemNode_p_VaoTruocNode_q(l,p);
        }
		else
		{
			break; // thoát khỏi vòng lặp hiện tại
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // luôn luôn gọi hàm khởi tạo danh sách liên kết đơn trước khi thao tác với danh sách
	Menu(l);

	system("pause");
	return 0;
}