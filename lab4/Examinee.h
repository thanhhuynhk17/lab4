#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Examinee.h
struct Examinee
{
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;

};



#pragma region Helper funtions
vector<string> splitStr(const string& str, const char& delim);

#pragma endregion


#pragma region Read file
/// <summary>
/// Get 1 student information
/// </summary>
/// <param name="line_info">1 line in dataset (except header)</param>
/// <returns>Examinee object</returns>
Examinee readExaminee(string line_info);

/// <summary>
/// Get all students information
/// </summary>
/// <param name="file_name">File name</param>
/// <returns>List Examinee</returns>
vector<Examinee> readExamineeList(string file_name);
#pragma endregion


#pragma region Write file
/// <summary>
/// Export total grade 
/// </summary>
/// <param name="examinee_list">List exam</param>
/// <param name="out_file_name">File name of report</param>
void writeTotal(vector<Examinee> examinee_list, string out_file_name);

#pragma endregion
