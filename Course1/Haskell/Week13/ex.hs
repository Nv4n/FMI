import Data.List
main :: IO ()
main = do
    print "-----------------"
    print "     Task 01     "
    print "-----------------"
    print (getIndices [2, 7, 11, 15] 9)
    print (getIndices [3, 2, 4] 6)
    print (getIndices [3, 3] 6)
    print "-----------------"
    print "     Task 02     "
    print "-----------------"
    print (mapNested (*3) (List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]]))
    print (mapNested (take 2 . show) (List [Elem 15, List [Elem 200, List [Elem 351.52, Elem 463.12], Elem 5]]))
    print (mapNested (*3) (Elem 1))
    print "-----------------"
    print "     Task 03     "
    print "-----------------"
    print (isPrimeDictionary t1 vocabulary)
    print (isPrimeDictionary t2 vocabulary)
    print (isPrimeDictionary t3 vocabulary)
    print "-----------------"
    print "     Task 04     "
    print "-----------------"
    print (findJudge 2 [(1, 2)])
    print (findJudge 3 [(1, 3), (2, 3)])
    print (findJudge 3 [(1, 3), (2, 3), (3, 1)])
    print (findJudge 3 [(1, 2), (2, 3)])
    print (findJudge 4 [(1, 3), (1, 4), (2, 3), (2, 4), (4, 3)])

--Task01--

getIndices :: [Int] -> (Int -> (Int, Int))
getIndices (x:xs) t = helper x xs 0
    where
        helper h cpy index 
            | not (null [x | x <- cpy, h + x == t]) = (index, index + 1)
            | otherwise = helper (head xs) (tail cpy) (index + 1)

--Task02--

data NestedList a = Elem a | List [NestedList a] deriving Show 

mapNested :: (a -> b) -> NestedList a -> NestedList b
mapNested f (Elem a) = Elem (f a)
mapNested f (List l) = List (map (mapNested f) l)

--Task03--

type Vocabulary = [String]
data BTree = Nil | Node Char BTree BTree deriving (Show)
vocabulary :: Vocabulary
vocabulary = ["the", "a", "Some", "swimming", "liStS", "lisp"]

t1 :: BTree
t1 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) 
              (Node 'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) 
    (Node 'h' (Node 's' (Node 'i' Nil Nil) (Node 'S' Nil Nil)) 
              (Node 'a' (Node 't' Nil Nil) (Node 'S' Nil Nil)))
t2 :: BTree
t2 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) (Node 'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) 
              (Node 'h' (Node 's' (Node 'i' Nil Nil) (Node 's' Nil Nil)) (Node 'p' (Node 'p' Nil Nil) (Node 'S' Nil Nil)))

t3 :: BTree
t3 = Node 'a' (Node 't' (Node 'l' Nil Nil) (Node 'i' Nil Nil)) (Node 'h' (Node 's' Nil Nil) (Node 'p' Nil Nil))

isPrimeDictionary :: BTree -> Vocabulary -> Bool
isPrimeDictionary t vocabulary = helper 0 0
    where
        helper k sum
            | null (getlevel t k) = isPrime sum
            | getlevel t k `elem` vocabulary = helper (k + 1) (sum + k + length (getlevel t k))
            | otherwise = helper (k + 1) sum

getlevel :: BTree -> Int -> [Char]
getlevel Nil _ = []
getlevel (Node value _ _) 0 = [value]
getlevel (Node value lt rt) k = getlevel lt (k - 1) ++ getlevel rt (k - 1)

isPrime :: Int -> Bool 
isPrime x = length [y | y <- [1..x], mod x y == 0] == 2

--Task04--

findJudge :: Int -> [(Int, Int)] -> Int
findJudge _ [(x, y)] = y
findJudge p xs = if sum [1..p] - sum (nub [x | (x, y) <- xs, z <- [1..p], x == z]) == 0 then -1 else sum [1..p] - sum (nub [x | (x, y) <- xs, z <- [1..p], x == z])