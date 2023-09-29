#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    ifstream inFile("index.html");

    if (!inFile.is_open()) 
    {
        cout << "The file index.html could not be opened" << endl;
        return 1;
    }

    string line;
    int errorCount = 0; 
    bool Tag = false;

    while (getline(inFile, line)) 
    {
        cout << line << endl;

        for (char c : line) 
        {
            if (c == '<') 
            {
                Tag = true;
            }
            else if (c == '>') 
            {
                if (!Tag) 
                {
                    ++errorCount;
                }
                Tag = false;
            }
        }

       Sleep(150);
    }
    
    inFile.close();

    cout << "Number of HTML validation errors: " << errorCount << endl;

    if (errorCount == 0) 
    {
        cout << "The file is a VALID HTML file" << endl;
    }
    else 
    {
        cout << "The file is NOT a VALID HTML file" << endl;
    }

    return 0;
}
