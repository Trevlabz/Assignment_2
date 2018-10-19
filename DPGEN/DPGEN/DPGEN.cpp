// DPGEN.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Trevor LaBanz
// ECE574A Assignment 2

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(string File1, string File2){
    
	//temporary file selection
	/*
	cout << "Enter input netlist .txt file: ";
	cin >> netlistFile;
	cout << endl;

	cout << "Enter output .v file: ";
	cin >> verilogFile;
	cout << endl;
	*/
	string inputFile;
	string outputFile;
	   
	inputFile = "474a_circuit1.txt";
	outputFile = "474a_circuit1.v";

	//need input/output file handling
	//if incorrect files display a usage statement
	   


	//ifstream(inputFile, ios::in);
	ifstream iFile(inputFile);
	ofstream oFile(outputFile);

	string currentLine;
	
	while ( getline(iFile,currentLine)) {
		string outputLine = "";									//reset outputLine variable
		
		if (currentLine.empty()) {							//handle empty lines
			oFile << '\n';
			//debug
			cout << /*"emptyline" <<*/ endl;
		}

		else if ((currentLine.substr(0,2) == "//")) {		//handle comment lines
			oFile << '\n';
			//debug
			cout << /*"comment line" <<*/ endl;
		}

		else if (currentLine.substr(0, 5) == "input") {		//handle input lines
			outputLine.append("input ");
			
			if (currentLine.substr(6, 3) == "Int") {		//determine if signed or unsigned int
				outputLine.append("signed ");
			}
			else if(currentLine.substr(6, 4) == "UInt"){
				
			}
			else {
				cout << "Unknown dataType" << endl;			//unknown type
				break;
			}

			int dataSize = stoi(currentLine.substr(currentLine.find("Int") + 3, 2));		//convert 2 characters to the right of "Int" to integer and store in datasize
			if (dataSize > 1) {																//if datasize >1 convert to "[dataSize-1:0]"
				outputLine.append("[" + to_string(dataSize - 1) + ":0] ");
			}
			
			string tempString = currentLine.substr(currentLine.find("Int") + 5);			//create substring of inputname list  !!This will need to be broken up later

			outputLine.append(tempString + ";");			//append whole inputname list string 
			
			oFile << outputLine << '\n';

			//debug
			cout << outputLine << endl;
			
		}

		else if (currentLine.substr(0, 6) == "output") {		//handle output lines
			//convert output to verilog
			outputLine.append("output ");

			if (currentLine.substr(7, 3) == "Int") {		//determine if signed or unsigned int
				outputLine.append("signed ");
			}
			else if (currentLine.substr(7, 4) == "UInt") {

			}
			else {
				cout << "Unknown dataType" << endl;			//unknown type
				break;
			}

			int dataSize = stoi(currentLine.substr(currentLine.find("Int") + 3, 2));		//convert 2 characters to the right of "Int" to integer and store in datasize
			if (dataSize > 1) {																//if datasize >1 convert to "[dataSize-1:0]"
				outputLine.append("[" + to_string(dataSize - 1) + ":0] ");
			}

			string tempString = currentLine.substr(currentLine.find("Int") + 5);			//create substring of outputname list  !!This will need to be broken up later

			outputLine.append(tempString + ";");			//append whole outputname list string 

			oFile << outputLine << '\n';

			//debug
			cout << outputLine << endl;
		}

		else if (currentLine.substr(0, 4) == "wire") {		//handle wire declaration lines
			outputLine.append("wire ");

			if (currentLine.substr(5, 3) == "Int") {		//determine if signed or unsigned int
				outputLine.append("signed ");
			}
			else if (currentLine.substr(5, 4) == "UInt") {

			}
			else {
				cout << "Unknown dataType" << endl;			//unknown type
				break;
			}

			int dataSize = stoi(currentLine.substr(currentLine.find("Int") + 3, 2));		//convert 2 characters to the right of "Int" to integer and store in datasize
			if (dataSize > 1) {																//if datasize >1 convert to "[dataSize-1:0]"
				outputLine.append("[" + to_string(dataSize - 1) + ":0] ");
			}

			string tempString = currentLine.substr(currentLine.find("Int") + 5);			//create substring of outputname list  !!This will need to be broken up later

			outputLine.append(tempString + ";");			//append whole outputname list string 

			oFile << outputLine << '\n';

			//debug
			cout << outputLine << endl;
		}






		else {
			cout << "unconverted: " << currentLine << endl;
			//debug
			oFile << currentLine << '\n';
		}

	}



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


