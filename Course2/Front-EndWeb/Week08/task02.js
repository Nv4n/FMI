const dates = [];

dates.push(new Date());

const customDate = new Date("12.08.2018");
customDate.setHours(21);
dates.push(customDate);

const days = dates.map(el => {
    const end = new Date(el.getFullYear(), el.getMonth() + 1, 0);
    return [end.getDate(), el.getDay()];
});


const formatedDates = dates.map((el, i) => {
    const end = new Date(el.getFullYear(), el.getMonth() + 1, 0);
    const day = ['неделя', 'понеделник', 'вторник', 'сряда', 'четвъртък', 'петък', 'събота'];
    return `Дата: ${el.toLocaleDateString()}, час: ${el.toLocaleTimeString()}, ${day[el.getDay()]}, ${end.getDate()} дни`;
});

console.log(dates);
console.log(...days);
console.log(formatedDates);