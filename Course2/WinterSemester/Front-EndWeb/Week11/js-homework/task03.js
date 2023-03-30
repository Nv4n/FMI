
function isPalindrom(text) {
    const halfSize = Math.floor(text.length / 2);
    const firstPart = text.substring(0, halfSize);
    const secondePart = text.slice(-halfSize).split('').reverse().join('');
    return firstPart === secondePart;
}

const input = ["abccba", "lalala", "something", "123321", "debel lebed"];
const output = input.filter(isPalindrom);
console.log(output);
