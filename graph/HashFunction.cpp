#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<sstream>
using namespace std;
int HASH(char);
class Student
{
    char *fname;
    char *lname;
    string sisi;
    char *number;
    char *major;
    int course;
    int tale=0,capacity=15;
    string *storage;
public:
    Student();
    void SearchPrint(const string ID);
    void read(const string ID);
    ~Student();
};
Student:: Student()
{
    storage = new string[capacity];
    fname = new char[8];
    strcpy(fname,"unknown");
    lname = new char[8];
    strcpy(lname,"unknown");
    sisi="unknown";
    number = new char[8];
    strcpy(number,"unknown");
    major = new char[8];
    strcpy(major,"unknown");
}
void Student::SearchPrint(const string ID)
{
    int temp;
    temp=tale;
    while(temp>0)
    {
        if(sisi==ID)
        {
            cout << "|Fname : " << fname <<endl;
            cout << "|Lname : " << lname <<endl;
            cout << "|ID : " << sisi <<endl;
            cout << "|Course:"<< course <<endl;
            cout << "|Number:"<< number <<endl;
            cout << "|Major:"<< major <<endl;
            return;
        }
        temp--;
    }
    if(temp==0)
    {
        cout << " ene suragchiin medeelel alga bn"<<endl;
    }
}
void Student::read(const string ID)
{
    tale++;
    storage[tale]=ID;
    delete []fname;
    delete []lname;
    delete []number;
    delete []major;
    char  _fname[20], _lname[20],_number[10],_major[20];
    cout << "ner oruulna uu : ";
    cin>>_fname;
    fname = new char[strlen(_fname)+1];
    strcpy(fname,_fname);
    cout << "ovog oruulna uu : ";
    cin>>_lname;
    lname = new char[strlen(_lname)+1];
    strcpy(lname,_lname);
    cout << "Course oruulna uu : ";
    cin>>course;
    cout << "Utasnii dugaar oruulna uu : ";
    cin>>_number;
    number = new char[strlen(_number)+1];
    strcpy(number,_number);
    cout << "Hutulbur oruulna uu : ";
    cin>>_major;
    major = new char[strlen(_major)+1];
    strcpy(major,_major);
    sisi=ID;
    return;
}
Student::~Student()
{
    delete []storage;
    delete []fname;
    delete []lname;
}
//
int majorpoint(const char major)
{
    switch(major)
    {
    case 'b':
        return 0;
        break;
    case 'd':
        return 1;
        break;
    case 'm':
        return 2;
        break;
    }
}
//Сургуулийн оноо өгөх
int schoolpoint(const char *school)
{
    if(strcmp(school,"seas"))
        return 1;
    else if(strcmp(school,"sas"))
        return 2;
    else  if(strcmp(school,"sipra"))
        return 1;
    else if(strcmp(school,"law"))
        return 4;
    else  if(strcmp(school,"bs"))
        return 5;
}
int toINT(const char *_char)
{
    return atoi(_char);
}
int HASH(const std::string ID)
{
    int sum,m,s,i,last=0,p=0;
    char major,school[5];/*seas,sas,sipra,law,bs*/;
    //хөтөлбөрийн үсэг бодох
    major = ID[2];
    m=majorpoint(major);
    //Сургууль
    i=4;
    while(!isdigit(ID[i]))
    {
        school[p]=ID[i];
        i++;
        p++;
    }
    s=schoolpoint(school);
    //Хойд талын 4н орон
    if(s==1)
        i=9;
    else if(s==2||s==4)
        i=8;
    else if(s==3)
        i=10;
    else if(s==5)
        i=7;
    last = toINT(&ID[i]);
    sum=(m*5+s)*10000+last;
    return sum;
}

Student NUM[600000];
int main()
{
    int i=1,n,input;
    string ID;
    while(true)
    {
        cout << "\toyutnii sisi ID gaar medeelel oruulah bol 1"<<endl;
        cout << "\toyutnii sisi ID gaar haih bol 2"<<endl;
        cout << "\tGarah bol 3"<<endl;
        cin >> input;
        switch(input)
        {
        case 1:
            cout << "oyutnii sisi ID ? "<<endl;
            cin >> ID;
            i=HASH(ID);
            NUM[i].read(ID);
            break;
        case 2:
            cout << "oyutnii sisi ID ? "<<endl;
            cin >> ID;
            i=HASH(ID);
            NUM[i].SearchPrint(ID);
            break;
        case 3:
            return false;
            break;
        }
    }
}
