#include <iostream>

#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
struct Node
{
	int data;
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
NODE* GetNode( int x) // Tao node moi co gia tri p-> data = x , va phan p->data = null 
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
void NhapNode(LIST& l, int& n )
{
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) // Nhap node
	{
		cin >> x;
		NODE* p = GetNode(x);
		AddTail(p, l);
	}
}
void XuatNode(LIST l )
{
	NODE* p = l.head;
	while (p != NULL)
	{
		cout << setw(5) << p->data;
		p = p->next;
	}
}
int NhapNodeFile(  int& n ,LIST& l , string FileName )
{
	
	int x;
	ifstream fi(FileName);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
	{
		fi >> x;
		Node* p = GetNode(x);
		AddTail(p, l);
	}
	return 1;
}
int XuatNodeFile(int n ,LIST& l , string FileName)
{
	ofstream fo(FileName);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	NODE* p = l.head;
	while (p != NULL)
	{
		fo << setw(5) << p->data;
		p = p->next;
	}

}
int main()
{
	int n;
	while (true)
	{
		cout << "Nhap n ";
		cin >> n;
		cout << "Bam phim bat ky de tiep tuc ";
		system("pause");
		system("cls");
	}
	
	/*LIST l;
	Init(l);
	int n;
	cout << "Nhap so node  ";
	string filename = "data1.txt";
	NhapNode(l, n);
	Node* p = l.head;
	XuatNodeFile(n, l, filename);*/
	
	return 0;
}