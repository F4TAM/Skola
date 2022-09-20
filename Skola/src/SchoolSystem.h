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


	std::vector<Student> students;
	std::vector<Class> schoolClasses;

};