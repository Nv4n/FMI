//@ts-check
import { download, serializeDocument } from "./utility";
import { generateDoc } from "./xml-doc-generator";
let counter = 1;

function downloadGeneratedFile() {
    let doc = generateDoc();
    download(`example${Date.now().toString()}.xml`, serializeDocument(doc));
    counter++;
}

(function () {
    let downloadBtn = document.getElementById("download");
    if (downloadBtn) {
        downloadBtn.addEventListener("click", () => downloadGeneratedFile());
    } else {
        alert("Can't find button with id download");
    }
})();
