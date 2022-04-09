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
main:: IO()
main = do
    print(func xs)

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

