#2.1
# Стандартно нормално разпределение
mu = 650
sigma = 40
x = 700

# a)
pnorm(q = 700, mean = mu, sd = sigma)
# b)
qnorm(p = 0.95, mean = mu, sd = sigma)


#2.2
#p=37%
#n=10
#4 success



#a)
dbinom(x=4,size=10,prob=0.37)

#b)
pbinom(q=8,size=10,prob=0.37)-pbinom(q=3,size=10,prob=0.37)
