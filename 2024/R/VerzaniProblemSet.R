#Verzani Problem Set
#14.1

load("homeprice")
library("UsingR")

homeprice
boxplot(homeprice$sale,homeprice$half)
?hist
head(homeprice)
attach(homeprice)
 lm(sale ~ half)
modelPriceBathroom
plot(half, sale)
abline(lm(sale ~ half))
summary(modelPriceBathroom)
plot(lm(sale ~ half))
#14.2
summary(lm(sale~half))
install.packages("faraway")

plot(savings)
head(savings)
library(faraway)
savings
plot(savings$pop15,savings$dpi)
summary(lm(dpi~pop15,data=savings))
abline(lm(dpi~pop15,data=savings))
aggregate(dpi~pop15,data=savings,FUN=function(x) {shapiro.test(x)$p.value})

hist(tb)
