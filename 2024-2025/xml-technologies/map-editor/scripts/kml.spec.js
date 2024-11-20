import { describe, expect, test } from "@jest/globals";

import createKmlDocument from "./kml.js";

const SINGLE_FEATURE = {
    name: "Факултет по математика и информатика",
    gsmCoordinates: "23.330584, 42.674396",
};

const MULTIPLE_FEATURES = [
    {
        name: "Стопански факултет",
        gsmCoordinates: "23.363992, 42.672976",
    },
    {
        name: "Исторически факултет",
        gsmCoordinates: "23.335206, 42.693023",
    },
    {
        name: "Факултет по математика и информатика",
        gsmCoordinates: "23.330584, 42.674396",
    },
];

// Ако някой от тестовите сценарии изглеждат странно (например някой могат да се обединят),
// това е защото са направени, така че да следват реда, в който добавяме функционалност на
// упражненията. Например пространствата от имена се добавят накрая и затова има отделен тест за тях.
// В реални тестове тази проверка би била част от някой позитивен сценарии.

describe.each([
    {
        scenario: "Без проверка на пространствата от имена",
        assertNamespace: false,
    },
    {
        scenario: "С проверка на пространствата от имена",
        assertNamespace: true,
    },
])("генериране на KML документ", ({ scenario, assertNamespace }) => {
    test(scenario, () => {
        const result = createKmlDocument(MULTIPLE_FEATURES);

        const rootElement = result.documentElement;
        assertElementWithChildren(rootElement, "kml", 1, assertNamespace);
        const folderElement = rootElement.childNodes[0];
        assertElementWithChildren(folderElement, "Folder", 3, assertNamespace);

        const placemarkElements = folderElement.childNodes;
        for (let i = 0; i < placemarkElements.length; i++) {
            const placemarkElement = placemarkElements[i];
            assertElementWithChildren(
                placemarkElement,
                "Placemark",
                2,
                assertNamespace
            );

            const nameElement = placemarkElement.childNodes[0];
            const pointElement = placemarkElement.childNodes[1];
            assertElementWithTextChild(
                nameElement,
                "name",
                MULTIPLE_FEATURES[i].name,
                assertNamespace
            );
            assertElementWithChildren(
                pointElement,
                "Point",
                1,
                assertNamespace
            );
            const coordinatesElement = pointElement.childNodes[0];
            assertElementWithTextChild(
                coordinatesElement,
                "coordinates",
                MULTIPLE_FEATURES[i].gsmCoordinates,
                assertNamespace
            );
        }
    });

    test(`Placemark е вложен директно в kml, ако има само един обект. ${scenario}`, () => {
        const result = createKmlDocument([SINGLE_FEATURE]);

        const rootElement = result.documentElement;
        assertElementWithChildren(rootElement, "kml", 1, assertNamespace);
        const placemarkElement = rootElement.childNodes[0];
        assertElementWithChildren(
            placemarkElement,
            "Placemark",
            2,
            assertNamespace
        );

        const nameElement = placemarkElement.childNodes[0];
        const pointElement = placemarkElement.childNodes[1];
        assertElementWithTextChild(
            nameElement,
            "name",
            SINGLE_FEATURE.name,
            assertNamespace
        );
        assertElementWithChildren(pointElement, "Point", 1, assertNamespace);
        const coordinatesElement = pointElement.childNodes[0];
        assertElementWithTextChild(
            coordinatesElement,
            "coordinates",
            SINGLE_FEATURE.gsmCoordinates,
            assertNamespace
        );
    });
});

test("има XML декларация", () => {
    const result = createKmlDocument(MULTIPLE_FEATURES);

    const xmlDeclarationNode = result.childNodes[0];
    expect(xmlDeclarationNode.nodeType).toBe(Node.PROCESSING_INSTRUCTION_NODE);
    expect(xmlDeclarationNode.nodeName).toBe("xml");
    expect(xmlDeclarationNode.nodeValue).toBe('version="1.0" encoding="UTF-8"');
});

test("има коментар с текущата дата", () => {
    const result = createKmlDocument(MULTIPLE_FEATURES);

    const commentNode = result.childNodes[1];
    expect(commentNode.nodeType).toBe(Node.COMMENT_NODE);
    expect(commentNode.nodeValue).toMatch(
        /^Генериран на \d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}\.\d{3}Z$/
    );
});

test("има XSD декларация", () => {
    const result = createKmlDocument(MULTIPLE_FEATURES);

    const rootElement = result.documentElement;
    const schemaLocationAttributeNode =
        rootElement.getAttributeNode("xsi:schemaLocation");
    expect(schemaLocationAttributeNode.namespaceURI).toBe(
        "http://www.w3.org/2001/XMLSchema-instance"
    );
    expect(schemaLocationAttributeNode.value).toBe(
        "http://www.opengis.net/kml/2.2 http://schemas.opengis.net/kml/2.2.0/ogckml22.xsd"
    );
});

function assertElementWithChildren(
    node,
    expectedLocalName,
    expectedChildNodesNum,
    assertNamespace
) {
    expect(node.nodeType).toBe(Node.ELEMENT_NODE);
    expect(node.localName).toBe(expectedLocalName);
    if (assertNamespace) {
        expect(node.namespaceURI).toBe("http://www.opengis.net/kml/2.2");
    }
    expect(node.childNodes.length).toBe(expectedChildNodesNum);
}

function assertElementWithTextChild(
    node,
    expectedLocalName,
    expectedTextValue,
    assertNamespace
) {
    assertElementWithChildren(node, expectedLocalName, 1, assertNamespace);
    expect(node.childNodes[0].nodeType).toBe(Node.TEXT_NODE);
    expect(node.childNodes[0].nodeValue).toBe(expectedTextValue);
}
