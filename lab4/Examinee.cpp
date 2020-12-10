#include "Examinee.h"
#include <fstream>
#include <string>

using namespace std;


#pragma region Helper funtions

vector<string> splitStr(const string& str, const char& delim) {
	vector<string> lsAttr;

	int start = 0;
	int len = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == delim || i == str.length()-1){
			// get sub string length
			len = i-start;
			if (i == str.length() - 1){
				len += 1;
			}

			string subStr = str.substr(start, len);
			lsAttr.push_back(subStr);

			// update start
			start = i+1;
		}
	}
	
	int lsLen = lsAttr.size();
	if (lsLen < 15){
		for (int i = lsLen; i < 15; i++) {
			lsAttr.push_back("");
		}
	}

	return lsAttr;
}
#pragma endregion


#pragma region Read file

Examinee readExaminee(string line_info) {
	Examinee exam;

	vector<string> lsInfo = splitStr(line_info, ',');
	
	exam.id = lsInfo[0];
	exam.math = (lsInfo[2] == "")? 0:stof(lsInfo[2]);
	exam.literature = (lsInfo[3] == "") ? 0 : stof(lsInfo[3]);
	exam.physic = (lsInfo[4] == "") ? 0 : stof(lsInfo[4]);
	exam.chemistry = (lsInfo[5] == "") ? 0 : stof(lsInfo[5]);
	exam.biology = (lsInfo[6] == "") ? 0 : stof(lsInfo[6]);
	exam.history = (lsInfo[7] == "") ? 0 : stof(lsInfo[7]);
	exam.geography = (lsInfo[8] == "") ? 0 : stof(lsInfo[8]);
	exam.civic_education = (lsInfo[9] == "") ? 0 : stof(lsInfo[9]);
	// calculate by hand
	exam.natural_science = exam.physic + exam.chemistry + exam.biology;
	exam.social_science = exam.history + exam.geography + exam.civic_education;

	exam.foreign_language = (lsInfo[12] == "") ? 0 : stof(lsInfo[12]);

	return exam;
}

vector<Examinee> readExamineeList(string file_name) {
	vector<Examinee> lsExam;

	// Open file
	ifstream infile(file_name);
	if (infile) {
		string line; 		// Get line
		bool isHeader = true;

		while (!infile.eof()) {
			getline(infile, line);
			if (!isHeader){
				Examinee exam = readExaminee(line);
				lsExam.push_back(exam);

			}
			else{ // skip header
				isHeader = false;
				// do nothing
			}
		}
	}else{
		// Open file failed, do nothing.
	}

	// Close file
	infile.close();
	return lsExam;
}

#pragma endregion


#pragma region Write file

void writeTotal(vector<Examinee> examinee_list, string out_file_name) {
	// Open file
	ofstream infile(out_file_name);


	for (int i = 0; i < examinee_list.size(); i++){
		// Calculate total grade
		// total = math + literature + foreign_language + natural_science + social_science;
		float total_grade = examinee_list[i].math + examinee_list[i].literature +
							examinee_list[i].foreign_language +
							examinee_list[i].natural_science + examinee_list[i].social_science;

		// Write data
		infile << examinee_list[i].id << " " << total_grade << endl;
	}
	
	// Close file
	infile.close();
}

#pragma endregion