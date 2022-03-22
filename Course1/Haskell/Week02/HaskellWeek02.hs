import GHC.Conc (numCapabilities)
main:: IO()
main = do
    print(myGCD 9 121)
    print(countDigits 1000)
    print(sumDigitsRec 123)
    print(sumDigitsIter 1234)
    print(reverseNumber 1234)

myGCD :: Int -> Int -> Int
myGCD a 0 = a
myGCD a b = myGCD b (a `mod` b)

countDigits :: Int -> Int 
countDigits num
    | num < 10 = 1
    | otherwise = 1 + countDigits (num `div` 10)

sumDigitsRec :: Int -> Int  
sumDigitsRec num
    | num < 10 = num
    | otherwise = num `mod` 10 + sumDigitsRec(num `div` 10)

sumDigitsIter :: Int -> Int 
sumDigitsIter num = helper 0 num
    where
        helper sum num = 
            if num < 10
                then sum + num
            else helper (sum+num  `mod` 10) (num `div` 10)

reverseNumber ::  Int -> Int 
reverseNumber num = helper 0 num
    where 
        helper revNum num = 
            if num < 10
                then revNum * 10 + num
            else helper (revNum * 10 + num `mod` 10) (num `div` 10)