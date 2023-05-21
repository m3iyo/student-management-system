#include <conio.h>
#include <fstream>
#include <string>
#include <process.h>
#include <windows.h>
#include <iomanip>
#include <iostream>
#include "header.h"

using namespace std;



//Declaring the functions to be used in this program

void welcome(); //LOADING SCREEN
void create_info(); //A FUNCTION FOR THE TEACHER TO CREATE A NEW STUDENT PROFILE
void find_student(); //FIND STUDENT FUNCTIONS TAKES IN 2 INPUTS, UNIVERSITY ID AND PIN CODE
void my_profile(); // A FUNCTION FOR THE STUDENT TO CHECK HIS/HER RECORDS
void update_info(); // A FUNCTION FOR THE TEACHER TO UPDATE A STUDENT's RECORD
void del_info(); // A FUNCTION FOR THE TEACHER TO DELETE/REMOVE A STUDENT's RECORD
void ranking(); // A FUNCTION THAT DISPLAYS THE RANKING OF THE CLASS BY AVERAGE(GWA)
void subject_ranking(); // A FUNCTION TO DISPLAY THE RANKING OF THE STUDENTS IN INDIVIDUAL SUBJECTS
void leaderboards(); //DISPLAYS RANKING OF THE STUDENTS, BY AVERAGE OR IN INDI VIDUAL SUBJECTS
void adviser(); //CLASSROOM ADVISER FUNCTION
void student(); //STUDENT FUNCTION
void adviser_login(); //PASSWORD FUNCTION FOR THE TEACHER TO LOGIN TO GAIN ADMINISTRATIVE ACCESS
void main_menu(); //MAIN MENU
void display_all(); //DISPLAYS THE STUDENT CLASS RECORDS
void launch(); //CAlls the Main Menu and The Loading Bar

void welcome()
{
	system("COLOR 0e");
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int load1 = 177, load2 = 219;

	cout << std::setprecision(0) << std::fixed;
	for (int i = 1; i <= 120; i++)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING...." << 0.83333333333 * i << "%\n";
		for (int j = 1; j <= i; j++)
		cout << (char)load2;

		if (0.83333333333 * i >= 1 & i <= 20)
		{
			cout << "\n\t\t\t\t\t\tInitializing...";
		}
		if (0.83333333333 * i >= 20 & i <= 50)
		{
			cout << "\n\t\t\t\t\tRetrieving students data from database...";
		}
		if (0.83333333333 * i >= 50 & i <= 100)
		{
			cout << "\n\t\t\t\t\t\tStarting program...";
		}
		Sleep(50);
	}

	SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
	system("COLOR 0f");
	system("cls");
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t   Student Management System";
	cout << "\n\n\t\t\t\t\t\t\t     by";
	cout << "\n\n\t\t\t\t\t\t   Lord Patrick Togonon";
	cout << "\n\n\t\t\t\t\t\t   Gem Win Cañete";
	cout << "\n\n\t\t\t\t\t\t   Matthew Andrei Valencia";
    cout << "\n\n\t\t\t\t\t\t   John Paul Sapasap";
    cout << "\n\n\t\t\t\t\t\t   Jed Andrew Del Rosario";
	cout << "\n\n\t\t\t\t\t\t\t   BSCS 1B";
    Sleep(5000);
    system("cls");
}

void create_info()
{
	Profile a;
	ofstream create("Record.txt", ios::out|ios::trunc);
	a.profile();
	create.write((char*)&a,sizeof(a));
	create.close();
}

void del_info()
{
	Profile a;
	ifstream open1("Record.txt");
	ofstream create1("Temp.txt", ios::binary);
	int count = 0;
	int id;
	if (!open1)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		cout<<"\n\n\n\n\n\t\t\t\t\tENTER THE STUDENT'S UNIVERSITY ID: ";
		cin >> id;
		system("cls");
		while(open1.read((char*)&a,sizeof(a)))
		{

			if (id != a.uni_id)
			{
				create1.write((char*)&a, sizeof(a));
            	count = 1;
			}
		}
		if (count == 0)
		{
			cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
		}
		else
		{
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     THE RECORD HAS BEEN DELETED SUCCESSFULLY\n\n\n\n\n\n\n\n";
		}
	}
	open1.close();
	create1.close();
	remove("Record.txt");
	rename("Temp.txt", "Record.txt");
}

