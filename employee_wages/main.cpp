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
        string name;
        double hourly_wage;
        double hours;
        double total;
        string line;
        int loop_num = 0;
        int processed_num = 0 ;
        
        // need to put this outside the while loop so it is only displayed once
        cout << fixed << setprecision(2)
        << left << setw(10) << "Name" << right << setw(10) <<  "Hourly wage" << setw(10) << "Hours" << setw(10) << "Total" << endl << endl;
        // this code below is attempting to get the bars that separate the header above and the data below
        cout << setw(10) << setfill('-') ;
        cout << setw(11) << "- " << setw(11) << "- " << setw(11) << "- " << setw(11) << "- "<< endl;
        cout << setfill(' ');
        
        while (getline(infile, line)){
            stringstream ss;
            ss.str(line);
            ss.clear();
            
            if (infile.eof()){
                cout << "You have reached the end of the file. Bye!" << endl;
                break;
            }
            else if (ss >> name >> hourly_wage >> hours){
                
                total = hourly_wage * hours;
//                cout << fixed << setprecision(2)
//                << setw(10) << "Name" << setw(8) <<  "Hourly wage" << setw(8) << "Hours" << setw(8) << "Total" << endl << endl;
                cout << left << setw(10) << name << right << setw(10) << hourly_wage << setw(10) << hours << setw(10) << total << endl;
                processed_num += 1;
            }
            loop_num += 1;
            
        }
		infile.close();
        
        cout << loop_num - processed_num << " lines not processed\n";
        
	}
}
