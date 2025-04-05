/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 4/4/2025
* TA: Berkeley Conkling
* Assignment: PA7
******************************************************************************************/

#pragma once
#include "Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::RunApp()
{
	bool exitFlag = false;

	while (exitFlag != true)
	{
		exitFlag = this->DrawMenu();
	}
}

bool Menu::DrawMenu()
{
	bool flagExitApp = false,
	 flagValidChoice = false;

	int choice = 0;

	while (flagValidChoice == false)
	{
		system("cls");
		cout << "Please select an option: " << endl;
		cout << "1. Import course list" << endl;
		cout << "2. Load master list" << endl;
		cout << "3. Store master list" << endl;
		cout << "4. Mark absences" << endl;
		cout << "5. Edit absences" << endl;
		cout << "6. Generate report" << endl;
		cout << "7. Exit" << endl;

		cin >> choice;

		if (choice < 1 || choice > 7)
		{
			flagValidChoice = false;
			cout << "Error: Invalid choice. Press any key to try again." << endl;
			_getch();
		}
		else
		{
			flagValidChoice = true;
		}
	}

	//Line choice value up with enumerated type
	choice = choice - 1;

	//Switch-case controller for program
	switch (choice)
	{
		case IMPORT_COURSE_LIST:
			ImportCourseList();
			break;
		case LOAD_MASTER_LIST:
			LoadMasterList();
			break;
		case STORE_MASTER_LIST:
			StoreMasterList();
			break;
		case MARK_ABSENCES:
			MarkAbsences();
			break;
		case EDIT_ABSENCES:
			break;
		case GENERATE_REPORT:
			GenerateReport();
			break;
		case EXIT_PROGRAM:
			cout << "Exiting program. Goodbye!" << endl;
			flagExitApp = true;
			break;
	}

	return flagExitApp;
}

void Menu::ImportCourseList()
{
	string discardStr = "",
			bufferStr = "",
			usefulStr = "",
		   usefulStr2 = "";
	stringstream buffer;
	ifstream classFile;
	Data nodeData;

	cout << "Deleting master list..." << endl;
	mMasterList.deleteList(mMasterList.getHeadPtr());
	cout << "Master list deleted." << endl;

	cout << "Importing data from classList.csv..." << endl;

	classFile.open("classList.csv");

	getline(classFile, discardStr);	//ignore header
	while (!classFile.eof())
	{
		getline(classFile, bufferStr);
		buffer.str(bufferStr);					//put line into string stream

		getline(buffer, usefulStr, ',');		//start "tokenizing" to get useful substrings
		nodeData.setRecordNo(stoi(usefulStr));	//set Record No.
		getline(buffer, usefulStr, ',');
		nodeData.setIDNo(stoi(usefulStr));		//set ID No.
		getline(buffer, usefulStr, ',');
		getline(buffer, usefulStr2, ',');
		nodeData.setName(usefulStr + "," + usefulStr2);			//set Name
		getline(buffer, usefulStr, ',');
		nodeData.setEmail(usefulStr);			//set email
		getline(buffer, usefulStr, ',');
		nodeData.setUnits(usefulStr);		//set units
		getline(buffer, usefulStr, ',');
		nodeData.setProgram(usefulStr);			//set program
		getline(buffer, usefulStr, ',');
		nodeData.setLevel(usefulStr);

		buffer.clear();
		mMasterList.insert(nodeData);
	}

	cout << "Data imported. Press any key to continue." << endl;

	classFile.close();
	_getch();
}

