#ifndef HEADER_H
#define HEADER_H

#include <iostream>

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
		std::cout << "\n\n\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t      CREATING STUDENT PROFILE\n";
		std::cout << "\t\t\t  -------------------------------\n";
		std::cout << "\t\tFILL OUT THE NEEDED INFORMATION, then press <Enter>\n";

		std::cout << "\n\t\tSTUDENT'S NAME: ";
		std::cin.ignore(20, '\n');
		std::cin.getline(student_name, 30);

		std::cout << "\n\t\tFATHER'S NAME: ";
		std::cin.getline(fathers_name, 30);

		std::cout << "\n\t\tMOTHER'S NAME: ";
		std::cin.getline(mothers_name, 30);

		std::cout << "\n\t\tDATE OF BIRTH(DD/MM/YY): ";
		std::cin.getline(dob, 30);

		std::cout << "\n\t\tPHONE NUMBER: ";
		std::cin.getline(phone_number, 20);

		std::cout << "\n\t\tCREATE STUDENT'S PIN(ex. 12345): ";
		std::cin.getline(pin, 20);

		std::cout << "\n\t\tCOLLEGE DEPARTMENT(ex. CICT, COE, CAS, COM): ";
		std::cin >> dept;
		std::cin.ignore(20, '\n');

		std::cout << "\n\t\tCOURSE and SECTION(ex. BSCS1B): ";
		std::cin.getline(section, 20);


		std::cout << "\n\t\tSTUDENT'S UNIVERSITY ID(ex. 20220099): ";
		std::cin >> uni_id;
		std::cin.ignore(20, '\n');

		std::cout << "\n\t\tNUMBER OF DAYS PRESENT: ";
		std::cin >> attendance;
		std::cin.ignore(20, '\n');

		system("pause");
		system("cls");

		std::cout << "\n\t\t\t\t\t  -------------------------------\n";
		std::cout << "\t\t\t\t\t           STUDENT'S GRADES\n";
		std::cout << "\t\t\t\t\t  -------------------------------\n";

		std::cout<<"\t\t\t\t       Computer Programming 1(CC202)    : ";
		std::cin >> grades[0];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t       Web Development(CCS221)    : ";
		std::cin >> grades[1];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t       Visual Computing(CCS222)    : ";
		std::cin >> grades[2];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t       Computer Programming 2(CC203)    : ";
		std::cin >> grades[3];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t       Living in the IT Era(SS117)    : ";
		std::cin >> grades[4];
		std::cin.ignore(20, '\n');

		std::cout<<"\t\t\t\t       Purposive Communication(ENG110)    : ";
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

		std::cout << "\t\t\t\t\tSTAT203\t\t\t" << grades[0] << std::endl;
		std::cout << "\t\t\t\t\tCCS221\t\t\t" << grades[1] << std::endl;
		std::cout << "\t\t\t\t\tCCS222\t\t\t" << grades[2] << std::endl;
		std::cout << "\t\t\t\t\tCC203\t\t\t" << grades[3] << std::endl;
		std::cout << "\t\t\t\t\tSS117\t\t\t" << grades[4] << std::endl;
		std::cout << "\t\t\t\t\tENG110\t\t\t" << grades[5] << std::endl;
	}

	//DISPLAYS THE PROFILE OF A SPECIFIC STUDENT WHEN CALLED
	void disp_student_profiles()
	{
		std::cout << "\t\t\t\t                      PROFILE" << std::endl;
		std::cout << "\n\t\t\t\tNAME: "<< student_name <<"\n";
    	std::cout << "\t\t\t\tMOTHER: "<< mothers_name << std::endl;
    	std::cout << "\t\t\t\tFATHER: "<< fathers_name <<"\n";
    	std::cout << "\t\t\t\tUNIVERSITY ID: "<< uni_id << std::endl;
    	std::cout << "\t\t\t\tPIN: "<< pin << std::endl;
    	std::cout << "\t\t\t\tDEPARTMENT: "<< dept << std::endl;
    	std::cout << "\t\t\t\tCOURSE and SECTION: "<< section << std::endl;;
    	std::cout << "\t\t\t\tPHONE NUMBER: "<< phone_number <<"\n\n";
    	std::cout << "\t\t\t\t                      GRADES" << "\n\n";
    	std::cout << "\t\t\t\tSTAT203\tCC201\tCC202\tMTH101\tUTS110\tSS110"<< std::endl;;
    	std::cout << "\n\t\t\t\t" << grades[0] <<"\t" << grades[1] <<"\t"<< grades[2] <<"\t" << grades[3] << "\t" << grades[4] << "\t" << grades[5] << "\n\n";
    	std::cout << "\n\t\t\t\tAVERAGE: " << average << std::endl;;
    	std::cout << "\n\t\t\t\tRATING: " << rating << std::endl;
    	std::cout << "\n\t\t\t\tATTENDANCE: "<< attendance << std::endl;
	}
	friend void del_info();
    friend void update_info();
    friend void find_student();
    friend void my_profile();
    friend void subject_ranking();
    friend void ranking();

};

#endif
