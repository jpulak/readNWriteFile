// program for validating opening/closing file
// output how much money made in each store based on file
// error handleing intigrated in case something is missing/wrong

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// func prototype

void processData(ifstream &inFile, ofstream &outFile);

// main func

int main() {
   
    // gather file input name
    
    string fileName;
    cout << "Please enter the input file name.";
    cin >> fileName;

    // open input file
    
    ifstream inFile(fileName);
    bool filesOpened = true;

    if (!inFile) 
    {
        cout << "\"" << fileName << "\"" << " could not be opened.";
        filesOpened = false;
    }

    // open output file if input file opens
    
    ofstream outFile("saleschart.txt");
    if (filesOpened && !outFile) 
    {
        cout << "saleschart.txt could not be opened" << endl;
        filesOpened = false;
        inFile.close();
    }

    // process data if both works
    
    if (filesOpened) 
    {
        processData(inFile, outFile);
        inFile.close();
        outFile.close();
    }
    cout << endl;
    return 0;
}

// process the data and output file

void processData(ifstream &inFile, ofstream &outFile) 
{
    unsigned int storeNum;
    int salesAmt;
    bool hasData = false;

    while (inFile >> storeNum >> salesAmt) 
    {
       
        // validate number
        
        if (storeNum >= 1 && storeNum <= 99) 
        {
           
            // validate sales amount
            
            if (salesAmt >= 0) 
            {
               
                // header if not made
                
                if (!hasData) 
                {
                    outFile << "SALES BAR CHART" << endl;
                    outFile << "(Each * equals 5,000 dollars)" << endl;
                    hasData = true;
                }

                // calc
                
                int numStars = salesAmt / 5000;
                outFile << "Store " << (storeNum < 10 ? " " : "") << storeNum << ": ";
                for (int i = 0; i < numStars; ++i) 
                {
                    outFile << "*";
                }
                outFile << endl;
            } 
            else 
            { 
                cout << "Skipped store #" << storeNum << "." << endl;
            }
        } 
        else 
        {
            cout << endl << storeNum << " is not in the range 1 through 99.";
        }
    }
}