void Menu::LoadMasterList()
{
	string discardStr = "",
		bufferStr = "",
		usefulStr = "",
		usefulStr2 = "",
		tempStr = "";
	stringstream buffer;
	ifstream masterList;
	Data nodeData;
	stack<string> tempStack;
	int i = 0;

	cout << "Deleting master list..." << endl;
	mMasterList.deleteList(mMasterList.getHeadPtr());
	cout << "Master list deleted." << endl;

	cout << "Importing data from masterList.csv..." << endl;

	masterList.open("masterList.csv");

	getline(masterList, discardStr);	//ignore header
	while (!masterList.eof())
	{
		while (!tempStack.empty())		//reset temp stacks
		{
			tempStack.pop();
		}
		while (!nodeData.getAbsenceDates().empty())
		{
			nodeData.popAbsenceDate(tempStr);
			//cout << tempStr << endl;
		}

		getline(masterList, bufferStr);
		if (bufferStr != "")
		{
			buffer.str(bufferStr);					//put line into string stream

			getline(buffer, usefulStr, ',');		//start "tokenizing" to get useful substrings
			nodeData.setRecordNo(stoi(usefulStr));	//set Record No.
			getline(buffer, usefulStr, ',');
			nodeData.setIDNo(stoi(usefulStr));		//set ID No.
			getline(buffer, usefulStr, ',');
			getline(buffer, usefulStr2, ',');
			nodeData.setName(usefulStr + "," + usefulStr2);			//set Name
			getline(buffer, usefulStr, ',');
			nodeData.setEmail(usefulStr);			//set email
			getline(buffer, usefulStr, ',');
			nodeData.setUnits(usefulStr);		//set units
			getline(buffer, usefulStr, ',');
			nodeData.setProgram(usefulStr);			//set program
			getline(buffer, usefulStr, ',');
			nodeData.setLevel(usefulStr);			//set level
			getline(buffer, usefulStr, ',');
			nodeData.setNumAbsences(stoi(usefulStr));	//set number of absences

			if (nodeData.getNumAbsences() > 0)
			{
				for (i = 0; i < nodeData.getNumAbsences(); ++i)
				{
					getline(buffer, usefulStr, ',');
					tempStack.push(usefulStr);
				}
				nodeData.setAbsenceDates(tempStack);
			}

			buffer.clear();
			mMasterList.insert(nodeData);
		}
	}

	cout << "Data imported. Press any key to continue." << endl;

	masterList.close();
	_getch();
}

void Menu::StoreMasterList()
{
	Node<Data>* pTemp = mMasterList.getHeadPtr();
	stack<string> tempStack;
	ofstream masterFile("masterList.csv", std::ofstream::trunc);	//open file and put it in truncation mode so previous contents get destroyed
	int i = 0;

	cout << "Storing master list in masterList.csv..." << endl;

	//File first line formatting
	masterFile << "RecordNo,ID,Name,Email,Units,Program,Level,AbsenceNo,AbsenceDates" << endl;

	while (pTemp != nullptr)
	{
		masterFile << pTemp->getData().getRecordNo() << ",";
		masterFile << pTemp->getData().getIDNo() << ",";
		masterFile << pTemp->getData().getName() << ",";
		masterFile << pTemp->getData().getEmail() << ",";
		masterFile << pTemp->getData().getUnits() << ",";
		masterFile << pTemp->getData().getProgram() << ",";
		masterFile << pTemp->getData().getLevel() << ",";
		//masterFile << pTemp->getData().getNumAbsences() << endl;

		//deal with absence dates and number of absences
		if (pTemp->getData().getNumAbsences() > 0)
		{
			masterFile << pTemp->getData().getNumAbsences() << ",";
			tempStack = pTemp->getData().getAbsenceDates();		//use copy constructor from std::stack
			for (i = 0; i < pTemp->getData().getNumAbsences(); ++i)
			{
				if (i == pTemp->getData().getNumAbsences() - 1)
				{
					masterFile << tempStack.top() << endl;
				}
				else
				{
					masterFile << tempStack.top() << ",";
				}
				tempStack.pop();	//move through stack
			}
		}
		else
		{
			masterFile << pTemp->getData().getNumAbsences() << endl;
		}
		pTemp = pTemp->getNextPtr();	//advance through list
	}

	masterFile.close();					//close file
	cout << "Master list saved to masterList.csv. Press any key to continue." << endl;
	_getch();
}

