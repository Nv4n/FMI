const radioBtns = document.getElementById("img-changer-container");
const slonImg = document.getElementById("animal-img");
const slonInfos = document.getElementsByClassName("animal-info");

radioBtns.addEventListener("click", (event) => {
    const radBtn = event.target;
    if (!radBtn.dataset.imgIndex) {
        return;
    }
    const srcIndex = radBtn.dataset.imgIndex;
    const extension = radBtn.dataset.imgExt;
    slonImg.src = `images/slon-${srcIndex}.${extension}`;
    Array.from(slonInfos).forEach((el) => el.classList.add("hidden"));
    slonInfos[srcIndex - 1].classList.remove("hidden");
});