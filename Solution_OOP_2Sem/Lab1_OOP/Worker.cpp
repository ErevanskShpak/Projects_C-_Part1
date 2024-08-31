#include "Worker.h"

bool Worker::Money::isCurrencyCorrect() const {
	size_t size = currency.size();
	for (int i = 0; i < size; ++i) {
		if (!(currency[i] >= 'a' && currency[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

void Worker::Money::setAmount() {
	cout << "Input amount: ";
	cin >> amount;
	while (!isNumberNumeric() || amount<=0) {
		cout << "Invalid input, please try again. The amount must consist only of digits and be greater than zero\n";
		cin >> amount;
	}
}

void Worker::Money::setCurrency() {
	cout << "Input currency: ";
	getline(cin, currency, '\n');
	while (!isCurrencyCorrect()) {
		cout << "Invalid input, please try again. The amount must consist only of little letters\n";
		getline(cin, currency, '\n');
	}
}

void Worker::setSalary(){
	cout << "Input salary\n";
	salary.setAmount();
	salary.setCurrency();
}

void Worker::showMainInfo() const {
	cout << "Worker: ";
	Person::showMainInfo();
}

void Worker::showAchievement() const {
	cout << "My salary is " << salary.getAmount() << " " << salary.getCurrency() << endl;
}