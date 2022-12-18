//* Form validation
const form = document.getElementById('studentForm');
const errorBox = document.querySelector('.box.red');
const successBox = document.querySelector('.box.green');
const studentTable = document.querySelector('table>tbody');

form.addEventListener('submit', (event) => {
    event.preventDefault();
    const parent = event.target;
    const fname = parent.querySelector('#studentName');
    const lname = parent.querySelector('#studentFamily');
    const facultyNumber = parent.querySelector('#studentNumber');
    const grade = parent.querySelector('#studentGrade');

    if (!triggerValidate(/^[А-Я][а-я]+(-[А-Я][а-я]+)?$/, fname)) {
        return;
    }
    if (!triggerValidate(/^[А-Я][а-я]+$/, lname)) {
        return;
    }
    if (!triggerValidate(/^([1-9][0-9]{4}|100000)$/, facultyNumber)) {
        return;
    }
    if (!triggerValidate(/^([2-5](\.[0-9]{1,2})?|6)$/, grade)) {
        return;
    }
    const studentFacNums = studentTable.querySelectorAll('tr > td:nth-child(3)');
    const facValue = facultyNumber.value.toString();
    for (const el of studentFacNums) {
        if (el.textContent.trim() === facValue) {
            triggerError(facultyNumber);
            return;
        }
    }
    console.log('here');
    const gradeValue = Number.parseFloat(grade.value.trim());
    const student = document.createElement('tr');
    student.innerHTML = `
    <td>
        ${fname.value.trim()}
    </td>
    <td>
        ${lname.value.trim()}
    </td>
    <td>
        ${facValue}
    </td>
    <td>
        ${gradeValue}
    </td>
    `;
    student.classList.toggle('green', gradeValue >= 5.5);
    studentTable.appendChild(student);
});

function triggerError(element) {
    element?.classList.remove('green');
    element?.classList.add('red-border');
    successBox.classList.add('hidden');
    errorBox.classList.remove('hidden');
}
function triggerSuccess(element) {
    element?.classList.remove('red-border');
    element?.classList.add('green');
    errorBox.classList.add('hidden');
    successBox.classList.remove('hidden');
}
function triggerValidate(pattern, element) {
    if (!validate(pattern, element)) {
        triggerError(element);
        return false;
    }
    triggerSuccess(element);
    //!FIXME Chrome pop up (blue background) effects the class change
    //? Inputs of type "text" are not affected without next 2 lines
    if (element.type !== 'number') {
        element.value = element.value + ' ';
        element.value = element.value.trim();
    }
    return true;
}
function validate(pattern, element) {
    return pattern.test(element.value.trim())
}