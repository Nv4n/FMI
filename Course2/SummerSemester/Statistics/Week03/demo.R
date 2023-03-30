func <- function(a, b, c) {
    return(a ^ 2 + b * c)
}
func(1, 2, 4)
func(b = 1, c = 2, a = 4)
func(b = 1, c = 2, 4)
func <- function(a, b = 12, c = 4) {
    (a ^ 2 + b * c)
}
func(a = 7)

# funct(b=7)

M3 <- matrix(data = c(1:28),
             nrow = 4,
             ncol = 7)
M3


M3 <- matrix(
    data = c(1:28),
    nrow = 7,
    ncol = 4,
    byrow = TRUE
)
M3

log((M3 + 6) / 8)

M3 %*% t(M3)

M4 <- matrix(1:8, nrow = 4, ncol = 2)
M34 <- M3 %*% M4
M34

dim(M34)
nrow(M34)
ncol(M34)

apply(X = M3, MARGIN = 1, FUN = sum)
apply(X = M34, MARGIN = 2, FUN = sum)
M34 [3, 2] <- -9999999
M34
M34 [, 2] <- 96
M34

M2 <- matrix(1, ncol = 4, nrow = 3)
M2
M5 <- matrix(999999, ncol = 2, nrow = 9)
rbind(M3, M2)
# cbind(M, M5)
