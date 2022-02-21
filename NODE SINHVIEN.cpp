#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct SINHVIEN{
    string hoten;
    string masv;
    string ngaysinh;
    float dtb;
};
// khai bao node sinh vien
struct NODE
{
	SINHVIEN data; // dữ liệu của 1 node
	struct NODE *pNext; // con trỏ dùng để liên kết giữa các node với nhau
};
// khai báo cấu trúc danh sách liên kết đơn
struct LIST
{ 
	NODE *pHead;
	NODE *pTail;
};
// ============ KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node đầu và cuối trỏ đến vùng nhớ rỗng
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE *KhoiTaoNode(SINHVIEN x)
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

// hàm thêm node p sinh vien vào đầu danh sách
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

// hàm thêm node p sinh vien vào cuối danh sách
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
void Doc_Thong_Tin_1_Sinh_Vien(ifstream &filein, SINHVIEN &sinhvien){
	getline(filein,sinhvien.hoten,',');
	filein.seekg(-3,ios::cur);
	getline(filein,sinhvien.masv,',');
	filein.seekg(-3,ios::cur);
	getline(filein, sinhvien.ngaysinh ,',');
	filein.seekg(0,ios::cur);
	filein>>sinhvien.dtb;
	// string temp;
	// filein>>temp;
}
void Doc_Danh_Sach_Sinh_Vien(ifstream &filein, LIST &l){
	while (!filein.eof()){
		SINHVIEN sv;
		Doc_Thong_Tin_1_Sinh_Vien(filein,sv);
		NODE *p=KhoiTaoNode(sv);
		ThemVaoCuoi(l,p);
	}
}
void Xuat(SINHVIEN sv)
{
	cout << "\nHo ten:" << sv.hoten;  
	cout << "\nMa sinh vien:" << sv.masv;
	cout << "\nNgay sinh:" << sv.ngaysinh;
	cout << "\nDiem trung binh:" << sv.dtb<<endl;
}

// hàm xuất danh sách sinh viên
void Xuat_Danh_Sach_Sinh_Vien(LIST l)
{
	int dem = 1;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\t SINH VIEN THU " << dem++;
		Xuat(k->data);
	}
}
int main(){
	LIST l;
	KhoiTaoDSLK(l);
	ifstream filein;
	filein.open("SINHVIEN.txt", ios::in);
	// SINHVIEN sv1;
	// Doc_Thong_Tin_1_Sinh_Vien(filein,sv1);
	// Xuat(sv1);
	// SINHVIEN sv;
	// Doc_Thong_Tin_1_Sinh_Vien(filein,sv);
	// Xuat(sv);
	Doc_Danh_Sach_Sinh_Vien(filein,l);
	Xuat_Danh_Sach_Sinh_Vien(l);
    return 0;
}