function countLetters(input) {
    let letterCount = {};
    for (const letter of input) {
        const l = letter.toLowerCase();
        if (/[a-z]/.test(l)) {
            letterCount[l] ??= 0;
            letterCount[l]++;
        }
    }
    Object.entries(letterCount).map(el => {
        const [key, value] = el;
        console.log(`${key}: ${value}`);
    });
}

const input = 'Do ex excepteur qui in. Eiusmod eu enim excepteur anim in nulla enim aliquip voluptate. Excepteur id consequat amet labore adipisicing occaecat ipsum mollit esse ut sunt do velit. Anim esse veniam ea cillum minim dolor exercitation adipisicing exercitation. Velit esse ad minim et ad aliqua. Elit consectetur id reprehenderit proident cillum ipsum sunt sint. Id dolor aute sit nisi excepteur ullamco incididunt esse occaecat culpa elit nisi.';


countLetters(input);