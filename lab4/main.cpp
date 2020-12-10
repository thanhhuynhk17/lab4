#include <iostream>
#include "Examinee.h"
using namespace std;


#pragma region CONSTANT VARIABLES

#define FNAME_IN "data.txt"
#define FNAME_OUT "data_out.txt"

#pragma endregion



int main() {

	vector<Examinee> lsExam = readExamineeList(FNAME_IN);
	writeTotal(lsExam, FNAME_OUT);
	cout << "Successfully." << endl;

	return 0;
}