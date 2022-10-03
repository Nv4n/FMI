import Data.List
main::IO()
main = do
    print $ getCombo

getCombo::Int
getCombo = length $ nub $ zipWith(+) [0..9] [0..9]