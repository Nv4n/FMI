//@ts-check

/**
 * @type {{name:string,gender:'m'|'f'}[]}
 */
export const firstNames = [
    { name: "Александър", gender: "m" },
    { name: "Борислав", gender: "m" },
    { name: "Владимир", gender: "m" },
    { name: "Георги", gender: "m" },
    { name: "Драган", gender: "m" },
    { name: "Елена", gender: "f" },
    { name: "Златина", gender: "f" },
    { name: "Иван", gender: "m" },
    { name: "Кристина", gender: "f" },
    { name: "Любо", gender: "m" },
    { name: "Мария", gender: "f" },
    { name: "Никола", gender: "m" },
    { name: "Огнян", gender: "m" },
    { name: "Петър", gender: "m" },
    { name: "Радослав", gender: "m" },
    { name: "Светлана", gender: "f" },
    { name: "Тодор", gender: "m" },
    { name: "Юляна", gender: "f" },
    { name: "Филип", gender: "m" },
    { name: "Цветана", gender: "f" },
];

export const lastNames = [
    "Андреев",
    "Борисов",
    "Владимиров",
    "Георгиев",
    "Димитров",
    "Еленов",
    "Златев",
    "Иванов",
    "Караиванов",
    "Лазаров",
    "Маринов",
    "Николов",
    "Огнянов",
    "Петров",
    "Радев",
    "Симеонов",
    "Тодоров",
    "Узунов",
    "Филипов",
    "Цветков",
];

export const emailDomains = ["gmail.com", "abv.bg", "yahoo.com", "outlook.com"];

//TODO RANDOM ADDRESSES DATA

/**
 * @typedef {Object} ContentInfo
 * @prop {boolean} isFragile
 * @prop {number} price
 * @prop {'BGN'|'EUR'|'USD'|'RON'} currency
 * @prop {number} [quantity]
 * @prop {number} weight
 * @prop {'g'|'kg'} unit
 * @prop {string} expiryDate
 * @prop {'tool'|'seeds'|'clothing'|'equipment'|'structure'} type
 */

/**
 * @typedef {Object} Product
 * @prop {string} name
 * @prop {string} brand
 * @prop {string} notes
 * @prop {ContentInfo} contentInfo
 */

/**
 * @type {Product[]}
 */
