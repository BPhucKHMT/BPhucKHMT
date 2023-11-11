#include <iostream>

#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
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
	cout << "Nhap ho ten sv " ;
	getline(cin, x.HoTen);
	cout << "Nhap ma so sinh vien ";
	cin >> x.MSSV;
	cout << "Nhap diem sinh vien ";
	cin >> x.Diem;
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
	while (p != NULL)
	{
		cout << setw(5) << p->data.HoTen << endl;
		cout  << setw(5) << p->data.MSSV << endl;
		cout  << setw(5) << p->data.Diem << endl;
		p = p->next;
	}
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
int XuatNodeFile(int sl , LIST& l, string FileName , int n)
{
	ofstream fo(FileName);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	NODE* p = l.head;
	while (p != NULL)
	{
		fo << setw(5) << p->data.HoTen<<endl;
		fo << setw(5) << p->data.MSSV << endl;
		fo << setw(5) << p->data.Diem << endl;
		p = p->next;
	}
	return 1;
}
void XuatMenu( LIST& l , int& n ,int& sl)
{
	cout << "**************************************************" << endl;
	cout << "** Phim 1 : Nhap sinh vien			**" << endl;
	cout << "** Phim 2 : Xuat ds sinh vien			**" << endl;
	cout << "** Phim 3 : Sap xep  sinh vien			**" << endl;
	cout << "** Phim 4 : Nhap sinh vien tu file 		**" << endl;
	cout << "** Phim 5 : Xuat sinh vien ra file		**" << endl;
	cout << "**************************************************" << endl;
	cout << "Nhap Phim so theo huong dan " << endl;
	cin >> sl;
	switch (sl)
	{
	case 1:
		NhapNode(l, n);
		break;
	default:
		XuatNode(l);
	}
	while (true)
	{
		system("pause");
		system("cls");
		XuatMenu(l, n, sl);
	}


}
int main()
{
	int sl;


	LIST l;
	Init(l);
	int n;
	XuatMenu(l,n, sl);
	
	return 0;
}
