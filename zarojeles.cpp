#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> load_file(const string& file_name, int& size);
bool is_valid(const int& size);
void print_brackets(const vector<char>& _vec);

int main(){

	int nyitora = 0;
	int size = 0;

	vector<char> _vec = load_file("input.txt", size);
	bool valid = is_valid(size);

	if (valid) {
		cout << "Helyes\n";
		print_brackets(_vec);
	}
	else
		cout << "Helytelen\n";

	return 0;
}



vector<char> load_file(const string& file_name, int& size) {
	ifstream inputf(file_name.c_str());
	char data;
	vector<char> _vec;
	while (inputf >> data) {
		_vec.push_back(data);
		//cout << data << endl;
		if (data == '(')
			size++;
		else if (data == ')')
			size--;
	}
	inputf.close();
	return _vec;
}

bool is_valid(const int& size) {
	if (size == 0)
		return true;
	else
		return false;
}

void print_brackets(const vector<char>& _vec) {
	int nyitora = 0;
	for (int i = 0; i < _vec.size(); i++) {
		if (_vec[i] == '(') {
			nyitora = 0;
			for (int j = i; j < _vec.size(); j++) {
				//cout << nyitora << endl;
				if (_vec[j] == '(') {
					nyitora++;
				}
				else if (_vec[j] == ')') {
					nyitora--;
				}
				if (nyitora == 0)
					cout << '(' << i << ", " << j << ')' << endl;
				//cout << nyitora << endl;
			}
		}
	}
}
