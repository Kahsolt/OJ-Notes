#!/usr/bin/env ruby
# Broken Keyboard (20)

str1 = gets
str2 = gets
found = ''
i = j = 0

while i <= str1.length do
  if str1[i] != str2[j] then
    c = str1[i].upcase
    unless found.include? c
      found.concat c
      print c
    end
  else
    j += 1
  end
  i += 1
end