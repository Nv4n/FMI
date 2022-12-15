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

function evalExp(expression) {
    const nums = [];
    const ops = [];
    for (const char of expression) {
        if (char === " ") {
            continue;
        }
        if (/\d/.test(char)) {
            nums.push(char.charCodeAt(0) - "0".charCodeAt(0));
        } else if (/[*/+-]/.test(char)) {
            ops.push(char);
        }
    };
    //!FIXME Need to make the evaluate accurate
    function evaluate() {
        if (nums.length <= 1) {
            return;
        }
        const operand1 = nums.pop();
        const operand2 = nums.pop();
        switch (ops.pop()) {
            case "+":
                nums.push(operand2 + operand1);

                break;
            case "-":
                nums.push(operand2 - operand1);
                break;
            case "*":
                nums.push(operand2 * operand1);
                break;
            case "/": {
                if (operand1 === 0) {
                    nums.push(NaN);
                    return;
                }
                nums.push(operand2 / operand1);
                break;
            }
            default:
                console.error('bad stuff happened');
                break;
        }
        evaluate(nums, ops);
    }
    evaluate();
    return nums.pop();
}