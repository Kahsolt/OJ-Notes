#!/usr/bin/env ruby

s = gets.downcase
sum = 0
s.each_char do |c|
  if c >= 'a' && c <= 'z' then
    sum += (c.ord - 'a'.ord) + 1
  end
end
ones = zeros = 0
while sum != 0 do
  (sum & 1 == 0) and (zeros += 1) or (ones += 1)
  sum >>= 1
end
puts "#{zeros} #{ones}"