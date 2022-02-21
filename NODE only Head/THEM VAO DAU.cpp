#include<iostream>
using namespace std;

// Nhập danh sách liên kết đơn các phân số
// khai báo cấu trúc 1 cái phân
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;

// nhập phân số
void Nhap_Phan_So(PHANSO &ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}

// hàm xuất phân số
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

// khai báo cấu trúc 1 cái node
struct node
{
	PHANSO data; // thành phần dữ liệu của 1 cái node
	node *pNext; // con trỏ dùng để giữ địa chỉ của cái node mà nó muốn liên kết đến
};
typedef struct node NODE;

// hàm khởi tạo 1 cái node 
NODE *KhoiTaoNode(PHANSO ps)
{
	NODE *p = new NODE; // Khởi tạo vùng nhớ cho cái node chuẩn bị thêm vào danh sách
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truyền giá trị ps vào cho cái data của cái node p
	p->pNext = NULL; // chưa liên kết đến thằng nào hết
	return p;
}

// hàm thêm 1 cái node p vào đầu danh sách
void ThemDau(NODE *&pHead, NODE *p)
{
	// nếu danh sách rỗng
	if(pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead; // cho node p cầnh thêm kết nối đến thằng đầu danh sách
		pHead = p; // cập nhật lại node đầu chính là node vừa thêm vào
	}
}

// hàm thêm 1 cái node p cuối danh sách
void ThemCuoi(NODE *&pHead, NODE *p)
{
	// nếu danh sách rỗng
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE *k = pHead; ; k = k->pNext)
		{
			// nếu cái thằng đang xét mà cái pNext bên trong nó đang liên kết đến NULL ==> k chính là node cuối danh sách
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

// hàm xuất danh sách các phân số
void Xuat_Danh_Phan_So(NODE *pHead)
{
	for (NODE *k = pHead; k != NULL; k = k ->pNext)
	{
		Xuat_Phan_So(k->data);
		cout << endl;
	}
}

// thiết kế menu thao tác trên danh sách liên kết đơn
void Menu(NODE *&pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY DANH SACH PHAN SO ========\n";
		cout << "\n1. Nhap phan so";
		cout << "\n2. Xuat danh sach phan so";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO ps;
			cout << "\n\n\t\t NHAP PHAN SO\n";
			Nhap_Phan_So(ps);

			NODE *p = KhoiTaoNode(ps);
			//ThemDau(pHead, p);
			ThemCuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH PHAN SO\n";
			Xuat_Danh_Phan_So(pHead);
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
	NODE *pHead = NULL;
	Menu(pHead);
	system("pause");
	return 0;
}