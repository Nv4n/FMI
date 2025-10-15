class Cat {
    constructor(name, breed, age) {
        this.name = name;
        this.breed = breed;
        this.age = age;
    }
}
function getSortedCats(cats, criteria) {
    const input = [...cats].map(c => {
        return { ...c };
    });

    switch (criteria) {
        case 'name':
            input.sort((c1, c2) => c1.name.localeCompare(c2.name));
            break;
        case 'breed':
            input.sort((c1, c2) => c1.breed.localeCompare(c2.breed));
            break;
        case 'age':
            input.sort((c1, c2) => c1.age - c2.age);
            break;
        case 'all':
            input.sort((c1, c2) => {
                const sortValueL = c1.name.length + c1.breed.length + c1.age;
                const sortValueR = c2.name.length + c2.breed.length + c2.age;
                return sortValueL - sortValueR;
            });
            break;
        default:
            break;
    }
    return input;
}

//* DEMO
const output = getSortedCats([{ "name": "Tina", "breed": "Maine Coon", "age": 2 }, { "name": "Annie", "breed": "Maine Coon", "age": 7 }, { "name": "Polly", "breed": "Brittish shorthair", "age": 3 }], "age"); //* input
console.log(...output);
//? expected [{"name": "Tina", "breed" : "Maine Coon", "age" : 2}, {"name": "Polly", "breed" : "Brittish shorthair", "age" : 3}, {"name": "Annie", "breed" : "Maine Coon", "age" : 7}]