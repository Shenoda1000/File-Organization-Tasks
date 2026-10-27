#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	fstream read("fruit.txt", ios::in);
	string f1, f2, f3;
	read >> f1 >> f2 >> f3;
	cout << f1 << " " << f2 << " " << f3 << "\n";
	read.close();
	fstream write("fruit.txt", ios::out | ios::app);
	write << "Fresh Fruits\n";
	write.close();
	return 0;
}