#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Person {
	string name;
	int age;
};
int main() {
	int n;
	cout << "Enter how many persons you want to add: ";
	cin >> n;
	fstream file("details.txt", ios::out);
	for (int i = 1; i <= n; i++) {
		Person ob;
		cout << "Enter the name of person number " << i << ": ";
		cin >> ob.name;
		cout << "Enter the age of person number " << i << ": ";
		cin >> ob.age;
		file << ob.name << " " << ob.age << "\n";
	}
	file.close();

	vector<Person>v(n);
	fstream file2("details.txt", ios::in);
	string nameP;
	int ageP;
	for (int i = 0; i < n; i++) {
		file2 >> nameP;
		file2 >> ageP;
		v[i].name = nameP;
		v[i].age = ageP;
	}
	file2.close();
	int indexOfYounger = 0;
	int indexOfOlder = 0;
	int youngerAge = v[0].age;
	int olderAge = v[0].age;
	for (int i = 1; i < n; i++) {
		if (v[i].age < youngerAge) {
			youngerAge = v[i].age;
			indexOfYounger = i;
		}
		if (v[i].age > olderAge) {
			olderAge = v[i].age;
			indexOfOlder = i;
		}
	}
	fstream file3("results.txt", ios::out);
	file3 << "the younger person:-\n";
	file3 << "name: " << v[indexOfYounger].name << "\n";
	file3 << "age: " << v[indexOfYounger].age << "\n";
	cout << "\n";
	file3 << "the older person:-\n";
	file3 << "name: " << v[indexOfOlder].name << "\n";
	file3 << "age: " << v[indexOfOlder].age << "\n";
	file3.close();
	return 0;
}