main::IO()
main = do
    print(getListLength [1,2,3,4,5])
    print(getSumOfList [1,2,3])
    print(getSumOfList [1.5,2.3,3.4])

-- Задача 1. Да се дефинира функция, която намира броя на елементите на списък.
getListLength::[a]->Int
getListLength = length

-- Задача 2. Да се дефинира функция, която намира сумата на елементите в списък.
getSumOfList::Num a =>[a]-> a
getSumOfList = sum

-- Задача 3. Да се дефинира функция, която намира дали даден елемент се съдържа в списък.
isElementInList::a->[a]->Bool 
isElementInList el list=True