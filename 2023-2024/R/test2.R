# install.packages("ggplot2")
library("ggplot2")


# Бинарна логистична регресия
# 
#       Бинарната логистична регресия (binary logistic regression) е вид регресионен 
#   анализ, който принадлежи към семейството на Обобщените линейни модели (Generalized 
#   Linear Models - GLM) и се използва за моделиране на бинарна зависима променлива. 
#   И тук, както при линейната регресия имаме:
#       - множеството X, в което се намират обясняващите променливи и на на тяхна база
#   получаваме прогнозите ни; 
#       - y е зависимата променлива (вектор), която приема стойности 0/1, True/False, 
#   Yes/No и т.н.

#       За разлика от линейната регресия, която има уравнение y = b(0) + b(1)*x(1) + ... 
#   + b(p)*x(p) + error, при бинарната логистична регресия имаме:
#       
#       logit(P) = log(P / (1 - P)) = b(0) + b(1)*x(1) + ... + b(p)*x(p) + error,
#   където P е вероятността за сбъдване на събитието  1, "True", "Yes" и т.н.


#       За пример ще изпозлваме данните mtcars, където ще се опитаме да прогнозираме
#   дали колата има автоматична или ръчна трансмисия (променливата "am")
data(mtcars)
str(mtcars)

mtcars[, "am"] <- as.factor(mtcars[, "am"])

#       Първоначално ще стартираме с една променлива, а след това ще направим по-
#   сложен модел. Нека тази променлива да бъде "mpg".

#       Нека стартираме с изследване връзката между зависимата и обясняващата 
#   променливи - първо графично и след това с помощта на тестове:
boxplot(mpg ~ am, data = mtcars, horizontal = TRUE)
#   Както се вижда от графиката, тази променлива е статистически значима, защото 
#   3-тия квартил променливата "mpg" за група 0 (ръчна трансмисия) е по-малък от
#   1-вия квартил за група 1 (автоматична трансмисия).


#       Нека да разгледаме и резултатите от тестовете за локация на разпределение.
#   Първо ще започне с проверка на хипотезите за нормално разпределение за всяка 
#   една от групите. За целта ще използваме Shapiro-Wilk Normality test. Да припомним,
#   че нулевата хипотеза е, че разпределението е нормално.
#   Избираме ниво на съгласие alpha = 0.05
aggregate(mpg ~ am, data = mtcars, FUN = function(x) {shapiro.test(x)$p.value})
#   И при двете групи, p-value на Shapiro-Wilk Normality test е по-голямо от нивото 
#   на съгласие, следователно ще примем (към настоящия момент), че двете групи са
#   нормално разпределени. 

#       Следващата стъпка е да проверим хипотезата, че локациите (средните стойности) 
#   на двете разпределения се различават. Тоест H0: mu1 == mu2. 
#       Тъй като и двете групи са нормално разпределени, то можем да използваме t-test
#   или разширението му Welch Two Sample t-test. С помощта на F-test ще проверим дали
#   групите имат константна вариация. Отново нивото ни на съгласие alpha ще бъде 0.05.
var.test(mpg ~ am, data = mtcars)

#       Не можем да отхвърлим нулевата хипотеза (константни вариации), следователно ще 
#   използваме t-test.
t.test(mpg ~ am, data = mtcars, var.equal = TRUE)
#   Стойността на p-value e < alpha = 0.05, следователно имаме статистически значима
#   разлика.

#   Сравняване на резултатите на Two sampe t-test с тези на Welch Two Sample t-test
t.test(mpg ~ am, data = mtcars)
#   Разликата в този случай не изглежда значима. И при двата теста се отхвърля нулевата
#   хипотеза. Разминаването идва в стойностите на p-value.


#       Продължаваме с графично представяне на връзката между променливите "am" и "mpg".
#   В проста бинарна логаритмична регресия (simple binary logistic regression), лесно
#   можем графично да представим връзката между тях.
plot(mtcars[, "mpg"], as.character(mtcars[, "am"]), xlab = "mpg", ylab = "Is automatic")
#   !!! Забележете, че използваме as.character(mtcars[, "am"]), вместо mtcars[, "am"].
#   На графиката трябва да се опитаме да построим такава линия, която да стартира от
#   0 (тоест не е автоматична трансмисията) и да премине към 1-ца (автоматична трансмисия)
#   с увеличаването на стойностите на "mpg".




#       За да построим бинарна логистична регресия, трябва да изпозлваме функцията glm().
binary_logistic_regression1 <- glm(am ~ mpg, data = mtcars, family = "binomial")
#       Функцията glm отговаря за обобщени линейни модели, към които принадлежи и 
#   бинарната логистична регресия (blr). За да уточним все пак, че става дума за blr,
#   то параметърът "family", трябва да бъде равен на "binomial".


binary_logistic_regression1
summary(binary_logistic_regression1)
#       Интерпретацията на резултата е същата като при линейните модели. И двата 
#   коефициента (константата и оценката на "mpg") са статистически значими. Следователно 
#   уравнението придобива вида log(P / (1 - P)) = -6.6035 +0.307*mpg.
#       С тази формула, изчисляването на вероятносите е по-трудно. Ето защо, можем да 
#   използваме тази:
#       P = 1 / (1 + exp(-(b0 + b1*x1)))
#   И от там: P = 1 / (1 + exp(6.6035 - 0.307*mpg)))


