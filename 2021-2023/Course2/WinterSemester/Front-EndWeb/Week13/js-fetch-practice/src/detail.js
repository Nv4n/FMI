const queryString = window.location.search;
const urlParams = new URLSearchParams(queryString);
const countryParam = urlParams.get('country');

const header = document.querySelector('.detail-page-header');
const countryDetails = document.querySelectorAll('.detail-page-content-box-content')[0];
const additionalDetails = document.querySelectorAll('.detail-page-content-box-content')[1];
const universitiesList = document.getElementById('universities-list');

header.innerHTML = "";
countryDetails.innerHTML = "";
additionalDetails.innerHTML = "";
universitiesList.innerHTML = "";

let country;
await(async () => {
    const countryObj = await (await fetch(`https://restcountries.com/v3.1/name/${countryParam}`)).json();
    country = countryObj[0];
})()
    .then(async () => {
        await initialize();
    });

async function initialize() {
    await createHeader();
    await createCountryDetails();
    await createAdditionalDetails();
}

async function createHeader() {
    header.innerHTML = `
    <img src="${country?.flags?.svg}" class="detail-page-header-image" alt="${country?.name?.common} Flag" />
    <div class="detail-page-header-title">${country?.name?.official}</div>
`;
    const closeBtn = document.createElement('button');
    closeBtn.id = 'closeBtn';
    closeBtn.innerHTML = 'Close';
    closeBtn.addEventListener('click', (event) => {
        window.location.href = '/index.html';
    });
    header.appendChild(closeBtn);
}

async function createCountryDetails() {
    countryDetails.innerHTML = `
        Capital: ${country?.capital[0]} <br />
        Region: ${country?.region} <br />
        Subregion: ${country?.subregion} <br />
        Country area: ${Math.round(country?.area)} km2 <br />
        Borders: ${country?.borders.join(", ")}
    `;
}

async function createAdditionalDetails() {
    additionalDetails.innerHTML = `
        Population: ${country?.population} <br />
        Language: ${country?.languages.join(', ')}<br />
        Timezone: ${country?.timezones.join(', ')} <br />
        Currency: Bulgarian lev (лв)
    `
}
console.log(country);
