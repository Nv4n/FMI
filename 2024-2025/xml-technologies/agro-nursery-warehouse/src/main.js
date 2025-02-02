//@ts-check
import { download, serializeDocument } from "./utility";
import { generateDoc } from "./xml-doc-generator";

/**
 *
 * @param {number} deliveryCnt
 * @param {number} productsCnt
 * @param {number} warehousesCnt
 * @returns {string}
 */
function downloadGeneratedFile(deliveryCnt, productsCnt, warehousesCnt) {
    let doc = generateDoc(deliveryCnt, productsCnt, warehousesCnt);
    let url = download(
        `example${Date.now().toString()}.xml`,
        serializeDocument(doc)
    );
    return url;
}

(function () {
    let downloadForm = document.getElementById("download");
    let xmlExampleEl = document.getElementById("xmlFrame");
    if (downloadForm && xmlExampleEl) {
        xmlExampleEl.style.display = "none";
        downloadForm.addEventListener("submit", (e) => {
            e.preventDefault();
            // @ts-ignore
            let formData = new FormData(e.target);
            let deliveryCnt = Number(formData.get("deliveries") || 3);
            let productsCnt = Number(formData.get("products") || 5);
            let warehousesCnt = Number(formData.get("warehouses") || 3);
            let url = downloadGeneratedFile(
                deliveryCnt,
                productsCnt,
                warehousesCnt
            );

            xmlExampleEl.setAttribute("src", url);
            xmlExampleEl.style.display = "block";
            URL.revokeObjectURL(url);
        });
    } else {
        alert("Can't find download form or/and frame element");
    }
})();
