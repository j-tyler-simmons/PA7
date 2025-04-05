/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 4/4/2025
* TA: Berkeley Conkling
* Assignment: PA7
******************************************************************************************/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <conio.h>
#include <string>
#include <sstream>	//string streams
#include <stack>
#include "List.hpp"
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::getline;
using std::stringstream;
using std::stoi;
using std::to_string;
using std::stack;

enum menuChoice
{
	IMPORT_COURSE_LIST,
	LOAD_MASTER_LIST,
	STORE_MASTER_LIST,
	MARK_ABSENCES,
	EDIT_ABSENCES,
	GENERATE_REPORT,
	EXIT_PROGRAM
};
class Menu
{
	public:
		//core constructor
		Menu();
		//copy constructor: not needed
		//copy assignment operator: not needed
		//destructor
		~Menu();

		//getters: not needed
		//setters: not needed

		//public member functions
		void RunApp();
		bool DrawMenu();
		void ImportCourseList();
		void LoadMasterList();
		void StoreMasterList();
		void MarkAbsences();
		void EditAbsences();		
		void GenerateReport();

	private:
		List<Data> mMasterList;
};