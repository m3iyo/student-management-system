/*
Program Title: A Simple C++ Student Management System

Submitted by: Lord Patrick Raizen Togonon, John Paul Sapasap, Matthew Andrei Valencia, Gem Win Canete, Jed Andrew Del Rosario

Program Description: The Program Takes in Inputs from both the admin and student. For the admin/teacher, first the program takes in a username and password which can be edited directly on the admin_credentials.txt file.
For the Student function, the program takes in inputs like the University ID and a PIN given by the Admin/Teacher (each student gets their own unique pin created by the Admin/Teacer)
*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <process.h>
#include <windows.h>
#include <iomanip>

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
void admin(); //CLASSROOM ADVISER FUNCTION
void student(); //STUDENT FUNCTION
void adviser_login(); //PASSWORD FUNCTION FOR THE TEACHER TO LOGIN TO GAIN ADMINISTRATIVE ACCESS
void main_menu(); //MAIN MENU
void display_all(); //DISPLAYS THE CLASS RECORD
void launch(); //CAlls the Main Menu and The Loading Bar

//The specification of the class "Profile"
//This "Profile" class can be used as an object in the main function or any other function blocks
class Profile
{
	private:
	char student_name[30];
	char fathers_name[30];
	char mothers_name[30];
	char dob[20];
	char phone_number[20];
	char section[20];
	char dept[5];
	int uni_id;
	float grades[6];
	char pin[20];
	int attendance;
	float average;
	char rating;

	void get_ave()
	{
		average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] + grades[5])/6;
	}

	void get_rating()
	{
		if (average >= 90)
		rating = 'A';

		else if ((average >= 85) && (average <= 89))
        rating = 'B';

        else if ((average >= 80) && (average <= 84))
        rating = 'C';

        else if((average >= 75) && (average <= 79))
        rating = 'D';

        else if(average < 75)
        rating = 'F'; //FAILURE
	}

	public:
	// STUDENT PROFILE FUNCTION FOR THE TEACHER TO INPUT THE STUDENT'S DETAILS
	void profile()
	{
		std::cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t      CREATING STUDENT PROFILE\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\tFILL OUT THE NEEDED INFORMATION, then press <Enter>\n";

		std::cout << "\n\t\t\t\tSTUDENT'S NAME: ";
		std::cin.ignore(20, '\n');
		std::cin.getline(student_name, 30);

		std::cout << "\n\t\t\t\tFATHER'S NAME: ";
		std::cin.getline(fathers_name, 30);

		std::cout << "\n\t\t\t\tMOTHER'S NAME: ";
		cin.getline(mothers_name, 30);

		std::cout << "\n\t\t\t\tDATE OF BIRTH(DD/MM/YY): ";
		cin.getline(dob, 30);

		std::cout << "\n\t\t\t\tPHONE NUMBER: ";
		cin.getline(phone_number, 20);

		std::cout << "\n\t\t\t\tCREATE STUDENT'S PIN(ex. 12345): ";
		cin.getline(pin, 20);

		std::cout << "\n\t\t\t\tCOLLEGE DEPARTMENT(ex. CICT, COE, CAS, COM): ";
		std::cin >> dept;
		std::cin.ignore(20, '\n');

		std::cout << "\n\t\t\t\tCOURSE and SECTION(ex. BSCS1B): ";
		cin.getline(section, 20);


		std::cout << "\n\t\t\t\tSTUDENT'S UNIVERSITY ID(ex. 20220099): ";
		std::cin >> uni_id;
		std::cin.ignore(20, '\n');

		std::cout << "\n\t\t\t\tNUMBER OF DAYS PRESENT: ";
		std::cin >> attendance;
		std::cin.ignore(20, '\n');

		system("pause");
		system("cls");

		std::cout << "\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t           STUDENT'S GRADES\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";

		std::cout<<"\t\t\t\t          It Era(SS117)  : ";
		std::cin >> grades[0];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t          Purposive Communication(ENG110)  : ";
		std::cin >> grades[1];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t          Computer Programming 2(CC203)  : ";
		std::cin >> grades[2];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t          Visual Computing(CCS222)  : ";
		std::cin >> grades[3];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t          Web Development(CCS221)  : ";
		std::cin >> grades[4];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t          Discrete(CIT201)  : ";
		std::cin >> grades[5];
		std::cin.ignore(20, '\n');

		std::cout << "\n";

		get_ave();
		get_rating();
	}

	// DISPLAYS THE REPORT CARD OF THE STUDENT WHEN CALLED, THE DETAILS THIS CONTAINS ARE INPUTTED BY THE TEACHER AT THE BEGINNING OF THE SCHOOL YEAR AND/OR AFTER A MAJOR EXAM
	void report_card()
	{
		std::cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t            REPORT CARD\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";

		std::cout << "\n\t\t\t\t\t          STUDENT PROFILE\n\n";
		std::cout << "\t\t\t\t\tNAME: " << student_name << std::endl;
		std::cout << "\t\t\t\t\tCOLLEGE DEPARTMENT: " << dept << std::endl;
		std::cout << "\t\t\t\t\tCOURSE and SECTION: " << section << std::endl;
		std::cout << "\t\t\t\t\tUNIVERSITY ID: " << uni_id << std::endl;
		std::cout << "\t\t\t\t\tDATE OF BIRTH: " << dob << std::endl;
		std::cout << "\t\t\t\t\tPHONE NUMBER: " << phone_number << std::endl;
		std::cout << "\t\t\t\t\tMOTHER's NAME: " << mothers_name << std::endl;
		std::cout << "\t\t\t\t\tFATHER's NAME: " << fathers_name << std::endl;

		std::cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t        ACADEMIC PERFORMANCE\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";

		std::cout << "\t\t\t\t\tSUBJECT                GRADES\n\n";

		std::cout << "\t\t\t\t\tSS117\t\t\t" << grades[0] << std::endl;
		std::cout << "\t\t\t\t\tENG110\t\t\t" << grades[1] << std::endl;
		std::cout << "\t\t\t\t\tCC203\t\t\t" << grades[2] << std::endl;
		std::cout << "\t\t\t\t\tCCS222\t\t\t" << grades[3] << std::endl;
		std::cout << "\t\t\t\t\tCCS221\t\t\t" << grades[4] << std::endl;
		std::cout << "\t\t\t\t\tCIT201\t\t\t" << grades[5] << std::endl;
	}

	//DISPLAYS THE PROFILE OF A SPECIFIC STUDENT WHEN CALLED
	void disp_student_profiles()
	{
		cout << "\t\t\t\t                      PROFILE" << std::endl;
		cout << "\n\t\t\t\tNAME: "<< student_name <<"\n";
    	cout << "\t\t\t\tMOTHER: "<< mothers_name << std::endl;
    	cout << "\t\t\t\tFATHER: "<< fathers_name <<"\n";
    	cout << "\t\t\t\tUNIVERSITY ID: "<< uni_id << std::endl;
    	cout << "\t\t\t\tPIN: "<< pin << std::endl;
    	cout << "\t\t\t\tDEPARTMENT: "<< dept << std::endl;
    	cout << "\t\t\t\tCOURSE and SECTION: "<< section << std::endl;;
    	cout << "\t\t\t\tPHONE NUMBER: "<< phone_number <<"\n\n";
    	cout << "\t\t\t\t                      GRADES" << "\n\n";
    	cout << "\t\t\t\tSS117\tENG110\tCC203\tCCS222\tCCS221\tCIT201"<< std::endl;;
    	cout << "\n\t\t\t\t" << grades[0] <<"\t" << grades[1] <<"\t"<< grades[2] <<"\t" << grades[3] << "\t" << grades[4] << "\t" << grades[5] << "\n\n";
    	cout << "\n\t\t\t\tAVERAGE: " << average << std::endl;;
    	cout << "\n\t\t\t\tRATING: " << rating << std::endl;
    	cout << "\n\t\t\t\tATTENDANCE: "<< attendance << std::endl;
	}
	friend void del_info();
    friend void update_info();
    friend void find_student();
    friend void my_profile();
    friend void subject_ranking();
    friend void ranking();

};

int main()
{
//	system("pause");
//	welcome();
	main_menu();
	getch();

	return 0;
}

void welcome()
{
	system("COLOR 0e");
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int load1 = 177, load2 = 219;

	std::cout << std::setprecision(0) << std::fixed;
	for (int i = 1; i <= 120; i++)
	{
		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING...." << 0.83333333333 * i << "%\n";
		for (int j = 1; j <= i; j++)
		std::cout << (char)load2;

		if (0.83333333333 * i >= 0 && i <= 22)
		{
			std::cout << "\n\t\t\t\t\t\tInitializing...";
		}
		if (0.83333333333 * i >= 20 && i <= 52)
		{
			std::cout << "\n\t\t\t\t\tRetrieving students data from database...";
		}
		if (0.83333333333 * i >= 50 && i <= 100)
		{
			std::cout << "\n\t\t\t\t\t\tStarting program...";
		}
		Sleep(50);
	}
	system("COLOR 0f");
	system("cls");
    std::cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t   Student Management System";
	std::cout << "\n\n\t\t\t\t\t\t\t     by";
	std::cout << "\n\n\t\t\t\t\t\t   Lord Patrick Togonon";
	std::cout << "\n\n\t\t\t\t\t\t   Gem Win Canete";
	std::cout << "\n\n\t\t\t\t\t\t   Matthew Andrei Valencia";
    std::cout << "\n\n\t\t\t\t\t\t   John Paul Sapasap";
    std::cout << "\n\n\t\t\t\t\t\t   Jed Andrew Del Rosario";
	std::cout << "\n\n\t\t\t\t\t\t\t   BSCS 1B";
    Sleep(4000);
    system("cls");
}

void create_info()
{
	Profile a;
	ofstream create("Record.txt", ios::binary|ios::app);
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
		std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		std::cout<<"\n\n\n\n\n\t\t\t\tENTER THE STUDENT'S UNIVERSITY ID: ";
		std::cin >> id;
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
			std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
		}
		else
		{
			std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     THE RECORD HAS BEEN DELETED SUCCESSFULLY\n\n\n\n\n\n\n\n";
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
		std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		std::cout<<"\n\n\n\n\n\t\t\t\tENTER THE STUDENT's UNIVERSITY ID: ";
		std::cin >> id;
		std::cin.ignore(20, '\n');
		system("cls");
		while(open1.read((char*)&a,sizeof(a)))
		{
			if (id == a.uni_id)
			{
				std::cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t     INPUT THE NEW/UPDATED INFO OF THE STUDENT";
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
			std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
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
		std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		std::cout<<"\n\n\n\n\n\t\t\t\tENTER THE STUDENT's UNIVERSITY ID: ";
		std::cin >> id;
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
			std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
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
		std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tENTER YOUR UNIVERSITY ID: ";
		cin >> id;
		std::cin.ignore(20, '\n');

		cout<<"\n\n\t\t\t\t\tENTER YOUR PIN: ";
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
			std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t ERROR ! ! ! RECORD DOES NOT EXIST !\n\n\n\n\n\n\n\n\n\n";
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
		std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
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
		std::cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t       CLASS RECORD(HI - LO)\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";

		for (int i = 0; i < n; i++)
		{
			b[i].disp_student_profiles();
			std::cout << "\n\n\t\t\t\t\t  -------------------------------\n\n";
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
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ERROR ! ! ! FILE NOT FOUND !\n\n\n\n\n\n\n\n\n\n";
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

    	std::cout<<"\n\n\n\n\n\n\t\t\t\t\t  ------------------------"<<"\n";
  		std::cout<<"\t\t\t\t\t     CHOOSE A SUBJECT"<<"\n";
    	std::cout<<"\t\t\t\t\t  ------------------------"<<"\n";
    	std::cout<<"\t\t\t\t\t\t  1. SS117"<<"\n";
		std::cout<<"\t\t\t\t\t\t  2. ENG110"<<"\n";
		std::cout<<"\t\t\t\t\t\t  3. CC203"<<"\n";
		std::cout<<"\t\t\t\t\t\t  4. CCS222"<<"\n";
    	std::cout<<"\t\t\t\t\t\t  5. CCS221"<<"\n";
    	std::cout<<"\t\t\t\t\t\t  6. CIT201"<<"\n\n";
    	std::cout<<"\t\t\t\t\t     ENTER YOUR CHOICE: ";
    	std::cin >> choice;
    	std::cin.ignore(1000, '\n');
    	system("cls");
    	std::cout << "\n";

    	if (choice > 6)
    	{
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
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

    	std::cout<<"\n\n\n\n\n\n";
        std::cout<<""<<"------------------------------------------------------------------------------------------------------------------------";
        std::cout<<""<<"\t\tRANK" << "\t\t\t\t\tNAME"<<"\t\t\t\t\tGRADES"<<"\n";
        std::cout<<""<<"------------------------------------------------------------------------------------------------------------------------"<<"\n\n\n\n\n";
        for(int i = 0;i < 5;++i)
        {
            std::cout<<"\t\t "<< i + 1 <<"\t\t\t " << b[i].student_name <<"\t\t\t\t  " << b[i].grades[count];
            std::cout<<endl;
        }
        std::cout<<""<<"------------------------------------------------------------------------------------------------------------------------";
        std::cout<<"\n\n\n";
        system("pause");
    }
}

void leaderboards()
{
	int choice;
	std::cout<<"\n\n\n\n\n\n\t\t\t\t\t     ------------------------"<<"\n";
  	std::cout<<"\t\t\t\t\t            LEADERBOARDS"<<"\n";
    std::cout<<"\t\t\t\t\t     ------------------------"<<"\n\n";
    std::cout<<"\t\t\t\t\t  1. VIEW RANKING BY GWA"<<"\n";
	std::cout<<"\t\t\t\t\t  2. VIEW RANKING PER SUBJECT"<<"\n";
	std::cout<<"\n\n\t\t\t\t\t            CHOICE: ";
    std::cin >> choice;
    std::cin.ignore (20, '\n');
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

void admin()
{
	int choice;
    start:
    system("cls");
    std::cout<<"\n\n\n\n\t\t\t\t\t\t------------------------"<<"\n";
    std::cout<<"\t\t\t\t\t\t         STUDENT"<<"\n";
    std::cout<<"\t\t\t\t\t\t------------------------"<<"\n\n";
    std::cout<<"\t\t\t\t\t     1. Create A New Student Profile"<<"\n";
    std::cout<<"\t\t\t\t\t     2. Find Student's Records'"<<"\n";
    std::cout<<"\t\t\t\t\t     3. View Classroom Leaderboards"<<"\n";
    std::cout<<"\t\t\t\t\t     4. View Class Records"<<"\n";
    std::cout<<"\t\t\t\t\t     5. Update Student's Record'"<<"\n";
    std::cout<<"\t\t\t\t\t     6. Delete a Record"<<"\n";
    std::cout<<"\t\t\t\t\t     7. Main Menu"<<"\n\n";
    std::cout<<"\t\t\t\t\t\t         CHOICE: ";;
    std::cin >> choice;
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
    std::cout<<"\n\n\n\n\t\t\t\t\t\t------------------------"<<"\n";
    std::cout<<"\t\t\t\t\t\t         STUDENT"<<"\n";
    std::cout<<"\t\t\t\t\t\t------------------------"<<"\n\n";
    std::cout<<"\t\t\t\t\t     1. View My Profile"<<"\n";
    std::cout<<"\t\t\t\t\t     2. View Classroom Leaderboards"<<"\n";
    std::cout<<"\t\t\t\t\t     3. Main Menu"<<"\n\n";
    std::cout<<"\t\t\t\t\t\t         CHOICE: ";;
    std::cin >> choice;
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

void admin_login()
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
		if (choice == 'Y' || 'y'){

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
	cin.ignore(20, '\n');
	while(strcmp(username,stored_username))
	{

		adminread >> stored_username;
		if(adminread.eof())
		{
			cout<<"\n\n\n\t\t\tUser not registered for the class. \n\t\t\tContact the chief administrator if this is a problem"<<endl;
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
		admin();
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
	std::cout << "\t\t\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
	std::cout << "\t\t\t\t |                                              |\n";
	std::cout << "\t\t\t\t|              Student Management System         |\n";
	std::cout << "\t\t\t\t |                                              |\n";
	std::cout << "\t\t\t\t|                    Main Menu                   |\n";
	std::cout << "\t\t\t\t |                                              |\n";
	std::cout << "\t\t\t\t|                  1. Teacher                    |\n";
	std::cout << "\t\t\t\t |                                              |\n";
	std::cout << "\t\t\t\t|                  2. Student                    |\n";
	std::cout << "\t\t\t\t |                                              |\n";
	std::cout << "\t\t\t\t|                  3. Exit                       |\n";
	std::cout << "\t\t\t\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|";
	std::cout << "\n\n\t\t\t\t\t" << "Choose an option, then press <Enter>: ";
	std::cin >> choice;

	switch (choice)
    {
    	case 1:
    		admin_login();
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
    		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     ERROR!! PLEASE TRY AGAIN!!\n\n\n\n\n\n\n\n";
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
		std::cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t            CLASS RECORD\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";
		while(open.read((char*)&a, sizeof(a)))
		{
			a.disp_student_profiles();
			std::cout << "\n\n\t\t\t\t\t  -------------------------------\n\n";
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
