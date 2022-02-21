#include<iostream>
using namespace std;
#include<string>
#include<fstream>

// khai báo cấu trúc ngày tháng năm sinh
struct date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct date DATE;

// hàm đọc dữ liệu ngày tháng năm từ file
void Doc_Ngay_Thang_Nam(ifstream &filein, DATE &date)
{
	filein >> date.ngay;
	filein.seekg(1, ios_base::cur); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> date.thang;
	filein.seekg(1, ios_base::cur); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> date.nam;
}

// khai báo cấu trúc sinh viên
struct sinhvien
{
	string hoten;
	string masv;
	DATE ngaysinh;
	float dtb;
};
typedef struct sinhvien SINHVIEN;

// khai báo cấu trúc 1 cái node sinh viên
struct node
{
	SINHVIEN data; // dữ liệu của node
	struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};
typedef struct node NODE;

// ========== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SINH VIÊN =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

// hàm khởi tạo danh sách liên kết đơn các sinh viên
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm khởi tạo 1 cái node để chuẩn bị thêm vào danh sách
NODE *KhoiTaoNode(SINHVIEN x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // đưa dữ liệu của biến sinh vien x vào data của cái Node p
	p->pNext = NULL; // khởi tạo node p nhưng node p chưa có liên kết đến node nào hết
	return p;
}

// hàm thêm 1 cái node sinh viên vào đầu danh sách
void ThemDau(LIST &l, NODE *p)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cũng chính là node đầu và node cuối
	}
	else
	{
		p->pNext = l.pHead; // cho con trỏ p trỏ đến pHead
		l.pHead = p; // cập nhật lại pHead là node p
	}
}

// hàm thêm 1 cái node sinh viên vào cuối danh sách
void ThemCuoi(LIST &l, NODE *p)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cũng chính là node đầu và node cuối
	}
	else
	{
		l.pTail->pNext = p; // cho con trỏ của pTail trỏ đến node p
		l.pTail = p; // cập nhật lại pTail chính là node p
	}
}

// hàm đọc dữ liệu 1 sinh viên từ file
void Doc_Thong_Tin_1_Sinh_Vien(ifstream &filein, SINHVIEN &sv)
{
	// đọc họ tên sinh viên
	getline(filein, sv.hoten, ','); // đọc đến dấu ',' thì dừng
	filein.seekg(1, ios_base::cur); // tại vị trí hiện tại dịch sang phải 1 byte để bỏ khoảng trắng ' '
	// đọc mã sinh viên
	getline(filein, sv.masv, ','); // đọc đến dấu ',' thì dừng
	filein.seekg(1, ios_base::cur); // tại vị trí hiện tại dịch sang phải 1 byte để bỏ khoảng trắng ' '
	// đọc thông tin ngày tháng năm sinh
	Doc_Ngay_Thang_Nam(filein, sv.ngaysinh);
	filein.seekg(2, ios_base::cur); // tại vị trí hiện tại dịch sang phải 2 byte để bỏ dấu phẩy và khoảng trắng ' '
	// đọc điểm trung bình
	filein >> sv.dtb;

	// tạo biến tạm để đọc cái kí tự xuống dòng ở cuối dòng
	string temp;
	getline(filein, temp);
}

// hàm đọc danh sách sinh viên từ file
void Doc_Danh_Sach_Sinh_Vien(ifstream &filein, LIST &l)
{
	// đọc đến cuối file thì dừng
	while (!filein.eof())
	{
		// BƯỚC 1: ĐỌC THÔNG TIN SINH VIÊN
		SINHVIEN sv;
		Doc_Thong_Tin_1_Sinh_Vien(filein, sv);
		// BƯỚC 2: KHỞI TẠO 1 CÁI NODE SINH VIÊN
		NODE *p = KhoiTaoNode(sv);
		// BƯỚC 3: THÊM SINH VIÊN(thêm node p) VÀO DANH SÁCH LIÊN KẾT ĐƠN CÁC SINH VIÊN
		ThemCuoi(l, p);
	}
}

// hàm xuất để test dữ liệu
void Xuat(SINHVIEN sv)
{
	cout << "\nHo ten:" << sv.hoten;  
	cout << "\nMa sinh vien:" << sv.masv;
	cout << "\nNgay sinh:" << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam;
	cout << "\nDiem trung binh:" << sv.dtb;
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

int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	// mở file lên
	ifstream filein;
	filein.open("SINHVIEN.TXT", ios::in);
	Doc_Danh_Sach_Sinh_Vien(filein, l);
	Xuat_Danh_Sach_Sinh_Vien(l);

	filein.close();
	system("pause");
	return 0;
}