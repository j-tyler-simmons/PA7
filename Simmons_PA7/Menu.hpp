#pragma once
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <conio.h>
#include <string>
#include <sstream>	//string streams
#include "List.hpp"
using std::cin;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::stoi;

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