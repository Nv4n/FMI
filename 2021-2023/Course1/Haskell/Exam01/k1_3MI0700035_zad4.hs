main::IO()
main = do
    print $ findSmallest [2, 5, 3, 7, 8, 1, 9] -- → [-1, 2, 2, 3, 7, -1, 1]
    print $ findSmallest [5, 7, 4, 9, 8, 10] -- → [-1, 5, -1, 4, 4, 8]
    print $ findSmallest [1, 5, 2, 2, 2, 5, 5, 4] -- → [-1, 1, 1, 1, 1, 2, 2, 2]

help::[Int] -> Int -> Int
help [] _ = -1
help (x:xs) n
    | n > x = x
    | otherwise = help xs n

findSmallest :: (Num a, Ord a) => [a] -> [a]
findSmallest (x:xs) = -1 : helper x xs
    where
        helper::[Int]->[Int]->[Int]
        helper cs (b:bs) = (help cs b) : helper (cs:b) bs
        helper _ c = c