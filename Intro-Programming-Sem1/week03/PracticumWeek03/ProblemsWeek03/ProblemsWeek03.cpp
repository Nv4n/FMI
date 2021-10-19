#include <iostream>
using std::endl;

void AmIEligableToVote()
{
	//По въведена от конзолата възраст на гражданин(цяло число) да се провери дали той има право да гласува на изборите.Да се направи с if else конструкция и с тернарен оператор.

	int age;
	std::cout << "Input your age:";
	std::cin >> age;
	if (age >= 18) {
		std::cout << "You are eligable to vote!" << endl;
	}
	else {
		std::cout << "You are not eligable to vote!" << endl;
	}

	age >= 18 ? std::cout << "You are eligable to vote!" << endl : std::cout << "You are not eligable to vote!" << endl;;
}

void CheckSymbolCase()
{
	/*По въведен символ да се отпечата на екрана едно от следните съобщения : (Първо)Ако е малка буква - "The upper case character corresponding to is ...", (Второ)Ако е главна буква - "The lower case character corresponding to is ...", или(Трето) Ако не е буква - " is not a letter".Използвайте ASCII таблицата.
		Enter symbol : a
		The upper case character corresponding to 'a' is A*/

	char symbol;
	std::cout << "Input a symbol: ";
	std::cin >> symbol;

	if (symbol >= 'A' && symbol <= 'Z') {
		std::cout << "The lower case character corresponding to " << symbol << " is " << (char)(symbol + 32) << endl;
	}
	else if (symbol >= 'a' && symbol <= 'z') {
		std::cout << "The upper case character corresponding to " << symbol << " is " << (char)(symbol - 32) << endl;
	}
	else {
		std::cout << symbol << " is not a letter" << endl;
	}
}

void AreDigitsEqual()
{
	/*Проверете дали поне 2 от цифрите на трицифрено число са равни помежду си и изведете "True", ако е вярно и "False" иначе. Да се направи с if else конструкция и тернарен оператор.
	Пример: 133 Изход: True*/

	int number;
	std::cout << "Input a 3 digit number: ";
	std::cin >> number;
	int firstDigit = number / 100;
	int secondDigit = number / 10 % 10;
	int thirdDigit = number % 10;

	if (firstDigit == secondDigit || firstDigit == thirdDigit || secondDigit == thirdDigit) {
		std::cout << "True" << endl;
	}
	else {
		std::cout << "False" << endl;
	}

	firstDigit == secondDigit || firstDigit == thirdDigit || secondDigit == thirdDigit ? std::cout << "True" << endl : std::cout << "False" << endl;

	std::cout << std::boolalpha << (firstDigit == secondDigit || firstDigit == thirdDigit || secondDigit == thirdDigit) << endl;
}

void OutputConditionResult(bool value = false)
{
	value ? std::cout << "All conditions were met => Success" << endl : std::cout << "1 or more conditions weren't met => Fail" << endl;
}

void CheckTruthy()
{
	/*Да се напише булев израз, който да има стойност истина, ако посоченото условие е вярно и стойност лъжа, в противен случай :
		цялото число n се дели или на 3 и на 5, или на 2 и на 7;
		уравнението ax2 + bx + c = 0 има реални корени
		точка се намира извън фигурата тип “венец” с център(0, 0) и радиуси 2 и 8*/
	bool truthy = true;
	int numberN;
	std::cout << "Input a number n: ";
	std::cin >> numberN;
	if (!(numberN % 15 == 0 || numberN % 14 == 0)) {
		OutputConditionResult();
		return;
	}

	double numberA, numberB, numberC;
	std::cout << "Input a,b and c for the quadratic formula ax^2 + bx + c = 0: ";
	std::cin >> numberA >> numberB >> numberC;
	if (!(numberB * numberB - 4 * numberA * numberC >= 0)) {
		OutputConditionResult();
		return;
	}

	int pointX, pointY;
	std::cout << "Input point X and Y values: ";
	std::cin >> pointX >> pointY;
	double distance = std::sqrt(pointX * pointX + pointY * pointY);

	if (!(distance >= 2 && distance <= 8)) {
		OutputConditionResult();
		return;
	}
	//TODO Last condition

	OutputConditionResult(true);

}




