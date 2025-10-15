import Data.List ()
main::IO()
main = do
    print $ cP [Present, Late, Present, Absent, Present, Present, Present, Absent] -- ➝ False
    print $ cP [Present, Late, Present, Late, Present, Late, Present, Absent,Late, Present] -- ➝ True
    print $ cP [Present, Late, Present, Late, Late, Late, Present, Present,Absent, Present] -- ➝ False

canPass :: Criterion -> (StudentRecord -> Bool)
canPass (m,l) = tryPass
    where
        tryPass:: StudentRecord -> Bool
        tryPass [] = False
        tryPass rs
            | wontPass $ checkAttendance rs 0 0 (-1) = False
            | otherwise = True

        checkAttendance::[Attendance] -> Lates -> Misses -> Lates -> (Lates,Misses)
        checkAttendance [] _ misses maxLates = (maxLates, misses)
        checkAttendance (a:as) lates misses maxLates
            | a == Absent = checkAttendance as lates (misses +1) maxLates
            | a == Late = checkAttendance as (lates+1) misses maxLates
            | a == Present && lates > maxLates = checkAttendance as 0 misses lates
            | otherwise = checkAttendance as 0 misses maxLates

        wontPass::(Lates,Misses) -> Bool
        wontPass (ls,ms)
            | ls > l = True
            | ms > m = True
            | otherwise = False



cP = canPass (1,2)

type Misses = Int
type Lates = Int
type Criterion = (Misses, Lates)
data Attendance = Absent | Late | Present
    deriving (Eq)
type StudentRecord = [Attendance]
