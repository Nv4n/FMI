//@ts-check
import formatXml from "xml-formatter";

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

/**
 *
 * @param {XMLDocument} doc
 * @returns {string}
 */
export function serializeDocument(doc) {
    const serializer = new XMLSerializer();
    const serializedDocument = serializer.serializeToString(doc);

    return formatXml(serializedDocument, {
        collapseContent: true,
        throwOnFailure: false,
    });
}

/**
 *
 * @param {string} filename
 * @param {string} content
 * @returns {string}
 */
export function download(filename, content) {
    const file = new File([content], filename);
    const url = URL.createObjectURL(file);

    const tempLinkElement = document.createElement("a");
    tempLinkElement.setAttribute("href", url);
    tempLinkElement.setAttribute("download", filename);

    tempLinkElement.style.display = "none";
    document.body.appendChild(tempLinkElement);

    tempLinkElement.click();

    document.body.removeChild(tempLinkElement);
    // URL.revokeObjectURL(url);
    return url;
}

/**
 *
 * @param {number} num
 * @returns {number}
 */
export function precision(num, precision) {
    let prec = 10 ** precision;
    return Math.round(num * prec) / prec;
}
