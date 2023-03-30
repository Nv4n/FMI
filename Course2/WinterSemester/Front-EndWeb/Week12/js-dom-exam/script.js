// your code here
const expressionInput = document.querySelector('.input');
let lvalues = [];
let operators = [];
let lvalue = undefined;
let rvalue = undefined;
let operator = undefined;
let onchange = document.createEvent('HTMLEvents');
onchange.initEvent('change', false, true);
const inputChanges = (event) => {
    const pattern = /^(0|[1-9]\d*)(\.|\.\d+)?$/;
    const input = event.target;
    if (!pattern.test(input.value)) {
        const negativePattern = /[^0-9.]/g;
        input.value = input.value.replace(negativePattern, '');
        if (/\..{0,}/g.test(input.value)) {
            input.value = input.value.replace(/\./, '');
        }

        if (/^00+/g.test(input.value)) {
            input.value = input.value.replace(/0/, '');
        }
    }
};
expressionInput.addEventListener('change', inputChanges);
expressionInput.addEventListener('input', inputChanges);
const inputButtons = document
    .querySelectorAll('button.action:not(.action-btn,.orange)');
inputButtons.forEach((btn) => {
    btn.addEventListener('click', (event) => {

        const value = event.target.textContent;
        expressionInput.value += value;
        expressionInput.dispatchEvent(onchange);
    })
});

const funcBtns = document
    .querySelectorAll('button.action.orange');
funcBtns.forEach((btn) => {
    btn.addEventListener('click', (event) => {
        if (btn.textContent === '=') {
            if (operator === undefined) {
                return;
            }
            evaluateExpression();
            return;
        }
        funcBtns.forEach(btn => {
            btn.style = '';
        });
        btn.style = 'border: 1px solid black';
        // lvalues.push(expressionInput.value);
        lvalue ??= expressionInput.value;
        operator = btn.textContent;
        expressionInput.value = '0';
    });
});

const historyList = document.querySelector('.calculation-list');
function evaluateExpression() {
    rvalue = expressionInput.value;
    console.log(lvalue, rvalue, operator);
    switch (operator) {
        case '+':
            expressionInput.value =
                Number.parseFloat(lvalue) + Number.parseFloat(rvalue);
            break;
        case '−':
            expressionInput.value =
                Number.parseFloat(lvalue) - Number.parseFloat(rvalue);
            break;
        case '÷':
            expressionInput.value =
                Number.parseFloat(lvalue) / Number.parseFloat(rvalue);
        case '×':
            expressionInput.value =
                Number.parseFloat(lvalue) * Number.parseFloat(rvalue);
        default:
            break;
    }
    const expr = document.createElement('li');
    expr.innerHTML = `${lvalue} ${operator} ${rvalue} = ${expressionInput.value}`;
    historyList.appendChild(expr);

    lvalue = undefined;
    rvalue = undefined;
    operator = undefined;
}

const clearBtn = document.querySelector('.action.action-btn:nth-child(1)');
clearBtn.addEventListener('click', (event) => {
    expressionInput.value = 0;
});

const sqrBtn = document.querySelector('.action.action-btn:nth-child(2)');
sqrBtn.addEventListener('click', (event) => {
    if (!(lvalue === undefined && lvalues.length == 0)) {
        return;
    }
    lvalue = Number.parseFloat(expressionInput.value);
    expressionInput.value = Math.sqrt(lvalue);
    lvalue = undefined;
})

const powBtn = document.querySelector('.action.action-btn:nth-child(3)');
powBtn.addEventListener('click', (event) => {
    if (!(lvalue === undefined && lvalues.length == 0)) {
        return;
    }
    lvalue = Number.parseFloat(expressionInput.value);
    expressionInput.value = Math.pow(lvalue, 2);
    lvalue = undefined;
})

const clearHistoryBtn = document.querySelector('.clear');
clearHistoryBtn.addEventListener('click', (event) => {
    historyList.innerHTML = '';
});

const calculator = document.querySelector('.wrapper');
const maxBtn = document.querySelector('.menu-item.flex.h-center.v-center.max');
maxBtn.addEventListener('click', (event) => {
    const time = 250;
    calculator.style = `transition:all ${time}ms ease-out;width:468px;height:644px;`;
    setTimeout(() => alert('Заслужавам шестичка и усмивка!'), time);
});

const minBtn = document.querySelector('.menu-item.flex.h-center.v-center.min');
minBtn.addEventListener('click', (event) => {
    calculator.style = 'transition:all 250ms ease-out;';
});

const closeBtn = document.querySelector('.menu-item.flex.h-center.v-center.close');
closeBtn.addEventListener('click', (event) => {
    calculator.style = 'transition:all 250ms ease-out;transform: translateY(-150px) scaleY(0%);';
});