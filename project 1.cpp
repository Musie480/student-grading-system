#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    char name[35];
    int id;
    int creditHours;
    double mid[3];
    double assignment[3];
    double final[3];
    double gpa;
};

void INSERT(Student students[]) {
    for (int i = 0; i < 2; i++) {
        cout << "Enter name for student " << i+1 << ": ";
        cin >> students[i].name;
        cout << "Enter ID for student " << i+1 << ": ";
        cin >> students[i].id;
        cout << "Enter credit hours for student " << i+1 << ": ";
        cin >> students[i].creditHours;
        for (int j = 0; j < 2; j++) {
            cout << "Enter mid grade for course " << j+1 << " for student " << i+1 << ": ";
            cin >> students[i].mid[j];
            cout << "Enter assignment grade for course " << j+1 << " for student " << i+1 << ": ";
            cin >> students[i].assignment[j];
            cout << "Enter final grade for course " << j+1 << " for student " << i+1 << ": ";
            cin >> students[i].final[j];
        }
    }
}

void calculateGPA(Student students[]) {
    for (int i = 0; i < 4; i++) {
        double sum = 0.0;
        for (int j = 0; j < 3; j++) {
            sum += (students[i].mid[j] + students[i].assignment[j] + students[i].final[j]) / 3.0;
        }
        students[i].gpa = sum / 3.0;
    }
}

void DISPLAY(Student students[]) {
    for (int i = 0; i < 4; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Credit Hours: " << students[i].creditHours << endl;
        cout << "GPA: " << students[i].gpa << endl;
        cout << endl;
    }
}

void SEARCH(Student students[]) {
    int num;
    bool found = false;
    cout<<"\nEnter the identity number of the student that you want to search: ";
    cin>>num;
    for(int i = 0; i < 4; i++) {
        if(num == students[i].id) {
            cout << "Name: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Credit Hours: " << students[i].creditHours << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Student with ID " << num << " not found." << endl;
    }
}

void MENU(Student students[]) {
    char c;
    cout<<"\n\t Welcome to our program\n";
    cout<<"\n\t STUDENT GPA \n ";
    cout<<"//-------------------------------------\n";
    cout<<"\n<#>. press I to INSERT\n";
    cout<<"\n<#>. press S to SEARCH\n";
    cout<<"\n<#>. press D to DISPLAY\n";
    cout<<"\n<#>.Select your option---->";
    cin>>c;
    cout<<"----------------------------\n";
    while(true) {
        switch(c) {
            case 'I':
                INSERT(students);
                calculateGPA(students);
                break;
            case 'S':
                SEARCH(students);
                break;
            case 'D':
                DISPLAY(students);
                break;
            default:
                cout<<"Invalid choice, please try again" << endl;
                break;
        }
        cout<<"\n\t STUDENT GPA \n ";
        cout<<"//-------------------------------------\n";
        cout<<"\n<#>. press I to INSERT\n";
        cout<<"\n<#>. press S to SEARCH\n";
        cout<<"\n<#>. press D to DISPLAY\n";
        cout<<"\n<#>.Select your option---->";
        cin>>c;
        cout<<"----------------------------\n";
    }
}
void login();
void registration();
void forgot();
int main() {
 const int NUM_STUDENTS = 2;
    Student students[NUM_STUDENTS];

    int c;
    cout<<"\t\t\t__________________________________________________\n\n\n"<<endl;
    cout<<"\t\t\t_________Welcome to login page____________________\n\n\n";
    cout<<"\t\t\t_____________     MENU     ________________\n\n\n";
    cout<<"\t|press 1 to login                  |"<<endl;
    cout<<"\t|press 2 to register               |"<<endl;  
    cout<<"\t|press 3 if you forgot ur password   |"<<endl;
    cout<<"\t|press 4 to EXIT    ||"<<endl;
    cout<<"\n\t\t\t enter ur choice";
    cin>>c;
    cout<<endl;
    switch(c)
    {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\t\t\tthank you \n\n";
            break;
        default:
            system("cls");
            cout<<"please select from option given above \n";
            main();
    }

   
    return 0;
}
void login()
{
    int count = 0;
    string userid, password, id, pass;
    system("cls");
    cout << "Enter username: ";
    cin >> userid;
    cout << "Enter password: ";
    cin >> password;
    ifstream input("records.txt");
    while(input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userid << "\nLogin successful! \n Thanks for logging in \n";
        const int NUM_STUDENTS = 2;
        Student students[NUM_STUDENTS];

        for (int i = 0; i < NUM_STUDENTS; i++) {
            INSERT(students);
        }

       DISPLAY(students);
    }
    else
    {
        cout << " \nLogin failed!\n please check username and password\n ";
        main();
    }
}
void registration()
{
    string Ruserid, Rpassword, Rid, Rpass;
    system("cls");
    cout<<"\t\t\t enter the username : ";
    cin>>Ruserid;
    cout<<"\t\t\t enter the password : ";
    cin>>Rpassword;
    ofstream f1("records.txt", ios::app);
    f1<<Ruserid<<' '<<Rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is succesfull \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\tyou forgot your password \n let's fix it\n";
    cout<<"press 1 to search your password\npress 2 to go back to the main menu\n";
    cin>>option;
    if(option==1)
    {
        string searchid, searchpass, id, pass;
        int count = 0;
        system("cls");
        cout<<"\t\t\t Enter your username : ";
        cin>>searchid;
        ifstream input("records.txt");
        while(input>>id>>pass)
        {
            if(id == searchid)
            {
                count = 1;
                searchpass = pass;
            }
        }
        input.close();
        if(count == 1)
        {
            cout<<"\t\t\t your password is : "<<searchpass<<"\n";
            main();
        }
        else
        {
            cout<<"sorry!!!, no such username found\n";
            cout<<"press 1 to try again or 2 to go back to the main menu\n";
            int option;
            cin>>option;
            if(option==1)
            {
                forgot();
            }
            else if(option==2)
            {
                main();
            }
        }
    }
    else if(option==2)
    {
        main();
    }
}
