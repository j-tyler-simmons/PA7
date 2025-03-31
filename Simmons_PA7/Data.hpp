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
		int getUnits() const;
		string getProgram() const;
		string getLevel() const;
		int getNumAbsences() const;
		stack<string> getAbsenceDates() const;
		//setters
		void setRecordNo(const int newRecord);
		void setIDNo(const int newID);
		void setName(const string& newName);
		void setEmail(const string& newEmail);
		void setUnits(const int newUnits);
		void setProgram(const string& newProgram);
		void setNumAbsences(const int newNumAbsences);
		void setAbsenceDates(const stack<string> newAbsenceDates);
	private:
		int mRecordNo;
		int mIDNo;
		string mName;
		string mEmail;
		int mUnits;
		string mProgram;
		string mLevel;
		int mNumAbsences;
		stack<string> mAbsenceDates;
};