const arr = [10, 5, 13, 18, 51];
function printArray(arr) {
    arr.map((el, i) => console.log(el));
}

function getMultBy2Array(arr) {
    return arr.map((el, i) => el *= 2);
}

function getEvenArray(arr) {
    return arr.filter(el => el % 2 === 0);
}

function hasLowerThan10(arr) {
    return arr.some(el => el < 10);
}

function devidableBy3(arr) {
    return arr.filter(el => el % 3 === 0);
}

function sum(arr) {
    return arr.reduce((sum, el) => sum + el, 0);
}

function getLast2Elements(arr) {
    return arr.slice(arr.length - 2);
}

printArray(arr);
console.log(getMultBy2Array(arr));
console.log(getEvenArray(arr));

console.log(hasLowerThan10(arr));
console.log(hasLowerThan10(getMultBy2Array(arr)));

console.log(devidableBy3(arr));
console.log(sum(arr));
console.log(getLast2Elements(arr));