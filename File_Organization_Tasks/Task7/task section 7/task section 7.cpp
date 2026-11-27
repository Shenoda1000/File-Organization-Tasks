#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	fstream file("students.txt", ios::out);
	if (file.good()) {
		cout << "open sucsess\n";
	}
	else {
		cout << "not open\n";
		return 0;
	}
	file << "Hadeer Mahmoud\n";
	file << "Youssef Ali\n";
	file << "Ahmed Mostafa\n";
	file << "Esraa Ebrahim\n";
	file.close();

	fstream file2("students.txt", ios::in);
	if (file2.good()) {
		cout << "open sucsess\n";
	}
	else {
		cout << "not open\n";
		return 0;
	}
	vector<string>names;
	string s;
	for (int i = 0; i < 4; i++) {
		getline(file2,s);
		names.push_back(s);
	}
	file2.close();
	sort(names.begin(), names.end());
	for (int i = 0; i < 4; i++) {
		cout << names[i] << "\n";
	}
	return 0;
}