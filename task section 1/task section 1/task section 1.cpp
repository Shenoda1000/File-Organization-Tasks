#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string FullName;
	cout << "Enter Full Name: ";
	getline(cin, FullName);
	int ID;
	cout << "Enter ID: ";
	cin >> ID;
	int Grade;
	cout << "Enter Grade: ";
	cin >> Grade;
	ofstream file("Student.txt");
	file << "Full Name: " << FullName << "\n";
	file << "ID: " << ID << "\n";
	file << "Grade: " << Grade << "\n";
	file.close();
	return 0;
}