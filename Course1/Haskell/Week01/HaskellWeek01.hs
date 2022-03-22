main::IO()
main = do
    print (myMin 1 2)
    print (isInside 10 1 20)
    print (calcAverage 5 2)
    print (fibRec 5)

myMin :: Int -> Int -> Int
isInside :: Int -> Int -> Int -> Bool
calcAverage :: Double -> Double -> Double
fibRec :: Int -> Integer

myMin a b = if a < b then a else b

isInside x a b
    | x < a = False
    | x > b = False
    | otherwise = True

calcAverage a b = (a^2 + b^2) / 2

fibRec a 
    | a > 1 = fibRec(a-2) + fibRec (a - 1)
    | otherwise = 1

fibIter :: Int -> Integer
fibIter n = helper 0 1 0 n

helper :: Integer -> Integer -> Int -> Int -> Integer
helper prev cur i n =
    if i == n then cur else helper cur (prev + cur) (i + 1) n

-- fibIter 3 -> helper 0 1 0 3 -> helper 1 1 1 3 -> helper 1 2 2 3
--  -> helper 2 3 3 3 -> 3