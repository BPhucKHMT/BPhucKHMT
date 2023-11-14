#include <iostream>
#include <windows.h >
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

#include <conio.h>
using namespace std;


struct SinhVien
{
	string HoTen;
	int MSSV;
	int Diem;
};
typedef struct SinhVien SINHVIEN;
struct Node
{
	SINHVIEN data;
	Node* next;
};
typedef struct Node  NODE;
// Khoi tao 1 danh sach gom co phan head va tail
struct list
{
	NODE* head;
	NODE* tail;
};
typedef struct list LIST;
void Init(LIST& l) //Init dung khoi tao danh sach lien ket don co dia chi head = tail =000000000
{
	l.head = l.tail = NULL;

}
bool IsEmpty(LIST l) //Ktra xem danh sach lien ket don co rong  khong
{
	if (l.head == NULL)
		return 1;
	return 0;
}
void NhapSV(SINHVIEN& x)
{
	cin.ignore(59, '\n');
	cout << "Nhap ho ten sv ";
	getline(cin, x.HoTen);
	cout << "Nhap ma so sinh vien ";
	cin >> x.MSSV;
	cout << "Nhap diem sinh vien ";
	cin >> x.Diem;
	while (!(x.Diem >= 0 and x.Diem <= 30))
	{
		cout << "Diem khong hop le , xin nhap lai :";
		cin >> x.Diem;
	}
}
NODE* GetNode(SINHVIEN x) // Tao node moi co gia tri p-> data = x , va phan p->data = null 
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}
void AddTail(NODE* p, LIST& l) // them node p vua tao vao sau node
{
	if (l.head == NULL) // neu chua co node nao ton tai
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void NhapNode(LIST& l, int& n)
{
	n = 1;
	SINHVIEN x;
	for (int i = 0; i < n; i++) // Nhap node
	{
		NhapSV(x);
		NODE* p = GetNode(x);
		AddTail(p, l);
	}
}
void XuatNode(LIST l)
{
	NODE* p = l.head;
	cout << " *****************************************************************" << endl;
	while (p != NULL)
	{
		cout << left << setw(20) << p->data.HoTen;
		cout << left << setw(20) << to_string(p->data.MSSV);
		cout << left << setw(20) << to_string(p->data.Diem) << '\t' << "*" << endl;
		p = p->next;
	}
	cout << " *****************************************************************";
}
int NhapNodeFile(int& n, LIST& l, string FileName)
{

	SINHVIEN x;
	ifstream fi(FileName);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
	{
		fi >> x.HoTen >> x.MSSV >> x.Diem;
		Node* p = GetNode(x);
		AddTail(p, l);
	}
	return 1;
}
int XuatNodeFile(int sl, LIST& l, string FileName, int n)
{
	ofstream fo(FileName);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	NODE* p = l.head;
	while (p != NULL)
	{
		fo << setw(5) << p->data.HoTen << endl;
		fo << setw(5) << p->data.MSSV << endl;
		fo << setw(5) << p->data.Diem << endl;
		p = p->next;
	}
	return 1;
}
void SapXepSV(LIST& l)
{
	for (NODE* p = l.head; p->next != NULL; p = p->next)
	{
		for (NODE* q = p->next; q != NULL; q = q->next)
			if (q->data.MSSV < p->data.MSSV)
			{
				NODE temp;
				temp.data = q->data;
				q->data = p->data;
				p->data = temp.data;
			}
	}
}
void ThemDau(LIST& l)
{
	SINHVIEN x;
	NhapSV(x);
	NODE* p = GetNode(x);
	if (l.head == NULL) // neu chua co node nao ton tai
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
int DemNode(LIST l)
{
	int dem = 0;
	NODE* p = l.head;
	while (p != NULL)
	{
		dem++;
		p = p->next;
	}
	return dem;
}
void AddMid(LIST& l, int vt)
{
	SINHVIEN x;
	if (vt == 1)
	{
		ThemDau(l);
		void;
	}
	NhapSV(x);
	NODE* p = GetNode(x);
	Node* t = l.head;
	if ((vt > 1 and vt <= DemNode(l)))
	{
		for (int i = 1; i < vt - 1; i++)
		{
			t = t->next;
		}
		p->next = t->next;
		t->next = p;

	}

	else if (vt == DemNode(l) + 1)
		AddTail(p, l);
	else
		cout << "Vi tri khong hop le ";
}
void XuatMenu(LIST& l, int& n, int& sl, char& x)
{
	string FileName = "data2.txt";
	cout << "**************************************************" << endl;
	cout << "** Phim 1 : Nhap sinh vien			**" << endl;
	cout << "** Phim 2 : Xuat ds sinh vien			**" << endl;
	cout << "** Phim 3 : Sap xep  sinh vien			**" << endl;
	cout << "** Phim 4 : Nhap sinh vien tu file 		**" << endl;
	cout << "** Phim 5 : Xuat sinh vien ra file		**" << endl;
	cout << "** Phim 6 : Them sinh vien dau danh sach	**" << endl;
	cout << "** Phim 7 : Them sinh vien giua danh sach	**" << endl;
	cout << "** Phim 8 : Xem so luong sinh vien		**" << endl;
	cout << "** Phim 9 : Lam moi man hinh			**" << endl;
	cout << "** Phim 10 : Tat man hinh			**" << endl;
	cout << "*********************************************************" << endl;
	x = 'y';
	while (true)
	{
		cout << '\n' << "Nhap Phim so theo huong dan " << endl;
		if (!(cin >> sl))
		{
			cout << "Invalid input. Please try again.\n";
			cin.clear(); // Xóa tr?ng thái l?i c?a std::cin
			cin.ignore(10000, '\n'); // Xóa b? ??m ??u vào
			continue; // Quay l?i ??u vòng l?p
		}

		switch (sl)
		{
		case 1:
			NhapNode(l, n);
			break;
		case 2:
			XuatNode(l);
			break;
		case 3:
			SapXepSV(l);
			break;
		case 4:
			NhapNodeFile(n, l, FileName);
			break;
		case 5:
			XuatNodeFile(sl, l, FileName, n);
			break;
		case 6:
			ThemDau(l);
			break;
		case 7:
			cout << "Nhap vi tri muon them ";
			int vt;
			cin >> vt;
			AddMid(l, vt);
			break;
		case 8:
			cout << "So luong sinh vien la ";
			cout << DemNode(l);
			break;


		case 9:
			system("pause");
			system("cls");
			XuatMenu(l, n, sl, x);
			break;
		case 10:
		{
			cout << "Vui long nhan ESC de thoat " << endl;
			char ch = _getch(); // S? d?ng hàm _getch() t? th? vi?n conio.h
			if (ch == 27)
			{ // 27 là mã ASCII c?a nút Esc
				std::cout << "Da Nhan esc chuong trinh se thoat " << std::endl;
				Sleep(100);

				return;
			}
		}
		break;
		default:

			cout << "So Nhap khong hop le , xin nhap lai " << endl;;
			continue;


		}

		/*while (true)
		{
			char ch = _getch(); // S? d?ng hàm _getch() t? th? vi?n conio.h
			cout << "Vui long nh?n nút Esc ?? thoát." <<endl;
			if (ch == 27)
			{ // 27 là mã ASCII c?a nút Esc
				std::cout << "?ã nh?n nút Esc. Ch??ng trình s? thoát." << std::endl;
				break;
			}
			/*system("pause");
			getchar();
			system("cls");
			XuatMenu(l, n, sl); }*/

	}


}

int main()
{
	int sl;


	LIST l;
	Init(l);
	int n;
	char x;
	XuatMenu(l, n, sl, x);



	return 0;
}
