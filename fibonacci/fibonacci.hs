-- Normal fibs infinite
fibs = 1 : scanl (+) 1 fibs

-- Get particular fibonacci number
fibsN n = fibs !! n

-- To get the nth fibonacci number, run Haskell's IDE GHCI 
-- (docs.haskellstack.org/en/stable/README)
-- Then load module using `:l fibonacci.hs`
-- To get nth fibonacci number, type `fibsN n`