void update_info()
{
	Profile a;
	ifstream open1("Record.txt");
	ofstream create1("Temp.txt");
	int count = 0;
	int id;
	if (!open1)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
        cout<<"\n\n\n\n\n\t\t\t\t\tENTER THE STUDENT's UNIVERSITY ID: ";
		cin >> id;
		cin.ignore(20, '\n');
		system("cls");
		while(open1.read((char*)&a,sizeof(a)))
		{
			if (id == a.uni_id)
			{
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t     INPUT THE NEW/UPDATED INFO OF THE STUDENT";
				Sleep(1500);
				system("cls");
				a.profile();
				create1.write((char*)&a,sizeof(a));
				count = 1;
			}
			else
			{
				create1.write((char*)&a,sizeof(a));
			}
		}
		if (count == 0)
		{
			cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
		}
	}
	open1.close();
	create1.close();
	remove("Record.txt");
	rename("Temp.txt", "Record.txt");
}

void find_student()
{
	Profile a;
	fstream open1("Record.txt");
	int count = 0;
	int id;
	if (!open1)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		cout<<"\n\n\n\n\n\t\t\t\tENTER THE STUDENT's UNIVERSITY ID: ";
		cin >> id;
		system("cls");
		while(open1.read((char*)&a,sizeof(a)))
		{
			if (id == a.uni_id)
			{
				count = 1;
				a.report_card();
			}
		}
		if (count == 0)
		{
			cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
		}
	}
	system("pause");
	open1.close();
}

void my_profile()
{
	Profile a;
	ifstream open("Record.txt");
	int count = 0;
	int id;
	char pass[20];
	if (!open)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tENTER YOUR UNIVERSITY ID: ";
		cin >> id;
		cin.ignore(20, '\n');

		cout<<"\n\n\t\t\t\tENTER YOUR PIN: ";
		cin.getline(pass, 20);
		system("cls");
		while (open.read((char*)&a,sizeof(a)))
		{
			if ((id == a.uni_id) && (strcmp(pass, a.pin) == 0))
			{
				count = 1;
				a.report_card();
			}
		}
		if (count == 0)
		{
			cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
		}
	}
	system("pause");
	open.close();
}

void ranking()
{
	Profile a, b[100], fill;
	ifstream open("Record.txt");
	int n = 0;

	if (!open)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		{
			do
			{
				b[n++] = a;
			}
			while (open.read((char*)&a, sizeof (a)));
		}
		open.close();

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (b[j].average < b[j + 1].average)
				{
					fill = b[j];
					b[j] = b[j + 1];
					b[j + 1] = fill;
				}
			}
		}
		cout << "\n\n\t\t\t\t\t  -------------------------------\n";
        cout << "\t\t\t\t\t       CLASS RECORD(HI - LO)\n";
        cout << "\t\t\t\t\t  -------------------------------\n";

		for (int i = 0; i < n; i++)	
		{
			b[i].disp_student_profiles();
			cout << "\n\n\n\n\n\n\t\t\t\t\t  -------------------------------\n\n";
		}
		getch();
		system("pause");
	}

}

void subject_ranking()
{
	Profile a, b[100], fill;
	ifstream open("Record.txt");
	int n = 0, choice, count;

	if (!open)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		{
			while(open.read((char*)&a,sizeof(a)))
            {
                b[n++] = a;
            }
		}
		open.close();

    	cout<<"\n\n\n\n\n\n\t\t\t\t\t  ------------------------"<<"\n";
        cout<<"\t\t\t\t\t     CHOOSE A SUBJECT"<<"\n";
        cout<<"\t\t\t\t\t  ------------------------"<<"\n";
        cout<<"\t\t\t\t\t\t  1. STAT203"<<"\n";
        cout<<"\t\t\t\t\t\t  2. CCS221"<<"\n";
        cout<<"\t\t\t\t\t\t  3. CCS222"<<"\n";
        cout<<"\t\t\t\t\t\t  4. CC203"<<"\n";
        cout<<"\t\t\t\t\t\t  5. SS117"<<"\n";
        cout<<"\t\t\t\t\t\t  6. ENG110"<<"\n\n";
        cout<<"\t\t\t\t\t     ENTER YOUR CHOICE: ";
    	cin >> choice;
    	cin.ignore(1000, '\n');
    	system("cls");
    	cout << "\n";

    	if (choice > 6)
    	{
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
		}
		else
		count = choice - 1;

		for(int i = 0;i < n;i++)
        {
             for(int j = 0;j < n - 1;j++)
            {
                if(b[j].grades[count] < b[j+1].grades[count])
                {
                    fill = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = fill;
                }
            }
    	}

    	cout<<"\n\n\n\n\n\n";
        cout<<""<<"------------------------------------------------------------------------------------------------------------------------";
        cout<<""<<"\t\tRANK" << "\t\t\t\tNAME"<<"\t\t\t\t\tGRADES"<<"\n";
        cout<<""<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
        for(int i = 0;i < 5;++i)
        {
            cout<<"\t "<< i + 1 <<"\t\t" << b[i].student_name <<"\t\t\t  " << b[i].grades[count];
            cout<<endl;
        }
        cout<<""<<"------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n";
        system("pause");
    }
}

