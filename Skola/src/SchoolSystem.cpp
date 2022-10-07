#include "SchoolSystem.h"

//variabel to reach anywhere´, used to navigate the menu easier
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

		case 4:
			AddStudentToClass();
			break;

		case 5:
			StudentInfo();
			break;

		case 6:
			return;
		}
	}
}
void SchoolSystem::Meny()
{
	PrintS("School System administration, Welcome!");
	PrintS("Here you can add students and classes and remove them!");
	PrintS("");
	PrintS("Press 1 to add a student ");
	PrintS("Press 2 to add a class ");
	PrintS("Press 3 to remove a student ");
	PrintS("Press 4 to add a student to a class ");
	PrintS("Press 5 to get student info!");
	PrintS("Press 6 to exit program");
}
void SchoolSystem::AddStudent()
{
	Student student;
	//bools to check if the user wants to continue after writing down information
	bool nameConfirmed = false;
	bool ageConfirmed = false;
	bool addressConfirmed = false; 

	std::string input = "";

	//Writes name and checks
	while (!nameConfirmed)
	{
		Clear();
		PrintS("You're now adding a new student.");
		PrintS("Start with the students name, write it down.");
		PrintW("name: ");
		std::cin.ignore();
		std::getline(std::cin, input);
		student.name = input;

		PrintW("The name is now: ");
		PrintS(input);
		PrintS("Press 1 to Confirm ");
		PrintS("Press anything else to Decline ");

		std::cin >> input;
		if (input == "1")
		{
			nameConfirmed = true;
		}
	
	}
	Clear();
	PrintS("The student name is saved ");

	//Writes age and check
	while (!ageConfirmed)
	{
		PrintS("Now write down the student age ");
		PrintW("age: ");
		std::string age = "";
		std::cin >> age;
		student.age = age;

		PrintW("The age is now: ");
		PrintS(age);
		PrintS("Press 1 to Confirm ");
		PrintS("Press anything else to Decline ");

		std::cin >> input;
		if (input == "1")
		{
			ageConfirmed = true;
		}
	}
	Clear();
	PrintS("Student age has now been saved!");

	//writes address and check
	while (!addressConfirmed)
	{
		PrintS("Now write down the student adress ");
		PrintW("address: ");
		std::cin.ignore();
		std::getline(std::cin, input);
		student.Address = input;

		PrintW("The address is now: ");
		PrintS(input);
		PrintS("Press 1 to Confirm ");
		PrintS("Press anything to Decline ");

		std::cin >> input;
		if (input == "1")
		{
			addressConfirmed = true;
		}
	}

	Clear();
	PrintS("The student address is now saved ");
	PrintS("");
	PrintS("Now everything is done! ");

	students.push_back(student);

	PrintS("Press any button to go to menu");
	std::cin.ignore();
	std::cin.get();
}
void SchoolSystem::RemoveStudent()
{
	std::string name;
	std::string input = "";

	//Checks first if there is no students
	if (students.size() == 0)
	{
		PrintS("There is not any students registered to the system!");
		PrintS("Press any button to return to menu!");
		std::cin.ignore();
		std::cin.get();
		return;
	}
	// a goto if the user wrote wrong name and want to retry
	again:

	PrintS("Write the name of the student you wish to remove!");
	PrintW("Name: ");
	std::cin >> input;
	
		for (int i = 0; i < students.size(); i++)
		{
			//checks the number in the vector and removes the student
			if (students[i].name == name)
			{
				PrintS("Press any button to remove student!");
				std::cin.get();

				students.erase(students.begin() + i);
			}
			//some feedback if the name did not exist but students exist in the vector
			else if (students[i].name != name)
			{
				PrintS("The name did not exist in the system! ");
				PrintS("Press 1 to go back to write name or press 2 to go back to menu!");
				std::cin >> input;

				if (input == "2")
				{
					return;
				}
				else if (input == "1")
				{
					goto again;
				}
				else
				{
					//if the person does not write 1 or 2 when asked so
					PrintS("You have to press 1 to write down a new name or press 2 to go to menu!");
					std::cin >> input;
				}
				
			}
		}

		PrintS("Press any button to return to menu! ");
		std::cin.get();

}
void SchoolSystem::AddClass()
{
	//just adding a class, just straight forward here
	std::string classname = "";

	PrintS("Hello! Here you create a new class for your schoolsystem!");
	PrintS("Please enter the name of the class you wish to create! ");
	PrintW("Classname: ");

	std::cin.ignore();
	std::getline(std::cin, classname);

	schoolClasses.push_back(classname);

	PrintW("Now you've added the class: ");
	PrintS(classname);

	PrintS("press any button to go back to menu!");
	std::cin.get();
	Clear();
}
void SchoolSystem::Clear()
{
	// a clear function that moves the cursor down in the local Windows Debugger to make it look nicer
	std::cout << "\x1B[2J\x1B[H";
}
void SchoolSystem::AddStudentToClass()
{
	std::string name;
	std::string schoolclass;
	std::string input = "";

	if (schoolClasses.size() == 0)
	{
		PrintS("There is not any classes registered to the system!");
		PrintS("To create a new class press 2 in the menu");
		PrintS("");
		PrintS("Press any button to return to menu!");
		std::cin.ignore();
		std::cin.get();
		Clear();
		return;
	}
	if (students.size() == 0)
	{
		PrintS("There is not any students registered to the system!");
		PrintS("To create a new student press 1 in the menu!");
		PrintS("");
		PrintS("Press any button to return to menu!");
		std::cin.ignore();
		std::cin.get();
		Clear();
		return;
	}
	
	//a goto to rewrite the name if the person wrote it wrong
	Rewrite:
	PrintS("Write down the class name you wish to add a student to!");
	PrintW("Class: ");
	std::cin >> schoolclass;

		
	//Looking through the vector to check if the given class name did not exist
	for (auto& classes : schoolClasses)
	{
		if (classes != schoolclass)
		{
			PrintS("The given name of the schoolclass did not exist! ");
			PrintS("Do you wish to rewrite the class name or return to menu?");
			again:
			PrintS("Write 1 to rewrite and 2 to go to menu");
			std::cin >> input;

			if (input == "1")
			{
				goto Rewrite;
			}
			else if (input == "2")
			{
				return;
			}
			else
			{
				//if the person did not write 1 or 2 when asked so 
				PrintS("You have to write 1 or 2!");
				goto again;
			}
		}
	}
	//goto again if the person wrote the wrong name
	rewrite2:

	PrintW("Write the student name you wish to add to the class: ");
	PrintS(schoolclass);
	PrintW("Name: ");
	std::cin >> name;

	//checks if the name exist in the students vector
	for (auto& student : students)
	{
		if (student.name == name)
		{
			student.schoolClass = schoolclass;
		}
		else
		{
			//if the name did not exist
			PrintS("the given name did not exist in the system!");
			PrintS("Do you wish to rewrite it or go to menu?");
			again2:
			PrintS("press 1 to rewrite and 2 to go to menu");
			std::cin >> input;

			if (input == "1")
			{
				goto rewrite2;
			}
			else if (input == "2")
			{
				return;
			}
			else 
			{
				//as said earlier,
				PrintS("you have to press either 1 or 2!");
				goto again2;
			}
		}
	}
	PrintW("Now ");
	PrintW(name);
	PrintW(" has been added to ");
	PrintS(schoolclass);
	PrintS("Press any button to return to menu!");

	std::cin.ignore();
	std::cin.get();
	Clear();
}
void SchoolSystem::StudentInfo()
{
	std::string input = "";

	//another goto if the person wrote the wrong name and want to retry
	rewrite:
	PrintS("Write the name of the student you wish to see information about");
	PrintW("Name: ");
	std::cin.ignore();
	std::cin >> input;

	//checks first if the name does not exist in the vector
	for (auto& student : students)
	{
		if (student.name != input)
		{
			PrintS("The given name did not have any information added!");
			PrintS("Do you want to rewrite the name or return to menu to add a student?");
			again:
			PrintS("Press 1 to rewrite or 2 to go back to menu");

			std::cin >> input;
			if (input == "1")
			{
				goto rewrite;
			}
			else if (input == "2")
			{
				return;
			}
			else
			{
				PrintS("you have to write 1 or 2");
				std::cin.get();
				goto again;
			}

			
		}
		//if the name does exist the information about the student comes up.
		if (student.name == input)
		{
			PrintW("Student name: "); 
			PrintS(student.name);
			PrintW("Student age: ");
			PrintS(student.age);
			PrintW("Students class: ");
			PrintS(student.schoolClass);
			PrintW("Students address: ");
			PrintS(student.Address);
			PrintS("");
			
			PrintS("Press anything to go back to menu!");
			std::cin.ignore();
			std::cin.get();
			Clear();
			return;
		}

	}
}
void SchoolSystem::PrintS(std::string word)
{
	//A function to print out instead of std but here it skips the next line
	std::cout << word << "\n";
}
void SchoolSystem::PrintW(std::string word)
{
	//Pretty much the same thing but this one does not skip the next line
	std::cout << word;
}
