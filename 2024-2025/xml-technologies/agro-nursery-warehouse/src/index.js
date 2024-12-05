//@ts-check
import { download, serializeDocument } from "./utility";
import { generateDoc } from "./xml-doc-generator";

(function downloadGeneratedFile() {
    let doc = generateDoc();
    download("test.xml", serializeDocument(doc));
});
