//@ts-check

import { emailDomains, firstNames, lastNames } from "./types.js";
import { random, toLatin } from "./utility.js";

/**
 *
 * @returns {string} Random full name
 */
export function generateFullName() {
    const randFirstName = firstNames[random(firstNames.length)];
    const randLastName = lastNames[random(lastNames.length)];
    return `${randFirstName.name} ${randLastName}${
        randFirstName.gender === "f" ? "a" : ""
    }`;
}

/**
 *
 * @param {string} fullName
 * @returns {string} Random email
 */
export function generateEmail(fullName) {
    const randomDomain = emailDomains[random(emailDomains.length)];
    return `${toLatin(fullName.replaceAll(" ", "_"))}@${randomDomain}`;
}

/**
 *
 * @returns {string} Random phone number
 */
export function generatePhone() {
    let phoneNumber = "+";
    for (let ind = 0; ind <= random(2) + 1; ind++) {
        phoneNumber += random(9).toString();
    }
    phoneNumber += " ";
    for (let ind = 0; ind <= random(2) + 1; ind++) {
        phoneNumber += random(9).toString();
    }
    phoneNumber += "-";
    for (let ind = 0; ind <= random(2) + 2; ind++) {
        phoneNumber += random(9).toString();
    }
    phoneNumber += "-";
    for (let ind = 0; ind <= random(4) + 2; ind++) {
        phoneNumber += random(9).toString();
    }
    return phoneNumber;
}
