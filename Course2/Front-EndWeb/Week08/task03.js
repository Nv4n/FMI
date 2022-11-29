const arr = [49, 0];

function contains50(arr) {
    return arr.some(el => el === 50);
}

function isSum50(arr) {
    return arr.reduce((sum, el) => sum += el, 0) === 50;
}

function whatIsNeededForSumOf50(arr) {
    return 50 - arr.reduce((sum, el) => sum += el, 0);
}

function mostCommonLetters(str) {
    const letterCount = {};
    for (const l of str) {
        letterCount[l] ??= 0;
        letterCount[l]++;
    }
    let mostCommonLetters = { ...letterCount };
    let biggestCount = Number.MIN_VALUE;

    // const letters = Object.entries(letterCount);
    for (const letter in letterCount) {
        if (letterCount[letter] > biggestCount) {
            biggestCount = letterCount[letter];
            mostCommonLetters = [];
            mostCommonLetters.push(letter);
        } else if (letterCount[letter] === biggestCount) {
            mostCommonLetters.push(letter);
        }
    }
    return mostCommonLetters;
}

function biggestPlatform(arr) {
    let maxCount = 0;
    let currCount = 0;

    for (let i = 0, currEl = arr[0]; i < arr.length; i++) {
        if (arr[i] !== currEl) {
            if (currCount > maxCount) {
                maxCount = currCount;
            }
            currCount = 0;
            currEl = arr[i];
        }
        currCount++;
    }

    return Math.max(maxCount, currCount);
}


console.log(contains50(arr));
console.log(isSum50(arr));
console.log(whatIsNeededForSumOf50(arr));

console.log(mostCommonLetters("AAABDSDPAPPP"));

console.log(biggestPlatform([1, 1, 1, 5, 7, 7, 8, 8, 8, 8, 9]));