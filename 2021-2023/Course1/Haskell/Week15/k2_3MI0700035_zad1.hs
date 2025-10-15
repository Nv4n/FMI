import Data.List
main::IO()
main = do
    print $ filterTypical ["Mallard", "Hook Bill", "African", "Crested","Pilgrim", "Toulouse", "Blue Swedish"] -- ➝ ["Mallard", "Hook Bill","Crested", "Blue Swedish"]
    print $ filterTypical ["Mallard", "Barbary", "Hook Bill", "Blue Swedish","Crested"] -- ➝ ["Mallard", "Barbary", "Hook Bill", "Blue Swedish","Crested"]
    print $ filterTypical ["African", "Roman Tufted", "Toulouse", "Pilgrim","Steinbacher"] -- ➝ []

filterTypical :: [String] ->[String]
filterTypical [] = []
filterTypical xs =  filter (`notElem` typical) xs
    where
        typical :: [String]
        typical = ["African", "Roman Tufted", "Toulouse", "Pilgrim","Steinbacher"]