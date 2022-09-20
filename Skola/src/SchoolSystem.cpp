#include "SchoolSystem.h"


char num = '0';
void SchoolSystem::Run()
{
	SchoolSystem system;
	bool running = true;

	while (running)
	{

		system.Meny();
		std::cin >> num;

		switch (num)
		{
		case '1':

			system.AddStudent();
			break;
		case '2':
			system.AddClass();
			break;

		case '3':
			system.RemoveStudent();
			break;
			

		case '6':
			SchoolSystem::Clear();
			system.Meny();
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
	bool nameConfirmed = false;
	bool passConfirmed = false;
	bool addressConfirmed = false; 
	bool classConfirmed = false;
	std::string input = "";


	while (!nameConfirmed)
	{
		SchoolSystem::Clear();
		std::cout << "You're now adding a new student." << "\n\n";
		std::cout << "Start with the students name, write it down." << "\n";
		std::cout << "name: ";
		std::cin.ignore();
		std::getline(std::cin, input);
		student.name = input;
		std::cout << "The name is now: " << input << "\n";
		std::cout << "Press 1 to Confirm " << "\n";
		std::cout << "Press 2 to Decline " << "\n";

		std::cin >> input;
		if (input == "1")
		{
			nameConfirmed = true;
		}
	
	}

	SchoolSystem::Clear();
	std::cout << "The student name is saved " << "\n";
	while (!passConfirmed)
	{
		std::cout << "Now write down the student age " << "\n";
		std::cout << "age: ";
		int age = 0;
		std::cin >> age;
		student.age = age;
		std::cout << "The age is now: " << age << "\n";
		std::cout << "Press 1 to Confirm " << "\n";
		std::cout << "Press 2 to Decline " << "\n";

		std::cin >> input;
		if (input == "1")
		{
			passConfirmed = true;
		}
	}

	SchoolSystem::Clear();
	std::cout << "Student age has now been saved!" << "\n";
	while (!addressConfirmed)
	{
		std::cout << "Now write down the student adress " << "\n";
		std::cout << "address: ";
		std::cin.ignore();
		std::getline(std::cin, input);
		student.Address = input;
		std::cout << "The address is now: " << input << "\n";
		std::cout << "Press 1 to Confirm " << "\n";
		std::cout << "Press 2 to Decline " << "\n";

		std::cin >> input;
		if (input == "1")
		{
			addressConfirmed = true;
		}
	}

	SchoolSystem::Clear();
	std::cout << "The student address is now saved " << "\n";

	while (!classConfirmed)
	{
		std::cout << "Now write down the class you wish the student to be in " << "\n";
		std::cout << "Class: ";
		std::cin.ignore();
		std::getline(std::cin, input);
		student.SchoolClass = input;
		std::cout << "The class you wrote is: " << input << "\n";
		std::cout << "Press 1 to Confirm " << "\n";
		std::cout << "Press 2 to Decline " << "\n";

		std::cin >> input;
		if (input == "1")
		{
			classConfirmed = true;
		}
	}

	std::cout << "Now everything is done! " << "\n";
	students.push_back(student);

	SchoolSystem::Clear();
	std::cout << "Press 6 to return to menu!" << "\n";
	std::cin >> num;
}

void SchoolSystem::RemoveStudent()
{

}

void SchoolSystem::AddClass()
{
	Class addClass;
	std::cout << "Hello! Here you create a new class for your schoolsystem!" << "\n";

}

void SchoolSystem::Clear()
{
	std::cout << "\x1B[2J\x1B[H";
}
