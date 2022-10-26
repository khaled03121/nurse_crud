#include<bits/stdc++.h>
#include<unistd.h>
#include "person.h"

using namespace std;

class nurse:public person
{
    public:
    string id,blood_group;
};

nurse nrs[100];
int number_of_nurse=0;

void read_nurse()
{
    ifstream ni("nurse.txt");
    int i=0;
    string ch;
    while(getline(ni,nrs[i].id))
    {
        getline(ni,nrs[i].name);
        getline(ni,nrs[i].mobile_no);
        getline(ni,nrs[i].blood_group);
        i++;
        getline(ni,ch);
        // cin.ignore();
    }
    number_of_nurse=i;
}
int is_valid(string bld_grp)
{
    for(int i=0;i<bld_grp.length();i++)
    {
        bld_grp[i] = toupper(bld_grp[i]);
    }
    int f=1;
    if(!(bld_grp=="A+"||bld_grp=="B+"||bld_grp=="O+"||bld_grp=="AB+"||
        bld_grp=="A-"||bld_grp=="B-"||bld_grp=="AB-"||bld_grp=="O-"))
    {
        cout<<"\n\tInvalid Blood Group Try Again..\n\n";
        cout<<"Blood Group : ";
        f=0; 
        return f;
    }
    return f;
} 


void delete_nurse()
{
    read_nurse();
    string del_id;
    cout<<"\nDELTETING NURSE DETAILS\n";
    cout<<"-----------------------\n";
    cout<<"ID          : ";
    getline(cin,del_id);
    ofstream no("nurse.txt");
    int i =0;
    while(i<number_of_nurse)
    {
        if(del_id!=nrs[i].id)
        {
            no<<nrs[i].id<<endl;
            no<<nrs[i].name<<endl;
            no<<nrs[i].mobile_no<<endl;
            no<<nrs[i].blood_group<<endl;
            no<<"\n";
        }
        i++;
    }
    number_of_nurse--;
    no.close();

}

void add_nurse()
{
    read_nurse();
    cin.ignore();
    nurse new_nurse;
    cout<<"\n\nADDING NEW NURSE DETAILS\n";
    cout<<"------------------------\n";
    cout<<"ID          : ";
    getline(cin,new_nurse.id);
    cout<<"Nurse Name  : ";
    getline(cin,new_nurse.name);
    cout<<"Mobile No.  : ";
    getline(cin,new_nurse.mobile_no);
    cout<<"Blood Group : ";
    while(getline(cin,new_nurse.blood_group))
    {
        if(is_valid(new_nurse.blood_group))
        {
            for(int i=0;i<new_nurse.blood_group.length();i++)
            {
                new_nurse.blood_group[i] = toupper(new_nurse.blood_group[i]);
            }
            break;
        }
    }
    ofstream no("nurse.txt");
    int i =0;
    nrs[number_of_nurse].id = new_nurse.id;
    nrs[number_of_nurse].name = new_nurse.name;
    nrs[number_of_nurse].mobile_no = new_nurse.mobile_no;
    nrs[number_of_nurse].blood_group = new_nurse.blood_group;
    number_of_nurse++;
    while(i<number_of_nurse)
    {
        no<<nrs[i].id<<endl;
        no<<nrs[i].name<<endl;
        no<<nrs[i].mobile_no<<endl;
        no<<nrs[i].blood_group<<endl;
        i++;
        no<<"\n";
    }
    no.close();
    
}

void update_info()
{
    read_nurse();
    int option;
    string idd;
    cout<<"Which info do you want to update?\n\n";
    cout<<"1: Mobile Number?\n";
    cin>>option;
    system("CLS");
    if(option!=1)
    {
        cout<<"Invalid Option, Please try Again..\n\n";
        update_info();
    }
    cout<<"Please give me the patient's ID you want to change : ";
    cin>>idd;

    ofstream on("nurse.txt");
    for(int i=0;i<number_of_nurse;i++)
    {
        if(nrs[i].id==idd)
        {
            string m;
            cout<<"Enter the Mobile Number : ";
            cin>>m;
            nrs[i].mobile_no=m;
        }
    }
    int i=0;
    while(i<number_of_nurse)
    {
        on<<nrs[i].id<<endl;
        on<<nrs[i].name<<endl;
        on<<nrs[i].mobile_no<<endl;
        on<<nrs[i].blood_group<<endl;
        i++;
        on<<"\n";
    }
    on.close();

}

void nurse_list()
{
    read_nurse();
    int i =0;
    cout<<"Nurse List : \n";
    cout<<"------------\n";
    while(i<number_of_nurse)
    {
        cout<<"ID          : "<<nrs[i].id<<endl;
        cout<<"Name        : "<<nrs[i].name<<endl;
        cout<<"Mobile NO.  : "<<nrs[i].mobile_no<<endl;
        cout<<"Blood Group : "<<nrs[i].blood_group<<endl;
        i++;
        cout<<"\n"<<endl;
    }
} 
int mm=0;
void welcome()
{
    if(mm==0){
        cout<<"\n\t\tWELCOME TO THE NURSE'S CRUD WORLD\n\n";
        cout<<"\t\t---------------------------------\n";
        sleep(5);
    }
        system("CLS");
        cout<<"\n\tPlease select an option\n";
        cout<<"\t-----------------------\n";
        cout<<"\n\t1: Add a new nurse\n\n";
        cout<<"\n\t2: Remove a nurse's Information\n\n";
        cout<<"\n\t3: Update an old nurse's Information\n\n";
        cout<<"\n\t4: Show all nurse's Information\n\n";
        cout<<"\n\tEnter 0 to escape\n\n";
        int option;
        cin>>option;
        system("CLS");
        if(option == 0)
        {
             cout<<"\n\t\t\t\tStay with us\n\n";
             sleep(2);
             return;
        }
        mm=1;
        if(option>5 || option<1)
        {
            cout<<endl<<"Invalid Option, Please try Again..\n\n";
            sleep(2);
            system("CLS");
 
            welcome();
        }
        if(option == 1)
        {
            add_nurse();
        }
        else if(option == 2)
        {
            delete_nurse();
        }
        else if(option == 3)
        {
            update_info();
        }
        else
        {
            nurse_list();
            cout<<"\nPress any key...";
            cin.ignore();
            string enter;
            getline(cin,enter);
        }
        welcome();
}
int main()
{
    welcome();

    return 0;
}