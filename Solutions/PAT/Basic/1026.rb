#!/usr/bin/env ruby

a, b = gets.split
intv = ((b.to_i - a.to_f) / 100.0).ceil
print "%02d:%02d:%02d" % [intv / 60 / 60, intv / 60 % 60, intv % 60 % 60]