export const products = [
    {
        name: "лопата",
        brand: "АгроИнструмент",
        notes: "подходяща за градинска работа",
        contentInfo: {
            isFragile: false,
            price: 25.5,
            currency: "BGN",
            weight: 2.3,
            unit: "kg",
            expiryDate: "2028-01-15",
            type: "tool",
        },
    },
    {
        name: "сито",
        brand: "СеверИн",
        notes: "за отделяне на пясък и камъни",
        contentInfo: {
            isFragile: true,
            price: 15.99,
            currency: "BGN",
            weight: 0.8,
            unit: "kg",
            expiryDate: "2027-12-01",
            type: "tool",
        },
    },
    {
        name: "семена от домати",
        brand: "СемеАгро",
        notes: "високодобивни сортове",
        contentInfo: {
            isFragile: false,
            price: 8.5,
            currency: "EUR",
            weight: 3,
            unit: "g",
            expiryDate: "2025-10-10",
            type: "seeds",
        },
    },
    {
        name: "трактор",
        brand: "Машиникс",
        notes: "идеален за средни площи",
        contentInfo: {
            isFragile: false,
            price: 150000,
            currency: "USD",
            weight: 1500,
            unit: "kg",
            expiryDate: "2032-05-25",
            type: "equipment",
        },
    },
    {
        name: "навес",
        brand: "ДомАгро",
        notes: "здрав и устойчив на дъжд",
        contentInfo: {
            isFragile: false,
            price: 950,
            currency: "RON",
            weight: 120,
            unit: "kg",
            expiryDate: "2030-11-15",
            type: "structure",
        },
    },
    {
        name: "градски ботуши",
        brand: "ТехноОбувки",
        notes: "удобни и издръжливи при всякакви условия",
        contentInfo: {
            isFragile: false,
            price: 45,
            currency: "BGN",
            weight: 1.5,
            unit: "kg",
            expiryDate: "2032-02-20",
            type: "clothing",
        },
    },
    {
        name: "ръкавици за градинарство",
        brand: "ГрадинаПро",
        notes: "за защита от остри предмети",
        contentInfo: {
            isFragile: false,
            price: 7.99,
            currency: "BGN",
            weight: 0.2,
            unit: "kg",
            expiryDate: "2027-06-10",
            type: "clothing",
        },
    },
    {
        name: "джобен нож",
        brand: "ФермерОборудване",
        notes: "за многофункционално използване",
        contentInfo: {
            isFragile: false,
            price: 12.5,
            currency: "BGN",
            weight: 0.5,
            unit: "kg",
            expiryDate: "2050-07-10",
            type: "tool",
        },
    },
    {
        name: "форма за разсад",
        brand: "СеменАгро",
        notes: "за точни и равномерни посеви",
        contentInfo: {
            isFragile: true,
            price: 50,
            currency: "EUR",
            weight: 2.5,
            unit: "kg",
            expiryDate: "2026-04-18",
            type: "equipment",
        },
    },
    {
        name: "орехови семена",
        brand: "ФермЕксперт",
        notes: "висококачествени семена за засаждане",
        contentInfo: {
            isFragile: false,
            price: 15.2,
            currency: "EUR",
            weight: 5,
            unit: "g",
            expiryDate: "2026-08-19",
            type: "seeds",
        },
    },
    {
        name: "косачка",
        brand: "Техноградинар",
        notes: "мощен двигател за големи площи",
        contentInfo: {
            isFragile: false,
            price: 320,
            currency: "USD",
            weight: 15,
            unit: "kg",
            expiryDate: "2027-05-11",
            type: "equipment",
        },
    },
    {
        name: "покрив за оранжерия",
        brand: "ЕкоСтрой",
        notes: "устойчив на UV лъчи и дъжд",
        contentInfo: {
            isFragile: false,
            price: 220,
            currency: "RON",
            weight: 25,
            unit: "kg",
            expiryDate: "2030-03-05",
            type: "structure",
        },
    },
    {
        name: "поливна система",
        brand: "Водаградин",
        notes: "лесна за настройка и използване",
        contentInfo: {
            isFragile: false,
            price: 180,
            currency: "BGN",
            weight: 10,
            unit: "kg",
            expiryDate: "2030-10-01",
            type: "equipment",
        },
    },
    {
        name: "осветителни тела за оранжерия",
        brand: "ЛумиТех",
        notes: "екологични и икономични",
        contentInfo: {
            isFragile: false,
            price: 90,
            currency: "EUR",
            weight: 5,
            unit: "kg",
            expiryDate: "2026-12-12",
            type: "equipment",
        },
    },
    {
        name: "система за вентилация",
        brand: "КлимаПро",
        notes: "за оптимални условия в оранжерията",
        contentInfo: {
            isFragile: false,
            price: 500,
            currency: "USD",
            weight: 25,
            unit: "kg",
            expiryDate: "2026-09-22",
            type: "structure",
        },
    },
    {
        name: "масло за трактор",
        brand: "ТехноМотор",
        notes: "висококачествено за дълготрайна работа",
        contentInfo: {
            isFragile: false,
            price: 20,
            currency: "BGN",
            weight: 1,
            unit: "kg",
            expiryDate: "2026-03-30",
            type: "equipment",
        },
    },
    {
        name: "косачка за трева",
        brand: "ТехноФермер",
        notes: "идеална за малки и средни градини",
        contentInfo: {
            isFragile: false,
            price: 150,
            currency: "USD",
            weight: 10,
            unit: "kg",
            expiryDate: "2032-08-05",
            type: "equipment",
        },
    },
    {
        name: "семена пепино пъпеш",
        brand: "Градинар",
        notes: "медено сладък сорт",
        contentInfo: {
            isFragile: false,
            price: 12.99,
            currency: "RON",
            weight: 0.9,
            unit: "g",
            expiryDate: "2030-04-10",
            type: "seeds",
        },
    },
    {
        name: "чанта за събиране на плодове",
        brand: "ГрадинкаПро",
        notes: "удобна и здрава",
        contentInfo: {
            isFragile: false,
            price: 18,
            currency: "BGN",
            weight: 0.8,
            unit: "kg",
            expiryDate: "2026-02-15",
            type: "clothing",
        },
    },
    {
        name: "защитни очила",
        brand: "ФермерГард",
        notes: "защита от при пръскане",
        contentInfo: {
            isFragile: true,
            price: 10,
            currency: "BGN",
            weight: 250,
            unit: "g",
            expiryDate: "2032-05-20",
            type: "clothing",
        },
    },
    {
        name: "семена лилаво зеле",
        brand: "Агроном",
        notes: "зимен сорт",
        contentInfo: {
            isFragile: false,
            price: 1,
            currency: "USD",
            weight: 2,
            unit: "g",
            expiryDate: "2027-07-22",
            type: "seeds",
        },
    },
    {
        name: "семена микс моркови",
        brand: "АгроПро",
        notes: "високо-добивен микс",
        contentInfo: {
            isFragile: false,
            price: 10,
            currency: "BGN",
            weight: 5,
            unit: "g",
            expiryDate: "2029-04-17",
            type: "seeds",
        },
    },
];

