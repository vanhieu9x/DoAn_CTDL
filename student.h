//// danh s�ch sinh vi�n
//
//#define _STUDENT_H
//#include"creditclass.h"
//
//struct student{
//	char idStudent[13];
//	char idClass[16];
//	char fistName[21], lastName[11];
//	int sex = 1; // 1 male, 2 female
//	char phoneNUmber[13];
//	int yearAdmission; // nam nhap hoc
//	float mediumScore = 0;	
//};
//typedef struct student STUDENT;
//
//struct NodeStudent{
//	STUDENT _student;
//	struct NodeStudent *pNext;
//};
//typedef struct NodeStudent NODE_STUDENT;
//
//struct ListStudent{
//	int n = 0;
//	NODE_STUDENT *pHead, *pTail;
//};
//typedef struct ListStudent LIST_STUDENT;
//
//NODE_STUDENT* GetNodeStudent(STUDENT DATA)
//{
//	NODE_STUDENT *p = new NodeStudent; //init pointer
//	if (p == NULL)
//		return NULL;
//	p->_student = DATA; // export data to node;
//	p->pNext = NULL; //init link list
//	return p;
//}
//
//void InitListStudent(LIST_STUDENT &l)
//{
//	l.pHead = l.pTail = NULL;	
//}
//
//void AddHeadListStudent(LIST_STUDENT &l, STUDENT data)
//{
//
//	NODE_STUDENT *p = GetNodeStudent(data);
//	p->pNext = l.pHead;
//	l.pHead = p;
//
//	++l.n;
//}
//
//bool ListStudentIsEmty(LIST_STUDENT l)
//{
//	return l.pHead = NULL;	
//}
//
//void AddTailListStudent(LIST_STUDENT &l, STUDENT data)
//{
//	NODE_STUDENT* p = GetNodeStudent(data);
//	if(l.pHead == NULL)
//	{
//		l.pHead = l.pTail = p;		
//	}
//	else
//	{
//		l.pTail->pNext = p;
//		l.pTail = p;	
//	}
//
//	++l.n;	
//}
//
//NODE_STUDENT* FindStudent(LIST_STUDENT l, char* id)
//{
//	if(l.pHead == NULL) return NULL;
//	
//	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
//		if (strcmp(p->_student.idStudent, id) == 0)
//			return p;
//	return NULL;
//}
//
//NODE_STUDENT* Middle(NODE_STUDENT* start, NODE_STUDENT* last)
//{
//	if (start == NULL)
//		return NULL;
//	NODE_STUDENT * slow = start;
//	NODE_STUDENT * fast = start->pNext;
//
//	while (fast != last)
//	{
//		fast = fast->pNext;
//		if (fast != last)
//		{
//			slow = slow->pNext;
//			fast = fast->pNext;
//		}
//	}
//	return slow;
//}
//
//NODE_STUDENT* BinarySearchStudent(LIST_STUDENT l, char* id)
//{ 
//	NODE_STUDENT* start = l.pHead;
//	NODE_STUDENT* last = NULL;
//	if(l.pHead == NULL) return NULL;
//	do
//	{	
//		NODE_STUDENT* p = Middle(start, last);
//		
//		if(p == NULL) return NULL;
//		
//		if (strcmp(p->_student.idStudent, id) == 0)
//			return p;		
//		else if (strcmp(p->_student.idStudent, id) < 0)
//		{		
//				
//			start = p->pNext;			
//		}
//		else
//		{	
//		
//			last = p;
//		}
//	} 
//	while ( start != last);
//	return NULL; // value not present;
//
//}
//
//int FindIndexStudent(LIST_STUDENT l, char *id)
//{
//	int index = -1;
//	if(l.pHead == NULL) return -1;
//	for(NODE_STUDENT *p = l.pHead; p != NULL; p = p->pNext)
//	{
//		++index;
//		if(strcmp(p->_student.idStudent, id) == 0);
//			return index;
//	}
//	return 0;
//}
//
//NODE_STUDENT* FindStudentByOrdinal(LIST_STUDENT l, int ordinal)
//{
//	if (l.pHead == NULL) return NULL;
//	if (l.n -1 < ordinal) return NULL;
//	if (l.n - 1 == ordinal) return l.pTail;
//	if (ordinal == 0) return l.pHead;
//	
//	NODE_STUDENT* p = l.pHead;
//	int count = 0;
//	while(count != ordinal)
//	{
//		p = p->pNext;
//		count++;
//	}
//	return p;
//}
//
//
//void InsertAfter(NODE_STUDENT* p, STUDENT &data)
//{
//	if(p == NULL) return;
//	NODE_STUDENT* q = new NODE_STUDENT;
//	
//	q->_student = data;
//	q->pNext = p->pNext;
//	p->pNext = q;
//}
//
//void InsertOrderForListStudent(LIST_STUDENT &l, STUDENT data)
//{
//	if(l.pHead == NULL)
//	{	
//		AddHeadListStudent(l, data);
//		return;
//	}
//	
//	NODE_STUDENT *p, *pAfter, *pBefore;	
//	p = GetNodeStudent(data);
//	
//	for(pAfter = l.pHead; pAfter != NULL && (strcmp(pAfter->_student.idStudent, data.idStudent) < 0); pBefore = pAfter, pAfter = pAfter->pNext);
//	
//	if(pAfter == l.pHead) 
//	{
//		AddHeadListStudent(l, p->_student);
//		return;
//
//	}
//	else
//	{
//		p->pNext = pAfter;
//		pBefore->pNext = p;
//		l.n++;
//		return;
//	}
//	
//}
//
//bool IsDeletedHead(LIST_STUDENT &l)
//{
//	if(ListStudentIsEmty(l)) return false;
//	NODE_STUDENT *p =l.pHead; 
//	
//	l.pHead = p->pNext;
//	delete p;
//	--l.n;
//	return true;
//}
//
//bool IsDeletedTail(LIST_STUDENT &l)
//{
//	if(ListStudentIsEmty(l)) return false;
//	
//	NODE_STUDENT *beforeP = NULL;
//	for (NODE_STUDENT *p = l.pHead; p != NULL; p = p->pNext)
//	{
//		if (p == l.pTail)
//		{
//			l.pTail = beforeP;
//			beforeP->pNext = NULL;
//			delete p;
//						
//			--l.n;
//			return true;
//		}
//		beforeP = p;
//	}
//}
//
//bool IsDeletedAfter(LIST_STUDENT &l, NODE_STUDENT*p)
//{
//	if (p == NULL || p->pNext == NULL) return false;
//	NODE_STUDENT* nodeDeleted = p->pNext;
//	p->pNext = nodeDeleted->pNext;
//	delete nodeDeleted;
//	--l.n;
//	return true;
//}
//
//bool IsDeletedStudentWithId(LIST_STUDENT &l, STUDENT data)
//{
//	NODE_STUDENT* nodeDeleted = BinarySearchStudent(l, data.idStudent);   //FindStudent(l, data.idStudent);
//	if (nodeDeleted == NULL) return false;
//	if (nodeDeleted == l.pHead) return IsDeletedHead(l);
//	if (nodeDeleted == l.pTail) return IsDeletedTail(l);
//	else
//	{
//		NODE_STUDENT* temp = l.pHead;
//		while (temp->pNext != nodeDeleted)
//			temp = temp->pNext;
//		return IsDeletedAfter(l,temp);
//	}
//}
//
//// xoa danh sach Sinh vien
//bool ClearListStudent(LIST_STUDENT &l)
//{
//	if (l.pHead) return false;
//	NODE_STUDENT* temp;
//	while (l.pHead != NULL)
//	{
//		temp = l.pHead;
//		l.pHead = l.pHead->pNext;
//		delete temp;
//	}
//	return true;
//}
//
//void OutputStudent(STUDENT st, int locate)
//{
//	DeleteOldData(sizeof(keyDisplayStudent) / sizeof(string), locate);
//	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + locate); cout << st.idStudent;
//	
//	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + locate); cout << st.fistName;
//	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + locate); cout << st.lastName;
//	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + locate);
//	if(st.sex == 1)cout << "Nam";
//	else cout << "Nu";
//	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + locate); cout << st.phoneNUmber;
//	Gotoxy(xKeyDisplay[5] + 1, Y_DISPLAY + 3 + locate); cout << st.yearAdmission;
//}
//
//void OutputListStudentWithIdClassPerPage(LIST_STUDENT l, int indexBegin)
//{		
//	if(l.pHead == NULL && l.pTail == NULL) return;
//	int count = -1;	
//	for(NODE_STUDENT* q = l.pHead; q != NULL; q = q->pNext)
//	{
//		count++;
//		if(count == indexBegin)
//		{
//			int i = -1;
//			while(q != NULL && i < QUANTITY_PER_PAGE - 1)
//			{
//				OutputStudent(q->_student, (++i) * 2);
//				q = q->pNext;
//			}	
//			break;		
//		}			
//	}
//	
//	Gotoxy(X_PAGE, Y_PAGE);
//	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
//}
//
//bool DataStudentIsEmty(STUDENT st)
//{
//	if(strlen(st.idClass) == 0)return true;
//	if(strlen(st.idStudent) == 0) return true;	
//	return false;
//}
//
//void InputStudent(LIST_STUDENT &l, STUDENT &st, bool isEdited = false)
//{
//	ShowCur(true);
//	int ordinal = 0;
//	bool isMoveUp = false;
//	bool isSave = false;
//	bool idIsExist = false;
//	
//	string idStudent, firstName, lastName, phoneNumber;
//	int yearAdmission = 0, sex = 0;
//	
//	if(isEdited)
//	{		
//		idStudent = st.idStudent;
//		firstName = st.fistName;
//		lastName = st.lastName;
//		phoneNumber = st.phoneNUmber;
//		yearAdmission = st.yearAdmission;
//		sex = st.sex;
//		
//		
//		Gotoxy(X_ADD  + 20 + 7, 0 * 3 + Y_ADD);
//		cout << idStudent;
//		Gotoxy(X_ADD + 17 + 7, 1 * 3 + Y_ADD);
//		cout << firstName;
//		Gotoxy(X_ADD + 18 + 7, 2 * 3 + Y_ADD);
//		cout << lastName;		
//		Gotoxy(X_ADD + 19 + 7, 3 * 3 + Y_ADD);
//		cout << sex;
//		Gotoxy(X_ADD + 20 + 7, 4 * 3 + Y_ADD);
//		cout << phoneNumber;
//		Gotoxy(X_ADD + 21 + 7, 5 * 3 + Y_ADD);
//		cout << yearAdmission;		
//	}
//		
//	while(true)
//	{
//		switch(ordinal)
//		{
//			case 0:
//				if(isEdited) break;
//				CheckMoveAndValidateID(idStudent, isMoveUp, ordinal, isSave, 20 + 7, 12);				
//				if(FindStudent(l, (char *)idStudent.c_str()) == NULL)
//				{
//					idIsExist = false;
//					break;
//				}
//				idIsExist = true;
//				
//				break;
//			case 1:
//				CheckMoveAndValidateNameSubject(firstName, isMoveUp, ordinal, isSave, 17 + 7, 20);
//				break;
//			case 2:
//				CheckMoveAndValidateNameSubject(lastName, isMoveUp, ordinal, isSave, 18 + 7, 10);
//				break;
//			case 3:
//				CheckMoveAndValidateNumber(sex, isMoveUp, ordinal, isSave, 19 + 7, 2);
//				break;
//			case 4:
//				CheckMoveAndValidateID(phoneNumber, isMoveUp, ordinal, isSave, 20 + 7, 11);
//				break;
//			case 5:
//				CheckMoveAndValidateNumber(yearAdmission, isMoveUp, ordinal, isSave, 21 + 7, 2019);
//				break;	
//		}
//		
//		if (isMoveUp)
//		{
//			if (ordinal == 0)
//				isMoveUp = false;
//			ordinal--;
//		}
//		else
//		{
//			if (ordinal == 5)
//				isMoveUp = true;
//			ordinal++;
//		}		
//		if(isSave)
//		{	
//			Gotoxy(X_NOTIFY, Y_NOTIFY);			
//			cout << setw(50) << setfill(' ') << " ";
//			trim(firstName);
//			trim(lastName);
//			StandarString(firstName);
//			StandarString(lastName);
//		
//			if(sex == 0 || firstName.empty() || lastName.empty() || yearAdmission == 0 || phoneNumber.empty() )
//			{
//				Gotoxy(X_NOTIFY, Y_NOTIFY);
//				cout << "Cac truong du lieu khong dc de trong";
//			}
//			else if(idIsExist)
//			{
//				Gotoxy(X_NOTIFY, Y_NOTIFY);
//				cout << "Ma sinh vien khong duoc trung";
//			}
//			else
//			{
//				
//										
//				strcpy(st.idStudent, idStudent.c_str());				
//				strcpy(st.fistName, firstName.c_str());
//				strcpy(st.lastName, lastName.c_str());
//				strcpy(st.phoneNUmber, phoneNumber.c_str());
//				st.sex = sex;
//				
//				st.yearAdmission = yearAdmission;
//				StandardName(st.lastName);
//				StandardName(st.fistName);
//				
//				if(isEdited)
//				{
//					NODE_STUDENT* p = FindStudent(l, st.idStudent);
//					p->_student = st;
//				}else
//				{				
//					InsertOrderForListStudent(l, st);				
//				}
//				totalPageStudent =((l.n - 1) / QUANTITY_PER_PAGE) + 1;
//				DeleteMenuAdd();
//				return;		
//			}
//			isSave = false;
//		}
//		else
//		{
//			isSave = false;
//		}
//	}
//	ShowCur(false);
//}
//
//void SetDefaultChooseStudent(STUDENT st, int ordinal)
//{
//	SetBGColor(GREEN);
//	OutputStudent(st, (ordinal % QUANTITY_PER_PAGE) * 2);
//	SetBGColor(PURPLE);
//}
//
//void EffectiveMenuStudent(int ordinal, STUDENT stnew, STUDENT stold)
//{
//	int current = ordinal;
//	SetDefaultChooseStudent(stnew, current);
//	OutputStudent(stold, (currposPrecStudent % QUANTITY_PER_PAGE) * 2);
//	currposPrecStudent = current;
//}
//
//void ChangePageChooseStudent(LIST_STUDENT l)
//{
//	clrscr();
//	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
//	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
//	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
//}
//
//NODE_STUDENT* ChooseStudent(LIST_STUDENT l)
//{
//	int keyboard_read = 0;
//	ShowCur(false);
//	pageNowStudent = 1;
//	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
//	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
//	totalPageStudent = ((l.n-1) / QUANTITY_PER_PAGE) + 1;
//	
//	NODE_STUDENT* newNodeStudent = FindStudentByOrdinal(l, currposStudent);
//	NODE_STUDENT* oldNodeStudent = NULL;
//	
//	OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
//	SetDefaultChooseStudent(newNodeStudent->_student, currposStudent);
//	
//	while(true)
//	{
//		keyboard_read = _getch();
//		if (keyboard_read == 0)
//			keyboard_read = _getch();
//		switch (keyboard_read)
//		{
//			case KEY_UP:
//				if(currposStudent % QUANTITY_PER_PAGE > 0)
//				{
//					currposStudent = currposStudent - 1;
//					oldNodeStudent = newNodeStudent;
//					for(newNodeStudent = l.pHead; newNodeStudent->pNext != oldNodeStudent; newNodeStudent = newNodeStudent->pNext);
//					EffectiveMenuStudent(currposStudent, newNodeStudent->_student, oldNodeStudent->_student);				
//				}
//				break;
//			case KEY_DOWN:
//				if(currposStudent % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && newNodeStudent->pNext != NULL)
//				{
//					currposStudent = currposStudent + 1;
//					oldNodeStudent = newNodeStudent;;
//					newNodeStudent = newNodeStudent->pNext;
//					EffectiveMenuStudent(currposStudent, newNodeStudent->_student, oldNodeStudent->_student);
//				}
//				break;
//			case PAGE_DOWN:
//				if(pageNowStudent < totalPageStudent)
//				{
//					pageNowStudent++;
//					ChangePageChooseStudent(l);
//					OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
//					
//					newNodeStudent = FindStudentByOrdinal(l, currposStudent);
//					SetDefaultChooseStudent(newNodeStudent->_student, currposStudent);				
//				}
//				break;
//			case PAGE_UP:
//				if(pageNowStudent > 1)
//				{
//					pageNowStudent--;
//					ChangePageChooseStudent(l);
//					OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
//					newNodeStudent = FindStudentByOrdinal(l, currposStudent);
//					SetDefaultChooseStudent(newNodeStudent->_student, currposStudent);
//				}
//				break;
//			case ENTER:  //enter
//				ShowCur(true);
//				return newNodeStudent;
//				break;
//			case 27: 
//				return NULL; 
//				break;	
//		}
//	}	
//}
//
//void ChangePageManageStudent(LIST_STUDENT l, string idClass)
//{
//	Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass ;
//	OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);	
//	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
//}
//
//void MenuManagerStudent(LIST_STUDENT &l)
//{
//backMenu:
//	clrscr();
//	int key;
//	string idClass;
//	Gotoxy(X_TITLE, Y_TITLE);
//	cout << "NHAP VAO MA LOP CAN QUAN LY: ";
//	
//	DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
//	CheckMoveAndValdateIdClass(idClass, 28);
//	Gotoxy(X_NOTIFY - 10, Y_NOTIFY);
//	cout << "BAN CO MUON SUA LAI MA LOP";
//	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
//	cout <<"ENTER: TIEO TUC - ESC: THOAT - AN PHIM BAT KI DE NHAP LAI";
//	
//	key = _getch();
//	if(key == ESC)
//		return;
//	else if(key == ENTER)
//	{
//		clrscr();
//		LIST_STUDENT temp;
//		InitListStudent(temp);
//		int n = 0;
//		for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
//		{
//			if(strcmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
//			{
//				AddTailListStudent(temp, p->_student);
//				n++;				
//			}
//		}
//		pageNowStudent = 1;
//		totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
//		OutputListStudentWithIdClassPerPage(temp, 0);
//		
//		Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
//		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass ;
//		
//		while(true)
//		{
//			while(_kbhit())
//			{
//				key = _getch();
//				if (key == 0 || key == 224)
//				{
//					key = _getch();
//					if(key == KEY_F2)
//					{	
//						STUDENT st;
//						strcpy(st.idClass, idClass.c_str());
//						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
//						InputStudent(l, st, false);
//						if(strlen(st.idStudent) == 0) return;
//												
//						//InsertOrderForListStudent(l, st);
//						InsertOrderForListStudent(temp, st);
//						
//						n++;
//						totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
//						clrscr();
//						ChangePageManageStudent(temp, idClass);
//						Gotoxy(X_NOTIFY, Y_NOTIFY);
//						cout << "Them thanh cong";
//					}
//					else if( key == KEY_F3)
//					{
//						NODE_STUDENT* k = ChooseStudent(temp);
//						if(k == NULL) goto backMenu;
//						
//						Gotoxy(X_NOTIFY, Y_NOTIFY);
//						cout << "Ban co chac chan xoa? Enter dong y";
//						key = _getch();
//						if(key == ENTER)
//						{
//							string temps = k->_student.idStudent;
//							NODE_STUDENT* p = FindStudent(l, (char*)temps.c_str());
//							IsDeletedStudentWithId(l, p->_student);
//							if(IsDeletedStudentWithId(temp, k->_student))
//							{
//								n--;
//								totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
//								if(n % QUANTITY_PER_PAGE == 0) pageNowStudent--;
//								clrscr();
//								ChangePageManageStudent(temp, idClass);
//								Gotoxy(X_NOTIFY, Y_NOTIFY);
//								cout << "Xoa thanh cong";
//							}
//						}else goto backMenu;
//					}
//					else if( key == KEY_F4)
//					{
//						NODE_STUDENT* k = ChooseStudent(temp);
//						if(k == NULL) goto backMenu;
//						
//						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
//						InputStudent(l, k->_student, true);
//				
//						NODE_STUDENT* p = BinarySearchStudent(l, k->_student.idStudent);
//						p = k;
//						
//						clrscr();
//						ChangePageManageStudent(temp, idClass);
//						Gotoxy(X_NOTIFY, Y_NOTIFY);
//						cout << "Sua thanh cong";
//					}
//					else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
//					{
//						pageNowStudent++;
//						clrscr();
//						ChangePageManageStudent(temp, idClass);
//					}
//					else if(key == PAGE_UP && pageNowStudent > 1)
//					{
//						pageNowStudent--;
//						clrscr();
//						ChangePageManageStudent(temp, idClass);
//					}
//				}
//				else if(key == ESC)
//				{
//					ClearListStudent(temp);
//					return;
//				}
//			}			
//		}
//	}
//	else
//	 goto backMenu;	
//}
//
//#endif



