// Lab_10.1.2
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count_strs(ifstream &stream) {
	string tmp;
	int count = 0;
	size_t pos;
	while (!stream.eof()) {
		getline(stream, tmp);
		pos = 0;
		while (pos = tmp.find(',', pos), pos != -1 && pos < tmp.length()-2) {
			++pos;
			if (tmp[++pos] == '-')
				count++;
			else --pos;
		}
	}
	return count;
}

void main() {
	string t;

	cout << "Input filename: "; cin >> t;

	ifstream stream(t);
	if (stream.is_open()) {
		cout << "Count strs in file: " << count_strs(stream);
		stream.close();
	}
	else cout << "Incorrect file name!";
	cout << endl;
}