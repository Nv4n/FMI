function translate(name) {
    let [first, last] = name.split(' ');

    const mapping = {
        'а': 'a',
        'б': 'b',
        'в': 'v',
        'г': 'g',
        'д': 'd',
        'е': 'e',
        'ж': 'zh',
        'з': 'z',
        'и': 'i',
        'й': 'y',
        'к': 'k',
        'л': 'l',
        'м': 'm',
        'н': 'n',
        'о': 'o',
        'п': 'p',
        'р': 'r',
        'с': 's',
        'т': 't',
        'у': 'u',
        'ф': 'f',
        'х': 'h',
        'ц': 'ts',
        'ч': 'ch',
        'ш': 'sh',
        'щ': 'sht',
        'ъ': 'a',
        'ь': 'y',
        'ю': 'yu',
        'я': 'ya',
    }
    const transLetter = (l) => mapping[l];
    const transName = (name) => {
        let res = [...name].map(l => transLetter(l.toLowerCase()));
        res[0] = res[0].charAt(0).toUpperCase() + res[0].charAt(1);
        return res.join('');
    }

    return transName(first) + ' ' + transName(last);
}


console.log(translate('Мартин Христов'));//Мартин Христов => Martin Hristov
console.log(translate('Янислав Тодоров'));//Янислав Тодоров => Yanislav Todorov
console.log(translate('Цанислав Гатев'));//Цанислав Гатев => Tsanislav Gatev
console.log(translate('Живко Иванов'));//Живко Иванов => Zhivko Ivanov
console.log(translate('Ния Пеева'));//Ния Пеева => Niya Peeva