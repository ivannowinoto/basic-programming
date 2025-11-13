#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

int main()
{
	int n;
	string name, ID, bday;
	
	while (cin >> n) {
		fstream file;
		file.open("data.txt", fstream::in | fstream::app);
		switch (n) {
			case 1:
				while (file >> name) {
					file >> ID >> bday;
					cout << "Name: " << name << endl;
					cout << "Number: " << ID << endl;
					cout << "Birthday: " << bday << endl;
					cout << endl;
				}
				break;
			case 2:
				cin >> name >> ID >> bday;
				file << name << " " << ID << " " << bday << endl;
				break;
			case 3:
				file.close();
				return 0;
			default:
				cout << "Invalid input!";
				break;
		}
	}
	return 0;
} 
