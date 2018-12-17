#!/usr/bin/env lua5.3
-- General Palindromic Number (20)

n = io.read('*number')
b = io.read('*number')
if n>=0 and n<b then
  print('Yes')
  print(n)
  os.exit()
end

N = {}
while n > 0 do
  N[#N + 1] = n % b
  n = math.floor(n / b)
end
ans = true
for i=1, math.floor(#N / 2) do
  if N[i] ~= N[#N-i+1] then
    ans = false
    break
  end
end
print(ans and 'Yes' or 'No')
for i=#N, 1, -1 do
  io.write(N[i])
  if i ~= 1 then
    io.write(' ')
  end
end