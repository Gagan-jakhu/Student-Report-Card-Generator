#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<cstdio>
using namespace std;
class student
{
    int p_marks=0,c_marks=0,m_marks=0,e_marks=0,cs_marks=0,roll=0;
    float per=0;
    char grade;
    char name[50];

    void calculate()
    {
        per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
        if(per>=80)
            grade='A';
        else if(per>=70)
            grade='B';
        else if(per>=60)
            grade='C';
        else if(per>=50)
            grade='D';
        else if(per>=40)
            grade='E';
        else
            grade='F';
    }
void getdata()
    {

        cout<<"\n\n\tEnter Roll No. of Student :- ";
        cin>>roll;
        cout<<"\n\n\tEnter Name of Student :- ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"\n\n\tEnter Physics Marks out of 100 :- ";
        cin>>p_marks;
        cout<<"\n\n\tEnter Chemistry Marks out of 100 :- ";
        cin>>c_marks;
        cout<<"\n\n\tEnter Mathematics Marks out of 100 :- ";
        cin>>m_marks;
        cout<<"\n\n\tEnter English Marks out of 100 :- ";
        cin>>e_marks;
        cout<<"\n\n\tEnter Computer Science Marks out of 100 :- ";
        cin>>cs_marks;
        calculate();

    }
    void showdata()
    {
        cout<<"\n\n\t**************STUDENT DETAILS ARE :- **************";
        cout<<"\n\n\n\tRoll No. of Student is :- "<<roll;
        cout<<"\n\n\tName of Student is :- "<<name;
        cout<<"\n\n\tMarks in Physics :- "<<p_marks;
        cout<<"\n\n\tMarks in Chemistry :- "<<c_marks;
        cout<<"\n\n\tMarks in Mathematics :- "<<m_marks;
        cout<<"\n\n\tMarks in English :- "<<e_marks;
        cout<<"\n\n\tMarks in Computer Science :- "<<cs_marks;
        cout<<"\n\n\tGrade of Student :- "<<grade;
        cout<<"\n\n\tPercentage of Student :- "<<per;
    }
public:
    void tabular()
    {
        cout<<roll<<"    "<<name<<"          "<<p_marks<<"   "<<c_marks<<"   "<<m_marks<<"   "<<e_marks<<"   "<<cs_marks<<"    "<<per<<"        "<<grade<<endl;
    }
    int return_roll()
    {
        return(roll);
    }

