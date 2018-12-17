#!/usr/bin/env ruby

n = gets.to_i
hund = n / 100
cent = n / 10 % 10
ones = n % 10
hund.times { print 'B' }
cent.times { print 'S' }
1.upto(ones) { |e| print e }