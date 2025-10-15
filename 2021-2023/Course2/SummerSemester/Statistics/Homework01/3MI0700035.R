# ф.н.: 3MI0700035
# името ви: Иван Петров
# специалността: ИС
# административната група и дали сте от минали години: група 2, курс 2
# името на асистента, при когото сте посещавали практикум: Методий Кандиларов

### Задача 1
tips <- read.csv("tips.csv")

head(tips)



### Задача 2
## Структурата data frame в R съдържа еднакъв тип по колони и еднаква дължина по редове.



### Задача 3
## редове
nrow(tips)
## колони
ncol(tips)



###Задача 4
colnames(tips)



### Задача5
## добавяне на колона
tips$bill.without.tip = tips$total_bill - tips$tip
head(tips)

## преместване на колона
tips <-
    tips[, c(names(tips)[c(1, 2)], "bill.without.tip", names(tips)[-c(1, 2, 8)])]
head(tips)

## проверка дали бакшиша може да се включи в сметката
nrow(tips) == sum(tips$total_bill > tips$tip)

## промяна името на колоната
names(tips)[1] <- "bill"
head(tips)

## изтриване на колоната
tips$bill.without.tip <- NULL
head(tips)

## преименуване на редовете
rownames(tips) <- paste0("Order", 1:nrow(tips))
head(tips)



### Задача 6
head(tips, n = 7)
tail(tips, n = 3)



### Задача 7
tips7 <- tips
str(tips7)
#bill количествена
#tip количествена
#sex качествена
#smoker качествена
#day качествена
#time качествена
#size количествена
#всички са непрекъснати
tips7$sex <- factor(tips7$sex)
tips7$smoker <- factor(tips7$smoker)
tips7$day <- factor(tips7$day)
tips7$time <- factor(tips7$time)
str(tips7)



### Задача 8
## (a)
tips8 <- tips
# минимална стойност
min(tips8$bill)
# максимална стойност
max(tips8$bill)
# средна стойност
mean(tips8$bill)

## (b)
quantile(tips8$bill, prob = 0.75)

## (c)
#Как се нарича още ’0.75-тия квантил’? Трети квартил

## (d)
# Имало е пушачи
sum(tips8$smoker == 'Yes')

## (e)
# Най-често срещан ден
days <- table(tips8$day)
names(days)[which.max(days)]

## (f)
# За вечеря
sum(tips8$time == "Dinner")



### Задача 9
## (a)
range(tips$bill)

## (b)
rank(sort(tips$bill))[15]

## (c)
tips[order(tips$size), ]

## (d)
library(dplyr)

tips %>% arrange(tips$size, tips$time)

## (e)
quantile(tips$bill, probs = 0.3)

## (f)
quantile(tips$tip, probs = 0.99)

## (g)
lower_hinge <- quantile(tips$tip, probs = 0.25)
upper_hinge <- quantile(tips$tip, probs = 0.75)
c(lower_hinge, upper_hinge)

## (h)
sd(tips$bill)

## (i)
var(tips$tip)

## (j)
names(sort(table(tips$size), decreasing = TRUE))[1]



### Задача 10
## (a)
# маси с пушачи / всички маси
sum(tips$smoker == "Yes") / nrow(tips)

## (b)
# маси с 4-ма / всички маси
sum(tips$size == 4) / nrow(tips)

## (c)
# маси с 3-ма и пушач / всички с 3-ма
sum(tips$size == 3 & tips$smoker == "Yes") / sum(tips$size == 3)

## (d)
# всички поръчки от събота вечер / всички поръчки
sum(tips$day == "Sat" & tips$time == "Dinner") / nrow(tips)

## (е)
# всички поръчки от събота вечер / всички поръчки от събота
sum(tips$day == "Sat" &
        tips$time == "Dinner") / sum(tips$day == "Sat")

## (f)
# всички маси за вечеря и плащащ мъж / всички вечерни маси
sum(tips$time == "Dinner" &
        tips$sex == "Male") / sum(tips$time == "Dinner")

### (g)
# всички маси за вечеря на която е платил мъж / всички маси на които е платил мъж
sum(tips$time == "Dinner" &
        tips$sex == "Male") / sum(tips$sex == "Male")

### (h)
sum(tips$time == "Dinner" & tips$sex == "Male") / nrow(tips)



