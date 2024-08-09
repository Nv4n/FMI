# Прочетете предоставените данни (file2.csv) с помощта на функцията "read.csv" в R
data = read.csv("file2.csv")

# Едномерен описателен анализ за всяка променлива, започваща с буквата "V"
data$V1 <- as.factor(data$V1)
vVars <- data[, grepl("^V", names(data))]
summary(vVars)

# Изследвате влиянието на всяка променлива, започваща с “V”, върху променливата “y”.
# Пример за корелационен анализ
numericVVars <- vVars[, grepl("^V[^1]", names(vVars))]
cor(numericVVars, data$y)


aggregate(y~V1,data=data,FUN=function(x){shapiro.test(x)})
t.test(y~V1,data=data)

# Постройте графики
# Scatter plot V2 & V3 върху y
# Box plot V1 върху y
library(ggplot2)

ggplot(data, aes(x = V1, y = y)) +
    geom_boxplot()  +
    labs(title = "Box plot of V1 vs y")
ggplot(data, aes(x = V2, y = y)) +
    geom_point() +
    labs(title = "Scatter plot of V2 vs y") +
    geom_smooth(method = "lm", se = FALSE)
ggplot(data, aes(x = V3, y = y)) +
    geom_point() +
    labs(title = "Scatter plot of V3 vs y") +
    geom_smooth(method = "lm", se = FALSE)
