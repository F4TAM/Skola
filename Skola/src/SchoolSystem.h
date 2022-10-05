#pragma once
#include "Student.h"
#include <vector>
#include <iostream>

class SchoolSystem 
{
public:
	void Run();
	void Meny();
	void AddStudent();
	void RemoveStudent();
	void AddClass();
	void Clear();
	void AddStudentToClass();
	void StudentInfo();
	void PrintS(std::string word);
	void PrintW(std::string word);

	std::vector<Student> students;
	std::vector<std::string> schoolClasses;
};