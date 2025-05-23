/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 4/4/2025
* TA: Berkeley Conkling
* Assignment: PA7
******************************************************************************************/

#pragma once
#include <iostream>
#include <stack>
using std::string;
using std::stack;
using std::cout;
using std::cerr;
using std::endl;

class Data
{
	public:
		//core constructor
		Data(int newRecord = 0, int newID = 0, 
			string newName = "", string newEmail = "", 
			int newUnits = 0, string newProgram = "",
			string newLevel = "", int newNumAbsences = 0);
		//copy constructor
		Data(Data& newData);
		//copy assignment operator
		Data& operator=(Data& rhs);
		//destructor
		~Data();
		//getters
		int getRecordNo() const;
		int getIDNo() const;
		string getName() const;
		string getEmail() const;
		string getUnits() const;
		string getProgram() const;
		string getLevel() const;
		int getNumAbsences() const;
		stack<string> getAbsenceDates() const;
		//setters
		void setRecordNo(const int newRecord);
		void setIDNo(const int newID);
		void setName(const string& newName);
		void setEmail(const string& newEmail);
		void setUnits(const string& newUnits);
		void setProgram(const string& newProgram);
		void setLevel(const string& newLevel);
		void setNumAbsences(const int newNumAbsences);
		void setAbsenceDates(const stack<string> newAbsenceDates);

		//member functions
		void pushAbsenceDate(const string& newDate);
		void popAbsenceDate(string& storageStr);

	private:
		int mRecordNo;
		int mIDNo;
		string mName;
		string mEmail;
		string mUnits;
		string mProgram;
		string mLevel;
		int mNumAbsences;
		stack<string> mAbsenceDates;
};