#define MAXLIST 5000
#include"constant.h"
#include"globalvariable.h"
#include"display.h"
#include"validate.h"
#include<iostream>
#include<cstring>
#include<string>
struct student{
	char idStudent[16];
	char idClass[16];
	char fistName[21], lastName[11];
	int sex = 1; // 1 male, 2 female
	char phoneNUmber[13];
	int yearAdmission; // nam nhap hoc
	float mediumScore = 0;	
};
typedef struct student STUDENT;

struct ListSV
{			
	STUDENT nodes[MAXSV];
	int n=0;
};

bool isEmpty (ListSV pList)
{
  return (pList.n == 0 ? TRUE : FALSE);
};

bool isFull (ListSV pList)
{
  return (pList.n == MAXLIST ? TRUE : FALSE);
};

int checkId(ListSV &ds, char s[]){
	for(int i=0; i<ds.n;i++)
		if(strcmp(ds.nodes[i].idStudent, s)==0)
			return 1;
	return 0;
}
// Them sinh vien vao vi tri thu i trong danh sach
int insertSV(ListSV &ds, int i, STUDENT sv){
	if(i<0||ds.n==MAXLIST||i>ds.n)
		return 0;
	else
		for(int j=ds.n-1; j>=i;j++){
			ds.nodes[j+1]=ds.nodes[j];
		}
		ds.nodes[i]=sv;
		ds.n++;
		return 1;
}

