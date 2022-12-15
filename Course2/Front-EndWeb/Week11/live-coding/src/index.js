const input = document.getElementById("task-input");
const list = document.getElementById("list");

input.addEventListener("keydown", (event) => {
    const isEnter = event.key === "Enter";
    let value = event.target.value;
    if (!isEnter || !value) {
        return;
    }

    const task = document.createElement("li");
    task.className = "task";
    const expPattern = /^# (\d [*/+-] ){1,}\d$/;
    if (expPattern.test(value)) {
        value = value.replace("#", "").trim();
        value = `${value} = ${evalExp(value)}`;
    }

    task.innerHTML = `
    <input type="checkbox">
    <span>${value}</span>
    <button class="btn-remove">X</button>
`;

    list.appendChild(task);
    input.value = "";
    updateCounter();
});

list.addEventListener("change", (event) => {
    const task = event.target.parentElement;
    task.classList.toggle("done", event.target.checked);
    updateCounter();
});

list.addEventListener("click", (event) => {
    const isRemoveBtn = event.target.classList.contains("btn-remove");
    if (!isRemoveBtn) {
        return;
    }
    const task = event.target.parentElement;
    list.removeChild(task);
    updateCounter();
});

const filterBtns = document.querySelector(".filter-container");
filterBtns.addEventListener("click", (event) => {
    if (!/\w{1,}-btn/.test(event.target.id)) {
        return;
    }
    if (event.target.classList.contains("active")) {
        return;
    }
    for (const element of filterBtns.children) {
        element.classList.remove("active");
    }
    const filter = event.target;
    filter.classList.toggle("active");

    switch (filter.id) {
        case "all-btn":
            for (const task of list.children) {
                task.classList.remove("hidden");
            }
            break;
        case "active-btn":
            for (const task of list.children) {
                if (task.classList.contains("done")) {
                    task.classList.add("hidden");
                } else {
                    task.classList.remove("hidden");
                }
            }
            break;
        case "completed-btn":
            for (const task of list.children) {
                if (!task.classList.contains("done")) {
                    task.classList.add("hidden");
                } else {
                    task.classList.remove("hidden");
                }
            }
            break;
        default:
            break;
    }
});

const clearBtn = document.getElementById("clear-completed");
clearBtn.addEventListener("click", () => {
    Array.from(list.children).forEach((el) => {
        if (el.classList.contains("done")) {
            list.removeChild(el);
        }
    });
});

const countLabel = document.getElementById("tasks-left");
function updateCounter() {
    let count = 0;
    for (const task of list.children) {
        if (!task.classList.contains("done")) {
            count++;
        }
    }

    countLabel.textContent = `${count} Left`;
}

updateCounter();

class Node {
    constructor(value) {
        this.data = value;
        this.left = undefined;
        this.right = undefined;
    }
}

function expressionParser(tree, i, expression) {
    if (i >= expression.length - 1) {
        tree.data = expression[i];
        return;
    }
    const num = expression[i++].charCodeAt(0) - "0".charCodeAt(0); //getting the int value
    const operand = expression[i++];
    tree.data = operand;
    tree.left = new Node(num);
    tree.right = new Node(undefined);
    expressionParser(tree.right, i, expression);
}

function expressionEval(tree) {
    if (tree.left === undefined && tree.right === undefined) {
        return tree.data;
    }
    switch (tree.data) {
        case "+":
            return tree.left.data + expressionEval(tree.right);
        case "-":
            return tree.left.data - expressionEval(tree.right);
        case "*":
            return tree.left.data * expressionEval(tree.right);
        case "/":
            return tree.left.data / expressionEval(tree.right);
        default:
            console.error("Undefined symbol");
            return;
    }
}

function evalExp(expression) {
    const exprArray = Array.from(expression.replaceAll(" ", ""));
    let tree = new Node(undefined);
    expressionParser(tree, 0, exprArray);
    return expressionEval(tree);
}
