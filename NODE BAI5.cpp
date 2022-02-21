// Kĩ thuật thêm 1 node p vào trước node q trong danh sách
#include<iostream>
using namespace std;

int n = 0; // khai báo biến toàn cục - chứa số lượng phần tử trong danh sách
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
	// for(int i = 0; i < n; i++)
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
        n++;
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
				NODE *g = k->pNext; // cho node g trỏ đến node nằm sau node q
				h->pNext = g; // Bước 1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
				k->pNext = h; // Bước 2: Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h
                n++;
			}
		}
	}
}

// Thêm node p vào trước node q(nằm trong danh sách liên kết đơn)
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x); // khởi tạo 1 node q

	// nếu danh sách chỉ tồn tại duy nhất 1 node và node này cũng chính là node q luôn - thì vấn đề trở về bài toán thêm node p vào đầu danh sách
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoDau(l, p); // thêm node p vào đầu danh sách
        n++;
	}
	else
	{
		NODE *g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		{
			// phát hiện node q có tồn tại trong danh sách thì bắt đầu thêm node p vào trước node q
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pNext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pNext = h; // Bước 2: cho node g trỏ đến node h
                n++; 
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}

// CÁCH 1: 
// hàm thêm 1 node p vào vị trí bất kì vt trong danh sách l
//void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt, int n) 
//{
//	
//	// danh sách đang rỗng
//	if (l.pHead == NULL || vt == 1)
//	{
//		// thêm node p vào đầu danh sách l
//		ThemVaoDau(l, p);
//	}
//	else if (vt == n + 1)
//	{
//		// thêm node p vào cuối danh sách l
//		ThemVaoCuoi(l, p); 
//	}
//	else // vt nằm trong đoạn [2, n]
//	{
//		int dem = 0; // xác định vt cần thêm
//		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
//		NODE *g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
//		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
//		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
//		{
//			dem++;
//			// tìm vị trí vt cần thêm
//			if (dem == vt)
//			{
//				NODE *h = KhoiTaoNode(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
//				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
//				h->pNext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
//				g->pNext = h; // Bước 2: cho node g trỏ đến node h 
//				break;
//			}
//			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
//		}
//	}
//
//}

// CÁCH 2: dùng biến toàn cục cho biến n
// hàm thêm 1 node p vào vị trí bất kì vt trong danh sách l
void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt)
{

	// danh sách đang rỗng
	if (l.pHead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		ThemVaoDau(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		ThemVaoCuoi(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		NODE *g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				NODE *h = KhoiTaoNode(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pNext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pNext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
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
		cout << "\n\t5. Them node p vao vi tri bat ki trong danh sach";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 5)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // dừng màn hình
		}
		else if (luachon == 1)
		{
			n++; // cách 2
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
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao truoc: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q(l, p); // thêm node p vào trước node q trong danh sách l
		}
		else if (luachon == 5)
		{
			//// cách 1: 
			//int n = 0;
			//// vòng lặp lấy số lượng node trong danh sách
			//for (NODE *k = l.pHead; k != NULL; k = k->pNext)
			//{
			//	n++;
			//}

			// khởi tạo giá trị cho node p
			int x;
			cout << "\nNhap gia tri node p: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);

			// nhập vị trí cần thêm cho node p ==> cần kiểm tra điều kiện
			int vt;
			do
			{
				cout << "\nNhap vi tri can them node p: ";
				cin >> vt;
				if (vt < 1 || vt > n + 1)
				{
					cout << "\nVi tri can them phai nam trong doan[1; " << n + 1 << "]";
					system("pause");
				}
			} while (vt < 1 || vt > n + 1);

			// ThemNode_p_VaoViTriBatKi(l, p, vt, n); CÁCH 1
			ThemNode_p_VaoViTriBatKi(l, p, vt); // CÁCH 2
			n++;
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