//tạm viết
void InsertOrderForListStudent(ListSV &ds, STUDENT sv){
	insertSV(ds, 0, sv);
}

//delete vị trí thứ i
void DeleteByOrdinal (struct ListSV &ds, int i)
{
  int j;
  int temp;
  if (i <= 0 || i > ds.n || isEmpty(ds))
  {
    return;
  }
  for (j = i; j < ds.n; j++)
  {
    ds.nodes[j-1] = ds.nodes[j];
  }
  ds.n--;
}

// Xoa sinh vien theo ma sinh vien
int deleteSV(ListSV &ds, char* s){
	if(ds.n==0)
		return 0;
	else{
		for(int i=1;i<ds.n;i++){
			if(strcmp(ds.nodes[i].idStudent, s)==0){
				for(int j=i; j<ds.n; j++){
					ds.nodes[j]=ds.nodes[j+1];
				}
				//delete ds.nodes[ds.n];
				int sizeDs = ds.n;
				DeleteByOrdinal(ds, sizeDs);
			}
		}
		ds.n--;
		return 1;
	}
}

// dung selection sort

void swapSV(STUDENT &a, STUDENT &b){
	STUDENT temp = a;
	a=b;
	b=temp;
}
void selectionSortSV(ListSV &ds){
	int min;
	STUDENT temp;
	for(int i=0;i<ds.n;i++){
		min = i;
		for(int j= i+1; j<ds.n; j++){
			if(strcmp(ds.nodes[j].lastName, ds.nodes[min].lastName)<0)
				min = j;
		}
		if(min!=i)
			swapSV(ds.nodes[i], ds.nodes[min]);
	}
}


