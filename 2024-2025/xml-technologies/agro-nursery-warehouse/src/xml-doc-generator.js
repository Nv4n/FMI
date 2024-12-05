//@ts-check

import {
    generateEmail,
    generateFullName,
    generatePhone,
} from "./data-generator";
import { contactLocations, deliveryStatuses, products } from "./types";
import { precision, random } from "./utility";

const namespace = "http://www.w3.org/2001/XMLSchema-instance";
let deliveriesCount = 3;
let productsCount = 3;
let warehousesCount = 3;

/**
 *
 * @param {number} deliveryCnt
 * @param {number} productsCnt
 * @param {number} warehousesCnt
 * @returns
 */
export function generateDoc(deliveryCnt, productsCnt, warehousesCnt) {
    deliveriesCount = deliveryCnt;
    productsCount = productsCnt;
    warehousesCount = warehousesCnt;

    const documentImplementation = document.implementation;
    const xmlDoc = documentImplementation.createDocument(null, null);

    const xml = xmlDoc.createProcessingInstruction(
        "xml",
        'version="1.0" encoding="UTF-8"'
    );
    xmlDoc.appendChild(xml);

    let warehousesEl = xmlDoc.createElement("warehouses");
    warehousesEl.setAttribute("xmlns:xsi", namespace);
    warehousesEl.setAttribute(
        "xsi:noNamespaceSchemaLocation",
        "warehouses.xsd"
    );

    let ownerEl = xmlDoc.createElement("owner");
    let fullName = `Агро магазин ${generateFullName()}`;
    let nameEl = xmlDoc.createElement("name");
    nameEl.textContent = fullName;

    ownerEl.appendChild(nameEl);
    ownerEl.appendChild(generateContact(xmlDoc, fullName));
    warehousesEl.appendChild(ownerEl);

    for (let ind = 0; ind < random(warehousesCount) + 1; ind++) {
        warehousesEl.appendChild(generateWarehouse(xmlDoc));
    }

    xmlDoc.appendChild(warehousesEl);
    return xmlDoc;
}
/**
 *
 * @param {XMLDocument} xmlDoc
 * @returns {Element} Random warehouse
 */
function generateWarehouse(xmlDoc) {
    let warehouseEl = xmlDoc.createElement("warehouse");
    let productsEl = xmlDoc.createElement("products");
    let setOfProducts = new Set();

    for (let ind = 0; ind < random(warehousesCount) + 1; ind++) {
        let randProduct;
        while (true) {
            randProduct = products[random(products.length)];
            if (!setOfProducts.has(randProduct)) {
                setOfProducts.add(randProduct);
                break;
            }
        }

        productsEl.appendChild(generateProduct(xmlDoc, randProduct).element);
    }

    let deliveriesEl = xmlDoc.createElement("deliveries");
    for (let ind = 0; ind < random(deliveriesCount) + 1; ind++) {
        deliveriesEl.appendChild(generateDelivery(xmlDoc));
    }

    warehouseEl.appendChild(productsEl);
    warehouseEl.appendChild(
        generateContact(xmlDoc, `Warehouse ${generateFullName()}`)
    );
    warehouseEl.appendChild(deliveriesEl);

    return warehouseEl;
}

/**
 *
 * @param {XMLDocument} xmlDoc
 * @returns {Element} Random delivery
 */
function generateDelivery(xmlDoc) {
    let deliveryEl = xmlDoc.createElement("delivery");
    let setOfProducts = new Set();
    let totalCost = 0;
    let productsEl = xmlDoc.createElement("products");

    for (let ind = 0; ind < random(productsCount) + 1; ind++) {
        let randProduct;
        while (true) {
            randProduct = products[random(products.length)];
            if (!setOfProducts.has(randProduct)) {
                setOfProducts.add(randProduct);
                break;
            }
        }
        let result = generateProduct(xmlDoc, randProduct);
        totalCost += result.cost;
        productsEl.appendChild(result.element);
    }
    console.log(totalCost);
    let vendorEl = xmlDoc.createElement("vendor");
    let fullName = generateFullName();
    let nameEl = xmlDoc.createElement("name");
    nameEl.textContent = fullName;

    vendorEl.appendChild(nameEl);
    vendorEl.appendChild(generateContact(xmlDoc, fullName));

    deliveryEl.setAttribute(
        "status",
        deliveryStatuses[random(deliveryStatuses.length)]
    );

    deliveryEl.setAttribute("cost", precision(totalCost, 2).toString());

    deliveryEl.appendChild(productsEl);
    deliveryEl.appendChild(vendorEl);
    return deliveryEl;
}

