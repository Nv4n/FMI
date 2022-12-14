const input = document.getElementById('task-input');
const list = document.getElementById('list');

input.addEventListener('keydown', (event) => {
    const isEnter = event.key === 'Enter';
    const value = event.target.value;
    if (!isEnter || !value) {
        return;
    }

    const task = document.createElement('li');
    task.className = 'task';
    const expPattern = /# (\d [*/+-] ){1,}\d/
    if (expPattern.test(value)) {
        value = value.replace('#', '').trim();
        value = `${value} = ${eval(value)}`;
    }

    task.innerHTML = `
    <input type="checkbox">
    <span>${value}</span>
    <button class="btn-remove">X</button>
`;

    list.appendChild(task);
    input.value = '';
    updateCounter();
});

list.addEventListener('change', (event) => {
    const task = event.target.parentElement;
    task.classList.toggle('done', event.target.checked);
    updateCounter();
});

list.addEventListener('click', (event) => {
    const isRemoveBtn = event.target.classList.contains("btn-remove");
    if (!isRemoveBtn) {
        return;
    }
    const task = event.target.parentElement;
    list.removeChild(task);
    updateCounter();
});

const filterBtns = document.querySelector('.filter-container');
filterBtns.addEventListener('click', (event) => {
    for (const element of filterBtns.children) {
        element.classList.remove('active');
    }
    const filter = event.target;
    filter.classList.toggle('active');
})


const clearBtn = document.getElementById('clear-completed');
clearBtn.addEventListener('click', () => {
    Array.from(list.children).forEach((el) => {
        if (el.classList.contains('done')) {
            list.removeChild(el);
        }
    })
});


const countLabel = document.getElementById('tasks-left');
function updateCounter() {
    let count = 0;
    for (const task of list.children) {
        if (!task.classList.contains('done')) {
            count++;
        }
    }

    countLabel.textContent = `${count} Left`;
}

updateCounter();

function evalExp(expression) {
    const nums = [];
    const operators = [];
    let res = undefined;
    expression.forEach((char) => {
        if (char === ' ') {
            return;
        }
        if (/\d/.test(char)) {
            nums.push(char.charCodeAt(0) - '0'.charCodeAt(0));
        } else if (/[*/+-]/.test(char)) {
            operators.push(char);
        }
    })
}