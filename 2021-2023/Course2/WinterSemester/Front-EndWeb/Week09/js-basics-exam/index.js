const sumArrays = (arr1, arr2) => {
  // your code here
  function flatten(src, dis) {
    src.forEach(el => {
      if (Array.isArray(el)) {
        flatten(el, dis);
      } else {
        dis.push(el);
      }
    });
  }

  let inp1 = [];
  let inp2 = [];

  flatten(arr1, inp1);
  flatten(arr2, inp2);

  if (inp1.every(el => typeof el !== 'number') || inp2.every(el => typeof el !== 'number')) {
    return 'No number type found in input arrays';
  }

  if (inp1.some(el => typeof el !== 'number') || inp2.some(el => typeof el !== 'number')) {
    let min = Number.MAX_VALUE;
    const findMin = (el) => min = typeof el === 'number' && min > el ? el : min;

    inp1.forEach(el => findMin(el));
    inp2.forEach(el => findMin(el));
    return `Min number found is ${min}`;
  }

  const res = inp1.filter(el => inp2.indexOf(el) !== -1 && el % 3 == 0);
  return res.reduce((acc, el) => acc += el, 0);
};

console.log(sumArrays([1, 2, 3, 4, 5, 6, 7, 8, 9], [7, 8, 6, 10, 11, 12, 9])); // 15
console.log(sumArrays([1, 2, [3, [4, [5, [6]]]]], [4, [[[[[[6]]]]]]])); // 6
console.log(sumArrays([1, 2, 3, () => { }], [3, 4])); // Min number found is 1
console.log(sumArrays([() => { }], ["1"])); // No number type found in input arrays
console.log(sumArrays([() => { }], [{}])); // No number type found in input arrays

const input = [
  { name: "Martin", mark: 4, course: "SI" },
  { name: "Elena", mark: 6, course: "IS" },
  { name: "Tsani", mark: 5, course: "IS" },
  { name: "Niya", mark: 2.9, course: "IS" },
  { name: "Ivo", mark: 2.5, course: "KN" }
];


const getTopStudents = students => {
  // your code here
  return [...students].map(el => { return { ...el } }).filter(stud => stud.mark >= 5.5);
};
const getLowStudents = students => {
  // your code here
  return [...students].map(el => { return { ...el } }).filter(stud => stud.mark < 3);
};
const orderStudents = (students, criteria) => {
  // your code here
  let res;

  if (criteria !== undefined
    && criteria?.course) {
    res = [...students].filter(stud => stud.course.match(criteria.course));
  } else {
    res = [...students];
  }
  res = res.map(el => { return { ...el } });
  res.map(stud => stud.mark = stud.mark >= 3 ? Math.round(stud.mark) : 2);


  if (criteria !== undefined
    && criteria?.type?.match('descending')) {
    res.sort((stud1, stud2) => stud2.mark - stud1.mark);
  } else {
    res.sort((stud1, stud2) => stud1.mark - stud2.mark);
  }
  return res;
};

console.log('Top: ', getTopStudents(input));
console.log('Low: ', getLowStudents(input));
console.log('ascending all: ', orderStudents([...input]));
console.log('descending all: ', orderStudents([...input], { type: "descending" }));
console.log('ascending IS: ', orderStudents([...input], { course: "IS" }));
console.log('descending IS: ', orderStudents([...input], { type: "descending", course: "IS" }));
console.log('ascending: IS', orderStudents([...input], { type: "ascending", course: "IS" }));

export { sumArrays, getTopStudents, getLowStudents, orderStudents };