/**
 *
 * @param {XMLDocument} xmlDoc
 * @param {import("./types").Product} product
 * @returns {{element:Element,cost:number}}
 */
function generateProduct(xmlDoc, product) {
    let productEl = xmlDoc.createElement("product");
    productEl.setAttribute("name", product.name);
    productEl.setAttribute("brand", product.brand);

    let notesEl = xmlDoc.createElement("notes");
    notesEl.textContent = product.notes;

    let contentInfoEl = xmlDoc.createElement("info");
    let fragileEl = xmlDoc.createElement("fragile");
    fragileEl.textContent = product.contentInfo.isFragile.toString();
    contentInfoEl.appendChild(fragileEl);

    let priceEl = xmlDoc.createElement("price");
    priceEl.textContent = product.contentInfo.price.toString();
    priceEl.setAttribute("currency", product.contentInfo.currency);
    contentInfoEl.appendChild(priceEl);

    let quantityEl = xmlDoc.createElement("quantity");
    const quantity = random(30) + 1;
    quantityEl.textContent = quantity.toString();
    contentInfoEl.appendChild(quantityEl);

    let weightEl = xmlDoc.createElement("weight");
    weightEl.textContent = product.contentInfo.weight.toString();
    weightEl.setAttribute("unit", product.contentInfo.unit);
    contentInfoEl.appendChild(weightEl);

    let expireDateEl = xmlDoc.createElement("expiry_date");
    expireDateEl.textContent = product.contentInfo.expiryDate;
    contentInfoEl.appendChild(expireDateEl);

    let typeEl = xmlDoc.createElement("type");
    typeEl.textContent = product.contentInfo.type;
    contentInfoEl.appendChild(typeEl);

    productEl.appendChild(contentInfoEl);
    productEl.appendChild(notesEl);

    let currencyCoeff = 1;
    if (product.contentInfo.currency === "EUR") {
        currencyCoeff = 1.96;
    } else if (product.contentInfo.currency === "USD") {
        currencyCoeff = 1.86;
    } else if (product.contentInfo.currency === "RON") {
        currencyCoeff = 2.55;
    }
    return {
        element: productEl,
        cost: quantity * product.contentInfo.price * currencyCoeff,
    };
}

/**
 *
 * @param {XMLDocument} xmlDoc
 * @param {string} fullname
 * @returns {Element}
 */
function generateContact(xmlDoc, fullname = generateFullName()) {
    let contactEl = xmlDoc.createElement("contact");
    let locationEl = xmlDoc.createElement("location");

    let randomLocation = contactLocations[random(contactLocations.length)];
    let countryEl = xmlDoc.createElement("country");
    countryEl.textContent = randomLocation.country;
    let cityEl = xmlDoc.createElement("city");
    cityEl.textContent = randomLocation.city;
    let addressEl = xmlDoc.createElement("address");
    addressEl.textContent = randomLocation.address;

    locationEl.appendChild(countryEl);
    locationEl.appendChild(cityEl);
    locationEl.appendChild(addressEl);

    contactEl.appendChild(locationEl);

    let choice = random(3);
    if (choice < 1) {
        let emailEl = xmlDoc.createElement("email");
        emailEl.textContent = generateEmail(fullname);
        contactEl.appendChild(emailEl);
    } else if (choice === 1) {
        let phoneEl = xmlDoc.createElement("phone");
        phoneEl.textContent = generatePhone();
        contactEl.appendChild(phoneEl);
    } else {
        let emailEl = xmlDoc.createElement("email");
        emailEl.textContent = generateEmail(fullname);
        let phoneEl = xmlDoc.createElement("phone");
        phoneEl.textContent = generatePhone();
        contactEl.appendChild(emailEl);
        contactEl.appendChild(phoneEl);
    }

    return contactEl;
}
