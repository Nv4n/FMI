import Data.List ()
import qualified Data.List as Num
main::IO()
main = do
    print $ "da"

maxSumSubT :: (Ord a, Num a) => BTree a -> a
maxSumSubT NullT = 0
maxSumSubT t = helper t Num.minimum 0
    where
        helper::(Ord a, Num a) => BTree a -> a -> Int -> a
        helper (Node value left right) maxSum n = helper left $ getGreaterSum $ maxSum (head $ sort $ value:getValue(n+1)) (tail $ sort $ value:getValue(n+1))

        getGreaterSum::(Ord a, Num a) => a -> [a] -> a
        getGreaterSum oldSum els currSum = 

getLevel::(Ord a, Num a) => BTree a -> Int ->[a]
getLevel NullT _ = []
getLevel (Node value _ _) 0 = [value]
getLevel (Node value left right) n = getLevel left (n-1) ++ getLevel right (n-1)

data BTree a = NullT | Node a (BTree a) (BTree a)