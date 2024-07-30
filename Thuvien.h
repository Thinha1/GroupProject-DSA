#ifndef _Thuvien_h
#define _Thuvien_h
//===================================================================================================
//Header:
// họ và tên thành viên thực hiện:
// 1.Đặng Anh Thịnh
// 2.Nguyễn Thị Thùy Dương
// 
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
struct thuvien {
	char masach[50];
	char tensach[31];
	char tentacgia[31];
	char nhaxuatban[31];
	int namxuatban;
	char theloai[50];
};
typedef thuvien ItemType;
struct DNode {
	ItemType info;
	DNode* next;
	DNode* prev;
};
struct DList {
	DNode* Head;
	DNode* Tail;
};
DNode* createDNode(ItemType x);
void doc_file(DList& dl, char tenfile[]);
void initDList(DList& dl);
int insertHead(DList& dl, DNode* p);
int isEmpty(DList dl);
void showDlist(DList dl);
void showDNode(DNode* p);
void xuatTTSach(ItemType x);
void xuatTTSachCot(ItemType x);
void process();
void showMenu();
void xuattheoten(DList dl, char ten[]);
void bubbleSort(DList& dl);
int size(DList dl);
int insertHead(DList& DL, DNode* p);
int checkIDDuplicate(DList dl, char masach[]);
void swap(ItemType& a, ItemType& b);
void toLowerString(char str[]);
void nhapTTSach(thuvien& tv);
DNode* createDNode(ItemType x);
void createDList_ByHand(DList& dl);
int deleteMiddle(DList& dl, ItemType& x);
int deleteHead(DList& dl, ItemType& x);
int deleteTail(DList& dl, ItemType& x);
int insertTail(DList& dl, DNode* p);
void countString(DList dl, char str[]);
void destroyDList(DList dl);
int countBooksByGenre(DList dl, const char* genre);
int countBooksByYear(DList dl, int year);
void printBooksByGenre(DList dl);
void printBooksByYear(DList dl);
int isGenreExists(DList dl, const char* genre);
void xoaKhoangTrangThua(char* str);
void copyDList(DList &dest, DList src);
DNode* findDNodehavebookname(DList dl, char str[]);
void writeList(FILE* fo, ItemType x);
void writeListToFile(DList& dl, char file_out[]);
void findAuthorWithMostBooks(DList dl);
void findPublisherWithLeastBooks(DList dl);
int countAuthors(DList dl, ItemType x);
int xulyXoa(DList& dl, int del);
int xulythem(DList& dl, int del);
int insertAfter(DList& dl, DNode* p, DNode* q);
int reverseDList(DList dl);
#endif _Thuvien_h