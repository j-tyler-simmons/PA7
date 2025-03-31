#include "Data.hpp"

Data::Data(int newRecord, int newID,
	string newName, string newEmail,
	int newUnits, string newProgram,
	string newLevel, int newNumAbsences)
{
	if (newRecord > 999 || newRecord < 0)
	{
		cout << "ERROR: Invalid value for Record number, number will be set to -1." << endl;
		mRecordNo = -1;
	}
	else
	{
		mRecordNo = newRecord;
	}

	if (newID > 999999999 || newID < 0)
	{
		cout << "ERROR: Invalid value for ID number, number will be set to -1." << endl;
		mIDNo = -1;
	}
	else
	{
		mIDNo = newID;
	}
	
	mName = newName;
	mEmail = newEmail;
	mUnits = newUnits;
	mProgram = newProgram;
	mLevel = newLevel;
	mNumAbsences = newNumAbsences;
	
	while (mAbsenceDates.empty() != true)
	{
		mAbsenceDates.pop();
	}
}

Data::Data(Data& newData)
{
	if (newData.mRecordNo > 999 || newData.mRecordNo < 0)
	{
		cout << "ERROR: Invalid value for Record number, number will be set to -1." << endl;
		mRecordNo = -1;
	}
	else
	{
		mRecordNo = newData.mRecordNo;
	}

	if (newData.mIDNo > 999999999 || newData.mIDNo < 0)
	{
		cout << "ERROR: Invalid value for ID number, number will be set to -1." << endl;
		mIDNo = -1;
	}
	else
	{
		mIDNo = newData.mIDNo;
	}

	mName = newData.mName;
	mEmail = newData.mEmail;
	mUnits = newData.mUnits;
	mProgram = newData.mProgram;
	mLevel = newData.mLevel;
	mNumAbsences = newData.mNumAbsences;
	mAbsenceDates = newData.mAbsenceDates;
}

Data& Data::operator=(Data& rhs)
{
	if (rhs.mRecordNo > 999 || rhs.mRecordNo < 0)
	{
		cout << "ERROR: Invalid value for Record number, number will be set to -1." << endl;
		mRecordNo = -1;
	}
	else
	{
		mRecordNo = rhs.mRecordNo;
	}

	if (rhs.mIDNo > 999999999 || rhs.mIDNo < 0)
	{
		cout << "ERROR: Invalid value for ID number, number will be set to -1." << endl;
		mIDNo = -1;
	}
	else
	{
		mIDNo = rhs.mIDNo;
	}

	mName = rhs.mName;
	mEmail = rhs.mEmail;
	mUnits = rhs.mUnits;
	mProgram = rhs.mProgram;
	mLevel = rhs.mLevel;
	mAbsenceDates = rhs.mAbsenceDates;

	return *this;
}

Data::~Data()
{
}

int Data::getRecordNo() const
{
	return mRecordNo;
}

int Data::getIDNo() const
{
	return mIDNo;
}

string Data::getName() const
{
	return mName;
}

string Data::getEmail() const
{
	return mEmail;
}

int Data::getUnits() const
{
	return mUnits;
}

string Data::getProgram() const
{
	return mProgram;
}

string Data::getLevel() const
{
	return mLevel;
}

int Data::getNumAbsences() const
{
	return mNumAbsences;
}

stack<string> Data::getAbsenceDates() const
{
	return mAbsenceDates;
}

void Data::setRecordNo(const int newRecord)
{
	mRecordNo = newRecord;
}

void Data::setIDNo(const int newID)
{
	mIDNo = newID;
}

void Data::setName(const string& newName)
{
	mName = newName;
}

void Data::setEmail(const string& newEmail)
{
	mEmail = newEmail;
}

void Data::setUnits(const int newUnits)
{
	mUnits = newUnits;
}

void Data::setProgram(const string& newProgram)
{
	mProgram = newProgram;
}

void Data::setNumAbsences(const int newNumAbsences)
{
	mNumAbsences = newNumAbsences;
}

void Data::setAbsenceDates(const stack<string> newAbsenceDates)
{
	mAbsenceDates = newAbsenceDates;
}
