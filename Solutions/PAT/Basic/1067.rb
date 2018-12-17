#!/usr/bin/env ruby

pswd, n = gets.split
n = n.to_i
pswd = pswd.to_s
t = 0
while true do
  trial = gets.to_s.strip
  if not trial or trial == '#'
    break
  elsif t == n
    puts "Account locked"
    break
  end
  if trial == pswd
    puts "Welcome in"
    break
  else
    puts "Wrong password: #{trial}"
    t += 1
  end
end