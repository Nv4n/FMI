main :: IO ()
main = do
  print (sumCountsIter 1 10) -- ➝ 1
  -- print (sumCountsIter 5123 1) -- ➝ 19
  -- print (sumCountsIter 1234 8) -- ➝ 10
  -- print (sumCountsIter 5555 5) -- ➝ 10
  -- print (sumCountsIter 65432 6) -- ➝ 11
  -- print (sumCountsIter 70000 1) -- ➝ 11
  -- print (sumCountsIter 123321 1) -- ➝ 29

-- isNumberSingleDigit:: Int -> Bool
-- isNumberSingleDigit d
--     | d < 0 = false
--     | d > 9 = false
--     | otherwise = true

--     isNumberSingleDigit:: Int -> Bool
-- isNumberSingleDigit d =
--     if d >= 0 && d<= 9
--         then true
--         else false

isNumberSingleDigit :: Int -> Bool
isNumberSingleDigit d = d >= 0 && d <= 9

sumCountsIter :: Int -> Int -> Int
sumCountsIter x d =
  if isNumberSingleDigit d
    then helper 1 x d
    else error "d is not in range"
  where
    helper start end d = 1