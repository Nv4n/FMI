-- name x1 x2...xk
-- | g1 = e1
-- | g2 = e2
-- | otherwise = e

-- x1...xk - аргументи
-- name - име на функция
-- g1..gk - условия
-- е...еk - резултати

--Пример:

-- (x:xs) - образец
-- f (x:xs) -- [5,6]
-- | even x ="Y"
-- | otherwise = "N"

-- xs :: [Int]
-- xs = [1,2,3]
-- func::[Int]->[Int]
-- func xs = [x + 1 | x <- xs, odd x] -- => [3]

-- xs :: [Int]
-- xs = [1,2,3]
-- func::[Int]->[String]
-- func xs = [show x | x <- xs] -- => ["1","2","3"]

-- xs2 :: [[[Int]]]
-- xs1 = ["A",'B'] => Wrong different types
-- xs2 = [[],[[123],[]],[]] => True
-- xs3 = [(2341,"Hi"),(323,"Hi","Wow")] => Wrong one of the vectors has too many args
-- xs4 = [["2341","Hi"],["323","Hi","Wow"]] => True

-- не пиши лист... пиши списък

-- Primitive
-- + Only 1 list
-- + The base case is the empty list
-- + One recursive call to the end of the list

-- General
-- + More than 1 list
-- + The base case doesn't depend on the list(s)
-- + More than 1 recursive call

-- f :: [Int] -> [Int] -> Int
-- f (x:xs) (y:ys)
--     | even x = x + y + f xs ys
--     | otherwise = f xs (y:ys)
-- f _ _ = 0


-- Topic:7
-- Slides: 21-25
-- foldl (\ acc x -> acc-x) 0 [1,2,3] -- => -6
-- main::IO()
-- main= do
--     print (foldr (\ x acc -> x - acc) 0 [1,2,3])
--     print (foldr1 (\ x y -> x - y) [1,2,3])
--     -- 1 - (2 - 3)
--     print (foldl1 (\ x y -> x - y) [1,2,3])
--     -- ()

-- Operators
-- Topic:2
-- Slides: 2,3,10
-- main::IO()
-- main = do
--     print $ 4 : [6]
--     print $ [[6]] >: [5] >: 4 == [[6],[5,4]]
-- -- print $ [[6]] >: [5] >: 4 == [[6],[5,4]]

-- infixr 7 >:

-- (>:) :: [a] -> a -> [a]
-- xs >: x = xs ++ [x]

-- Topic: 5
-- Slides: 5, 6
-- f 0 n = n
-- f 0 _ = n
-- f (x:xs) = x --construct

-- import Data.Char (digitToInt)
-- main::IO()
-- main = do
--     print $ isInteresting 123
-- isInteresting :: Int -> Bool
-- isInteresting n = mod n (sum $ map digitToInt $ show n) == 0 

-- specialSum :: a -> a -> [a]
-- specialSum a b = [x | x <- [a..b], mod (x - 1) 4 == 0 && elem '6' show x]

-- main::IO()
-- main = do
--     print $ onlyArithmetic[[3],[1,2,3,4],[3,5,8,9,11]]
--     print $ takeWhile even [1, 2, 3] -- => []
--     print $ takeWhile even [2,4,5,6] -- => [2,4]

-- isArithmetic :: (Eq a, Enum a) => [a] -> Bool
-- isArithmetic xs =  length xs < 2 || xs == take (length xs) [xs!!0, xs!!1..]

-- onlyArithmetic :: (Eq a, Enum a) => [[a]] -> [[a]]
-- onlyArithmetic xs = [x | x <- xs, isArithmetic x]

-- onlyArithmetic' :: (Eq a, Enum a) => [[a]] -> [[a]]
-- -- onlyArithmetic' xss = filter (\xs -> isArithmetic xs) xss
-- onlyArithmetic' = filter isArithmetic

-- mySin :: Integer -> Double -> Double
-- mySin 0 x = x
-- mySin n x= ((-1)^n + x^(2*n+1)) / fromIntegral (product [1..2*n +1]) + mySin (n + 1) x

-- main::IO()
-- main = do
--     print $ dominates (\x -> x + 1) (\x -> x+2) [1,2,3,4,5] == False
--     print $ dominates (\x -> x + 3) (\x -> x+2) [1,2,3,4,5] == False 

-- dominates :: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool
-- dominates f g xs = all (\ x -> f x >= g x) xs

-- main::IO()
-- main = do
    -- print $ dominatesFold

-- dominatesFold:: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool
-- dominatesFold f g xs = foldl (\acc x -> f x >= g x) True


-- type Student = String
-- type Subject = String
-- type Note = Int

-- type Record = (Student, Subject, Note)

-- hardestSubject :: [Record] -> Subject
-- hardestSubject db = foldr (\ x y -> if getAvg x > getAvg y then y else x) $ nub [n | (_,n,subj)<- db]
--     where
--         getAvg subjName = sum grades / length grades
--             where
--                 grades = [gr | (_, n, gr) <- db, n == subjName]

-- main::IO()
-- main = do
    -- print $ reverseOrdStuff 37563 -- == 36
    -- print $ reverseOrdStuff 37563 -- == 367
    -- print $ reverseOrdStuff 32567 -- == 7
    -- print $ reverseOrdStuff 32666 -- == 7

-- reverseOrdStuff :: Int -> Int
-- reverseOrdStuff n = helper (div n 10) (mod n 10)
    -- where
        -- helper::Int -> Int -> Int 
        -- helper 0 result = result
        -- helper leftover result
            -- | mod leftover 10 < div (mod leftover 100) 10 = helper (div leftover 10) (result * 10 + mod leftover 10)
            -- | otherwise = result 

