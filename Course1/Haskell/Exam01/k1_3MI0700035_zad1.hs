import GHC.Float.RealFracMethods (ceilingDoubleInt, ceilingFloatInt)
main::IO()
main = do
    print $ primesProd 12 -- → 6
    print $ primesProd 1200 -- → 200560490130

isPrime:: Int -> Bool 
isPrime n = (helper 0 2 n) == 0
    where
        helper divCounts currDiv num
            | currDiv == (num `div` 2 + 1) = divCounts
            | num `mod` currDiv == 0 = helper (divCounts + 1) (currDiv + 1) num
            | otherwise = helper divCounts (currDiv + 1) num

primesProd :: Int -> Int
primesProd n = helper 2
    where
        helper currNum 
            | n < 0 = error "Invalid argument"
            | currNum >= sqrt n = 0
            | isPrime currNum && currNum < sqrt n = 1 + helper (currNum + 1)
            | otherwise  = helper (currNum + 1)