#       За съжаление, извеждането на стойността на R2 за логистична регресия не е 
#   толкова лесно, както при линейната регресия. Това затруднява и избора на най-добър
#   модел измежду множество от модели.
#       Основно се използват три метрики за изчисляване на Pseudo R2:
#   - McFadden's R2
#   - Cox & Snell R2
#   - Nagelkerke R2
#       Метриката "Nagelkerke R2" най-много се доближава по интерпретация до R2 на
#   линейната регресия. Тоест, тя се изменя в интервала [0, 1]


#       Избор на най-добър модел от множество модели, може да се направи като използваме
#   Akaike Information Criteria (AIC). Избираме модела с най-малка стойност на AIC.
#       AIC може да приема и отрицателни стойности.


#       !!! Само за информация
#   Изчисляването е:
null_logistic_regression <- glm(am ~ 1, data = mtcars, family = "binomial")


nagelkerke_R2 <- function(model, null_model) {
    n <- model$df.null
    L0 <- exp(logLik(null_model)[1])
    L1 <- exp(logLik(model)[1])
    round((1 - (L0/L1)^(2/n)) / (1 - L0^(2/n)), 4)
}


pseudo_r2 <- nagelkerke_R2(binary_logistic_regression1, null_logistic_regression)
print(paste("Nagelkerke R2:", pseudo_r2))


#       След като имаме готов модел, ще покажем как се правят и прогнози с помощта
#   на модела. За разлика от линейната регресия, прогнозите, получени от функцията
#   predict, са два три вида - "link", "response" и "terms". Нас ни интересува
#   type = "response", тъй като този вид прогнози връща вероятността за настъпване
#   на събитието.


blr_pred <- 
    predict(object = binary_logistic_regression1, newdata = mtcars, type = "response")


#       Нека да начертаем кривата, която която разграничава едно събитие дали ще се
#   случи или не
XX <- data.frame(mpg = seq(from = 5, to = 40, by = 0.1))
probability_curve <- 
    predict(object = binary_logistic_regression1, newdata = XX, type = "response")



plot(mtcars[, "mpg"], as.character(mtcars[, "am"]), xlab = "mpg", ylab = "Is automatic", 
     main = "Probability curve")
lines(XX[, "mpg"], probability_curve, col = "red", lwd = 2)




#       Финалната стъпка е да построим бинарен логистичен модел, използвайки повече
#   от една променливи. Целта, разбира се, е да подобрим точността на модела.
binary_logistic_regression2 <- glm(am ~ wt + hp, data = mtcars, family = "binomial")
binary_logistic_regression2
summary(binary_logistic_regression2)




null_logistic_regression <- glm(am ~ 1, data = mtcars, family = "binomial")
pseudo_r2 <- nagelkerke_R2(binary_logistic_regression2, null_logistic_regression)
print(paste("Nagelkerke R2:", pseudo_r2))


#       Сега ще изобразим кривата, за да покажем визуално, че този модел е по-добър.
#   Нека и да сравним резултатите от използването на една променлива (mpg) и от
#   изпозлването на повече от една променливи ("wt" и "hp):



coeffs1 <- binary_logistic_regression1$coefficients
Z1 <- round(coeffs1[[1]], 4) + round(coeffs1[[2]], 4)*mtcars[, "mpg"]
Probab1 <- round(1 / (1 + exp(-Z1)), 4)
result_DF1 <- data.frame(Z = Z1, Probab = Probab1, am = as.character(mtcars[, "am"]))
result_DF1 <- result_DF1[order(result_DF1[, "Z"], decreasing = FALSE), ]
xlable1 <- paste0("Z = ", round(coeffs1[[1]], 4), " + ", round(coeffs1[[2]], 4), "*mpg")


coeffs2 <- binary_logistic_regression2$coefficients
Z2 <- round(coeffs2[[1]], 4) + round(coeffs2[[2]], 4)*mtcars[, "wt"] + 
    round(coeffs2[[3]], 4)*mtcars[, "hp"]
Probab2 <- round(1 / (1 + exp(-Z2)), 4)
result_DF2 <- data.frame(Z = Z2, Probab = Probab2, am = as.character(mtcars[, "am"]))
result_DF2 <- result_DF2[order(result_DF2[, "Z"], decreasing = FALSE), ]

xlable2 <- paste0("Z = ", round(coeffs2[[1]], 4), " + ", round(coeffs2[[2]], 4), 
                  "*wt + ", round(coeffs2[[3]], 4), "*hp")

#       nagelkerke_R2
model1_pseudo_r1 <- nagelkerke_R2(binary_logistic_regression1, null_logistic_regression)
model1_pseudo_r2 <- nagelkerke_R2(binary_logistic_regression2, null_logistic_regression)





par(mfrow = c(1, 2))
plot(result_DF1[, "Z"], result_DF1[, "am"], xlab = xlable1, ylab = "Is automatic",
     main = "Probability curve")
text(min(Z1) + diff(range(Z1))/5, 0.8, paste("Nagelkerke R2 =", model1_pseudo_r1))
lines(result_DF1[, "Z"], result_DF1[, "Probab"], col = "red", lwd = 2)


plot(result_DF2[, "Z"], result_DF2[, "am"], xlab = xlable2, ylab = "Is automatic",
     main = "Probability curve")
text(min(Z2) + diff(range(Z2))/5, 0.8, paste("Nagelkerke R2 =", model1_pseudo_r2))
lines(result_DF2[, "Z"], result_DF2[, "Probab"], col = "red", lwd = 2)
par(mfrow = c(1, 1))