void PointsDependingOnNumber()
{
	/*Дадено е цяло число – начален брой точки.Върху него се начисляват бонус точки по правилата, описани по - долу.Да се напише програма, която пресмята бонус точките, които получава числото и общия брой точки(числото + бонуса).

	Ако числото е до 100 включително, бонус точките са 5.
	Ако числото е по - голямо от 100, бонус точките са 20 % от числото.
	Ако числото е по - голямо от 1000, бонус точките са 10 % от числото.Допълнителни бонус точки(начисляват се отделно от предходните) : o За четно число -> + 1 т.o За число, което завършва на 5 -> + 2 т.Пример : Вход : 20 Изход : 6 26*/

	int startingPoints;
	std::cout << "Input your starting points: ";
	std::cin >> startingPoints;

	double bonus = 0;
	if (startingPoints <= 100) {
		bonus += 5;
	}
	else if (startingPoints > 1000) {
		bonus += startingPoints * 0.1;
	}
	else {
		bonus += startingPoints * 0.2;
	}

	if (startingPoints % 2 == 0) {
		bonus += 1;
	}
	else if (startingPoints % 10 == 5) {
		bonus += 2;
	}

	std::cout << "Bonus: " << bonus << " Total points: " << bonus + startingPoints << endl;
}

void VacationCalculator()
{
	//Поради големия студ, който се очаква, директорът на едно училище обявил ваканция с продължителност n дни, започваща от 22 януари 2006г.Напишете програма, която въвежда от стандартния вход числото n(2 < n < 22) и извежда на стандартния изход датата, на която учениците трябва да бъдат отново на училище.

	int vacationDuration;
	std::cout << "Input vacation's duration: ";
	std::cin >> vacationDuration;
	int day = 22 + vacationDuration;
	std::string month = "January";
	if (day > 31) {
		day -= 31;
		month = "February";
	}

	std::cout << "The end of the vacation will be on: " << day << "." << month << "." << 2006 << endl;
}

void TemperatureCalculator()
{
	/*Bonus task - Калкулатор за преобразуване на температура
		Преминаването от Фаренхайт към Целзий се извършва като извадите 32, умножите по 5 и разделите на 9. За преминаване от Целзий към Келвини добавяте 273.15.Напишете програма, която по въведени градуси по Фаренхайт да изведе на екрана градусите ои Целзий и / или Келвини.Изборът на изход зависи от въведена команда(след като сте въвели числената стойност) c, k, a(за целзий, калвинии двете).

		Пример: (примерните изходи са закръглени до втория знак) Вход : 0 a Изход : Celsium: -17.78 Kelvin : 255.37 Вход : 40 c Изход : Celsium: 4.4 Вход : 56 k Изход : Kelvin: 13.34*/

	double farenheit;
	char calculatorMode;
	std::cout << "Input the tempreture in farenheit and 'a'-all, 'k'-Kelvin or 'c'-Celsium depending on what result you want: " << endl;
	std::cin >> farenheit >> calculatorMode;
	calculatorMode = std::tolower(calculatorMode);

	double celsium = (farenheit - 32) * 5 / 9;
	double kelvin = celsium + 273.15;

	if (calculatorMode == 'a') {
		printf("Celsium: %.2f Kelvin: %.2f\n", celsium, kelvin);
	}
	else if (calculatorMode == 'k') {
		printf("Kelvin: %.2f\n", kelvin);
	}
	else if (calculatorMode == 'c') {
		printf("Celsium: %.2f\n", celsium);
	}
	else {
		std::cout << "No mode was selected!" << endl;
	}
}

void FamilyVacation()
{
	double budget;
	std::cout << "Input budget: ";
	std::cin >> budget;

	int days;
	std::cout << "Input how many days they will stay: ";
	std::cin >> days;

	double pricePerNight;
	std::cout << "Input the price per night: ";
	std::cin >> pricePerNight;
	if (days > 7)
	{
		pricePerNight *= 0.95;
	}

	int percentageAdditionalExpenses;
	std::cout << "Input percentage additional expenses: ";
	std::cin >> percentageAdditionalExpenses;

	double totalPrice = days * pricePerNight + budget * percentageAdditionalExpenses / 100;
	if (totalPrice <= budget) {
		std::cout << "Ivanovi will be left with " << budget - totalPrice << " leva after vacation." << endl;
	}
	else {
		std::cout << totalPrice - budget << " leva needed." << endl;
	}
}

int main()
{
	int taskIndex;
	std::cout << "Input specific task index: ";
	std::cin >> taskIndex;
	switch (taskIndex) {
	case 1: {
		AmIEligableToVote();
		break;
	}
	case 2: {
		CheckSymbolCase();
		break;
	}
	case 3: {
		AreDigitsEqual();
		break;
	}
	case 4: {
		CheckTruthy();
		break;
	}
	case 5: {
		PointsDependingOnNumber();
		break;
	}
	case 6: {
		VacationCalculator();
		break;
	}
	case 7: {
		TemperatureCalculator();
		break;
	}
	case 8: {
		FamilyVacation();
		break;
	}
	default: {
		std::cout << "Task index doesn't exist!" << endl;
	}
	}

	return 0;
}