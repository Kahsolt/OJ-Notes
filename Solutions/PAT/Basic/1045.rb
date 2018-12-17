#!/usr/bin/env ruby

gets
nums = gets.split.map {|e| e.to_i}
maxs = Array.new(nums.count)
mins = Array.new(nums.count)

maxs[0] = nums[0]
for i in 1...nums.length do
  maxs[i] = nums[i] < maxs[i-1] && maxs[i-1] || nums[i]
end
mins[nums.length-1] = nums[nums.length-1]
for i in (nums.length-2)...0 do
  mins[i] = nums[i] > mins[i+1] && mins[i+1] || nums[i]
end

ans = []
for i in 0...nums.length do
  ans.push(nums[i]) if nums[i] >= maxs[i] and nums[i] <= mins[i]
end
puts ans.length
puts ans.join ' '