int FindIndexStudent(ListSV ds, char* ma){
	if(ds.n==0) return -1;
	else{
		for(int i=0; i<ds.n; i++){
			if(strcmp(ds.nodes[i].idStudent, ma)==0)
				return i;
		}
	}
	return -1;
}

STUDENT BinarySearchStudent(ListSV ds, char* id){
	if(!isEmpty(ds))
		for(int i= 0; i<ds.n;i++){
			if(strcmp(ds.nodes[i].idStudent, id)==0)
				return ds.nodes[i];
		}
}

STUDENT FindStudent(ListSV ds, char* id)
{
	if(!isEmpty(ds))
		for(int i= 0; i<ds.n;i++){
			if(strcmp(ds.nodes[i].idStudent, id)==0)
				return ds.nodes[i];
		}
	else{
		STUDENT st;
		st.sex = -1;
		return st;
	}
}

STUDENT FindStudentByOrdinal(ListSV ds, int ordinal){
	if(!isEmpty(ds)&&ds.n-1>=ordinal) 
	{
		return ds.nodes[ordinal];
	}
}

bool isDelete(ListSV &ds, int ordinal){
	if(ds.n==0||ds.n<ordinal) return false;
	
	DeleteByOrdinal(ds, ordinal);
	
	for(int i=ordinal; i<ds.n - ordinal;i++){
		ds.nodes[i]=ds.nodes[i+1];
	}
	ds.n=ds.n-1;
	return true;
}

