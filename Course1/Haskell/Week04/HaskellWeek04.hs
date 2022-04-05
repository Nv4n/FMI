main::IO()
main = do
    -- print(getListLength [1,2,3,4,5])
    -- print(getSumOfList [1,2,3])
    -- print(getSumOfList [1.5,2.3,3.4])
    -- print(isElementInList 5 [1,2,3])
    -- print(isElementInList 5 [1,5,3])
    print(getListInRange 1 10)
    print(removeSingleElement 1 [2,3,1,5,1,7])
    print(removeAllElements 1 [2,3,1,5,1,7])
    print(incrementAllBy [1,5,7,2.5] 3.1)

-- Задача 1. Да се дефинира функция, която намира броя на елементите на списък.
getListLength::[a]->Int
getListLength = length

-- Задача 2. Да се дефинира функция, която намира сумата на елементите в списък.
getSumOfList::Num a =>[a]-> a
getSumOfList = sum

-- Задача 3. Да се дефинира функция, която намира дали даден елемент се съдържа в списък.
isElementInList::Eq a => a->[a]->Bool
isElementInList _ [] = False 
isElementInList el (x:xs)= x == el || isElementInList el xs

-- Задача 4. Да се дефинира функция, която генерира списък с простите числа в интервала [a,b].
getListInRange:: Int -> Int -> [Int]
getListInRange start end = [start .. end]

-- Задача 5. Да се дефинира функция, която премахва първия елемент, равен на x, от даден списък.
removeSingleElement:: Eq t => t -> [t] -> [t]
removeSingleElement _ [] = []
removeSingleElement el (x:xs)
    | el == x = xs
    | otherwise = x : removeSingleElement el xs

-- Задача 6. Да се дефинира функция, която премахва всички елементи на даден списък, които са равни на x.
removeAllElements:: Eq t => t -> [t] -> [t]
removeAllElements _ [] = []
removeAllElements el xs = [x | x <- xs, x/=el]

-- Задача 7. Да се дефинира функция incrementAllBy :: [Int] -> Int -> [Int], която получава списък и число и го добавя към всеки елемент на списъка.
incrementAllBy::Num t => [t] -> t -> [t]
incrementAllBy [] _ = []
incrementAllBy xs num = [x + num | x <- xs]