    void store_student();
    void show_student();
    void search_student(int);
    void delete_student(int);
    void update_student(int);
};
void student::store_student()
{
    cout<<"\n\n********************ENTER STUDENT DETAILS********************";
    student st;
    ofstream fout;
    st.getdata();
    fout.open("gagan2.dat",ios::app|ios::binary);
    fout.write((char*)&st,sizeof(student));
    fout.close();
    cout<<"\n\n******** STUDENT DETAILS HAS BEEN SUCCESSFULLY INSERTED ********";

}
void student::show_student()
{
    ifstream fin;
    student st;
    fin.open("gagan2.dat",ios::binary|ios::in);
    if(!fin)
    {
        cout<<"\n\n\tFile Could be Opened ";
        return;
    }
    fin.read((char*)&st,sizeof(student));
    cout<<"\n\n\t\t\tALL STUDENTS RESULT \n\n";
    cout<<"===================================================================="<<endl;
    cout<<"R.NO    Name          P    C    M    E    CS    %age    Grade    "<<endl;
    cout<<"===================================================================="<<endl;
    while(!fin.eof())
    {
        st.tabular();
        fin.read((char*)&st,sizeof(student));
    }

    fin.close();
}
void student::search_student(int n)
{
        ifstream fin;
        int count=0;
    student st;
    fin.open("gagan2.dat",ios::binary|ios::in);
    if(!fin)
    {
        cout<<"\n\n\tFile Could be Opened ";
        return;
    }
    fin.read((char*)&st,sizeof(student));
    while(!fin.eof())
    {
        if(st.return_roll()==n)
        {
            st.showdata();
            count++;
        }
        fin.read((char*)&st,sizeof(student));
    }
    fin.close();
    if(count==0)
    {
        cout<<"\n\n\tRecord Not Exist";
    }
}
void student::delete_student(int n)
{
    int count=0,found=0;
    student st;
    ifstream fin;
    ofstream fout;
    fin.open("gagan2.dat",ios::binary|ios::in);
    if(!fin)
    {
        cout<<"\n\n\tFile Could be Opened ";
        return;
    }
    fout.open("temp2.dat",ios::binary|ios::out);
    fin.read((char*)&st,sizeof(student));
    while(!fin.eof())
    {
        if(st.return_roll()!=n)
        {
            fout.write((char*)&st,sizeof(student));
            found++;
        }
        fin.read((char*)&st,sizeof(student));
        count++;
    }
    fout.close();
    fin.close();
    remove("gagan2.dat");
    rename("temp2.dat","gagan2.dat");
    if(count==found)
    cout<<"\n\n\tRECORD NOT FOUND ";
    else
    cout<<"\n\n\t******** RECORD HAS BEEN DELETED SUCCESSFULLY ******** ";


}
void student::update_student(int n)
{
    fstream file;
    int found =0;
    student st;
    file.open("gagan2.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout<<"\n\n\tFile Could be Opened ";
        return;
    }
    file.read((char*)&st,sizeof(student));
    while(!file.eof())
    {
        if(st.return_roll()==n)
        {
            cout<<"\n\n********************ENTER STUDENT'S NEW DETAILS********************";
            st.getdata();
            file.seekg(file.tellg()-sizeof(student));
            file.write((char*)&st,sizeof(student));
            found++;
            cout<<"\n\n\tRECORD HAS BEEN UPDATED SUCCESSFULLY";
        }
            file.read((char*)&st,sizeof(student));
    }
    file.close();
    if(found==0)
    {
        cout<<"\n\n\tRecord Not Found";
    }

}
int  menu()
{
    int choice;
    cout<<"\n\n\t\tSTUDENT REPORT CARD GENERATOR";
    cout<<"\n\n\t1.> Insert Student Record ";
    cout<<"\n\n\t2.> View class Record ";
    cout<<"\n\n\t3.> View specific  Student Record ";
    cout<<"\n\n\t4.> Delete  Student Record ";
    cout<<"\n\n\t5.> update  Student Record ";
    cout<<"\n\n\t6.> Exit ";
    cout<<"\n\n\tEnter your choice ";
    cin>>choice;
    return(choice);
}
void intro()
{
	cout<<"\n\n\n\t\t\t\t      STUDENT";
	cout<<"\n\n\t\t\t\t    REPORT CARD";
	cout<<"\n\n\t\t\t\t      PROJECT\n\n\n";
	cout<<"\n\t\t\t     *************************\n";
	cout<<"\t       MADE BY :-    *\t\t\t     * \n\t\t\t     *     1.> GAGAN\t     * \n\t\t\t     *     2.> Vikky Garg    *\n\t\t\t     *     3.> Jay kumar     * \n\t\t\t     *     4.> Geeta\t     * ";
    cout<<"\n\t\t\t     *************************";
	cout<<"\n\t\t\t     *   Branch :- Bio-tech. *";
	cout<<"\n\t\t\t     *   Year :- second\t     *";
	cout<<"\n\t\t\t     *************************";
}
int main()
{
    intro();
    getch();
    system("cls");
    student s1;
    int rll;
    while(1)
    {
        system("cls");
        switch(menu())
        {
             case 1:
                 system("cls");
                 s1.store_student();
                 break;
             case 2:
                 system("cls");
                s1.show_student();
                break;
             case 3:
                 system("cls");
                 cout<<"\n\n\tEnter Roll NO. to view Student Record :- ";
                 cin>>rll;
                 s1.search_student(rll);
                 break;
             case 4:
                 system("cls");
                 cout<<"\n\n\tEnter Roll NO. to Delete Student Record :- ";
                 cin>>rll;
                 s1.delete_student(rll);
                 break;
             case 5:
                 system("cls");
                 cout<<"\n\n\tEnter Roll NO. to Update Student Record :- ";
                 cin>>rll;
                s1.update_student(rll);
                break;
             case 6:
                 system("cls");
                 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t***************************************";
                cout<<"\n\t\t\t*  THANK YOU FOR USING THIS SOFTWARE  *";
                cout<<"\n\t\t\t***************************************\n\n\n\n\n\n\n\n\n\n\n";
                exit(0);
             default:
                cout<<"\n\n\tInvalid Choice";
        }
        getch();
    }


}
