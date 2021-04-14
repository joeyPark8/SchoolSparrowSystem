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


	cout << "a. 명렬표 보기" << endl << "b. 출석 기록 하기" << endl << "c. 출석 현황 보기" << endl << "d. 종료" << endl;
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