void leaderboards()
{
	int choice;
	cout<<"\n\n\n\n\n\n\t\t\t\t\t     ------------------------"<<"\n";
  	cout<<"\t\t\t\t\t            LEADERBOARDS"<<"\n";
    cout<<"\t\t\t\t\t     ------------------------"<<"\n\n";
    cout<<"\t\t\t\t\t  1. VIEW RANKING BY GWA"<<"\n";
	cout<<"\t\t\t\t\t  2. VIEW RANKING PER SUBJECT"<<"\n";
	cout<<"\n\n\t\t\t\t\t            CHOICE: ";
    cin >> choice;
    cin.ignore (20, '\n');
    system("cls");

    switch (choice)
    {
    	case 1:
    		ranking();
    		break;

    	case 2:
    		subject_ranking();
    		break;
    	default:
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
	}
}

void adviser()
{
	int choice;
    start:
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t------------------------" << "\n";
    cout<<"\t\t\t\t\t\t         STUDENT" << "\n";
    cout<<"\t\t\t\t\t\t------------------------" << "\n\n";
    cout<<"\t\t\t\t\t     1. Create A New Student Profile" << "\n";
    cout<<"\t\t\t\t\t     2. Find Student's Records'" << "\n";
    cout<<"\t\t\t\t\t     3. View Leaderboards" << "\n";
    cout<<"\t\t\t\t\t     4. View Class Records" <<"\n";
    cout<<"\t\t\t\t\t     5. Update Student's Record'"<<"\n";
    cout<<"\t\t\t\t\t     6. Delete a Record" << "\n";
    cout<<"\t\t\t\t\t     7. Main Menu" << "\n\n";
    cout<<"\t\t\t\t\t\t         CHOICE: ";;
    cin >> choice;
    system("cls");

    switch (choice)
    {
    	case 1:
    		create_info();
    		break;

    	case 2:
    		find_student();
    		break;

    	case 3:
    		leaderboards();
    		break;

    	case 4:
    		display_all();
    		break;

    	case 5:
    		update_info();
    		break;

    	case 6:
    		del_info();
    		break;

    	case 7:
    		main_menu();
    		break;

    	default:
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
	}
	Sleep(1000);
	goto start;
}

void student()
{
	int choice;
    start:
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t------------------------"<<"\n";
    cout<<"\t\t\t\t\t\t         STUDENT"<<"\n";
    cout<<"\t\t\t\t\t\t------------------------"<<"\n\n";
    cout<<"\t\t\t\t\t     1. View My Profile"<<"\n";
    cout<<"\t\t\t\t\t     2. View Classroom Leaderboards"<<"\n";
    cout<<"\t\t\t\t\t     3. Main Menu"<<"\n\n";
    cout<<"\t\t\t\t\t\t         CHOICE: ";;
    cin >> choice;
    system("cls");

    switch (choice)
    {
    	case 1:
    		my_profile();
    		break;

    	case 2:
    		leaderboards();
    		break;

    	case 3:
    		main_menu();
    		break;

    	default:
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
	}
	Sleep(1000);
	goto start;
}

