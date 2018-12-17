#!/usr/bin/env ruby

A, P = gets.split ' '
x2, y2, z2 = A.split('.').map {|e| e.to_i}
x1, y1, z1 = P.split('.').map {|e| e.to_i}

if x1>x2 or (x1==x2 and y1>y2) or (x1==x2 and y1==y2 and z1>=z2) then
  z1 = z1 - z2
  if z1 < 0 then y1-=1; z1+=29 end
  y1 = y1 - y2
  if y1 < 0 then x1-=1; y1+=17 end
  x1 = x1 - x2

  puts "#{x1}.#{y1}.#{z1}"
else
  x2, y2, z2 = P.split('.').map {|e| e.to_i}
  x1, y1, z1 = A.split('.').map {|e| e.to_i}

  z1 = z1 - z2
  if z1 < 0 then y1-=1; z1+=29 end
  y1 = y1 - y2
  if y1 < 0 then x1-=1; y1+=17 end
  x1 = x1 - x2

  puts "-#{x1}.#{y1}.#{z1}"
end