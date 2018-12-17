#!/usr/bin/env ruby

N = gets.to_i

if N <= 4
  puts 0
elsif N <= 6
  puts 1
else
  p = [0, 0]
  for i in 2..N do
    k=2
    while i*k<=N do
      p[i*k]=0
      k+=1
    end
  end

  cnt = 0
  i = 3
  while i<=N-2 do
    if p[i]==nil && p[i+2]==nil
      cnt+=1
      i+=2
    else
      i+=1
    end
  end
  puts cnt
end

