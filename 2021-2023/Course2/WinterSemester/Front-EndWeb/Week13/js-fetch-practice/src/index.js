const countryList = document.getElementById("countryList");
countryList.innerHTML = "";

let countries;
await(async () => {
    const countriesObj = await (await fetch("https://restcountries.com/v3.1/all")).json();
    countries = countriesObj;
})()
    .then(async () => { await initialize(); });

async function initialize() {
    countries.forEach(async (country) => {
        await addCountry(country);
    });
}

async function addCountry(country) {
    const countryItem = document.createElement('li');
    countryItem.className = 'country';
    countryItem.innerHTML = `
        <img class="country-image" alt="${country?.name?.common} flag" src="${country?.flags?.svg}" />
        <div class="country-title">${country?.name?.common}</div>
    `;
    const moreInfoBtn = document.createElement('button');
    moreInfoBtn.className = 'country-btn';
    moreInfoBtn.innerHTML = 'More information';

    moreInfoBtn.addEventListener('click', (event) => {
        const countryParam = country?.name?.common
            .toLowerCase();
        window.location.href = `/detail.html?country=${countryParam}`;
    });

    countryItem.appendChild(moreInfoBtn);
    countryList.appendChild(countryItem);
}

const filterBtn = document.querySelector(".filters .filter-btn");
const filterOption = document.querySelector('.filters .filter-item select');
const filterSearch = document.querySelector('.filters .filter-item input');

// console.log(filterBtn);
filterBtn.addEventListener('click', (event) => {
    // if(filterOption.)
})
