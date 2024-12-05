//@ts-check

import {
    generateEmail,
    generateFullName,
    generatePhone,
} from "./data-generator";
import { contactLocations, deliveryStatuses, products } from "./types";
import { random } from "./utility";

const namespace = "http://www.w3.org/2001/XMLSchema-instance";

export function generateDoc() {
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

    let ownerEl = xmlDoc.createElementNS(namespace, "owner");
    let fullName = generateFullName();
    let nameEl = xmlDoc.createElementNS(namespace, "name");

    ownerEl.appendChild(nameEl);
    ownerEl.appendChild(generateContact(xmlDoc, fullName));
    warehousesEl.appendChild(ownerEl);

    for (let ind = 0; ind < random(3) + 1; ind++) {
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
    let warehouseEl = xmlDoc.createElementNS(namespace, "warehouse");
    let productsEl = xmlDoc.createElementNS(namespace, "products");
    let setOfProducts = new Set();

    for (let ind = 0; ind < random(5) + 1; ind++) {
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

    let deliveriesEl = xmlDoc.createElementNS(namespace, "deliveries");
    for (let ind = 0; ind < random(3) + 1; ind++) {
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
    let deliveryEl = xmlDoc.createElementNS(namespace, "delivery");
    let setOfProducts = new Set();
    let totalCost = 0;
    let productsEl = xmlDoc.createElementNS(namespace, "products");

    for (let ind = 0; ind < random(3) + 1; ind++) {
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
    let vendorEl = xmlDoc.createElementNS(namespace, "vendor");
    let fullName = generateFullName();
    let nameEl = xmlDoc.createElementNS(namespace, "name");

    vendorEl.appendChild(nameEl);
    vendorEl.appendChild(generateContact(xmlDoc, fullName));

    let statusEl = xmlDoc.createElementNS(namespace, "status");
    statusEl.textContent = deliveryStatuses[random(deliveryStatuses.length)];
    let costEl = xmlDoc.createElementNS(namespace, "cost");
    costEl.textContent = totalCost.toString();

    deliveryEl.appendChild(productsEl);
    deliveryEl.appendChild(vendorEl);
    deliveryEl.appendChild(statusEl);
    deliveryEl.appendChild(costEl);
    return deliveryEl;
}

/**
 *
 * @param {XMLDocument} xmlDoc
 * @param {import("./types").Product} product
 * @returns {{element:Element,cost:number}}
 */
function generateProduct(xmlDoc, product) {
    let productEl = xmlDoc.createElementNS(namespace, "product");
    productEl.setAttribute("name", product.name);
    productEl.setAttribute("brand", product.brand);

    let notesEl = xmlDoc.createElementNS(namespace, "notes");
    notesEl.textContent = product.notes;

    let contentInfoEl = xmlDoc.createElementNS(namespace, "info");
    let fragileEl = xmlDoc.createElementNS(namespace, "fragile");
    fragileEl.textContent = product.contentInfo.isFragile.toString();
    contentInfoEl.appendChild(fragileEl);

    let priceEl = xmlDoc.createElementNS(namespace, "price");
    priceEl.textContent = product.contentInfo.price.toString();
    priceEl.setAttribute("currency", product.contentInfo.currency);
    contentInfoEl.appendChild(priceEl);

    let quantityEl = xmlDoc.createElementNS(namespace, "quantity");
    const quantity = random(30);
    quantityEl.textContent = quantity.toString();
    contentInfoEl.appendChild(quantityEl);

    let weightEl = xmlDoc.createElementNS(namespace, "weight");
    weightEl.textContent = product.contentInfo.weight.toString();
    weightEl.setAttribute("unit", product.contentInfo.unit);
    contentInfoEl.appendChild(weightEl);

    let expireDateEl = xmlDoc.createElementNS(namespace, "expiry_date");
    expireDateEl.textContent = product.contentInfo.expiryDate;
    contentInfoEl.appendChild(expireDateEl);

    let typeEl = xmlDoc.createElementNS(namespace, "type");
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
    let contactEl = xmlDoc.createElementNS(namespace, "contact");
    let locationEl = xmlDoc.createElementNS(namespace, "location");

    let randomLocation = contactLocations[random(contactLocations.length)];
    let countryEl = xmlDoc.createElementNS(namespace, "country");
    countryEl.textContent = randomLocation.country;
    let cityEl = xmlDoc.createElementNS(namespace, "city");
    cityEl.textContent = randomLocation.city;
    let addressEl = xmlDoc.createElementNS(namespace, "address");
    addressEl.textContent = randomLocation.address;

    locationEl.appendChild(countryEl);
    locationEl.appendChild(cityEl);
    locationEl.appendChild(addressEl);

    contactEl.appendChild(locationEl);

    let choice = random(3);
    if (choice < 1) {
        let emailEl = xmlDoc.createElementNS(namespace, "email");
        emailEl.textContent = generateEmail(fullname);
        contactEl.appendChild(emailEl);
    } else if (choice === 1) {
        let phoneEl = xmlDoc.createElementNS(namespace, "phone");
        phoneEl.textContent = generatePhone();
        contactEl.appendChild(phoneEl);
    } else {
        let emailEl = xmlDoc.createElementNS(namespace, "email");
        emailEl.textContent = generateEmail(fullname);
        let phoneEl = xmlDoc.createElementNS(namespace, "phone");
        phoneEl.textContent = generatePhone();
        contactEl.appendChild(emailEl);
        contactEl.appendChild(phoneEl);
    }

    return contactEl;
}
