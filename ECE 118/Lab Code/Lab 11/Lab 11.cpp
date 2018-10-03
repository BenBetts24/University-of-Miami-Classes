#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include <sys/resource.h>
#include <map>
using namespace std;

struct date {
	int year;
	int month;
	int day;
};

struct person {
	string firstName;
	string lastName;
	date birthday;
	string state;
	long int ssn;
	double balance;

	void printPerson()
	{
		cout << firstName << " ";
		cout << lastName << " ";
		cout << birthday.year << " ";
		cout << birthday.month << " ";
		cout << birthday.day << " ";
		cout << state << " ";
		cout << ssn << " ";
		cout << balance << endl;
	}

	void filePrintPerson(ofstream& output)
	{
		output << firstName << " ";
                output << lastName << " ";
                output << birthday.year << " ";
                output << birthday.month << " ";
                output << birthday.day << " ";
                output << state << " ";
                output << ssn << " ";
                output << balance << endl;
	}

	void printState()
	{
		cout << state << " ";
		cout << firstName << " ";
		cout << lastName << " ";
		cout << balance << endl;
	}
};

double get_cpu_time()
{ 
	struct rusage ruse;
	getrusage(RUSAGE_SELF, &ruse);
	return ruse.ru_utime.tv_sec+ruse.ru_utime.tv_usec/1000000.0 + ruse.ru_stime.tv_sec+ruse.ru_stime.tv_usec/1000000.0;
}

bool name_compare(string name_one, string name_two)
{
	if (name_one.length() != name_two.length())
		return false;

	for (int index = 0; index < name_one.length(); index++)
		if ((name_one[index] !=  toupper(name_two[index])) && (name_one[index] != tolower(name_two[index])))
			return false;

	return true;
}

void match_names(person pArray[], const int arraySize, string name)
{
	int count = 0;

	for (int index = 0; index < arraySize; index++)
	{
		if (name_compare(pArray[index].firstName, name) || name_compare(pArray[index].lastName, name))
		{
			pArray[index].printPerson();
			count++;
		}
	}

	if (count == 0)
		cout << "No matches!" << endl;
}

void print_oldest(person pArray[], const int arraySize)
{
	person oldest;
	oldest.birthday.year = 2050;
	oldest.birthday.month = 20;
	oldest.birthday.day = 50;

	for (int index = 0; index < arraySize; index++)
	{
		if (pArray[index].birthday.year < oldest.birthday.year)
			oldest = pArray[index];
		else if (pArray[index].birthday.year == oldest.birthday.year)
		{
			if (pArray[index].birthday.month < oldest.birthday.month)
				oldest = pArray[index];
			else if (pArray[index].birthday.month == oldest.birthday.month)
			{
				if (pArray[index].birthday.day < oldest.birthday.day)
					oldest = pArray[index];
			}
		}
	}

	oldest.printPerson();
}

int find_youngest(person pArray[], const int arraySize, const int start)
{
	int yIndex;
	person youngest;
	youngest.birthday.year = 0;
	youngest.birthday.month = 0;
	youngest.birthday.day = 0;

	for (int index = start; index < arraySize; index++)
	{
		if (pArray[index].birthday.year > youngest.birthday.year)
		{
                        youngest = pArray[index];
			yIndex = index;
		}
                else if (pArray[index].birthday.year == youngest.birthday.year)
                {
                        if (pArray[index].birthday.month > youngest.birthday.month)
			{
                                youngest = pArray[index];
				yIndex = index;
			}
                        else if (pArray[index].birthday.month == youngest.birthday.month)
                        {
                                if (pArray[index].birthday.day > youngest.birthday.day)
				{
                                        youngest = pArray[index];
					yIndex = index;
				}
                        }
                }

	}

	return yIndex;
		
}

map <string, int> statesMap(person pArray[], const int arraySize)
{
	map <string, int> states;

	for (int index = 0; index < arraySize; index++)
	{
		if (states.find(pArray[index].state) == states.end())
			states.insert(pair<string, int>(pArray[index].state, index));
		else if (pArray[states[pArray[index].state]].balance < pArray[index].balance)
			states[pArray[index].state] = index;
	}	

	return states;
}

void main()
{
	ifstream data("/home/www/students/lokesh/labs/data/data100.txt");
	ofstream output("people_out.txt");
	person pArray[100000];
	int arraySize = sizeof(pArray)/sizeof(pArray[0]);

	if (data.is_open() && output.is_open())
	{
		for (int index = 0; index < arraySize; index++)
		{
			data >> pArray[index].firstName >> pArray[index].lastName;
			data >> pArray[index].birthday.year >> pArray[index].birthday.month >> pArray[index].birthday.day;
			data >> pArray[index].state >> pArray[index].ssn >> pArray[index].balance;
		}
	
		data.close();
	
		int storeIndex;
		person storePerson;

		double sortTime = get_cpu_time();

		for (int index = 0; index < arraySize - 1; index++)
		{
			storeIndex = find_youngest(pArray, arraySize, index);
			storePerson = pArray[index];
			pArray[index] = pArray[storeIndex];
			pArray[storeIndex] = storePerson;
		}

		sortTime = get_cpu_time() - sortTime;

		for (int index = 0; index < arraySize; index++)
			pArray[index].filePrintPerson(output);
	
		cout << "File Created in " << sortTime << "!" << endl;
		cout << "File size: " << arraySize << endl;
	
		output.close();

		cout << "STATE    FIRSTNAME    LASTNAME    BANKBALANCE" << endl << endl;

		map <string, int> states = statesMap(pArray, arraySize);

		for (map<string, int>::iterator it = states.begin(); it != states.end(); ++it)
			pArray[it->second].printState();
	}
	else
		cout << "One or more files could not be opened!" << endl;
}
