import formatXml from 'xml-formatter';

export function serializeDocument(doc) {
    const serializer = new XMLSerializer();
    const serializedDocument = serializer.serializeToString(doc);

    return formatXml(serializedDocument, { collapseContent: true, throwOnFailure: false });
}

export function download(filename, content) {
    const file = new File([content], filename);
    const url = URL.createObjectURL(file);

    const tempLinkElement = document.createElement('a');
    tempLinkElement.setAttribute('href', url);
    tempLinkElement.setAttribute('download', filename);

    tempLinkElement.style.display = 'none';
    document.body.appendChild(tempLinkElement);

    tempLinkElement.click();

    document.body.removeChild(tempLinkElement);
    URL.revokeObjectURL(url);
}
