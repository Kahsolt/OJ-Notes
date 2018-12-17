#!/usr/bin/env lua5.3

digit = {
  '0','1','2','3','4','5','6',
  '7','8','9','A','B','C'
}
function cvt(x) -- dec to 13th
  high = math.floor(x / 13)
  low = x % 13
  return digit[high+1]..digit[low+1]
end

io.write('#'..cvt(io.read('*number'))..
  cvt(io.read('*number'))..cvt(io.read('*number')))