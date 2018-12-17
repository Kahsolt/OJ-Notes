#!/usr/bin/env lua5.3
-- The Dominant Color (20)

d = {}    -- plain algorithm, count presences (TLE)
m = io.read('*number')
n = io.read('*number')
for i = 1, n do
  for j = 1, m do
    c = io.read('*number')
    d[c] = (d[c] ~= nil) and  (d[c] + 1) or 1
  end
end

cnt = 0
ans = nil
for k, v in pairs(d) do
  if v > cnt then
    cnt = v
    ans = k
  end
end
print(ans)