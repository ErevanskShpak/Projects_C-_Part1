#include "People.h"

People::People() {
	vec.resize(3);
	size = 3;
	vec[0] = new Worker("Daniil", "Paulouski", Worker::Money(3000, "dollars"));
	vec[1] = new Student("Aleksandra", "Solodukha", "Highschool 10", {
		Student::Grade("OOP", 10),
		Student::Grade("Math", 8),
		Student::Grade("OAIP", 9)
		});
	vec[2] = new StudentWorker("Anton", "Huleu", "Highschool 10", {
		Student::Grade("OOP", 4),
		Student::Grade("Math", 3),
		Student::Grade("OAIP", 2)
		}, Worker::Money(500, "rubles"));
}

void People::push_back(){
	cout << "1. Student\n2. Worker\n3. StudentWorker\nInput: ";
	int choice;
	cin >> choice;
	while (!isNumberNumeric() || !(choice>=1 && choice<=3)) {
		cout << "Invalid input, please try again. The number must consist of digits and be less than the size of the array\n";
		cin >> choice;
	}
	
	switch (choice) {
		case 1: {
			Student man1;
			man1.setName();
			man1.setSurname();
			man1.setSchool();
			man1.setGrades();
			vec.push_back(new Student(man1));
			break;
		}
		case 2: {
			Worker man2;
			man2.setName();
			man2.setSurname();
			man2.setSalary();
			vec.push_back(new Worker(man2));
			break;
		}
		case 3: {
			StudentWorker man3;
			man3.setName();
			man3.setSurname();
			man3.setSchool();
			man3.setGrades();
			man3.setSalary();
			vec.push_back(new StudentWorker(man3));
			break;
		}
	}
	size++;
}

void People::erase() {
	if (!size) {
		cout << "There are no persons\n";
		return;
	}
	unsigned int i;
	cout << "Enter number of person\n";
	cin >> i;
	while (!isNumberNumeric() || !(i > 0 && i <= size)) {
		cout << "Invalid input, please try again. The number must consist of digits and be less than the size of the array\n";
		cin >> i;
	}

	vec.erase(vec.begin()+i-1);
	size--;
}

void People::showPerson() const {
	if (!size) {
		cout << "There are no persons\n";
		return;
	}
	int i;
	cout << "Enter number of person\n";
	cin >> i;
	while (!isNumberNumeric() || !(i > 0 && i <= size)) {
		cout << "Invalid input, please try again. The number must consist of digits and be less than the size of the array\n";
		cin >> i;
	}

	vec[i - 1]->showMainInfo();
	vec[i - 1]->showAchievement();
}

void People::showAll() const {
	if (!size) {
		cout << "There are no persons\n";
		return;
	}

	for (Person* cur : vec) {
		cur->showMainInfo();
	}
}

void People::sortPersons() {
	if (!size) {
		cout << "There are no persons\n";
		return;
	}
	sort(vec.begin(), vec.end(), [&](Person* a, Person* b) {
		return a->getName() < b->getName();
		});
	showAll();
}