void adviser_login()
{
	system("cls");
	char password[7];
	char stored_password[7];
	char username[20];
	char stored_username[20];
	char choice;
	string master_pass;
	string stored_master_pass;

	ofstream adminwrite;
	ifstream adminread;
	ifstream admincreate;

	adminread.open("admin_credentials.txt");
	if (!adminread)
	{
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t  System Error: User not Found\n\n\n";
		system("pause");
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Would you like to create one?(Y/N): ";
		cin >> choice;
		if (choice == 'Y'){

			admincreate.open("master_pass.dat");

			cout << "Enter the master password provided by the chief administrator \n";
			cout << "Master Password: ";
			cin >> master_pass;

			admincreate >> stored_master_pass;

			if (master_pass == stored_master_pass){

				system("cls");
				cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Select a username: ";
				cin >> stored_username;
				cin.ignore(20, '\n');
				cout << "\n\n\n\n\t\t\t\t\t  Create a 6 digit password: ";
				cin >> stored_password;
				cin.ignore(20, '\n');

				adminwrite.open("admin_credentials.txt");
				adminwrite << stored_username << " ";
				adminwrite << stored_password;

			} else {

				cout << "\n Master Password incorrect. Administrator Account can not be created. \nContact the chief administrator immediately.";

				exit(0);
			}

			admincreate.close();
			adminwrite.close();

		}
		else{
			cout << "\nCan not Access Page without an Administrative Account.. Contact the chief administrator if this is a problem.";
			exit(0);
		}
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\tENTER USERNAME AND PASSWORD FOR ADMINISTRATIVE ACCESS";
	cout << "\n\n\t\t\t\t\t\tUsername: ";
	cin >> username;
	while(strcmp(username,stored_username))
	{

		adminread >> stored_username;
		if(adminread.eof())
		{
			cout<<"\n\n\n\t\t\t\t\tThe username you entered is not registered. \n\n\t\t\t\t\tContact your system administrator if this is a problem" << std::endl;
			Sleep(3000);
			main_menu();
    	}
	}
	int counter = 0;

	start:
	adminread >> stored_password;
	cout << "\n\n\t\t\t\t\t\tPassword: ";
	for (int i = 0; i < 6; i++)
	{
		password[i] = getch();
        cout<<"*";
	}

	if(strcmp(password, stored_password) == 0)
	{
    	cout<<"\n\n\t\t\t\t\t\tACCESS GRANTED"<< endl;
    	system("pause");
    	system("cls");
		adviser();
	}
	else
	{
		if (counter == 2)
		{
			cout<<"\n\n\t\t\t\t\t\tACCESS DENIED"<<"\n\n\n\n\n\n\n\n";
			Sleep(500);
			main_menu();
		}
		cout << "\n\n\t\t\t\t\t\tWrong password. "<<endl;
    	cout << "\n\n\t\t\t\t\t\tTry Again";
    	counter++;
    	Sleep(300);
    	system("cls");
		goto start;
	}
	adminread.close();
}

void main_menu()
{
	system("COLOR 07");
	system("cls");
	int choice;
	start:
	cout << "\t\t\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
	cout << "\t\t\t\t |                                              |\n";
	cout << "\t\t\t\t|             Student Management System          |\n";
	cout << "\t\t\t\t |                                              |\n";
	cout << "\t\t\t\t|                   Main Menu                  |\n";
	cout << "\t\t\t\t |                                              |\n";
	cout << "\t\t\t\t|                 1. Admin                     |\n";
	cout << "\t\t\t\t |                                              |\n";
	cout << "\t\t\t\t|                 2. Student                   |\n";
	cout << "\t\t\t\t |                                              |\n";
	cout << "\t\t\t\t|                 3. Exit                      |\n";
	cout << "\t\t\t\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|";
	cout << "\n\n\t\t\t\t\t" << "Choose an option, then press <Enter>: ";
	cin >> choice;

	switch (choice)
    {
    	case 1:
    		adviser_login();
    		break;

    	case 2:
    		student();
    		break;

    	case 3:
    		system("cls");
    		cout << "\n\n\n\n\n\t\t\t\t      THANK YOU FOR USING OUR APP... GOODBYE!";
			Sleep(2500);
			exit(0);

    	default:
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
    		cin.ignore(20, '\n');
	}
	Sleep(1000);
	goto start;
}

void display_all()
{
	Profile a;
	ifstream open("Record.txt");
	if (!open)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		cout << "\t\t\t\t\t            CLASS RECORD\n";
		cout << "\t\t\t\t\t  -------------------------------\n";
		while(open.read((char*)&a, sizeof(a)))
		{
			cout << "Record read successfully" << std::endl;
			a.disp_student_profiles();
			cout << "\n\n\t\t\t\t\t  -------------------------------\n\n";
		}
		system("pause");
	}
	open.close();
}

void launch()
{
	welcome();
	main_menu();
}



