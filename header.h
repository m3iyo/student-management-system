#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;


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
	// STUDENT PROFILE FUNCTION FOR THE TEACHER/ADMIN TO INPUT THE STUDENT'S DETAILS
	void profile()
	{
		cout << "\n\n\t\t\t  -------------------------------\n";
		cout << "\t\t\t      CREATING STUDENT PROFILE\n";
		cout << "\t\t\t  -------------------------------\n";
		cout << "\t\tFILL OUT THE NEEDED INFORMATION, then press <Enter>\n";

		cout << "\n\t\tSTUDENT'S NAME: ";
		cin.ignore(20, '\n');
		cin.getline(student_name, 30);

		cout << "\n\t\tFATHER'S NAME: ";
		cin.getline(fathers_name, 30);

		cout << "\n\t\tMOTHER'S NAME: ";
		cin.getline(mothers_name, 30);

		cout << "\n\t\tDATE OF BIRTH(DD/MM/YY): ";
		cin.getline(dob, 30);

		cout << "\n\t\tPHONE NUMBER: ";
		cin.getline(phone_number, 20);

		cout << "\n\t\tCREATE STUDENT'S PIN(ex. 12345): ";
		cin.getline(pin, 20);

		cout << "\n\t\tCOLLEGE DEPARTMENT(ex. CICT, COE, CAS, COM): ";
		cin >> dept;
		cin.ignore(20, '\n');

		cout << "\n\t\tCOURSE and SECTION(ex. BSCS1B): ";
		cin.getline(section, 20);


		cout << "\n\t\tSTUDENT'S UNIVERSITY ID(ex. 20220099): ";
		cin >> uni_id;
		cin.ignore(20, '\n');

		cout << "\n\t\tNUMBER OF DAYS PRESENT: ";
		cin >> attendance;
		cin.ignore(20, '\n');

		system("pause");
		system("cls");

		cout << "\n\t\t\t\t\t  -------------------------------\n";
		cout << "\t\t\t\t\t           STUDENT'S GRADES\n";
		cout << "\t\t\t\t\t  -------------------------------\n";

		cout<<"\t\t\t\t       Statistics(STAT203)    : ";
		cin >> grades[0];
		cin.ignore(20, '\n');

		cout<<"\t\t\t\t       Web Development(CCS221)    : ";
		cin >> grades[1];
		cin.ignore(20, '\n');

		cout<<"\t\t\t\t       Visual Computing(CCS222)    : ";
		cin >> grades[2];
		cin.ignore(20, '\n');

		cout<<"\t\t\t\t       Computer Programming 2(CC203)    : ";
		cin >> grades[3];
		cin.ignore(20, '\n');

		cout<<"\t\t\t\t       Living in the IT Era(SS117)    : ";
		cin >> grades[4];
		cin.ignore(20, '\n');

		cout<<"\t\t\t\t       Purposive Communication(ENG110)    : ";
		cin >> grades[5];
		cin.ignore(20, '\n');

		cout << "\n";

		get_ave();
		get_rating();
	}

	// DISPLAYS THE REPORT CARD OF THE STUDENT WHEN CALLED, THE DETAILS THIS CONTAINS ARE INPUTTED BY THE TEACHER AT THE BEGINNING OF THE SCHOOL YEAR AND/OR AFTER A MAJOR EXAM
	void report_card()
	{
		cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		cout << "\t\t\t\t\t            REPORT CARD\n";
		cout << "\t\t\t\t\t  -------------------------------\n";

		cout << "\n\t\t\t\t\t          STUDENT PROFILE\n\n";
		cout << "\t\t\t\t\tNAME: " << student_name << std::endl;
		cout << "\t\t\t\t\tCOLLEGE DEPARTMENT: " << dept << std::endl;
		cout << "\t\t\t\t\tCOURSE and SECTION: " << section << std::endl;
		cout << "\t\t\t\t\tUNIVERSITY ID: " << uni_id << std::endl;
		cout << "\t\t\t\t\tDATE OF BIRTH: " << dob << std::endl;
		cout << "\t\t\t\t\tPHONE NUMBER: " << phone_number << std::endl;
		cout << "\t\t\t\t\tMOTHER's NAME: " << mothers_name << std::endl;
		cout << "\t\t\t\t\tFATHER's NAME: " << fathers_name << std::endl;

		cout << "\n\n\t\t\t\t\t  -------------------------------\n";
		cout << "\t\t\t\t\t        ACADEMIC PERFORMANCE\n";
		cout << "\t\t\t\t\t  -------------------------------\n";

		cout << "\t\t\t\t\tSUBJECT                GRADES\n\n";

		cout << "\t\t\t\t\tSTAT203\t\t\t" << grades[0] << std::endl;
		cout << "\t\t\t\t\tCCS221\t\t\t" << grades[1] << std::endl;
		cout << "\t\t\t\t\tCCS222\t\t\t" << grades[2] << std::endl;
		cout << "\t\t\t\t\tCC203\t\t\t" << grades[3] << std::endl;
		cout << "\t\t\t\t\tSS117\t\t\t" << grades[4] << std::endl;
		cout << "\t\t\t\t\tENG110\t\t\t" << grades[5] << std::endl;
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
    	cout << "\t\t\t\tSTAT203\tCC201\tCC202\tMTH101\tUTS110\tSS110"<< std::endl;;
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

#endif