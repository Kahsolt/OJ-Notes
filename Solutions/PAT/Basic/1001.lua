#!/usr/bin/env lua
-- 害死人不偿命的(3n+1)猜想 (15)

n = io.read("*number")
cnt = 0
while n ~= 1 do
  n = (n & 1 == 0) and (n >> 1) or ((3 * n + 1) >> 1)
  cnt = cnt + 1
end
print(math.floor(cnt))