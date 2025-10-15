main :: IO ()
main = do
    print (maxRotation 56789 ) -- ➝ 68957
    print (maxRotation 12490 ) -- ➝ 29140

--    Задача 2
lengthNum:: Int -> Int
lengthNum 0 = 1
lengthNum num = helper 0 num
    where
        helper count curr
            | curr == 0 = count
            | otherwise = helper (count + 1) (curr `div` 10)

maxRotation:: Int -> Int
maxRotation num = getMaxNumRotation 0 (lengthNum num - 1) num num
    where
        rotate currSteps maxSteps curr  =
            (firstPart * 10 ^ lengthNum secondPart + secondPart) * 10 + lastPart
            where
                mainDiv = 10 ^ (maxSteps - currSteps + 1)
                restDiv= mainDiv `div` 10
                firstPart = curr `div` mainDiv
                restPart = curr `mod` mainDiv
                secondPart = restPart `mod` restDiv
                lastPart = restPart `div` restDiv

        getMaxNumRotation steps maxSteps maxNum currNum
            | steps == maxSteps = maxNum
            | rotate steps maxSteps currNum > maxNum
                = getMaxNumRotation (steps + 1) maxSteps (rotate steps maxSteps currNum) (rotate steps maxSteps currNum)
            | otherwise = getMaxNumRotation (steps + 1) maxSteps maxNum (rotate steps maxSteps currNum)