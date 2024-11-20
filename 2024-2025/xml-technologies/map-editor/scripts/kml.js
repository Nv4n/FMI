//@ts-check

import { Feature } from "ol";
import { toStringXY } from "ol/coordinate";
import { toLonLat } from "ol/proj";

export default function createKmlDocument(features) {
    const documentImplementation = document.implementation;
    const namespace = "http://www.opengis.net/kml/2.2";

    const kmlDoc = documentImplementation.createDocument(null, null);
    const xml = kmlDoc.createProcessingInstruction(
        "xml",
        'version="1.0" encoding="UTF-8"'
    );
    kmlDoc.appendChild(xml);
    const kmlEl = kmlDoc.createElementNS(namespace, "kml");

    const comment = kmlDoc.createComment(
        `Генериран на ${new Date().toISOString()}`
    );
    kmlDoc.appendChild(comment);

    kmlEl.setAttribute(
        "xmlns:xsi",
        "http://www.w3.org/2001/XMLSchema-instance"
    );
    kmlEl.setAttributeNS(
        "http://www.w3.org/2001/XMLSchema-instance",
        "xsi:schemaLocation",
        "http://www.opengis.net/kml/2.2 http://schemas.opengis.net/kml/2.2.0/ogckml22.xsd"
    );

    const folderEl = kmlDoc.createElementNS(namespace, "Folder");

    for (let i = 0; i < features.length; i++) {
        const feature = features[i];

        // console.log("Име:", feature.name);
        // console.log("Координати:", feature.gsmCoordinates);

        const placemark = kmlDoc.createElementNS(namespace, "Placemark");

        placemark.setAttribute("id", `placemark${i}`);
        const name = kmlDoc.createElementNS(namespace, "name");
        name.textContent = feature.name;
        const pointEl = kmlDoc.createElementNS(namespace, "Point");
        const coords = kmlDoc.createElementNS(namespace, "coordinates");
        coords.textContent = feature.gsmCoordinates;
        pointEl.appendChild(coords);
        placemark.appendChild(name);
        placemark.appendChild(pointEl);

        if (features.length > 1) {
            folderEl.appendChild(placemark);
        } else {
            kmlEl.appendChild(placemark);
        }
    }
    if (features.length > 1) {
        kmlEl.appendChild(folderEl);
    }
    kmlDoc.appendChild(kmlEl);
    return kmlDoc;
}

// Добавяне на свойства към Feature, които ще улеснят работата с него
Object.defineProperty(Feature.prototype, "name", {
    get() {
        return this.get("name");
    },
});
Object.defineProperty(Feature.prototype, "gsmCoordinates", {
    get() {
        const coordinates = toLonLat(this.getGeometry().getCoordinates());

        return toStringXY(coordinates, 6);
    },
});