void Menu::MarkAbsences()
{
	Node<Data>* pTemp = mMasterList.getHeadPtr();
	Data tempData;
	string tempStr = "";
	string dateStr = "";
	char choice = '\0';
	bool flagValidChoice = false;

	system("cls");

	// retrieved from StackOverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0); // get time now
	struct tm* now = localtime(&t);

	//putting date into a string and formatting
	dateStr = to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + "/" + to_string(now->tm_year + 1900);

	while (pTemp != nullptr)
	{
		flagValidChoice = false;
		while (!flagValidChoice)
		{
			
			while (!tempData.getAbsenceDates().empty())	//reset stack
			{
				tempData.popAbsenceDate(tempStr);
				cout << "Data popped: " << tempStr << endl;
			}
			cout << "Student Name: " << pTemp->getData().getName() << endl;
			cout << "Mark as absent? (y/n)" << endl;
			cin >> choice;
			if (choice != 'y' && choice != 'n')
			{
				cout << "Error: Invalid choice entered. Press any key to try again." << endl;
				_getch();
			}
			else
			{
				if (choice == 'y')
				{
					cout << "Marking absent..." << endl;
					//read data in list node to tempData
					tempData.setAbsenceDates(pTemp->getData().getAbsenceDates());
					tempData.setEmail(pTemp->getData().getEmail());
					tempData.setLevel(pTemp->getData().getLevel());
					tempData.setName(pTemp->getData().getName());
					tempData.setProgram(pTemp->getData().getProgram());
					tempData.setNumAbsences(pTemp->getData().getNumAbsences());
					tempData.setIDNo(pTemp->getData().getIDNo());
					tempData.setRecordNo(pTemp->getData().getRecordNo());
					tempData.setUnits(pTemp->getData().getUnits());
					//push date onto tempStack
					tempData.pushAbsenceDate(dateStr);
					//increment number of absences
					tempData.setNumAbsences(tempData.getNumAbsences() + 1);
					//write data to node
					pTemp->setData(tempData);
					cout << "Marked absent for " << dateStr << endl;
				}
				else
				{
					//do nothing
				}
				flagValidChoice = true;
			}
		}
		pTemp = pTemp->getNextPtr();	//advance through list
	}
	cout << "End of list reached. Press any key to continue." << endl;
	_getch();
}

void Menu::GenerateReport()
{
	bool flagValidChoice = false;
	int choice = -1,
 absenceFilter = -1;
	Node<Data>* pTemp = mMasterList.getHeadPtr();
	ofstream reportFile("report.csv", std::ofstream::trunc);

	while (!flagValidChoice)
	{
		system("cls");
		cout << "Please enter a choice for report formatting:" << endl;
		cout << "1. Show all student information with most recent absence date." << endl;
		cout << "2. Filter to only students at or above a certain number of absences." << endl;
		cin >> choice;

		if (choice != 1 && choice != 2)
		{
			cout << "Error: Invalid option entered. Press any key to try again." << endl;
			_getch();
		}
		else
		{
			flagValidChoice = true;
		}
	}

	if (choice == 1)
	{
		reportFile << "Record No.,ID No.,Email,Name,Program,Units,Level,No. of Absences,Most Recent Absence"
			<< endl;
		while (pTemp != nullptr)
		{
			reportFile << pTemp->getData().getRecordNo() << "," << pTemp->getData().getIDNo() <<
				"," << pTemp->getData().getEmail() << "," << pTemp->getData().getName() <<
				"," << pTemp->getData().getProgram() << "," << pTemp->getData().getUnits() <<
				"," << pTemp->getData().getLevel() << "," << pTemp->getData().getNumAbsences();

			if (pTemp->getData().getNumAbsences() > 0)
			{
				reportFile << "," << pTemp->getData().getAbsenceDates().top() << endl;
			}
			else
			{
				reportFile << endl;
			}
			pTemp = pTemp->getNextPtr();
		}
	}

	else if (choice == 2)
	{
		flagValidChoice = false;
		reportFile << "Record No.,ID No.,Email,Name,Program,Units,Level,No. of Absences,Most Recent Absence"
			<< endl;
		while (!flagValidChoice)
		{
			cout << "Please enter the number of absences you would like to filter by."
				<< endl;
			cin >> absenceFilter;

			if (absenceFilter < 0)
			{
				cout << "Error: Please enter a valid filter number. Press any key to try again."
					<< endl;
				_getch();
			}
			else
			{
				flagValidChoice = true;
			}
		}

		pTemp = mMasterList.getHeadPtr();	//reset temporary pointer to head pointer of list
		while (pTemp != nullptr)
		{
			if (pTemp->getData().getNumAbsences() >= absenceFilter)
			{
				reportFile << pTemp->getData().getRecordNo() << "," << pTemp->getData().getIDNo() <<
					"," << pTemp->getData().getEmail() << "," << pTemp->getData().getName() <<
					"," << pTemp->getData().getProgram() << "," << pTemp->getData().getUnits() <<
					"," << pTemp->getData().getLevel() << "," << pTemp->getData().getNumAbsences();

				if (pTemp->getData().getNumAbsences() > 0)
				{
					reportFile << "," << pTemp->getData().getAbsenceDates().top() << endl;
				}
				else
				{
					reportFile << endl;
				}
			}
			pTemp = pTemp->getNextPtr();	//traverse list
		}
	}
	reportFile.close();

	cout << "Report generated (see report.csv). Press any key to continue." << endl;
	_getch();
}
