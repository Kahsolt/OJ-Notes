#!/usr/bin/env lua
-- 写出这个数 (20)

words = {
  'yi', 'er', 'san', 'si', 'wu',
  'liu', 'qi', 'ba', 'jiu'
}
words[0] = 'ling'
sum = 0
number = io.read('*line')
for i=1, #number do
  sum = sum + tonumber(number:sub(i, i))
end
sum = tostring(sum)
for i = 1, #sum do
  if i ~= 1 then io.write(' ') end
  io.write(words[tonumber(sum:sub(i, i))])
end