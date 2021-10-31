#pragma once
#include <iostream>
#include <conio.h>

#include "Namespaces.h"
#include "Queriesh.h"

void getInput(int& input, int max) {
	while (true) {
		char* str = new char[25];
		std::cin >> str;
		input = std::atoi(str);
		if (input >= 1 && input <= max)
			break;
		else
			std::cout << "Please, input a corrent number (1-" <<
			max << ")\n";
	}
}

void waitForClick() {
	while (_getch()) {
		break;
	}
}

void executeUserInput(int num) {
	CRsdEnvironment envoirment("RDDrvO", "RDDrvO.dll");
	CRsdConnection connection(envoirment, "TestBase");
	CSQLCondition condition;

	char* name;
	int input;
	switch (num) {
	case(1):
		name = "Total number of students";
		std::cout << name << std::endl;
		Query_1(connection);
		break;
	case(2):
		name = "Information about students";
		std::cout << "Would you like to use a filter?\n\n"
			"1) Yes\n"
			"2) No\n";
		getInput(input, 2);
		if (input == 1) {
			system("cls");
			std::cout << "Would you like to filter a age?\n\n"
				"1) Yes\n"
				"2) No\n";
			getInput(input, 2);
			if (input == 1) {
				std::cout << "That a condition?\n\n"
					"1) Ages less than\n"
					"2) Ages equal\n"
					"3) Ages more than\n";
				getInput(input, 3);
				int value;
				std::cout << "Please, enter a value\n\n";
				getInput(value, INT_MAX);
				switch (input) {
				case(1):
					condition = MetaDataForStudentTable::age_field < value;
					break;
				case(2):
					condition = MetaDataForStudentTable::age_field == value;
					break;
				case(3):
					condition = MetaDataForStudentTable::age_field > value;
					break;
				}
			}
			system("cls");
			std::cout << "Would you like to filter a study year?\n\n"
				"1) Yes\n"
				"2) No\n";
			getInput(input, 2);
			if (input == 1) {
				std::cout << "That a condition?\n\n"
					"1) study year less than\n"
					"2) study year equal\n"
					"3) study year more than\n";
				getInput(input, 3);
				int value;
				std::cout << "Please, enter a value\n\n";
				getInput(value, INT_MAX);
				switch (input) {
				case(1):
					condition = condition && MetaDataForStudentTable::year_field < value;
					break;
				case(2):
					condition = condition && MetaDataForStudentTable::year_field == value;
					break;
				case(3):
					condition = condition && MetaDataForStudentTable::year_field > value;
					break;
				}
			}
			system("cls");
			std::cout << "Would you like to filter a gender?\n\n"
				"1) Yes\n"
				"2) No\n";
			getInput(input, 2);
			if (input == 1) {
				std::cout << "Choose a gender\n\n"
					"1) Male\n"
					"2) Famele\n";
				getInput(input, 2);
				switch (input) {
				case(1):
					condition = condition && MetaDataForStudentTable::gender_field == 0;
					break;
				case(2):
					condition = condition && MetaDataForStudentTable::gender_field == 1;
					break;
				}
			}
			system("cls");
		}
		Query_2(connection, condition);
		break;
	case(3):
		name = "Student tuition fees";
		std::cout << "Would you like to use a filter?\n\n"
			"1) Yes\n"
			"2) No\n";
		getInput(input, 2);
		if (input == 1) {
			system("cls");
			std::cout << "That a condition?\n\n"
				"1) Sum less than\n"
				"2) Sum equal\n"
				"3) Sum more than\n";
			getInput(input, 3);
			int value;
			std::cout << "Please, enter a value\n\n";
			getInput(value, INT_MAX);
			switch (input) {
			case(1):
				condition = MetaDataForStudyFeesTable::sum_field < value;
				break;
			case(2):
				condition = MetaDataForStudyFeesTable::sum_field == value;
				break;
			case(3):
				condition = MetaDataForStudyFeesTable::sum_field > value;
				break;
			}
			system("cls");
		}
		Query_3(connection, condition);
		break;
	case(4):
		name = "Teacher - subject";
		Query_4(connection);
		break;
	case(5):
		name = "Student - subject";
		std::cout << "Would you like to use a filter?\n\n"
			"1) Yes\n"
			"2) No\n";
		getInput(input, 2);
		if (input == 1) {
			system("cls");
			std::cout << "That a condition?\n\n"
				"1) Number of subjects less than\n"
				"2) Number of subjects equal\n"
				"3) Number of subjects more than\n";
			getInput(input, 3);
			int value;
			std::cout << "Please, enter a value\n\n";
			getInput(value, INT_MAX);
			switch (input) {
			case(1):
				condition = MetaDataForStudentTable::sumSubject_field < value;
				break;
			case(2):
				condition = MetaDataForStudentTable::sumSubject_field == value;
				break;
			case(3):
				condition = MetaDataForStudentTable::sumSubject_field > value;
				break;
			}
			system("cls");
		}
		Query_5(connection, condition);
		break;
	}
	std::cout << "\nClick any button\n";
	waitForClick();
	system("cls");
}

void startEventLoop() {
	while (true) {
		std::cout << "Please, choose a query:\n\n"
			"1) Total number of students\n"
			"2) Information about students\n"
			"3) Student tuition fees\n"
			"4) Teacher - subject\n"
			"5) Student - subject\n"
			"6) Exit\n";
		int num;
		getInput(num, 6);
		if (num == 6)
			break;
		system("cls");
		executeUserInput(num);
	}
}