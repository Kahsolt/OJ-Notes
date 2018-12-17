#!/usr/bin/env lua5.3

function isPrime(x)
  if x == 1 then return false
  elseif x == 2 then return true end
  for i=2, math.floor(math.sqrt(x)+1) do
    if x % i == 0 then
      return false
    end
  end 
  return true
end

function revRadix(x, r)
  ans = 0
  while x > 0 do
    ans = ans * r + x % r
    x = math.floor(x / r)
  end
  return ans
end

while true do
  n = io.read('*number')
  if n < 0 then break end
  r = io.read('*number')
  print((isPrime(n) and isPrime(revRadix(n, r)))
    and 'Yes' or 'No')
end