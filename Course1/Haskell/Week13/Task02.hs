{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
import Data.List
import Distribution.Simple.Command (OptDescr(BoolOpt))
main::IO()
main = do
    print $ toBST t1 -- ➝ t1Result
    print $ toBST t2 -- ➝ t2Result
    print $ toBST t3 -- ➝ t3Result


toBST :: (Ord a) => BTree a -> BTree a
toBST Empty = Empty
toBST (Node value left right) = getNewTree (Node value left right)
    where
        getNewTree::(Ord a) => BTree a -> Btree a
        getNewTree _ = Empty
        -- getNewTree (Node value left right)

        logic::Bool
        logic = getLogic (Node value left right) 0 >= 1

        -- getChangeValues::(Int, Int, Int, Int)
        -- getChangeValues

        getLogic::(Ord a) => BTree a -> Int -> Int
        getLogic Empty n = n
        getLogic (Node value left right) n = getLogic left (getValue left value) + n + getLogic right (getValue right value)

        getValue::(Ord a) =>  BTree a -> a -> Int
        getValue Empty _  = 0
        getValue (Node value left right) n
            | n > value = 1
            | otherwise = -1

t1:: BTree Int
t1 = Node 2 (Node 5 Empty Empty) (Node 7 (Node 1 Empty Empty) (Node 8 Empty Empty))

t2:: BTree Int
t2 = Node 0 (Node 1 Empty Empty) Empty

t3::BTree Int
t3 = Node 5 (Node 2 (Node 1 Empty Empty) (Node 8 Empty Empty)) (Node 3 (Node 7 Empty Empty) (Node 10 Empty Empty))

data BTree a = Empty | Node a (BTree a) (BTree a)