df<-read.csv("titanic.csv",header = TRUE,sep=",")

# 1
df
ncol(df)
nrow(df)

# 2
colnames(df)
typeof(df$Pclass)
unique(df$Sex)
# PassengerId - количествени непрекъснати
# Survived - качествени
# Pclass - качествени
# Name 
# Sex - качестени
# Age - количествени непрекъснати
# SibSp - качествени
# Ticket
# Fare - количествени непрекъснати
# Cabin 
# Embarked - качествени

df<-df[ , !(colnames(df) %in% c("Name","Ticket","Cabin"))]
df
df$Survived<-as.factor(df$Survived)
df$Sex<-as.factor(df$Sex)
df$Embarked<-as.factor(df$Embarked)
df

#a)
sum(df$Survived==1)/nrow(df)

#b)
min(df$Age,na.rm = TRUE)
max(df$Age,na.rm=TRUE)
mean(df$Age,na.rm = TRUE)

#c)
summary(df$Fare)
#7.91

#d) Трети квартил

#e)
summary(df$Embarked)
#S

#f)
sd(df$Fare)

#g)
ordered_fares <- sort(unique(df$Fare),na.last = TRUE,decreasing = TRUE)
#512.3292 263.0000 262.3750 247.5208 227.5250


rank(df$Fare)
#264



#4
#a)
342/891

#b
nrow(df[df$Pclass==3 & df$Survived==1,])
119/891

#c
nrow(df[df$Pclass==3 & df$Embarked=="S",])
353/891

#d
nrow(df[df$Embarked=="S",])
nrow(df[df$Pclass==3, ])
353/644


#5
males<-df[df$Sex=="male", ]
males<-males[order(males$Fare,na.last = TRUE,decreasing = TRUE),]
males
#a) C-680 C-738 S-28 S-439 C-119

#b)
females<-df[df$Sex=="female" & df$Survived==0 & df$Pclass==1 & df$Age>22, ]
nrow(females)

#6 Male
passangers <- df[, c("Sex", "Survived")]
passangers


summary_table <- table(passangers[, c("Sex","Survived")])
summary_table
barplot(summary_table, beside = TRUE,
        col = c("red","blue"),
        legend = c("Died","Survived"),
        main = "Survival Counts by Gender",
        xlab = "Gender",
        ylab = "Count",
        names.arg = rownames(summary_table))

#7 20-40
boxplot(df$Age)
 


# Задача 2
x = c(1.9, 6.2, 6.3, 5.4, -4.2, 8.1, 1.6, 9.9, 7, -1, -2.3, 6.8, 3.2, 0.4, -0.7,
      2.3, 1.9, 3.8, 3.7, 8.8, 8.7, 8.9, 0.4, 7.2, 3.8)
y = c(0, 74, 80, 39, -237, 226, 0, 493, 125, -27, -79, 110, 2, -4, -20, 0, 1, 6,
      4, 315, 301, 328, -3, 140, 5)

#1
plot(x~y)

#2
?cor
cor(x,y,method=c("spearman"))
#0.9967264
plot(x~y)
y<-tan(y)
#3
cor(x^3,y)


#Задача 3
?rbinom
13/52
samples<-rbinom(n=100,size=10,prob=13/52)

#1 0.28
length(samples[samples==2 ])/100
dbinom(x=2,size=10,prob=1/4)

length(combn(10,2))*(1/4)^2*(3/4)^8
#2 0.4


#3 0.56
length(samples[samples<3])/100


#4 0.676


#5 >2 Пика
qbinom(p=0.75,size=10,prob=1/4,lower.tail = FALSE)
?qbinom
#Задача 4
mu<-15000
sigma<-3000
samples<-rnorm(n=40,mean=mu,sd=sigma)

#a 0.05
length(samples[samples>20000])/40

#b 0,45
length(samples[samples>=15000&samples<=20000])/40

#c 0.15
length(samples[samples<12000])/40

#d 12800
length(samples[samples>12800])/40


#Задача 5
?set.seed
set.seed(3000)
 
rolls<-sample(1:6,size=1000,replace = TRUE)
cumulative_mean <- cumsum(rolls) / (1:1000)

plot(1:1000, cumulative_mean, type = "l", col = "blue",
    xlab = "Брой хвърляния", ylab = "Кумулативна средна стойност",
    main = "Закон за големите числа за средната стойност при хвърляне на зар")

# Добавяне на хоризонтална линия, показваща теоретичната средна стойност
abline(h = mean(1:6), col = "red", lty = 2)

# Добавяне на легенда
legend("topright", legend = c("Кумулативна средна стойност", "Теоретична средна стойност"),
       col = c("blue", "red"), lty = c(1, 2))
?plot

#Задача 6
calcSin <- function(x,n) {
    res<-0
    for (i in 0:n) {
        res<-res+ (-1)^i/factorial(2*i+1)*x^(2*i+1)
    }
    sum(res)
}
calcSin(x=3,n=9)
#0.14112


#Задача 7
x = c(15.1, 14.3, 9.5, 12.6, 16.2, 16.6, 10.2, 13.5, 8.5, 14, 31.6, 29.5, 23.6,
      30.9, 29.4, 25.5, 19.3, 23.8, 30.6, 27.9, 21.4, 11.9, 21, 12.3, 17.4)
hist(x)
shapiro.test(x)
#1 yes

mean(x)
median(x)
sd(x)
#2 mean=19.464, median=17.4, sd=7.489931


#3 mean=23.464,sd 7.489931
x2<-x+4
mean(x2)
sd(x2)

#4 16.38-22.55
n<-length(x)
mu<-mean(x)
sigma<-sd(x)
sigma
t<-2.06
mu
mu+t*sigma/sqrt(n)
length(x)
#5 0.6826
(22.55-16.38)/2
# 3.085
?qt
2*0.8413-1
?barplot


22.55-
