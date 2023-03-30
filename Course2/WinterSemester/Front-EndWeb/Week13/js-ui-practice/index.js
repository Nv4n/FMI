const list = document.querySelectorAll(".navigation li");
function changeActive() {
    list.forEach((navItem) => navItem.classList.remove('active'));
    this.classList.add('active');
}

list.forEach((navItem) => {
    navItem.addEventListener('click', changeActive);
});