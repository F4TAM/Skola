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

		switch (num)
		{
		case 1:

			system.AddStudent();

			break;

		}
		//Meny
		//input
		//Feedback

	}
}

void SchoolSystem::Meny()
{
	std::cout << "School System administration, Welcome!" << "\n";
	std::cout << "Here you can add students and classes and remove them!" << "\n";
	std::cout << "\n";
	std::cout << "Press 1 to add a student " << "\n" <<  "Press 2 to add a class " << "\n" << "Press 3 to remove a student " << "\n" << "Press 4 to remove a class " << "\n" <<
	"Press 5 to exit program" << "\n";
}

void SchoolSystem::AddStudent()
{
	Student student;
	bool confirmed = false;
	std::string input = "";


	while (!confirmed)
	{
		SchoolSystem::Clear();
		std::cout << "You're now adding a new student." << "\n\n";
		std::cout << "Start with the students name, write it down." << "\n";
		std::cout << "name: ";
		std::cin >> input;
		student.name = input;
		std::cout << "The name is now: " << input << "\n";
		std::cout << "Press 1 to Confirm " << "\n";
		std::cout << "Press 2 to Decline " << "\n";

		std::cin >> input;
		if (input == "1")
		{
			confirmed = true;
		}
	
	}

	SchoolSystem::Clear();
	std::cout << "The student name is saved " << "\n";
	std::cout << "Now write down the student age " << "\n";
	std::cout << "age: ";
	int age = 0;
	std::cin >> age;



	student.age = age;
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

void SchoolSystem::Clear()
{
	std::cout << "\x1B[2J\x1B[H";
}
