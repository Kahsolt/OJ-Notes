#!/usr/bin/env ruby

str1 = gets
str2 = gets
len1 = str1.length
len2 = str2.length
found = ''
i = j = 0

while i <= len1 do
  if str1[i] != str2[j] then
    c = str1[i].upcase
    if !found.include? c then
      found.concat c
      print c
    end
    i += 1
  else
    i += 1
    j += 1
  end
end