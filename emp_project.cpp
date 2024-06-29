// EMPLOYEE MANAGEMENT SYSTEM USING CPP - Sagar Developer

//Include All Header files.
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

int dashboard(); //login declaration


class Employee_management
{
private:
    // Variables for employee details
    char name[30];
    char id[5];
    char designation[30];
    int age, salary;
    char experience[20];

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void Employee_management::menu() //Project Menu
{
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> WELLCOM TO EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM - By Sagar Developer <<\n\n";
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee Salary: ";
    cin >> salary;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
    file.close();
}

void Employee_management::display() // Display data of employe
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      Salary      ||    EXPERIENCE    ||";
        cout << "\n -------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << salary << "\t\t" << experience;
            file >> name >> id >> designation >> age >> salary >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::modify() // Modify data of employe
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee salary: ";
                cin >> salary;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee Salary: " << salary << "\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "---------------------\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Employee_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

void adminLogin(string name, string pass){

    string _tmpName = name != "" ? name : "";
    string _tmpPass = pass != "" ? pass : "";

    bool isFound = false;

    char ch;
    fstream file;
    system("cls");
    file.open("Ep_data.txt", ios::in);
    cout << "\n\t\t\t\t\t--------------------";
    cout << "\n\t\t\t\t\t>> Admin Login <<";
    cout << "\n\t\t\t\t\t--------------------";
    cout << "\n\n\t\t\t\t\tEnter Your Name: ";
    cin >> _tmpName;
    cout << "\n\t\t\t\t\tEnter Your Password: ";
    cin >> _tmpPass;

    while (!file.eof())
    {
        cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        string tmpData = "";

        // Read File & Do Validation
        while (file) {
            // Output the text from the file
            getline(file, tmpData);

            if (tmpData == (" "+_tmpName+" "+_tmpPass)){
                isFound = true;
            }
        }

        /// In case login new admin
        if ((pass == "" && name == "") && isFound){
            cout << "\n\nAccess Granted..\n\n";
            system("PAUSE");
            system("cls");
            break;
        }
        /// In case register new admin
        else if (pass == _tmpPass && name == _tmpName)
        {
            cout << "\n\nAccess Granted..\n\n";
            system("PAUSE");
            system("cls");
            break;
        }
        else
        {
            cout << "\n\nAccess Aborted...\n\n";
            system("PAUSE");
            system("cls");
            adminLogin("", "");
        }
    }
    file.close();
}

int dashboard() // Employee Authentication
{
    string name = "";
    string pass = "";
    fstream file;
    char ch;
    system("cls");
   
    cout << "\n\t\t\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
   
    cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> Admin Registration <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("Ep_data.txt", ios::app);
        file << " " << name << " " << pass << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        adminLogin(name, pass);
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        adminLogin("", "");
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        dashboard();
    }
    return 0;
}


int main()
{
    // Call the function
    Employee_management system;
    dashboard();
    system.menu();
    return 0;
}