#include "Thuvien.h"
#include<iostream>
using namespace std;
//===================================================================================================
//tao mot node
DNode* createDNode(ItemType x)
{
	DNode* p = new DNode;
	if (p == NULL)
	{
		printf("khong the cap phat nut moi ");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
//===================================================================================================
//tao mot danh sach
void initDList(DList& dl)
{
	dl.Head = NULL;
	dl.Tail = NULL;
}
//===================================================================================================
//kiem tra rong
int isEmpty(DList dl)
{
	if (dl.Head == NULL)
	{
		return 1;
	}
	else
		return 0;
}
//===================================================================================================
//them dau
int insertHead(DList& DL, DNode* p) 
{
	if (p == NULL) 
	{
		printf("Khong them duoc");
		return 0;
	}
	if (isEmpty(DL) == 1) 
	{
		DL.Head = p;
		DL.Tail = p;
	}
	else 
	{
		p->next = DL.Head;
		p->prev = NULL;
		DL.Head->prev = p;	
		DL.Head = p;
	}
	return 1;
}
//===================================================================================================
//them cuoi
int insertTail(DList& dl, DNode* p)
{
	if (p == NULL)
	{
		printf("Khong them duoc");
		return 0;
	}
	if (isEmpty(dl) == 1)
	{
		dl.Head = p;
		dl.Tail = p;
	}
	else
	{
		dl.Tail->next = p;
		p->prev = dl.Tail;
		dl.Tail = p;
	}
	return 1;
}
//===================================================================================================
//them vao sau node q
int insertAfter(DList& dl, DNode* p, DNode* q) {
	if (p == NULL || q == NULL) {
		printf("Khong them duoc");
		return 0;
	}

	DNode* r = q->next;
	p->next = r;
	p->prev = q;
	q->next = p; 
	if (r != NULL) {
		r->prev = p;
	}
	else {
		dl.Tail = p;
	}

	return 1;
}
//===================================================================================================
//load thong tin sach tu filetext
void loadSach(FILE* fi, ItemType& x)
{
	fscanf(fi, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^\n]%*c", x.masach, x.tensach, x.tentacgia, x.nhaxuatban, &x.namxuatban, x.theloai);
}
//===================================================================================================
//thong tin mot quyen sach
void xuatTTSach(ItemType x)
{
	printf("|     %-10s | %-12s | %-28s | %-25s | %-18s | %d\n", x.masach, x.tensach, x.tentacgia, x.nhaxuatban, x.theloai, x.namxuatban);
	
}
//===================================================================================================
// thong tin sach vao danh sach theo cot
void xuatTTSachCot(ItemType x)
{
	printf("      %-10s %-27s %-22s %-20s %-12d  %-22s\n", x.masach, x.tensach, x.tentacgia, x.nhaxuatban, x.namxuatban, x.theloai);

}
//===================================================================================================
//in ra thong tin sach
void showDNode(DNode* p)
{
	xuatTTSachCot(p->info);
}
//===================================================================================================
//tao mot danh sach tu file  text
void doc_file(DList& dl, char tenfile[])
{
	FILE* fi = fopen(tenfile, "rt");
	if (fi == NULL)
	{
		printf("Loi doc file");
		return;
	}
	initDList(dl);
	int n;
	fscanf(fi, "%d\n", &n);

	
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		loadSach(fi, x);
		DNode* p = createDNode(x);
		insertTail(dl, p); 
	}
	printf("Nhap file text thanh cong!");
	fclose(fi);
}
int checkIDDuplicate(DList dl, char masach[])
{
	DNode* p = dl.Head;
	while(p != NULL)
	{
		if (strcmp(p->info.masach, masach) == 0)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}
//===================================================================================================
//nhap thong tin  quyen sach
void nhapTTSach(thuvien& tv)
{
	fflush(stdin);
	printf("Nhap ma sach: ");
	fgets(tv.masach, 50, stdin);
	tv.masach[strcspn(tv.masach, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

	printf("Nhap ten sach: ");
	fgets(tv.tensach, 31, stdin);
	tv.tensach[strcspn(tv.tensach, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

	printf("Nhap ten tac gia: ");
	fgets(tv.tentacgia, 31, stdin);
	tv.tentacgia[strcspn(tv.tentacgia, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

	printf("Nhap ten nha xuat ban: ");
	fgets(tv.nhaxuatban, 31, stdin);
	tv.nhaxuatban[strcspn(tv.nhaxuatban, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

	printf("Nhap nam xuat ban: ");
	scanf("%d", &tv.namxuatban);
	getchar();
	printf("Nhap the loai: ");
	fgets(tv.theloai, 50, stdin);
	tv.theloai[strcspn(tv.theloai, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng
}
//===================================================================================================
//tao mot danh sach tu ban phim
void createDList_ByHand(DList& dl)
{
	initDList(dl);
	ItemType x;
	int n;
	do {
		printf("Nhap so luong sach: ");
		scanf("%d", &n);
	}while (n < 0);

	for (int i = 0; i < n; i++) 
	{
		nhapTTSach(x);
		if(checkIDDuplicate(dl, x.masach) == 1)
		{
			printf("Trung ma sach!");
			getchar();
			return;
		}
		DNode* p = createDNode(x);
		if (insertHead(dl, p) == 0)
		{
			continue;
		}
		if(i != (n - 1))
		printf("nhap Enter de nhap thong tin quyen sach tiep theo:\n");
	}
}
//===================================================================================================
//thong tin danh sach sach dang co trong thu vien
void showDlist(DList dl)
{
	DNode* p = dl.Head;
	if (p == NULL)
		printf("Danh sach rong\n");
	else
		printf("%-4s | %-12s | %-23s | %-18s | %-14s | %-4s | %-15s\n", "STT", "MA SACH", "TEN SACH", "TAC GIA", "NHA XUAT BAN", "NAM XUAT BAN", "THE LOAI");
	int stt = 01;
	while (p != NULL) 
	{
		toLowerString(p->info.theloai);
		printf("%02d", stt++);
		showDNode(p);
		p = p->next;
	}
}
//===================================================================================================
//hoan vi
void swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}
//===================================================================================================
//sap xep noi bot
void bubbleSort(DList& dl) 
{
	if (isEmpty(dl) == 1 || dl.Head == dl.Tail) return;
	for (DNode* i = dl.Head; i != dl.Tail; i = i->next) 
	{
		for (DNode* j = dl.Tail; j != i; j = j->prev) 
		{
			toLowerString(i->info.theloai);
			toLowerString(j->info.theloai);
			int comp = strcmp(j->info.theloai, i->info.theloai);
			if ((comp < 0) || (comp == 0 && strcmp(j->info.masach, i->info.masach) < 0)) 
			{
				swap(i->info, j->info);
			}
		}
	}
	showDlist(dl);
	printf("Da sap xep thanh cong !");
}
//===================================================================================================
//chuyen thanh chu thuong
void toLowerString(char str[])
{
	for (int i = 0; str[i] != '\0'; i++) 
	{
		str[i] = tolower(str[i]);
	}
}
//===================================================================================================
//tim node chua ten sach
int findDNode(DList dl, char str[])
{
	int count = 0;
	DNode* p = dl.Head;
	while (p != NULL)
	{
		char temp[30];
		strcpy(temp, p->info.tensach);
		toLowerString(temp);
		if (strstr(temp, str) != NULL) 
		{
			count++;
		}
		p = p->next;
	}
	return count;
}
//===================================================================================================
//xoa khoang trang
void xoaKhoangTrangThua(char* str) {
	int len = strlen(str);
	while (len > 0 && isspace((unsigned char)str[len - 1])) {
		len--;
	}
	str[len] = '\0'; 
}
//===================================================================================================
//tim node chua ten sach
DNode* findDNodehavebookname(DList dl, char str[])
{
	if (isEmpty(dl) == 1)
		return NULL;
	DNode* p = dl.Head;
	xoaKhoangTrangThua(str);
	while (p != NULL) 
	{
		if (strcmp(p->info.tensach, str) == 0) 
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
//===================================================================================================
//dem so sach co ten lap trinh
void countString(DList dl, char str[])
{
	char tmp[30];
	strcpy(tmp, str);
	toLowerString(tmp);
	xoaKhoangTrangThua(tmp);
	printf("Co tong %d lan xuat hien chuoi '%s' trong danh sach", findDNode(dl, tmp), str);
}
//===================================================================================================
//xoa node cuoi
int deleteTail(DList& dl, ItemType& x)
{
	if (isEmpty(dl) == 1)
	{
		printf("Khong xoa duoc");
		return 0;
	}
	DNode* p = dl.Tail;
	dl.Tail = dl.Tail->prev;
	if (dl.Tail == NULL)
		dl.Head = NULL;
	else
		dl.Tail->next = NULL;
	x = p->info;
	delete p;
	return 1;

}
//===================================================================================================
//xoa node dau
int deleteHead(DList& dl, ItemType& x)
{
	if (isEmpty(dl) == 1)
	{
		printf("Khong xoa duoc");
		return 0;
	}
		
	DNode* p = dl.Head;
	dl.Head = dl.Head->next;
	if (dl.Head == NULL)
		dl.Tail = NULL;
	else
		dl.Head->prev = NULL;
	x = p->info;
	delete p;
	return 1;
}
//===================================================================================================
//xoa sau mot node
int deleteAfter(DList& dl, DNode* q, ItemType& x)
{
	if (q == NULL || q == dl.Tail) 
	{
		printf("Khong xoa duoc");
		return 0;
	}
	DNode* p = q->next; //node kế sau
	DNode* r = p->next;
	q->next = r;
	if (r == NULL)
		dl.Tail = q;
	else
		r->prev = p;
	x = p->info;
	delete p;
	return 1;
}
//===================================================================================================
//kich thuoc danh sach
int size(DList dl) {
	int count = 0;
	DNode* p = dl.Head;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
//===================================================================================================
//xoa giua
int deleteMiddle(DList& dl, ItemType& x) {
	if ((dl.Head == NULL || dl.Head->next == NULL) || (dl.Head->next->next == NULL))
	{
		printf("Khong xoa duoc");
		return 0;
	}
	DNode* slow_ptr = dl.Head;
	DNode* fast_ptr = dl.Head;
	while (fast_ptr != NULL && fast_ptr->next != NULL)
		fast_ptr = fast_ptr->next->next;
	slow_ptr = slow_ptr->next;
	x = slow_ptr->info;
	DNode* middle_node = slow_ptr;
	middle_node->prev->next = middle_node->next;
	if (middle_node->next != NULL)
	{
		middle_node->next->prev = middle_node->prev;
		middle_node->next = NULL;
		middle_node->prev = NULL;
	}
	return 1;
}
//===================================================================================================
//xu li cac ham xoa
int xulyXoa(DList& dl, int del)
{ // 1: xoa dau 2: xoa giua 3: xoa cuoi
	ItemType x;
	if (del == 1)
	{
		if (deleteHead(dl, x) == 1)
		{
			printf("Du lieu vua xoa la:\n");
			xuatTTSach(x);
			printf("\nDanh sach sau khi da xoa:\n");
			showDlist(dl);
			return 1;
		}
		else return 0;
	}
	else if (del == 2)
	{
		if (deleteMiddle(dl, x) == 1) 
		{
			printf("Du lieu vua xoa la:\n");
			xuatTTSach(x);
			printf("\nDanh sach sau khi da xoa:\n");
			showDlist(dl);
			return 1;
		}
		else return 0;
	}
	else if (del == 3)
	{
		char finding[50];
		printf("Nhap ten quyen sach truoc vi tri muon xoa: ");
		getchar();
		fgets(finding, 50, stdin);
		DNode* q = findDNodehavebookname(dl, finding);
		if (q != NULL) 
		{
			if (deleteAfter(dl, q, x) == 1) 
			{
				printf("Du lieu vua xoa la:\n");
				xuatTTSach(x);
				printf("\nDanh sach sau khi da xoa :\n");
				showDlist(dl);
			}
			else return 0;
		}
		else 
		{
			printf("Khong tim thay quyen sach.\n");
			return 0;
		}
		return 1;
	}
	else if (del == 4)
	{
		if (deleteTail(dl, x) == 1)
		{
			printf("Du lieu vua xoa la:\n");
			xuatTTSach(x);
			printf("\nDanh sach sau khi da xoa:\n");
			showDlist(dl);
			return 1;
		}
		else return 0;
	}
	else
	{
		printf("Khong tim thay chuc nang!\nVui long nhap lai!\n");
		return 0;
	}
	
}
//===================================================================================================
//xu li cac ham themm
int xulythem(DList& dl, int add)
{
	ItemType x;
	DNode* p;

	if (add == 1)
	{
		printf("Nhap du lieu cua quyen sach muon them: \n");
		nhapTTSach(x);
		if (checkIDDuplicate(dl, x.masach) == 1)
		{
			printf("Trung ma sach!");
			getchar();
			return 0;
		}
		p = createDNode(x);
		insertHead(dl, p);  
		printf("Du lieu vua them la:\n");
		xuatTTSach(x); 
		printf("\nDanh sach sau khi them dau:\n");
		showDlist(dl);  
		return 1;
	}
	else if (add == 2)
	{
		ItemType y;
		char finding[50];
		printf("Nhap du lieu cua quyen sach muon them: \n");
		nhapTTSach(x);
		if (checkIDDuplicate(dl, x.masach) == 1)
		{
			printf("Trung ma sach!");
			getchar();
			return 0;
		}
		p = createDNode(x);
		printf("Nhap ten quyen sach truoc vi tri muon chen: ");
		fgets(finding, 50, stdin);
		DNode* q = findDNodehavebookname(dl, finding);
		if (q != NULL) { 
			printf("Du lieu vua them la:\n");
			xuatTTSach(x);
			if (checkIDDuplicate(dl, x.masach) == 1)
			{
				printf("Trung ma sach!");
				getchar();
				system("pause");
				return 0;
			}
			insertAfter(dl, p, q);
			printf("\nDanh sach sau khi them sau :\n");
			showDlist(dl); 
		}
		else {
			printf("Khong tim thay quyen sach.\n");
			system("pause");
			return 0;
		}
		return 1;
	}
	else if (add == 3)
	{
		printf("Nhap du lieu cua quyen sach muon them: \n");
		nhapTTSach(x);
		if (checkIDDuplicate(dl, x.masach) == 1)
		{
			printf("Trung ma sach!");
			getchar();
			system("pause");
			return 0;
		}
		p = createDNode(x);
		insertTail(dl, p); 
		printf("Du lieu vua them la:\n");
		xuatTTSach(x);
		printf("\nDanh sach sau khi them cuoi:\n");
		showDlist(dl);
		return 1;
	}
	else
	{
		printf("Khong tim thay chuc nang! \nVui long nhap lai! (Chi nhap chu in hoa)");
		return 0;
	}
}
//===================================================================================================
//dem tac gia dang co trong danh sach
int countAuthors(DList dl, ItemType x) {
	int count = 0;

	DNode* p = dl.Head;
	while (p != NULL) {
		if (strcmp(p->info.tentacgia, x.tentacgia) == 0) {
			count++;
		}
		p = p->next;
	}

	return count;
}
//===================================================================================================
//tim tac gia co so sach nhieu nhat
void findAuthorWithMostBooks(DList dl) {
	int max_sosach = 0; // Số lượng sách nhiều nhất của một tác giả

	// Tìm số sách nhiều nhất
	DNode* p = dl.Head;
	while (p != NULL) {
		ItemType x;
		strcpy(x.tentacgia, p->info.tentacgia);
		int sosach = countAuthors(dl, x);

		if (sosach > max_sosach) {
			max_sosach = sosach;
		}

		p = p->next;
	}

	// In ra tất cả các tác giả có số sách nhiều nhất
	p = dl.Head;
	while (p != NULL) {
		ItemType x;
		strcpy(x.tentacgia, p->info.tentacgia);
		int sosach = countAuthors(dl, x);

		if (sosach == max_sosach) {
			bool isDuplicate = false;

			// Kiểm tra trùng lặp trong danh sách tác giả đã in
			DNode* authorNode = dl.Head;
			while (authorNode != p) {
				ItemType y;
				strcpy(y.tentacgia, authorNode->info.tentacgia);
				if (strcmp(y.tentacgia, x.tentacgia) == 0) {
					isDuplicate = true;
					break;
				}
				authorNode = authorNode->next;
			}

			if (!isDuplicate) {
				printf("Tac gia co nhieu sach nhat: %s\n", p->info.tentacgia);
			}
		}

		p = p->next;
	}

	printf("So sach: %d\n", max_sosach);
}
//
//===================================================================================================
//dem nha xuat ban sach trong danh sach
int countBooksByPublisher(DList dl, ItemType x) {
	int countSach = 0; // Số lượng sách

	DNode* p = dl.Head;
	for (; p != NULL; p = p->next) {
		if (strcmp(x.nhaxuatban, p->info.nhaxuatban) == 0) {
			countSach++;
		}
	}

	return countSach;
}
//===================================================================================================
//tim nha xuat ban co sach it nhat mot danh sach
void findPublisherWithLeastBooks(DList dl) {
	int min_sosach = INT_MAX; // Số lượng sách ít nhất của một nhà xuất bản
	char nxb_it_sach_nhat[30]; // Tên nhà xuất bản có ít sách nhất

	// Tìm số sách ít nhất
	DNode* p = dl.Head;
	while (p != NULL) {
		ItemType x;
		strcpy(x.nhaxuatban, p->info.nhaxuatban);
		int sosach = countBooksByPublisher(dl, x);

		if (sosach < min_sosach) {
			min_sosach = sosach;
			strcpy(nxb_it_sach_nhat, x.nhaxuatban);
		}

		p = p->next;
	}

	// In ra tất cả các nhà xuất bản có số sách ít nhất
	p = dl.Head;
	while (p != NULL) {
		ItemType x;
		strcpy(x.nhaxuatban, p->info.nhaxuatban);
		int sosach = countBooksByPublisher(dl, x);

		if (sosach == min_sosach) {
			bool isDuplicate = false;

			// Kiểm tra trùng lặp trong danh sách nhà xuất bản đã in
			DNode* publisherNode = dl.Head;
			while (publisherNode != p) {
				ItemType y;
				strcpy(y.nhaxuatban, publisherNode->info.nhaxuatban);
				if (strcmp(y.nhaxuatban, x.nhaxuatban) == 0) {
					isDuplicate = true;
					break;
				}
				publisherNode = publisherNode->next;
			}

			if (!isDuplicate) {
				printf("Nha xuat ban co it sach nhat: %s\n", p->info.nhaxuatban);
			}
		}

		p = p->next;
	}

	printf("So sach: %d\n", min_sosach);
	
}
//===================================================================================================
//dem so luong sach trong  nam
int countBooksByYear(DList dl, int year) {
	int countSach = 0; 

	DNode* p = dl.Head;
	while (p != NULL) {
		if (p->info.namxuatban == year) {
			countSach++;
		}

		p = p->next;
	}

	return countSach;
}
//===================================================================================================
//thong tin thong ke so luong sach qua cac nam
void printBooksByYear(DList dl) {
	int namhientai;
	printf("hay nhap vao nam hien tai: ");
	scanf("%d", &namhientai);
	getchar();

	int namthongke;
	printf("hay nhap vao nam bat dau thong ke: ");
	scanf("%d", &namthongke);
	getchar();

	printf("thong ke theo tung nam:\n");
	for (int year = namthongke; year <= namhientai; year++) {
		int count = countBooksByYear(dl, year);
		printf("nam %d: %d sach\n", year, count);
	}
}
//===================================================================================================
//tim so the loai da co trong danh sach
int isGenreExists(DList dl, char genre[]) {
	DNode* p = dl.Head;
	while (p != NULL) {
		if (strcmp(p->info.theloai, genre) == 0) {
			return 1;
		}
		p = p->next;
	}
	return 0;
}
//===================================================================================================
//loại bỏ
void destroyDList(DList dl) {
	DNode* p = dl.Head;
	while (p != NULL) {
		DNode* temp = p;
		p = p->next;
		delete temp;
	}

	dl.Head = NULL;
	dl.Tail = NULL;
}
//===================================================================================================
//dem the loai xuat hien 
int countBooksByGenre(DList dl, char* genre) {
	int count = 0;
	DNode* p = dl.Head;

	while (p != NULL) {
		toLowerString(p->info.theloai);
		if (strcmp(p->info.theloai, genre) == 0) {
			count++;
		}
		p = p->next;
	}

	return count;
}
//===================================================================================================
//in ra thong tin thong ke the loai
void printBooksByGenre(DList dl) {
	printf("thong ke sach theo tung the loai:\n");

	// Tạo một danh sách các thể loại sách không trùng lặp
	DList uniqueGenres;
	initDList(uniqueGenres);
	DNode* p = dl.Head;
	DList printedGenres;
	initDList(printedGenres);
	// Duyệt qua danh sách uniqueGenres và đếm số sách thuộc mỗi thể loại
	while (p != NULL) {
		int found = 0;
		DNode* q = printedGenres.Head;
		while (q != NULL) {
			if (strcmp(p->info.theloai, q->info.theloai) == 0) 
			{
				found = 1;
				break;
			}
			q = q->next;
		}
		if (found == 0) {
			int count = countBooksByGenre(dl, p->info.theloai);
			printf("The loai %s: %d sach\n", p->info.theloai, count);
			insertTail(printedGenres, createDNode(p->info));
		}
			p = p->next;
	}
}
//===================================================================================================
//Hàm sao chép danh sách liên kết
void copyDList(DList &dest, DList src) {
	// Kiểm tra danh sách gốc có rỗng hay không
	if (isEmpty(src)) {
		initDList(dest); // Khởi tạo danh sách mới nếu danh sách gốc rỗng
		return;
	}
	// Khởi tạo danh sách mới
	initDList(dest);

	// Duyệt qua từng nút trong danh sách gốc
	DNode* current = src.Head;
	while (current != NULL) {
		// Tạo một nút mới
		DNode* new_node = createDNode(current->info);

		// Thêm nút mới vào danh sách mới
		if (isEmpty(dest)) 
		{
			dest.Head = dest.Tail = new_node;
		}
		else 
		{
			insertTail(dest, new_node);
		}
		// Di chuyển đến nút kế tiếp trong danh sách gốc
		current = current->next;
	}
}

//viet thong tin luu vao file text
void writeList(FILE* fo, ItemType x)
{
	fprintf(fo, "    %-10s %-25s %-20s %-18s %-10d  %-20s\n", x.masach, x.tensach, x.tentacgia, x.nhaxuatban, x.namxuatban, x.theloai);
}
//===================================================================================================
//save thong tin
void writeListToFile(DList& dl, char file_out[]) {
	FILE* fo = fopen(file_out, "wt");
	if (fo == NULL) {
		printf("Không thể mở hoặc tạo file!");
		return;
	}
	DNode* p = dl.Head;
	int stt = 1;
	if (p == NULL)
		fprintf(fo, "Danh sach rong");
	else
		fprintf(fo, "%-2s| %-10s | %-23s | %-18s | %-14s | %-4s | %-15s\n", "STT", "MA SACH", "TEN SACH", "TAC GIA", "NHA XUAT BAN", "NAM XUAT BAN", "THE LOAI");
	while (p != NULL) {
		ItemType x;
		fprintf(fo, "\n%2d", stt++);
		writeList(fo, p->info);
		p = p->next;
	}
	fclose(fo);
}
//===================================================================================
// dao nguoc danh sach lien ket doi
int reverseDList(DList dl) {
	DNode* p = dl.Tail;
	if (p == NULL) {
		printf("Danh sach rong\n");
		return 0;
	}
	else
		printf("%-4s | %-12s | %-23s | %-18s | %-14s | %-4s | %-15s\n", "STT", "MA SACH", "TEN SACH", "TAC GIA", "NHA XUAT BAN", "NAM XUAT BAN", "THE LOAI");
	int stt = 01;
	while (p != NULL)
	{
		toLowerString(p->info.theloai);
		printf("%02d", stt++);
		showDNode(p);
		p = p->prev;
	}
	return 1;
}