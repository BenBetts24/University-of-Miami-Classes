#include <iostream>
#include <string>
#include <fstream>
#include "support.h"
using namespace std;

void bubble(int arr[], const int size, int argc) {

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (argc != 5) { //if argc == 5, you told it to reverse, Only usable with command line input
				if (arr[j] > arr[j+1]) {
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			} else {
                                if (arr[j] < arr[j+1]) {
                                        int temp = arr[j+1];
                                        arr[j+1] = arr[j];
                                        arr[j] = temp;
                                }
			}
		}
	}
}

void shaker(int arr[], const int size, int argc) {

	int start = 0;
	int end = size - 1;

	if (argc != 5) {
		while (start < end) {
	
			for (int i = start; i < end; i++) {
				if (arr[i] > arr[i+1]) {
					int temp = arr[i+1];
					arr[i+1] = arr[i];
					arr[i] = temp;
				}
			}
	
			end--;
	
			for (int i = end; i > start; i--) {
				if (arr[i] < arr[i-1]) {
					int temp = arr[i-1];
					arr[i-1] = arr[i];
					arr[i] = temp;
				}
			}
	
			start++;
		}
	} else {
		while (start < end) {

        	        for (int i = start; i < end; i++) {
                	        if (arr[i] < arr[i+1]) {
                        	        int temp = arr[i+1];
                                	arr[i+1] = arr[i];
                                	arr[i] = temp;
                        	}
                	}

                	end--;

                	for (int i = end; i > start; i--) {
                        	if (arr[i] > arr[i-1]) {
                                	int temp = arr[i-1];
                                	arr[i-1] = arr[i];
                                	arr[i] = temp;
                        	}
                	}

                	start++;
        	}
	}
}

void selection(int arr[], const int size, int argc) {
	int min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (argc != 5) {
				if (arr[min] > arr[j]) {
					min = j;
				}
			} else {
                                if (arr[min] < arr[j]) {
                                        min = j;
                                }
			}
		}

	int temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;

	}
}

void insertion(int arr[], const int size, int argc) {

	for (int i = 1; i < size; i++) {

		int temp = arr[i];
		int j = i - 1;

		if (argc != 5) {
			while (j >= 0 && arr[j] > temp) {
			
				arr[j+1] = arr[j];
				j--;

			}
		} else {
                        while (j >= 0 && arr[j] < temp) {

                                arr[j+1] = arr[j];
                                j--;

                        }
		}

		arr[j+1] = temp;

	}
}

int getNumber(string fileName, int arr[], const int size) {
	
	ifstream source(fileName.c_str());
	int index = 0;
	
	while (!source.eof() && (index < size)) {
		source >> arr[index];
		index++;
	}

	source.close();

	return (index);
}

void menu(int &size, string &fileName, int &type, int argc, char** argv) {

	string typeString;

	if (argc <= 1) { //checks if the number of arguments passed in included this information
		cout << "Please enter the size of the array you wish to sort: ";
		cin >> size;
		cout << "Please enter the name of the file you wish to read from: ";
		cin >> fileName;
		cout << "Please select a sorting algorithm (bubble, shaker, selection, or insertion): ";
		cin >> typeString;
		type = 5;
	} else {
		size = atoi(argv[1]);
		fileName = argv[2];
		typeString = argv[3];
		type = 5;
	}

	do {

	if (type == 0) {
		cout << "Please enter a listed algorithm: ";
		cin >> typeString;
	}

	if (typeString == "Bubble" || typeString == "bubble" || typeString == "b")
		type = 1;
	else if (typeString == "Shaker" || typeString == "shaker" || typeString == "c")
		type = 2;
	else if (typeString == "Selection" || typeString == "selection" || typeString == "s")
		type = 3;
	else if (typeString == "Insertion" || typeString == "insertion" || typeString == "i")
		type = 4;
	else
		type = 0;
	
	} while (type == 0);


}

void writeFile(string fileName, int arr[], int size, int type) {

	ofstream output;
	string  outName;

	if (type == 1) {
		outName = "bubble_" + fileName;
		output.open(outName.c_str());
	} else if (type == 2) {
                outName = "shaker_" + fileName;
                output.open(outName.c_str());
        } else if (type == 3) {
                outName = "selection_" + fileName;
                output.open(outName.c_str());
        } else if (type == 4) {
                outName = "insertion_" + fileName;
                output.open(outName.c_str());
        }

	for (int i = 0; i < size; i++) {
		output << arr[i] << endl;	
	}

	output.close();
}

void print(int arr[], const int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char** argv) {

	int size = 5;
	string fileName;
	int type;
	
	menu(size, fileName, type, argc, argv);
	
	int * arr = new int[size];
	
	int actual = getNumber(fileName, arr, size);
	cout << "File Succesfully Read" << endl;
	if (actual != size)
		cout << "The requested size was " << size << " but the file only contained " << actual << " integers!" << endl;
	
	double startTime = getCPUTime();
	
	switch (type) {
		case 1: bubble(arr, actual, argc); break;
		case 2: shaker(arr, actual, argc); break;
		case 3: selection(arr, actual, argc); break;
		case 4: insertion(arr, actual, argc); break;
	}

	double endTime = getCPUTime();

	double timeTaken = endTime - startTime;
	cout << "Sorting took: " << timeTaken << " seconds." << endl;;

	//print(arr, size);
	writeFile(fileName, arr, size, type);

	return 0;
}
