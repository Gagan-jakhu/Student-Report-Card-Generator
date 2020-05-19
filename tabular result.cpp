#include<iostream>
using namespace std;
show_tabular()
{
    int p=91,c=92,m=93,e=94,cs=95,r_no=1,age=80;
    char name[20]="gagan";
    char grade='A';
    cout<<"===================================================================="<<endl;
    cout<<"R.NO       Name         P    C    M    E    CS    %age    Grade    "<<endl;
    cout<<"===================================================================="<<endl;
    cout<<r_no<<"          "<<name<<"        "<<p<<"   "<<c<<"   "<<m<<"   "<<e<<"   "<<cs<<"    "<<age<<"        "<<grade<<endl;
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
    //show_tabular();
}
