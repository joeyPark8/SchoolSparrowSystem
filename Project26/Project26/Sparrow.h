#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Sparrow
{
public:
	map<int, string> studentList;
	vector<int> studentNumberList;
	map<int, vector<string>> attendence;
	int day;

private:
	string studentListFilePath = "data/studentList.txt";
	string attendenceFilePath = "data/attendence.txt";

	vector<string> split(string str) {
		vector<string> splitedString;
		string word;
		int count = 0;
		for (char i : str) {
			count += 1;
			if (i != ' ' && count != str.length()) {
				word += i;
			}
			else {
				if (count == str.length()) word += i;
				splitedString.push_back(word);
				word = "";
			}
		}

		return splitedString;
	}

public:
	void load() {
		ifstream reader;

		reader.open(studentListFilePath);

		if (reader.is_open()) {
			string line;
			while (getline(reader, line)) {
				vector<string> splitedLine = split(line);
				
				const char* snum = splitedLine[1].c_str();
				int num = atoi(snum);
				string name = splitedLine[3];

				studentList.insert(pair<int, string>(num, name));
				studentNumberList.push_back(num);
			}
		}

		reader.close();

		reader.open(attendenceFilePath);

		if (reader.is_open()) {
			string line;
			while (getline(reader, line)) {
				vector<string> splitedLine = split(line);

				const char* snum = splitedLine[0].c_str();
				int num = atoi(snum);
				splitedLine.erase(splitedLine.begin());
				vector<string> history;

				for (string i : splitedLine) {
					history.push_back(i);
				}

				attendence.insert(pair<int, vector<string>>(num, history));
			}
		}

		reader.close();
	}

	void seeStudentList() {
		int count = 0;
		int index = 0;
		string tip;
		bool hasBeenChanged = false;
		for (auto [num, name] : studentList) {
			count += 1;
			index += 1;
			tip = (count % 2 == 0) ? ",\n" : ", ";
			if (num != studentNumberList[studentNumberList.size() - 1]) {
				tip = (num / 10 != studentNumberList[index] / 10) ? "\n" : tip;
				if (num / 10 != studentNumberList[index] / 10) {
					hasBeenChanged = true;
				}
			}
			if (hasBeenChanged == true) {
				count += 1;
				hasBeenChanged = false;
			}
			tip = (index == studentList.size()) ? "" : tip;
			cout << "번호: " << num << " 이름: " << name << tip;
		}
	}
};

