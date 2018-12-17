#!/usr/bin/env ruby

def go(x, d)
  q = x / d
  r = x % d
  if q != 0 then
    go q, d
  end
  print r
end

a, b, d = gets.split.map { |e| e.to_i }
go(a + b, d)