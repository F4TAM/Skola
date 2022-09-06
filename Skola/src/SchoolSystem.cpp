#include "SchoolSystem.h"

void SchoolSystem::Run()
{
	SchoolSystem system;
	int num = 0;
	bool running = true;

	while (running)
	{

		system.Meny();
		std::cin >> num;

		//Meny
		//input
		//Feedback

		switch (num)
		{
		case 1:


			break;

		}
	}
}

void SchoolSystem::Meny()
{
	std::cout << "Welcome to schoolsystem! " << "\n";
	std::cout << "Here you can add students and classes and remove them!" << "\n";
	std::cout << "\n";
	std::cout << "Press 1 to add a student " << "\n" <<  "Press 2 to add a class " << "\n" << "Press 3 to remove a student " << "\n" << "Press 4 to remove a class " << "\n" <<
	"Press 5 to exit program" << "\n";
}

void SchoolSystem::AddStudent()
{
	Student student;
	student.name = "blabal";
	student.age = 123;
	student.Adress = "";
	student.number = "";
	students.push_back(student);
}

void SchoolSystem::RemoveStudent()
{

}

void SchoolSystem::AddStudentMenu()
{

}
