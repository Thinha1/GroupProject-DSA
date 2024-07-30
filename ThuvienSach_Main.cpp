#include<iostream>
#include "Thuvien.h"
#include "MyLib.h"
using namespace std;
//void showMenu() 
//{
//	printf("\n********************************************************************");
//	printf("\n*          LIBRARY MANAGEMENT PROGRAM                              *");
//	printf("\n********************************************************************");
//	printf("\n* 1.NHAP THEM THONG TIN MOT QUYEN SACH DA SAP XEP(co danh sach)    *");
//	printf("\n*                                                                  *");
//	printf("\n* 2.TAO MOT DANH SACH SACH VOI FILE TEXT.                          *");
//	printf("\n*                                                                  *");
//	printf("\n* 3.TAO MOT DANH SACH TU BAN PHIM.                                 *");
//	printf("\n*                                                                  *");
//	printf("\n* 4.THUC HIEN XOA DU LIEU.                                         *");
//	printf("\n*                                                                  *");
//	printf("\n* 5.DEM SO LUONG SACH CHUA CHUOI LAP TRINH.                        *");
//	printf("\n*                                                                  *");
//	printf("\n* 6.SAP XEP DANH SACH THEO CUNG THE LOAI.                          *");
//	printf("\n*                                                                  *");
//	printf("\n* 7.TIM TAC GIA CO NHIEU SACH NHAT.                                *");
//	printf("\n*                                                                  *");
//	printf("\n* 8.TIM NHA XUAT BAN CO IT SACH NHAT.                              *");
//	printf("\n*                                                                  *");
//	printf("\n* 9.THONG KE SACH THEO TUNG NAM XUAT BAN.                          *");
//	printf("\n*                                                                  *");
//	printf("\n* 10.DEM SO LUONG SACH THEO TUNG THE LOAI.                         *");
//	printf("\n*                                                                  *");
//	printf("\n* 11.XEM NOI DUNG DANH SACH DANG CO.                               *");
//	printf("\n*                                                                  *");
//	printf("\n* 12.THUC HIEN THEM DU LIEU O CAC VI TRI.                          *");
//	printf("\n*                                                                  *");
//	printf("\n* 0. Thoat chuong trinh                                            *");
//	printf("\n*                                                                  *");
//	printf("\n********************************************************************");
//	printf("\nVui long chon chuc nang: ");
//}
//**************************************************************************
void process() 
{
	char fin[20] = "TTSach.txt";
	char file_out[25] = "TTSach-Output.txt";
	ItemType x;
	DList dl;
	DList temp_dl;
	DNode* p;
	thuvien tv;
	int choicesave;
	char str[30];
	int lc;
	int del, add;

	do 
	{
		system("cls");
		XY(30, 2);
		BGcolor(6);
		cout << " LIBRARY MANAGEMENT PROGRAM ";
		lc = menu_02();
		system("cls");
		ShowCur(1);
		/*showMenu();*/
		switch (lc) 
		{
		case 1:
			nhapTTSach(tv);
			if (checkIDDuplicate(dl, tv.masach) == 1)
			{
				printf("Trung ma sach!");
				getchar();
				break;
			}
			p = createDNode(tv);
			printf("Noi dung quyen sach vua nhap la:\n");
			showDNode(p);
			copyDList(temp_dl, dl);
			insertTail(dl, p);
			bubbleSort(dl);
			printf("Sach da duoc them vao thu vien thanh cong!\n");
			do 
			{
				printf("Luu du lieu vao file moi? \n(1: Yes / 2: No): ");
				scanf("%d", &choicesave);
				if (choicesave == 1) 
				{
					writeListToFile(dl, file_out);
					printf("\nLuu file thanh cong!");
				}
				else if (choicesave == 2) //khong muon luu thi khoi phuc lai tu ban sao
				{
					destroyDList(dl);
					copyDList(dl, temp_dl);
					printf("Khong luu file nen hoan tac lenh vua thuc thi");
					getchar();
					break;
				}
				if (choicesave < 1 || choicesave > 2)
					printf("Chi nhap 1 hoac 2\nVui long nhap lai!\n");
			} while (choicesave < 1 || choicesave > 2);
			break;
		case 2:
			doc_file(dl, fin);
			printf("\n");
			showDlist(dl);
			system("pause");
			break;
		case 3:
			createDList_ByHand(dl);
			printf("Sach da duoc them vao thu vien thanh cong!\n");
			break;
		case 4:
			do 
			{
				printf("Xoa dau (1) | Xoa giua (2) | Xoa sau (3) | Xoa cuoi (4): ");
				scanf("%d", &del);
				if (del < 1 || del > 4)
					printf("Khong tim thay chuc nang!\nVui long nhap lai!\n");
			} while (del < 1 || del > 4);
			copyDList(temp_dl, dl); //sao chép dslk ra dslk tạm
			if (xulyXoa(dl, del) == 1) {
				do 
				{
					printf("Luu du lieu vao file moi? \n(1: Yes / 2: No): ");
					scanf("%d", &choicesave);
					if (choicesave == 1) 
					{
						writeListToFile(dl, file_out);
						printf("\nLuu file thanh cong!");
						break;
					}
					else if(choicesave == 2)
					{
						destroyDList(dl); // xóa bản không được lưu
						copyDList(dl, temp_dl); //khôi phục lại từ bản sao
						printf("Khong luu file nen hoan tac lenh vua thuc thi");
						getchar();
						getchar();
						break;
					}
					if (choicesave < 1 || choicesave > 2)
						printf("Chi nhap 1 hoac 2\nVui long nhap lai!\n");
				} while (choicesave < 1 || choicesave > 2);
			}
			break;
		case 5:
			printf("Nhap vao chuoi can tim: ");
			fflush(stdin);
			fgets(str, 30, stdin);
			countString(dl, str);
			printf("\n");
			system("pause");
			break;
		case 6:
			bubbleSort(dl);
			printf("\n");
			system("pause");
			break;
		case 7:
			findAuthorWithMostBooks(dl);
			printf("\n");
			system("pause");
			break;
		case 8:
			findPublisherWithLeastBooks(dl);
			printf("\n");
			system("pause");
			break;
		case 9:
			printBooksByYear(dl);
			printf("\n");
			system("pause");
			break;
		case 10:
			printBooksByGenre(dl);
			printf("\n");
			system("pause");
			break;
		case 11:
			showDlist(dl);
			printf("\n");
			system("pause");
			break;
		case 12:
			do {
				printf("them dau (1) | them vao sau (2) | them cuoi (3): ");
				scanf("%d", &add);
				if (add < 1 || add > 3)
					printf("Khong tim thay chuc nang!\nVui long nhap lai!\n");
			} while (add < 1 || add > 3);
			copyDList(temp_dl, dl); //sao chép dữ liệu sang dslk tạm
			if (xulythem(dl, add) == 1) {
				do
				{
					printf("Luu du lieu vao file moi? \n(1: Yes / 2: No): ");
					scanf("%d", &choicesave);
					if (choicesave == 1) {
						writeListToFile(dl, file_out);
						printf("\nLuu file thanh cong!");
						break;
					}
					else if (choicesave == 2)
					{
						destroyDList(dl);// xóa dslk không được lưu
						copyDList(dl, temp_dl);//khôi phục từ bản sao
						printf("Khong luu file nen hoan tac lenh vua thuc thi");
						getchar();
						/*getchar();*/
						break;
					}
					if (choicesave < 1 || choicesave > 2)
						printf("Chi nhap 1 hoac 2\nVui long nhap lai!\n");
				} while (choicesave < 1 || choicesave > 2);
			}
			break;
		case 13:
			printf("Danh sach sau khi in dao nguoc la :");
			reverseDList(dl);
			system("pause");
			break;
		}
	} while (lc != 0);
}
//**************************************************************************************************
void main()
{
	loading();
	process();
	getchar();
}