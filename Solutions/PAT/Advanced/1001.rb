#!/usr/bin/env ruby
# A+B Format (20)

def prt(x)
  low = x % 1000
  high = x / 1000
  if high == 0 then
    print low
  else
    prt high
    printf ',%03d', low
  end
end
s = gets.split.map {|e| e.to_i}.reduce :+
print '-' if s < 0
prt s.abs