import Data.List ()
main::IO()
main =
    print $ "test"

isBoring :: (Eq a) => NTree a -> Bool
isBoring NullT = True
isBoring t = helper t 0
    where
        helper::(Eq a) => NTree a -> Int -> Bool
        helper NullT _ = True
        helper (Node value branches) ind
            | ind < 2 = (map (\ br -> helper br (ind - 1)) branches) `elem` [False]
            | length branches < 2 = not (map (\br -> helper br (ind - 1)) branches) `elem` [False]
            | otherwise = False


t1::NTree Int
t1 = Node 10 [Node 10 [Node 10 [], Node 8 [Node 10 []], Node 2 []], Node 10 [Node 11[],Node 10[], Node 6[]]]

t2::NTree Char
t2 = Node 's'[Node 's'[], Node 's'[], Node 's'[]]

data NTree a = NullT | Node a [NTree a]