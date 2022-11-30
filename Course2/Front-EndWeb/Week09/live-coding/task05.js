function countsObjPerType(arr) {
    let typeCount = {};
    for (const el of arr) {
        const type = typeof el;
        typeCount[type] ??= 0;
        typeCount[type]++;
    }
    const res = `
Strings: ${typeCount['string']}
Numbers: ${typeCount['number']}
Booleans: ${typeCount['boolean']}
Objects: ${typeCount['object']}
Functions: ${typeCount['function']}
    `;
    console.log(res.trim());
}

const input = [
    () => console.log("test"),
    1,
    "2",
    "3",
    "4",
    5.00,
    {
        name: "Martin"
    },
    false,
    true,
    "false"
];

countsObjPerType(input);