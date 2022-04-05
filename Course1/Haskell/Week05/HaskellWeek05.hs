{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
main::IO()
main = do
    print(chunksOf 3 [1,2,3,4,5,6,7,8,9,10])
    print(divisors 123)
    print(isTriangular [[1,0,0],[0,2,0],[0,0,3]])
    print(isTriangular [[1,0,0],[0,2,0],[0,5,3]])
    -- print (isImage [1,2,3] [3,3])
    -- print(multiplyAllBy [1,2,3] 3)
    -- print(filterSmallerThan [1,2,3,4,5,10] 3)
    -- print(isAscending 321)

-- Задача 1. Да се дефинира функция multiplyAllBy :: [Int] -> Int -> [Int], която получава списък и число и умножава всеки елемент на списъка по числото.
multiplyAllBy :: Num t => [t] -> t -> [t]
multiplyAllBy [] _ = []
multiplyAllBy xs multp = [x * multp | x <- xs]

-- Задача 2. Да се дефинира filterSmallerThan xs n, която получава списък xs и число n и премахва елементите на списъка xs, които са по-малко от числото n.
filterSmallerThan:: [Int] -> Int -> [Int]
filterSmallerThan xs n = [x | x <- xs, x >= n]

toList::Integer -> [Integer]
toList num =
    if num < 10 then [num]
    else num `mod` 10 : toList (num `div` 10)

-- Задача 3. Да се дефинира функция isAscending :: Integer -> Bool, която проверява дали цифрите на число са във възходящ ред. Функцията да получава число, но да работи със списък от цифрите му.
isAscendingList:: [Integer ] -> Bool
isAscendingList [] = True
isAscendingList [_] = True
isAscendingList (x1:x2:xs) = x1 > x2 && isAscendingList (x2:xs)

isAscending :: Integer -> Bool
isAscending num = isAscendingList (toList num)

-- Задача 4. Нека as = [a1, a2, … , ak] и bs = [b1, b2, … , bk] са непразни списъци с еднакъв брой числа. Да се дефинира предикат isImage :: [Int] -> [Int] -> Bool, който да връща „истина“ точно когато съществува такова число x, че ai = x + bi за всяко i = 1,..., k.
isImage::[Int] -> [Int] -> Bool
isImage (a:as) (b:bs) =
    if length as /= length bs then error "The lengths of the lists are not equal!"
    else  helper (a - b) as bs
        where
            helper _ [] _ = True
            helper x (c:cs) (d:ds) = x == c - d && helper x cs ds

-- Задача 5. Да се дефинира функция chunksOf :: Int -> [a] -> [[a]], която разделя входния списък на подсписъци с дължина равна на подаденото число.
chunksOf :: Int -> [a] -> [[a]]
chunksOf _ [] = []
chunksOf steps xs = take steps xs : chunksOf steps (drop steps xs)

-- Задача 6. Да се дефинира функция divisors :: Integer -> [Integer], която генерира списък от всички (собствени) делители на дадено число.
divisors :: Integer -> [Integer]
divisors num = [x | x <- [1 .. (num `div` 2 )], num `mod` x == 0]

-- Задача 7. Да се дефинира предикат isTriangular :: [[Int]] -> Bool, който получава квадратна числова матрица, представена като списък от списъци, и проверява дали тя е горно триъгълна, т.е. дали всичките елементи под главния ѝ диагонал са нули.

isTriangular :: [[Int]] -> Bool
isTriangular [] = False
isTriangular as = helper 0 as
    where
        helper _ [] = True
        helper steps (b:bs) = sum (take steps b) == 0 && helper (steps + 1) bs