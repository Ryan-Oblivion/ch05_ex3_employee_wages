#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
    string filename = "wages.txt";
    
    ifstream infile;
    infile.open(filename);
	if (infile) {
		infile.close();
	}
}
