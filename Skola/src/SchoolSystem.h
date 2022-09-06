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

	void AddStudentMenu();


	std::vector<Student> students;
	std::vector<std::string> schoolClasses;

};