#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Student {
	char Name[20];
	int ID;
	float Grade;
	char delim='$';
};
int main()
{
	char chois;
	cout << "Enter Your Chois (y,n): ";
	cin >> chois;
	fstream file("students.txt", ios::out | ios::app);
	while (chois != 'n' && chois == 'y') {
		Student ob;
		cout << "Enter Name: ";
		cin.ignore();
		cin.getline(ob.Name, 20);
		file << ob.Name << ", ";

		cout << "Enter ID: ";
		cin >> ob.ID;
		file << ob.ID << ", ";

		cout << "Enter Grade: ";
		cin >> ob.Grade;
		file << ob.Grade << " " << ob.delim << "\n";
		
		cout << "Enter Your Chois (y,n): ";
		cin >> chois;
	}
	file.close();
	return 0;
}