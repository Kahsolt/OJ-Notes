#!/usr/bin/env lua5.3
-- Elevator (20)

time = 0
cur = 0
n = io.read("*number")
while true do
  n = io.read("*number")
  if not n then break end
  if cur > n then
    time = time + 4 * (cur - n) + 5
    cur = n
  elseif cur < n then
    time = time + 6 * (n - cur) + 5
    cur = n
  else
    time = time + 5
  end
end
print(time)