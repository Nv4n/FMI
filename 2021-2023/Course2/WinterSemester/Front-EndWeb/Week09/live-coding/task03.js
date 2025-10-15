function evaluateName(input) {
    const names = input.split(', ');
    const nameScores = names.map(name => {
        const score = [...name].reduce((sum, letter) => sum + letter.charCodeAt(0), 0);
        return score;
    });
    const index = nameScores.indexOf(Math.max(...nameScores));
    return names[index];
}

console.log(evaluateName('Anna Dosewa Asenowa, Iwo Peew Peew'));