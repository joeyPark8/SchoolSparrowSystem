#include "Sparrow.h"
#include <iostream>

using namespace std;

int main() {
	Sparrow bird;

	bird.load();

	for (auto [num, name] : bird.studentList) {
		cout << num << " : " << name << endl;
	}
	cout << endl;

	for (auto [num, history] : bird.attendence) {
		cout << num << " " << bird.studentList[num] << " | ";
		for (auto i : history) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "a. ���ǥ ����" << endl << "b. �⼮ ��� �ϱ�" << endl << "c. �⼮ ��Ȳ ����" << endl << "d. ����" << endl;
	cout << endl << "> ";
	
	char choice;
	cin >> choice;

	if (choice == 'a') {
		bird.seeStudentList();
	}
	else if (choice == 'b') {

	}
	else if (choice == 'c') {

	}
	else if (choice == 'd') {

	}

	return 0;
}