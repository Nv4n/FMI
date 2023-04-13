# 1
df <- read.csv("tips.csv")

head(df)

#2
# Съдържа един и същи тип на данните по колони и еднаква дължина по редове.

#3
nrow(df)
ncol(df)

#4
colnames(df)

#5
df$bill.without.tip = df$total_bill - df$tip
head(df)

df <-
    df[, c(names(df)[c(1, 2)], "bill.without.tip", names(df)[-c(1, 2, 8)])]
head(df)

summary(df$total_bill > df$tip)

names(df)[1] <- "bill"
head(df)

df$bill.without.tip <- NULL
head(df)

rownames(df) <- paste0("Order", 1:nrow(df))
head(df)

#6
head(df, n = 7)
tail(df, n = 3)

#7
#TODO
