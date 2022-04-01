main :: IO ()
main = do
    print (sumCountsIter 1 1) -- ➝ 1
    print (sumCountsIter 5123 1) -- ➝ 19
    print (sumCountsIter 1234 8) -- ➝ 10
    print (sumCountsIter 5555 5) -- ➝ 10
    print (sumCountsIter 65432 6) -- ➝ 11
    print (sumCountsIter 70000 1) -- ➝ 11
    print (sumCountsIter 123321 1) -- ➝ 29

-- Задача 1
isNumberSingleDigit :: Int -> Bool
isNumberSingleDigit d = d >= 0 && d <= 9

getOccurancesInNumber:: Int -> Int -> Int
getOccurancesInNumber 0 0 = 1
getOccurancesInNumber num digit = helper 0 num
    where
        helper count num
            | num == 0 = count
            | num `mod` 10 == digit = helper (count+1) (num `div` 10)
            | otherwise  = helper count (num `div` 10)
    

getSumOfDigits:: Int -> Int 
getSumOfDigits num = helper 0 num
    where
        helper sum num
            | num == 0 = sum
            | otherwise = helper (sum + num `mod` 10) (num `div` 10)


sumCountsIter:: Int -> Int -> Int
sumCountsIter 0 0 = 1
sumCountsIter num digit =
    if isNumberSingleDigit digit
        then getSumOfDigits (getOccurancesInRange 0 1)
    else error "Input is not a digit"
    where
        getOccurancesInRange count currentNum
            | currentNum == (num + 1) = count
            | otherwise = getOccurancesInRange (count + getOccurancesInNumber currentNum digit) (currentNum + 1) 
