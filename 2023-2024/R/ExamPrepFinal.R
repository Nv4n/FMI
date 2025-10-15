age = c(18, 23, 25, 35, 65, 54, 34, 56, 72, 19, 23, 42 , 18 , 39, 37)
bpm = c(202,
        186,
        187,
        180,
        156,
        169,
        174,
        172,
        153,
        199,
        193,
        174,
        198,
        183,
        178)
df = data.frame(age, bpm)
df
summary(lm(bpm ~ age, data = df))

plot(age, bpm)
lmRes = lm(bpm ~ age)
lmRes
summary(lmRes)
abline(lmRes)
y = 210.04846 - 0.79773 * age

getExpectedBpm = function(X) {
    return(210.04846 - 0.79773 * X)
}
getExpectedBpm(30)
getExpectedBpm(40)
getExpectedBpm(50)
predict(lmRes)

e = bpm - y
e
shapiro.test(e)
qqnorm(e)
qqline(e)
plot(lmRes)

bptest(lmRes)

predict(lmtestpredict(lmRes, interval = "confidence", level = 0.9)
simple.lm(age, bpm, show.ci = TRUE, conf.level = 0.90)
? simple.lm




# 13.1
prices = c(
    300 * 10 ^ 3,
    250 * 10 ^ 3,
    400 * 10 ^ 3,
    550 * 10 ^ 3,
    317 * 10 ^ 3,
    389 * 10 ^ 3,
    425 * 10 ^ 3,
    289 * 10 ^ 3,
    389 * 10 ^ 3,
    559 * 10 ^ 3
)
bedroomsCount = c(3, 3, 4, 5, 4, 3, 6, 3, 4, 5)
lmResult <- lm(prices ~ bedroomsCount)
summary(lmResult)
plot(bedroomsCount, prices)
abline(lmResult)

length(prices)
y = 94400 + 73100 * bedroomsCount
# Est. Bedroom Count - Expected /  Bedroom error
t <- (73100 - 60000) / 23764

pvalue <- pt(t, df = 8, lower.tail = FALSE)
pvalue > 0.05
# H1



#13.2
rm(list = ls())
beers <- c(5, 2, 9, 8, 3, 7, 3, 5, 3, 5)
bal <- c(0.10, 0.03, 0.19, 0.12, 0.04, 0.095, 0.07, 0.06, 0.02, 0.05)
lmRes<-lm(bal~beers)
summary(lmRes)
plot(beers,bal)
abline(lmRes)

t<-(0.02-0.019200 )/0.003511 
length(beers)
pvalue<-pt(t,df=8,lower.tail = TRUE)
pvalue
pvalue>0.02
#H1


#13.4
#H0 = -5.34
#H1 < -5.34

elevation=c(600,1000,1250,1600,1800,2100,2500,2900)/1000
temp=c(56,54,56,50,47,49,47,45)
lmRes<-lm(temp~elevation)
summary(lmRes)
plot(elevation,temp)
abline(lmRes)
length(elevation)
resid(lmRes)
#t<-(-5.34-)
t<-(-5.34+5.1146 )/0.9214
pvalue<-pt(t,df=6,lower.tail = TRUE)
pvalue>0.05
?identify


#14
install.packages("faraway")
library(faraway)
savings

