import Data.List
main::IO()
main = do
    print $ toBST t1 -- ➝ t1Result
    print $ toBST t2 -- ➝ t2Result
    print $ toBST t3 -- ➝ t3Result


toBST :: (Ord a) => BTree a -> BTree a


t1:: Btree Int
t1 = Node 2 (Node 5) (Node 7 (Node 1) (Node 8))

t2:: BTree Int
t2 = Node 0 (Node 1)

t3::Btree Int
t3 = Node 5 (Node 2 (Node 1) (Node 8)) (Node 3 (Node 7) (Node 10))

data BTree a = Empty | Node a (BTree a) (BTree a) 