#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("welcome.txt", ios::out);
    file << "Hello Everybody";
    file.seekp(11);
    file << "one ";
    file.close();
    return 0;
}