/** @type{['canceled','returned','finished','pending']} */
export const deliveryStatuses = ["canceled", "returned", "finished", "pending"];

/** @type {{country:string,city:string,address:string}[]} */
export const contactLocations = [
    { country: "България", city: "София", address: "ул. Витоша 10" },
    { country: "Сърбия", city: "Белград", address: "бул. Краля Александра 25" },
    { country: "Румъния", city: "Букурещ", address: "ул. Липскани 32" },
    { country: "Гърция", city: "Атина", address: "пл. Синтагма 5" },
    { country: "Турция", city: "Истанбул", address: "пл. Таксим 1" },
    {
        country: "Северна Македония",
        city: "Скопие",
        address: "бул. Македония 15",
    },
    { country: "Албания", city: "Тирана", address: "пл. Скандербег 10" },
    {
        country: "Босна и Херцеговина",
        city: "Сараево",
        address: "ул. Башчаршия 8",
    },
    {
        country: "Черна гора",
        city: "Подгорица",
        address: "ул. Независимост 12",
    },
    { country: "Косово", city: "Прищина", address: "ул. Майка Тереза 18" },
    { country: "Хърватия", city: "Загреб", address: "ул. Илица 45" },
    { country: "Словения", city: "Любляна", address: "ул. Прешернов площад 3" },
    { country: "Молдова", city: "Кишинев", address: "бул. Стефан чел Маре 22" },
    { country: "България", city: "Пловдив", address: "ул. Главна 67" },
    { country: "България", city: "Варна", address: "бул. Сливница 14" },
    { country: "Сърбия", city: "Нови Сад", address: "ул. Змай Йовина 9" },
    { country: "Румъния", city: "Клуж-Напока", address: "ул. Унири 21" },
    { country: "Гърция", city: "Солун", address: "ул. Егнатиа 33" },
    { country: "Турция", city: "Анкара", address: "ул. Ататюрк 77" },
    {
        country: "Северна Македония",
        city: "Битоля",
        address: "ул. Широк сокак 5",
    },
    { country: "Албания", city: "Шкодра", address: "ул. Розафа 2" },
    {
        country: "Босна и Херцеговина",
        city: "Мостар",
        address: "ул. Стари мост 3",
    },
    { country: "Черна гора", city: "Котор", address: "ул. Стари град 7" },
    { country: "Косово", city: "Гниляне", address: "ул. Илирия 10" },
    { country: "Хърватия", city: "Дубровник", address: "ул. Страдун 12" },
    { country: "Словения", city: "Марибор", address: "ул. Главен площад 4" },
    { country: "Молдова", city: "Тираспол", address: "ул. Одеска 15" },
    { country: "България", city: "Бургас", address: "ул. Богориди 23" },
    { country: "Румъния", city: "Брашов", address: "ул. Република 11" },
    { country: "Турция", city: "Измир", address: "ул. Конак 6" },
];
