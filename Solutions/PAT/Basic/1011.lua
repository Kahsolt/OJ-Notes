#!/usr/bin/env lua
-- A+B和C (15)

for i=1, io.read('*number') do
  a = io.read('*number')
  b = io.read('*number')
  c = io.read('*number')
  print(string.format('Case #%d: %s',
        i, a + b > c and true or false))
end