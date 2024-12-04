//@ts-check

/**
 * @param {number} maxValue
 * @returns {number}
 */
export function random(maxValue) {
    return Math.floor(Math.random() * maxValue);
}

/**
 *
 * @param {string} cyrillic
 */
export function toLatin(cyrillic) {
    const conversion = {
        а: "a",
        б: "b",
        в: "v",
        г: "g",
        д: "d",
        е: "e",
        ж: "zh",
        з: "z",
        и: "i",
        й: "y",
        к: "k",
        л: "l",
        м: "m",
        н: "n",
        о: "o",
        п: "p",
        р: "r",
        с: "s",
        т: "t",
        у: "u",
        ф: "f",
        х: "h",
        ц: "ts",
        ч: "ch",
        ш: "sh",
        щ: "sht",
        ъ: "a",
        ь: "y",
        ю: "yu",
        я: "ya",
    };

    let letters = cyrillic.toLowerCase().split("");
    console.log(letters);
    return letters
        .map((letter) => {
            if (!!conversion[letter]) {
                return conversion[letter];
            } else {
                return letter;
            }
        })
        .concat(`${Math.floor(Math.random() * 2000)}`)
        .join("");
}
