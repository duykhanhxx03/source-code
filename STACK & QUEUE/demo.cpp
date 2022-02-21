#include<iostream>
using namespace std;

/*
Nhập danh sách stack chứa các số nguyên, sau đó xuất ra màn hình các giá trị số nguyên đó

*/

// khai báo cấu trúc của 1 cái node trong stack
struct node
{
	int data; // stack đang chứa các số nguyên
	struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của stack
struct stack
{
	NODE *pTop; // dùng con trỏ đầu để quản lí stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá trị của biến x vào trong data của cái node
	p->pNext = NULL;
	return p;
}

// =============== KIỂM TRA STACK CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(STACK s)
{
	// nếu danh sách rỗng
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO ĐẦU STACK- LIFO ===============
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		s.pTop = p; // node p chính là node đầu stack
	}
	else // danh sách đã có phần tử
	{
		p->pNext = s.pTop; // cho con trỏ của node p trỏ đến node đầu danh sách <=> tạo kiên kết
		s.pTop = p; // cập nhật lại node đầu
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU STACK VÀ HỦY NÓ ĐI - LIFO ===============
bool Pop(STACK &s, int &x) // x chính là giá trị cần lấy trong node
{
	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; // node p chính là node thế mạng để tí nữa chúng ta xóa nó đi
		x = p->data; // gán giá trị của node đầu stack vào biến x	
		s.pTop = s.pTop->pNext; // cập nhật node đầu stack là node tiếp theo	
		delete p; // xóa node đầu stack vừa lấy 
		
	}
	return true;// lấy phần tử đầu stack thành công
}


// =============== XEM THÔNG TIN CỦA PHẦN TỬ ĐẦU STACK - KHÔNG CÓ HỦY NÓ ĐI NHÉ ===============
bool Top(STACK &s, int &x) // x chính là giá trị cần lấy ra để xem
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data; // lấy giá trị của phần tử đầu stack ra để xem
	return true;
}

// hàm xuất danh sách stack
void XuatStack(STACK s)
{
	while (IsEmpty(s) == false)
	{
		int x;
		Pop(s, x);
		cout << x << " ";
	}

	if (IsEmpty(s) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

// hàm nhập danh sách các số nguyên trong stack
void NhapStack(STACK &s)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao stack - Push";
		cout << "\n\t2. Xuat danh sach stack ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau stack - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			XuatStack(s);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(s, x);
			cout << "\nPhan tu dau stack la: " << x;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	STACK s;
	KhoiTaoStack(s);

	NhapStack(s);

	system("pause");
	return 0;
}