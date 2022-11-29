function filterTopStudents(students) {
    const topOnes =
        students.filter(stud => stud.grade >= 5.5)
    topOnes.map(stud => console.log(`${stud.name} ${stud.lastname}, fn: ${stud.fn}`))
}
function filterPassedStudents(students) {
    return [...students].map(stud => {
        stud.grade = stud.grade >= 3 ? stud.grade : 2;
        return stud;
    });
}

const input = [
    {
        name: "Martin",
        lastname: "Hristov",
        fn: 61733,
        grade: 3
    },

    {
        name: "Tsanislav",
        lastname: "Hristov",
        fn: 62547,
        grade: 2.9
    },

    {
        name: "Ivo",
        lastname: "Georgiev",
        fn: 68554,
        grade: 5
    },

    {
        name: "Niya",
        lastname: "Peeva",
        fn: 71585,
        grade: 5.5
    }
];

filterTopStudents(input);
console.log(...filterPassedStudents(input));