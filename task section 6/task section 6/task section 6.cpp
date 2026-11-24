#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream file("grades.txt", ios::out);
	if (file.good()) {
		cout << "grades.txt is opened\n";
	}
	else {
		cout << "grades.txt is not opened\n";
		return 0;
	}
	int grade;
	for (int i = 1; i <= 5; i++) {
		cout << "Enter grade number " << i << " :";
		cin >> grade;
		file << grade << " ";
	}
	file.close();

	fstream file2("grades.txt", ios::in);
	if (file2.good()) {
		cout << "grades.txt is opened\n";
	}
	else {
		cout << "grades.txt is not opened\n";
		return 0;
	}
	for (int i = 1; i <= 5; i++) {
		file2 >> grade;
		cout << grade << " ";
	}
	cout << "\n";
	file2.close();

	cout << "Enter grade for deleting: ";
	cin >> grade;
	fstream file3("grades.txt", ios::in);
	fstream temporary("temporary.txt", ios::out);
	if (file3.good() && temporary.good()) {
		cout << "grades.txt is opened\n";
		cout << "temporary.txt is opened\n";
	}
	else {
		if (file3.fail()) {
			cout << "grades.txt is not opened\n";
			temporary.close();
		}
		else if (temporary.fail()) {
			cout << "temporary.txt is not opened\n";
			file3.close();
		}
		else {
			cout << "grades.txt is not opened\n";
			cout << "temporary.txt is not opened\n";
		}
		return 0;
	}
	for (int i = 1; i <= 5; i++) {
		int x;
		file3 >> x;
		if (x != grade) {
			temporary << x << " ";
		}
	}
	file3.close();
	temporary.close();
	if (remove("grades.txt") == 0) {
		cout << "remove sucsess\n";
	}
	else {
		cout << "remove not sucsess\n";
	}
	if (rename("temporary.txt", "grades.txt") == 0) {
		cout << "rename sucsess\n";
	}
	else {
		cout << "rename not sucsess\n";
	}
	
	return 0;
}