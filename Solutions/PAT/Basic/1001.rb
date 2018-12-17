#!/usr/bin/env ruby
# 害死人不偿命的(3n+1)猜想 (15)

x = gets.to_i
cnt = 0
while x != 1 do
  x = (x & 1 == 1 and (3 * x + 1) >> 1 or x >> 1)
  cnt += 1
end
puts cnt