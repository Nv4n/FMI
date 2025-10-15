function flatten(arr) {
    const result = [];

    function flattenHelper(arr) {
        arr.forEach(el => {
            if (Array.isArray(el)) {
                flattenHelper(el);
            } else {
                result.push(el);
            }
        });
    }

    flattenHelper(arr);
    return result;
}

console.log(flatten([[[[[[[[[[1]]]]]]]]]]));
console.log(flatten([1, [2, [3, [4, [5]]]]]));