### Задача 11
## (a)
tips[tips$size == max(tips$size) & tips$time == "Lunch", ]

## (b)
sum(tips$bill + tips$tip > 20 &
        tips$smoker == "Yes" & tips$time == "Lunch")



### Задача 12
grouped <-
    tips %>% group_by(day) %>% summarise(total_people = sum(size)) %>% arrange(desc(total_people))

barplot(
    grouped$total_people,
    names.arg = grouped$day,
    col = "steelblue",
    xlab = "Ден от седмицата",
    ylab = "Клиенти",
    main = "Най-натоварени дни"
)



### Задача 13
gender_df <- table(tips$sex, tips$time)
barplot(
    gender_df,
    beside = TRUE,
    col = c("blue", "pink"),
    legend = rownames(gender_df),
    ylab = "Брой платци",
    xlab = "Време от деня",
    main = "Платци спрямо пол и време от деня"
)



### Задача 14
library(ggplot2)
table(tips$sex, tips$day, tips$time)
#броят на мъжете, платили сметката в петък на обяд? 7

ggplot(tips, aes(x = day, fill = sex)) +
    geom_bar(position = position_dodge2(preserve = "single")) +
    facet_grid(time ~ day, scales = "free") +
    labs(y = "Време от деня", x = "Ден от седмицата", fill = "Пол на платеца") +
    theme_minimal()



### Задача 15
dens <- density(tips$bill)
hist(
    tips$bill,
    xlab = "Сметка",
    ylab = "Плътност" ,
    col = "blue",
    main = "Хистограма за сметка",
    freq = FALSE,
    ylim = c(0, max(dens$y))
)

lines(dens, col = "red", lwd = 2)



### Задача 16
boxplot(tips$tip, main = "Бакшиш за вечеря", ylab = "Стойност")
q <- quantile(tips$tip, c(0.25, 0.75))
iqr <- q[2] - q[1]

## Пресметнете къде точно се намират линиите на този boxplot.
lower <- max(min(tips$tip), q[1] - 1.5 * iqr)
upper <- min(max(tips$tip), q[2] + 1.5 * iqr)
lower
upper

## Симетрична ли е графиката? Не

## Наблюдавате ли outliers? Да

## Колко е стойността на първите два най-малки outlier-а на графиката?
outliers <- tips$tip[tips$tip < lower | tips$tip > upper]
head(sort(outliers), 2)



### Задача 17
boxplot(
    tip ~ sex,
    data = tips,
    xlab = "Пол",
    ylab = "Бакшиш",
    main = "Размер на бакшиша спрямо пола"
)

### Средната стойност е по-висока? при мъжете
### Мъжете имат повече outlier-и



### Задача 18
library(lattice)

barchart(
    tip ~ time | sex,
    data = tips,
    groups = sex,
    auto.key = TRUE,
    xlab = "време на деня",
    ylab = "обща стройност бакшиши",
    main = "Обща стройност на бакшишите спрямо време от деня и пола",
    #border = NA
)

## Извод: мъжете дават повече бакшиши и на по-голяма обща стойност



### Задача 19
library(ggplot2)

ggplot(tips, aes(x = bill, y = tip)) +
    geom_point() +
    xlab("Сметка") +
    ylab("Бакшиш") +
    ggtitle("Сметки и бакшиш")

## Корелация на Пийрсън
cor(tips$bill, tips$tip, method = "pearson")

## Кореляция на Спирман
cor(tips$bill, tips$tip, method = "spearman")

## Начертайте регресионната права.
plot(tips$bill,
     tips$tip,
     xlab = "Сметка",
     ylab = "Бакшиш",
     main = "Сметки и бакшиш")
line_reg <- lm(tips$tip ~ tips$bill)
abline(line_reg, lwd = 2)

## Изведете оценките на коефициентите на линейната функция.
coefficients <- coef(line_reg)
intercept <- coefficients[1]
slope <- coefficients[2]
names(slope)[1] <- "(Slope)"
c(intercept, slope)

## Напишете как ще изглежда уравнението на линейния модел.
# tip = intercept + slope * bill

## Ако сметката е била $25, каква е очакваната стойност на бакшиша, на базата на линейния модел?
# 3.67$ = 0.92 + 0.11* 25$