bool IsDeletedStudentWithId(ListSV &ds, STUDENT data){
	if(ds.n==0) return false;
	int index = FindIndexStudent(ds, data.idStudent);
	if(index > -1){
		return isDelete(ds, index);
	}else return false;
}

bool ClearListStudent(ListSV &ds){
	for(int i = 0; i<ds.n; i++)
		DeleteByOrdinal(ds, i);
		
	ds.n=0;
}

void OutputStudent(STUDENT sv, int locate){
	DeleteOldData(sizeof(keyDisplayStudent)/sizeof(string), locate);
	Gotoxy(xKeyDisplay[0]+1, Y_DISPLAY + 3 + locate); cout<<sv.idStudent;
	Gotoxy(xKeyDisplay[1]+1, Y_DISPLAY + 3 + locate); cout<<sv.fistName;
	Gotoxy(xKeyDisplay[2]+1, Y_DISPLAY + 3 + locate); cout<<sv.lastName;
	Gotoxy(xKeyDisplay[3]+1, Y_DISPLAY + 3 + locate);
	if(sv.sex == 1) cout<<"Nam";
	else cout<<"Nu";
	Gotoxy(xKeyDisplay[4]+1, Y_DISPLAY + 3 + locate); cout<<sv.phoneNUmber;
	Gotoxy(xKeyDisplay[5]+1, Y_DISPLAY + 3 + locate); cout<<sv.idClass;
}

