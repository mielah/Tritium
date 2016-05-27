#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line, cline;
	int c = 1;
	ofstream outFile;
	outFile.open("createDiseaseDatabase.sql"); //creates a new file to store the sql script
	
	ifstream inFile;
	ifstream conditionFile;
	inFile.open("diseaseName.txt"); //opens the disease name file
	
	outFile << "create database diseaseSurvival;\n\n"; //creates database
	outFile << "create table diseases (\n name varchar(255) NOT NULL,\n condition varchar(255),\n id int NOT NULL identity(1,1),\n mortality varchar(255),\n constraint pk_diseases primary key(id)\n);\n\n"; //creates diseases table
	
	while (getline(inFile, line)) {
		outFile << "insert into diseases (name) values ('" + line + "');\n"; //inserts the name into the table
	}

	inFile.close(); //finished reading all the names

	inFile.open("mortalities.txt"); //opens the survival percentage file
	conditionFile.open("condition.txt"); //opens the condition file
	
	while (getline(inFile, line) && getline(conditionFile, cline)) {
		outFile << "update diseases set mortality= '" + line + "', condition='" +cline + "' where id=" + to_string(c) + ";\n"; //inserts mortality rate
		c++;
	}

	inFile.close();
	conditionFile.close();
	outFile.close(); //closes the files

	return 0;
}
