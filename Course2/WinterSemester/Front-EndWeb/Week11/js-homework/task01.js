class Person {
    constructor(name, age, gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    showPersonInfo() {
        console.log(`name: ${this.name}
        age: ${this.age}
        gender: ${this.gender}`.replace(/  +/g, ''));
    }
};

class Student extends Person {
    constructor(name, age, gender, grade) {
        super(name, age, gender);
        this.grade = grade;
    }
    showStudentInfo() {
        super.showPersonInfo();
        console.log(`grade: ${this.grade}`);
    }
}

class Employee extends Person {
    constructor(name, age, gender, daySalary) {
        super(name, age, gender);
        this.daySalary = daySalary;
    }
    calculateOvertime(hours) {
        const wagePerHour = this.daySalary / 8;
        return this.age >= 18 ? wagePerHour * 1.5 * hours : 0;
    }
    showEmployeeInfo() {
        super.showPersonInfo();
        console.log(`daySalary: ${this.daySalary}`)
    }
}

const people = [
    new Person('Victor', 73, 'male'),// 1
    new Employee('Lucile', 38, 'female', 68),// 2
    new Student('Harriet', 15, 'female', 3),// 3
    new Person('Elmer', 56, 'male'),// 4
    new Student('Lela', 25, 'female', 4),//5
    new Employee('Olga', 77, 'female', 53), //6
    new Person('Minnie', 14, 'female'),//7
    new Student('James', 20, 'male', 3),//8
    new Employee('Joshua', 65, 'male', 28),//9
    new Person('Ian', 96, 'male'),//10
]


//* DEMO
const ivan = new Person('Ivan', 24, "male");
const drago = new Employee("Drago", 23, 'male', 50);
const pencho = new Student("Pencho", 23, 'male', 253);
const gosho = new Person('Gosho', 24, 'male');
const dimitur = new Employee("Mitko", 17, 'male', 50);
const penko = new Student("Penko", 23, 'male', 253);

people.push(ivan, drago, pencho, gosho, dimitur, penko);
people.forEach(p => {
    if (!p) {
        return;
    }
    if (p instanceof Employee) {
        p.showEmployeeInfo();
        console.log(`Overtime bonus: ${p.calculateOvertime(2)}`);
        return;
    }

    if (p instanceof Student) {
        p.showStudentInfo();
        return;
    }
    p.showPersonInfo();
});
// Изход от 3 и 4 точка:
// name: Ivan
// age: 24
// gender: male
// name: Drago
// age: 23
// gender: male
// daySalary: 50
// Overtime bonus: 18.75
// name: Pencho
// age: 23
// gender: male
// grade: 253
// name: Penko
// age: 23
// gender: male
// grade: 253
// name: Gosho
// age: 24
// gender: male
// name: Mitko
// age: 17
// gender: male
// daySalary: 50
// Overtime bonus: 0