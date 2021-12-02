import System.IO
import Data.List (delete)
import Data.Char

main = do
  sort list

sort :: [a] -> [a]
sort [] = []
sort xs = do
  putStrLn x
  sort (delete x xs) ++ [x]
    where x = maximum xs
