import Data.List (delete)

sort :: [a] -> [a]
sort [] = []
sort xs = sort (delete x xs) ++ [x]
          where x = maximum xs
