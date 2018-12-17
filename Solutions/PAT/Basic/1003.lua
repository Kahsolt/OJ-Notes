#!/usr/bin/env lua
-- 我要通过！(20)

n = io.read('*number')
for i = 1, n do
  str = io.read('*line')
  if str:match("[APT]*") == '' then
    print("NO")
  elseif str:match("[A]*P[A]+T[A]*") then
    left = str:match("([A]+)PAAT[A]+") or ''
    right = str:match("[A]+PAAT([A]+)") or ''
    print(#left <= #right and "YES" or "NO")
  else
    print("NO")
  end
end