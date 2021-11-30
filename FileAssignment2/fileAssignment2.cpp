//
//  main.cpp
//  FileAssignment2
//
//  Created by Samuel Rudqvist on 11/2/21.
//



#include <string>
#include <iostream>     // Header library, lets us use input and output (cout)
#include <fstream>      // Class to operate in files
using namespace std;    // Can use names for objects and variables from the standard library
                        // (replace std with blank)


struct personData {
    char name[25];
    char address[50];
    int age;
    char status;
};

personData theData[4] = {
    {"Davy Jones", "1234 Monkey Blvd.", 25, 'S'},
    {"Taylor Swift", "44 Sunset Drive", 31, 'S'},
    {"Maxwell Smart", "157 Riverside Ave.", 86, 'M'},
    {"Bjarne Stroustrup", "Denmark", 70, 'M'}
};


/*
void writeData();
void readData();
void printPerson(const personData& pd);
void readThirdRecord();*/

// Microsoft has deprecated fopen. This should allow the program to build in VS.
#pragma warning(disable : 4996)


void writeData(){
    cout << "\nWriting Output\n";
    ofstream writeFile("myoutput.dat", ios::out | ios::binary);
    if (!writeFile.good()) {
        cerr << "\nCould not open writeFile.\n";
    }
    for (int i = 0; i < 4; i++) {
        writeFile.write((char*)&theData[i], sizeof(personData));
    }
    writeFile.close();
    cout << "\nwriteFile has been closed\n";
    
}

void readData() {
    personData input[4];
    ifstream readFile;
    readFile.open("myoutput.dat", ios::in | ios:: binary);
    if (!readFile.good()) {
        cerr << "\nCould not open readFile\n";
        
    }
    
    int i = 0;
    while (!readFile.eof() && i < 5) {
        readFile.read((char*)&input[i], sizeof(personData));
        i++;
    }
    readFile.close();
    cout << "\nreadFile has been closed";
}

void readThirdRecord() {
    personData oneRecord;
    cout << "Reading third record" << endl;
    ifstream infile;
    infile.open("myoutput.dat", ios::in | ios::binary);
    if (!infile.good()) {
        cerr << "Could not open input file" << endl;
    }

    infile.seekg(2 * sizeof(personData));
    infile.read((char*)& oneRecord, sizeof(personData));
    infile.close();
    printPerson(oneRecord);

    cout << "Third record read" << endl;
}


void printPerson(const personData& pd) {
    cout << pd.name << ", " << endl << pd.address;
    cout << ", " << endl << pd.age << ", " << pd.status;
    cout << endl << endl;
}


int main()
{
    
    
    writeData();
    readData();
    readThirdRecord();
    
    return 0;
 }
