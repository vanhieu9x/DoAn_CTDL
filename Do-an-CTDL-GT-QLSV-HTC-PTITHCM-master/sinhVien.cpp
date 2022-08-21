#include"constant.h"
#include"globalvariable.h"
#include"display.h"
#include"validate.h"
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
struct student{
	char idStudent[16];
	char idClass[16];
	char firstName[21], lastName[11];
	int sex = 1; // 1 male, 2 female
	char phoneNumber[13];
	int yearAdmission; // nam nhap hoc
	//float mediumScore = 0;	
};
typedef struct student STUDENT;
struct ListSV
{			
	STUDENT nodes[MAXSV];
	int n=0;
};


int checkMaSo(ListSV &ds, char s[]){
	for(int i=0; i<ds.n;i++)
		if(strcmp(ds.nodes[i].idStudent, s)==0)
			return 1;
	return 0;
}
// Them sinh vien vao vi tri thu i trong danh sach
int insertSV(ListSV &ds, int i, STUDENT sv){
	if(i<0||ds.n==MAXSV||i>ds.n)
		return 0;
	else
		for(int j=ds.n-1; j>=i;j++){
			ds.nodes[j+1]=ds.nodes[j];
		}
		ds.nodes[i]=sv;
		ds.n++;
		return 1;
}
// Xoa sinh vien theo ma sinh vien
int deleteSV(ListSV &ds, char s[]){
	if(ds.n==0)
		return 0;
	else{
		for(int i=1;i<ds.n;i++){
			if(strcmp(ds.nodes[i].idStudent, s)==0){
				//delete ds.nodes[i];
				for(int j=i; j<ds.n; j++){
					ds.nodes[j]=ds.nodes[j+1];
				}
				//delete ds.nodes[ds.n];
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
void selectionSortSTUDENT(ListSV &ds){
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


int findIndexStudent(ListSV ds, char* ma){
	if(ds.n==0) return 0;
	else{
		for(int i=0; i<ds.n; i++){
			if(strcmp(ds.nodes[i].idStudent, ma)==0)
				return i;
		}
	}
	return 0;
}

int binarySearchStudent(ListSV ds, char* id){
	if(ds.n==0)
		return 0;
	else
	{
		int r=ds.n-1;
		int l=0;
		while(r>=l){
			int mid = l + (r-l)/2;
			if(strcmp(ds.nodes[mid].idStudent, id)==0)
				return mid;
			if(strcmp(ds.nodes[mid].idStudent, id)<0)
				l = mid+1;
			else
				r = mid+1;
		}
	}
	return 0;
}



STUDENT *findStudentByOrdinal(ListSV ds, int ordinal){
	if(ds.n==0||ds.n-1<ordinal) 
		return NULL;
	else{
		STUDENT *p = new STUDENT;
		p = &ds.nodes[ordinal];
		return p;
	}
}

bool isDelete(ListSV &ds, int ordinal){
	if(ds.n==0||ds.n<ordinal) return false;
	//delete ds.nodes[ordinal];
	for(int i=ordinal; i<ds.n - ordinal;i++){
		ds.nodes[i]=ds.nodes[i+1];
	}
	ds.n=ds.n-1;
	return true;
}

bool clearListStudent(ListSV &ds){
	ds.n=0;
}

void outputStudent(STUDENT sv, int locate){
	DeleteOldData(sizeof(keyDisplayStudent)/sizeof(string), locate);
	Gotoxy(xKeyDisplay[0]+1, Y_DISPLAY + 3 + locate); cout<<sv.idStudent;
	Gotoxy(xKeyDisplay[1]+1, Y_DISPLAY + 3 + locate); cout<<sv.firstName;
	Gotoxy(xKeyDisplay[2]+1, Y_DISPLAY + 3 + locate); cout<<sv.lastName;
	Gotoxy(xKeyDisplay[3]+1, Y_DISPLAY + 3 + locate);
	if(sv.sex == 1) cout<<"Nam";
	else cout<<"Nu";
	Gotoxy(xKeyDisplay[4]+1, Y_DISPLAY + 3 + locate); cout<<sv.phoneNumber;
	Gotoxy(xKeyDisplay[5]+1, Y_DISPLAY + 3 + locate); cout<<sv.idClass;
}

void outputListStudentWithIdClassPerPage(ListSV ds, int indexBegin){
	if(ds.n==0) return;
	int count = -1;
	for(int i = 0 ; i<ds.n; i++){
		count++;
		if(count == indexBegin){
			int j= -1;
			while(i<QUANTITY_PER_PAGE - 1&&i<ds.n){
				outputStudent(ds.nodes[i], (++j)*2);
				i++;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout<<"Trang "<< pageNowStudent<<"/"<<totalPageStudent;
}

void inputStudent(ListSV &ds, STUDENT sv, bool isEdited = false){
	ShowCur(true);
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsEdited = false;
	
	string idStudent, firstName, lastName, idClass, phoneNumber;
	int sex; //phoneNumber;
	
	if(isEdited){
		idStudent = sv.idStudent;
		firstName = sv.firstName;
		lastName = sv.lastName;
		idClass = sv.idClass;
		sex = sv.sex;
		phoneNumber = sv.phoneNumber;
		
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
				if(FindStudent(ds, (char *)idStudent.c_str())==NULL){
					idIsEdited = false;
					break;
				}
				idIsEdited = true;
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
				CheckMoveAndValidateNameSubject(phoneNumber, isMoveUp, ordinal, isSave, 20+7,12);
				break;
			//case 5:s
				//checkMoveAndValidateID(idClass, isMoveUp, ordinal, isSave, )
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
			else if(idIsEdited){
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout<<"Ma sinh vien khong duoc trung";
			}
			else{
				strcpy(sv.idClass, idStudent.c_str());
				strcpy(sv.firstName, firstName.c_str());
				strcpy(sv.lastName, lastName.c_str());
				strcpy(sv.phoneNumber, phoneNumber.c_str());
				sv.sex=sex;
				//sv.yearAdmission=yearAdmission;
				StandardName(sv.firstName);
				StandardName(sv.lastName);
				
				if(isEdited){
					STUDENT *p = FindStudent(ds, sv.idStudent);
					&p = sv;
				}
				else{
					InsertOrderForListStudent(ds, sv);
				}
				totalPageStudent = ((ds.n-1)/ QUANTITY_PER_PAGE)+1;
				DeleteMenuAdd();
				return;
			}
			isSave = false;
		}
		else
			isSave = false;
	}
	ShowCur(false);
}
