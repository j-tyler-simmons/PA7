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

	switch (choice)
	{
		case 1:
			ImportCourseList();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
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

void Menu::StoreMasterList()
{
	Node<Data>* pTemp = mMasterList.getHeadPtr();
	stack<string> tempStack;
	ofstream masterFile;
	int i = 0;

	masterFile.open("masterFile.csv");	//open file

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
	}

	masterFile.close();					//close file
}
