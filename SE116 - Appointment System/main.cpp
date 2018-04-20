#include <iostream>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"

using namespace std;

int main ()
{
    Patient PObj;
    Doctor  DObj;

    string tempID;
    string tempName;
    string tempSurname;
    int tempAge;
    string tempTelephone;
    int c1;
    int n1;
    int p1;

    string Cardiology="Cardiology";
    string Neurology="Neurology";
    string Physiotherapy="Physiotherapy";

    string CName1="Murat";
    string CSurname1="Sener";
    string CName2="Naser";
    string CSurname2="Can";
    string CSpeciallity="Cardiology";
    string NName1="Aybars";
    string NSurname1="Akkor";
    string NName2="Soner";
    string NSurname2="Buyukkinaci";
    string NSpeciallity="Neurology";
    string PName1="Alper";
    string PSurname1="Gokce";
    string PName2="Ihsan";
    string PSurname2="Albayrak";
    string PSpeciallity="Physiotherapy";

    string setDate1="09:00-10:00";
    string setDate2="10:00-11:00";
    string setDate3="11:00-12:00";

    string setDate4="13:00-14:00";
    string setDate5="14:00-15:00";
    string setDate6="15:00-16:00";

    cout<<"  --WELCOME TO MEDICAL PARK HOSPITAL--"<<endl<<endl;
    cout<<"--Please Enter Your Informations--"<<endl<<endl;
    cout<<"ID        :";
    cin>>tempID;
    PObj.setID(tempID);
    cout<<"Name      :";
    cin>>tempName;
    PObj.setName(tempName);
    cout<<"Surname   :";
    cin>>tempSurname;
    PObj.setSurname(tempSurname);
    cout<<"Age       :";
    cin>>tempAge;
    PObj.setAge(tempAge);
    cout<<"Telephone :";
    cin>>tempTelephone;
    PObj.setTelephone(tempTelephone);

    int choice;
    go:cout<<endl<<"--Choose Hospital Department--"<<endl;
    cout<<"1 -) Cardiology"<<endl;
    cout<<"2 -) Neurology"<<endl;
    cout<<"3 -) Physiotherapy"<<endl;
    cin>>choice;
    if(choice==1)
    {
       PObj.setIllness(Cardiology);
    }
    else if(choice==2)
    {
        PObj.setIllness(Neurology);
    }
    else if(choice==3)
    {
        PObj.setIllness(Physiotherapy);
    }

    switch(choice)
    {
    case 1:
        int c;
        cout<<"-Cardiology Doctors-"<<endl;
        cout<<"1-)Dr. Murat Sener(09:00-12:00)"<<endl;
        cout<<"2-)Dr. Naser Can  (13:00-16:00)"<<endl;
        cin>>c;
        if (c==1)
        {
            DObj.setName(CName1);
            DObj.setSurname(CSurname1);
            DObj.setSpeciality(CSpeciallity);
        }
        else if(c==2)
        {
            DObj.setName(CName2);
            DObj.setSurname(CSurname2);
            DObj.setSpeciality(CSpeciallity);
        }

        switch(c)
        {
        case 1:
            cout<<endl<<"Dr. Murat Sener's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 09:00 - 10:00"<<endl;
            cout<<"2 - 10:00 - 11:00"<<endl;
            cout<<"3 - 11:00 - 12:00"<<endl;
            cin>>c1;
            if(c1==1)
                DObj.setDate(setDate1);
            else if(c1==2)
                DObj.setDate(setDate2);
            else if(c1==3)
                DObj.setDate(setDate3);
            break;
        case 2:
            cout<<"Dr. Naser Can's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 13:00 - 14:00"<<endl;
            cout<<"2 - 14:00 - 15:00"<<endl;
            cout<<"3 - 15:00 - 16:00"<<endl;
            cin>>c1;
            if(c1==1)
                DObj.setDate(setDate4);
            else if(c1==2)
                DObj.setDate(setDate5);
            else if(c1==3)
                DObj.setDate(setDate6);
            break;
        default:
            cout<<"Wrong Entry!"<<endl;
        }
        break;

    case 2:
        int n;
        cout<<"-Neurology Doctors-"<<endl;
        cout<<"1-)Dr. Aybars Akkor     (09:00-12:00)"<<endl;
        cout<<"2-)Dr. Soner Buyukkinaci(13:00-16:00)"<<endl;
        cin>>n;
        if (n==1)
        {
            DObj.setName(NName1);
            DObj.setSurname(NSurname1);
            DObj.setSpeciality(NSpeciallity);
        }
        else if(n==2)
        {
            DObj.setName(NName2);
            DObj.setSurname(NSurname2);
            DObj.setSpeciality(NSpeciallity);

        }

        switch(n)
        {
        case 1:
            cout<<endl<<"Dr. Aybars Akkor's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 09:00 - 10:00"<<endl;
            cout<<"2 - 10:00 - 11:00"<<endl;
            cout<<"3 - 11:00 - 12:00"<<endl;
            cin>>n1;
            if(n1==1)
                DObj.setDate(setDate1);
            else if(n1==2)
                DObj.setDate(setDate2);
            else if(n1==3)
                DObj.setDate(setDate3);
            break;
        case 2:
            cout<<"Dr. Soner Buyukkinaci's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 13:00 - 14:00"<<endl;
            cout<<"2 - 14:00 - 15:00"<<endl;
            cout<<"3 - 15:00 - 16:00"<<endl;
            cin>>n1;
            if(n1==1)
                DObj.setDate(setDate4);
            else if(n1==2)
                DObj.setDate(setDate5);
            else if(n1==3)
                DObj.setDate(setDate6);
            break;
            default:
            cout<<"Wrong Entry!"<<endl;
        }
        break;

    case 3:
        int p;
        cout<<"Physiotherapy Doctors"<<endl;
        cout<<"1-)Dr. Alper Gokce   (09:00-12:00)"<<endl;
        cout<<"2-)Dr. Ihsan Albayrak(13:00-16:00)"<<endl;
        cin>>p;
        if (p==1)
        {
            DObj.setName(PName1);
            DObj.setSurname(PSurname1);
            DObj.setSpeciality(PSpeciallity);
        }
        else if(p==2)
        {
            DObj.setName(PName2);
            DObj.setSurname(PSurname2);
            DObj.setSpeciality(PSpeciallity);
        }

        switch(p)
        {
        case 1:
            cout<<endl<<"Dr. Alper Gokce's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 09:00 - 10:00"<<endl;
            cout<<"2 - 10:00 - 11:00"<<endl;
            cout<<"3 - 11:00 - 12:00"<<endl;
            cin>>p1;
            if(p1==1)
                DObj.setDate(setDate1);
            else if(p1==2)
                DObj.setDate(setDate2);
            else if(p1==3)
                DObj.setDate(setDate3);
            break;
        case 2:
            cout<<"Dr. Ihsan Onder Albayrak's Working Hours:"<<endl;
            cout<<"Weekdays"<<endl;
            cout<<"1 - 13:00 - 14:00"<<endl;
            cout<<"2 - 14:00 - 15:00"<<endl;
            cout<<"3 - 15:00 - 16:00"<<endl;
            cin>>p1;
            if(p1==1)
                DObj.setDate(setDate4);
            else if(p1==2)
                DObj.setDate(setDate5);
            else if(p1==3)
                DObj.setDate(setDate6);
            break;
            default:
            cout<<"Wrong Entry!"<<endl;
        }

        break;
        default:
                cout<<"--Wrong Entry!--"<<endl;
                goto go;
    }
        PObj.Infos();
        DObj.Infos();
    return 0;
}