void OutputListStudentWithIdClassPerPage(ListSV ds, int indexBegin){
	if(ds.n==0) return;
	int count = -1;
	for(int i = 0 ; i<ds.n; i++){
		count++;
		if(count == indexBegin){
			int j= -1;
			while(i<QUANTITY_PER_PAGE - 1&&i<ds.n){
				OutputStudent(ds.nodes[i], (++j)*2);
				i++;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout<<"Trang "<< pageNowStudent<<"/"<<totalPageStudent;
}

void InputStudent(ListSV &ds, STUDENT sv, bool isEdited = false){
	ShowCur(true);
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;
	
	string idStudent, firstName, lastName, idClass, phoneNumber;
	int yearAdmission = 0, sex = 0;
	
	if(isEdited){
		idStudent = sv.idStudent;
		firstName = sv.fistName;
		lastName = sv.lastName;
		idClass = sv.idClass;
		sex = sv.sex;
		phoneNumber = sv.phoneNUmber;
		
		Gotoxy(X_ADD  + 20 + 7, 0 * 3 + Y_ADD);
		cout << idStudent;
		Gotoxy(X_ADD + 17 + 7, 1 * 3 + Y_ADD);
		cout << firstName;
		Gotoxy(X_ADD + 18 + 7, 2 * 3 + Y_ADD);
		cout << lastName;		
		Gotoxy(X_ADD + 19 + 7, 3 * 3 + Y_ADD);
		cout << sex;
		Gotoxy(X_ADD + 20 + 7, 4 * 3 + Y_ADD);
		cout << phoneNumber;
		Gotoxy(X_ADD + 21 + 7, 5 * 3 + Y_ADD);
		cout << idClass;
	}
	while(true){
		switch(ordinal){
			case 0:
				if(isEdited) break;
				CheckMoveAndValidateID(idStudent, isMoveUp, ordinal, isSave, 20 + 7, 12);
				if(FindStudent(ds, (char *)idStudent.c_str()).sex != -1){
					idIsExist = false;
					break;
				}
				idIsExist = true;
				break;
			case 1:
				CheckMoveAndValidateNameSubject(firstName, isMoveUp, ordinal, isSave, 17+7, 20);
				break;
			case 2:
				CheckMoveAndValidateNameSubject(lastName, isMoveUp, ordinal, isSave, 18+7, 10);
				break;
			case 3:
				CheckMoveAndValidateNumber(sex, isMoveUp, ordinal, isSave, 19+7, 2);
				break;
			case 4:
				CheckMoveAndValidateID(phoneNumber, isMoveUp, ordinal, isSave, 20+7,11);
				break;
			case 5:
				CheckMoveAndValidateNumber(yearAdmission, isMoveUp, ordinal, isSave, 21 + 7, 2019);
				break;
		}
		if(isMoveUp){
			if(ordinal == 0);
				isMoveUp = false;
			ordinal--;
		}
		else{
			if(ordinal == 5)
				isMoveUp = true;
			ordinal++;
		}
		if(isSave){
			Gotoxy(X_NOTIFY, Y_NOTIFY);
			cout<< setw(50)<<setfill(' ')<<" ";
			trim(firstName);
			trim(lastName);
			StandarString(firstName);
			StandarString(lastName);
			
			if(sex==0 || firstName.empty()|| lastName.empty()|| phoneNumber.empty())
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout<<"Cac truong du lieu khong duoc de trong";
			} 
			else if(idIsExist){
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout<<"Ma sinh vien khong duoc trung";
			}
		}
		
		if (isMoveUp)
		{
			if (ordinal == 0)
				isMoveUp = false;
			ordinal--;
		}
		else
		{
			if (ordinal == 5)
				isMoveUp = true;
			ordinal++;
		}		
		if(isSave)
		{	
			Gotoxy(X_NOTIFY, Y_NOTIFY);			
			cout << setw(50) << setfill(' ') << " ";
			trim(firstName);
			trim(lastName);
			StandarString(firstName);
			StandarString(lastName);
		
			if(sex == 0 || firstName.empty() || lastName.empty() || yearAdmission == 0 || phoneNumber.empty() )
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Cac truong du lieu khong dc de trong";
			}
			else if(idIsExist)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Ma sinh vien khong duoc trung";
			}
			else
			{						
				strcpy(sv.idStudent, idStudent.c_str());				
				strcpy(sv.fistName, firstName.c_str());
				strcpy(sv.lastName, lastName.c_str());
				strcpy(sv.phoneNUmber, phoneNumber.c_str());
				sv.sex = sex;
				
				sv.yearAdmission = yearAdmission;
				StandardName(sv.lastName);
				StandardName(sv.fistName);
				
				if(isEdited)
				{
					STUDENT p = sv;
				}else
				{				
					InsertOrderForListStudent(ds, sv);				
				}
				totalPageStudent =((ds.n - 1) / QUANTITY_PER_PAGE) + 1;
				DeleteMenuAdd();
				return;		
			}
			isSave = false;
		}
		else
		{
			isSave = false;
		}
	}
	ShowCur(false);
}

