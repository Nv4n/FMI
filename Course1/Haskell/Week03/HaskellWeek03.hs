main :: IO ()
main = do
	-- print (pow 5.5 3)
	-- print (isPrime 100)
	-- print (isPrime 997)
	-- print (isAscending 1234)
	-- print (isAscending 1204)
	-- print (countOccurences 153161 1)
	-- print (countOccurences 0 0)
	print (isPerfectNumber 100)
	print (isPerfectNumber 496)
	print (sumPrimeDivisors 100)
	print (sumPrimeDivisors 83)


-- Задача 1. Да се дефинира функция pow, която генерира линейно рекурсивен процес и намира x на степен n, където x е реално, а n - естествено число.

pow :: Double -> Int -> Double
pow number power
	| power == 0 = 1
	| otherwise = number * pow number (power - 1)

--     Задача 2. Да се дефинира предикат isPrime, който проверява дали дадено естествено число е просто.
-- (Заб.: Числото 1 не е нито просто, нито съставно.)

isPrime :: Int -> Bool
isPrime 1 = False
isPrime num = helper 2
	where
    helper currDiv
    	| currDiv == num = True 
    	| mod num currDiv == 0 = False
    	| otherwise = helper (currDiv + 1)

-- Задача 3. Да се дефинира предикат isAscending, който връща истина, ако цифрите на дадено естествено число са в нарастващ ред от първата към последната.

isAscending :: Int -> Bool
isAscending 0 = True
isAscending num =
	num `mod` 10 > (num `div` 10) `mod` 10 && isAscending (num `div` 10)

isNumberSingleDigit :: Int -> Bool
isNumberSingleDigit d = d >= 0 && d <= 9

-- . Да се дефинира функция countOccurences, намираща броя на срещанията на дадена цифра d в записа на число n.
countOccurences :: Int -> Int -> Int
countOccurences 0 0 = 1 
countOccurences num numToFind = 
	if isNumberSingleDigit numToFind == False
		then error "Number is not in range"
	else helper 0 num
		where 
			helper count num
				| num == 0                   = count
				| num `mod` 10 == numToFind  = helper (count + 1) (num `div` 10)
				| otherwise                  = helper count (num `div` 10)

-- Да се дефинира предикат isPerfectNumber, който връща дали едно число е съвършено, т.е. равно на сумата от делителите му.
isPerfectNumber:: Int -> Bool
isPerfectNumber num = num == helper 0 1
	where
	    helper divSum divider
			| divider == num = divSum
	    	| num `mod` divider == 0 = helper (divSum + divider) (divider + 1)
	    	| otherwise = helper divSum (divider + 1)

-- Задача 6. Да се дефинира функция sumPrimeDivisors, която намира сумата на всички прости делители на едно число.

sumPrimeDivisors::Int -> Int 
sumPrimeDivisors num = helper 0 2
	where 
		helper sum divider
			| divider == num + 1= sum
			| num `mod` divider == 0 && isPrime divider = helper (sum + divider) (divider+1)
			| otherwise = helper sum (divider+1)