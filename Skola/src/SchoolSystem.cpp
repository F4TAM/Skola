#include "SchoolSystem.h"


int num = 0;

void SchoolSystem::Run()
{
	bool running = true;

	while (running)
	{
		Meny();
		std::cin >> num;

		switch (num)
		{
		case 1:

			AddStudent();
			break;

		case 2:

			AddClass();
			break;

		case 3:
			RemoveStudent();
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
	std::string input = "";


	while (!nameConfirmed)
	{
		Clear();
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

	Clear();
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

	Clear();
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

	Clear();
	std::cout << "The student address is now saved " << "\n";
	
	std::cout << "\n";

	std::cout << "Now everything is done! " << "\n";
	students.push_back(student);

	std::cout << "Press any button to go to menu" << "\n";
	std::cin.ignore();
	std::cin.get();
}

void SchoolSystem::RemoveStudent()
{
	std::string name;
	std::string input = "";

	std::cout << "Write the name of the student you wish to remove!" << "\n";
	std::cout << "Name: " << "\n";

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].name == name)
		{
			std::cout << "Press any button to remove student!" << "\n";
			std::cin.get();

			students.erase(students.begin() + i);
		}

		else if(students[i].name != name)
		{
			std::cout << "The name did not exist in the system! " << "\n";

		}
	}

}

void SchoolSystem::AddClass()
{
	std::string classname = "";


	std::cout << "Hello! Here you create a new class for your schoolsystem!" << "\n";
	std::cout << "Please enter the name of the class you wish to create! " << "\n\n";
	std::cout << "Classname: ";

	std::cin.ignore();
	std::getline(std::cin, classname);

	schoolClasses.push_back(classname);

	std::cout << "Now you've added the class: ";

	for (size_t  i = 0; i <schoolClasses.size(); i++)
	{
		std::cout << schoolClasses.at(i) << "\n";
	}

	std::cout << "\n";
	std::cout << "press any button to go back to menu!" << "\n";

	std::cin.get();
	Clear();
}

void SchoolSystem::Clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

void SchoolSystem::AddStudentToClass()
{
	std::string name;
	std::string schoolclass;

	//feedback namn
	std::cin >> name;

	//feedback class
	std::cin >> schoolclass;

	for (auto& classes : schoolClasses)
	{
		if (classes != schoolclass) return;
	}

	for (auto& student : students)
	{
		if (student.name == name) student.SchoolClass = schoolclass;
	}

	//output
}
