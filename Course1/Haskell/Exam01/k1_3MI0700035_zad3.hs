{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

import Data.List (permutations)
import Distribution.Simple.Utils (xargs)
main::IO()
main = do
    print $ maxChain [(3,4), (5,6), (7,8)] -- → 3
    print $ maxChain [(9,14), (3,5), (4,7)] -- → 2

isChain:: (Int,Int) -> (Int,Int) -> Bool
isChain (a,b) (c,d) = b < c

maxChain :: [(Int, Int)] -> Int
maxChain xs = helper (permutations xs) 0 (-1)
    where
        helper:: [[(Int,Int)]] -> Int -> Int -> Int
        helper [[]] _ maxCC = maxCC
        helper (b:bs) currCC maxCC
            | currCC > maxCC = helper (b:bs) 0 currCC
            | otherwise = helper bs (secHelper b 0) maxCC
                where
                    secHelper (c1:c2:cs) currCount
                        | isChain c1 c2 = secHelper (c2:cs) (currCount + 1)
                        | otherwise = secHelper (c2:cs) currCount
                    secHelper _ currCount = currCount