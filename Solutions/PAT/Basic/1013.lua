#!/usr/bin/lua5.3

m = io.read("*number")
n = io.read("*number")

function isPrime(x)
  if x <= 1 then return false end
  if ('23579'):find(tostring(x)) then return true end
  for i = 2, math.ceil(math.sqrt(math.sqrt(x)+x)) do
    if x % i == 0 then
      return false
    end
  end
  return true
end

cnt = 0
x = 2

while cnt < n do
  if isPrime(x) then
    cnt = cnt + 1
    if cnt >= m then
      io.write(x)
      if (cnt - m + 1) % 10 == 0 then
        io.write('\n')
      elseif cnt < n then
        io.write(' ')
      end
    end
  end
  if x >= 10 then
    if ('179'):find(tostring(x)) then
      x = x + 2
    elseif x % 10 == 3 then
      x = x + 4
    else
      x = x + 1
    end
  else 
    x = x + 1
  end
end