void SetDefaultChooseStudent(STUDENT st, int ordinal)
{
	SetBGColor(GREEN);
	OutputStudent(st, (ordinal % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
}

void EffectiveMenuStudent(int ordinal, STUDENT stnew, STUDENT stold)
{
	int current = ordinal;
	SetDefaultChooseStudent(stnew, current);
	OutputStudent(stold, (currposPrecStudent % QUANTITY_PER_PAGE) * 2);
	currposPrecStudent = current;
}

void ChangePageChooseStudent(ListSV ds)
{
	clrscr();
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
}

STUDENT ChooseStudent(ListSV ds)
{
	int keyboard_read = 0;
	ShowCur(false);
	pageNowStudent = 1;
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	totalPageStudent = ((ds.n-1) / QUANTITY_PER_PAGE) + 1;
	
	STUDENT newNodeStudent = FindStudentByOrdinal(ds, currposStudent);
	STUDENT oldNodeStudent;
	
	OutputListStudentWithIdClassPerPage(ds, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	SetDefaultChooseStudent(newNodeStudent, currposStudent);
	
	while(true)
	{
		keyboard_read = _getch();
		if (keyboard_read == 0)
			keyboard_read = _getch();
		switch (keyboard_read)
		{
			case KEY_UP:
				if(currposStudent % QUANTITY_PER_PAGE > 0)
				{
					currposStudent = currposStudent - 1;
					oldNodeStudent = newNodeStudent;
					//for(newNodeStudent = l.pHead; newNodeStudent->pNext != oldNodeStudent; newNodeStudent = newNodeStudent->pNext);
					for(int i= 0; i<ds.n;i++){
						newNodeStudent = ds.nodes[i];
						if(newNodeStudent.idStudent != oldNodeStudent.idStudent) break;
					}
					EffectiveMenuStudent(currposStudent, newNodeStudent, oldNodeStudent);				
				}
				break;
			case KEY_DOWN:
				if(currposStudent % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && ds.n >= currposStudent + 1)
				{
					currposStudent = currposStudent + 1;
					oldNodeStudent = newNodeStudent;
					newNodeStudent = ds.nodes[currposStudent];
					EffectiveMenuStudent(currposStudent, newNodeStudent, oldNodeStudent);
				}
				break;
			case PAGE_DOWN:
				if(pageNowStudent < totalPageStudent)
				{
					pageNowStudent++;
					ChangePageChooseStudent(ds);
					OutputListStudentWithIdClassPerPage(ds, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
					
					newNodeStudent = FindStudentByOrdinal(ds, currposStudent);
					SetDefaultChooseStudent(newNodeStudent, currposStudent);				
				}
				break;
			case PAGE_UP:
				if(pageNowStudent > 1)
				{
					pageNowStudent--;
					ChangePageChooseStudent(ds);
					OutputListStudentWithIdClassPerPage(ds, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
					newNodeStudent = FindStudentByOrdinal(ds, currposStudent);
					SetDefaultChooseStudent(newNodeStudent, currposStudent);
				}
				break;
			case ENTER:  //enter
				ShowCur(true);
				return newNodeStudent;
				break;
			case 27: 
				STUDENT st;
				st.sex = -1;
				return st; 
				break;	
		}
	}	
}

void ChangePageManageStudent(ListSV ds, string idClass)
{
	Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass ;
	OutputListStudentWithIdClassPerPage(ds, (pageNowStudent - 1) * QUANTITY_PER_PAGE);	
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
}

void MenuManagerStudent(ListSV &ds)
{
backMenu:
	clrscr();
	int key;
	string idClass;
	Gotoxy(X_TITLE, Y_TITLE);
	cout << "NHAP VAO MA LOP CAN QUAN LY: ";
	
	DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
	CheckMoveAndValdateIdClass(idClass, 28);
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY);
	cout << "BAN CO MUON SUA LAI MA LOP";
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
	cout <<"ENTER: TIEO TUC - ESC: THOAT - AN PHIM BAT KI DE NHAP LAI";
	
	key = _getch();
	if(key == ESC)
		return;
	else if(key == ENTER)
	{
		clrscr();
		ListSV temp;
		//InitListStudent(temp);
		int n = 0;
		// for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
		// {
		// 	if(strcmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
		// 	{
		// 		AddTailListStudent(temp, p->_student);
		// 		n++;				
		// 	}
		// }
		for(int i=0; i<ds.n; i++){
			if(strcmp(ds.nodes[i].idClass, (char*)idClass.c_str())==0){
				temp.nodes[n] = ds.nodes[i];
				n++;
				temp.n = n;
			}
		}
		pageNowStudent = 1;
		totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
		OutputListStudentWithIdClassPerPage(temp, 0);
		
		Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass ;
		
		while(true)
		{
			while(_kbhit())
			{
				key = _getch();
				if (key == 0 || key == 224)
				{
					key = _getch();
					if(key == KEY_F2)
					{	
						STUDENT st;
						strcpy(st.idClass, idClass.c_str());
						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
						InputStudent(ds, st, false);
						if(strlen(st.idStudent) == 0) return;
						
						InsertOrderForListStudent(temp, st);
						
						n++;
						totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
						clrscr();
						ChangePageManageStudent(temp, idClass);
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Them thanh cong";
					}
					else if( key == KEY_F3)
					{
						STUDENT k = ChooseStudent(temp);
						if(k.sex == -1) goto backMenu;
						
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Ban co chac chan xoa? Enter dong y";
						key = _getch();
						if(key == ENTER)
						{
							string idSt = k.idStudent;
							STUDENT p = FindStudent(ds, (char*)idSt.c_str());
							IsDeletedStudentWithId(ds, p);
							if(IsDeletedStudentWithId(temp, k))
							{
								n--;
								totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
								if(n % QUANTITY_PER_PAGE == 0) pageNowStudent--;
								clrscr();
								ChangePageManageStudent(temp, idClass);
								Gotoxy(X_NOTIFY, Y_NOTIFY);
								cout << "Xoa thanh cong";
							}
						}else goto backMenu;
					}
					else if( key == KEY_F4)
					{
						STUDENT k = ChooseStudent(temp);
						if(k.sex == -1) goto backMenu;
						
						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
						InputStudent(ds, k, true);
				
						// STUDENT p = BinarySearchStudent(ds, k.idStudent);
						// p = k;
						
						clrscr();
						ChangePageManageStudent(temp, idClass);
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Sua thanh cong";
					}
					else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
					{
						pageNowStudent++;
						clrscr();
						ChangePageManageStudent(temp, idClass);
					}
					else if(key == PAGE_UP && pageNowStudent > 1)
					{
						pageNowStudent--;
						clrscr();
						ChangePageManageStudent(temp, idClass);
					}
				}
				else if(key == ESC)
				{
					ClearListStudent(temp);
					return;
				}
			}			
		}
	}
	else
	 goto backMenu;	
}

