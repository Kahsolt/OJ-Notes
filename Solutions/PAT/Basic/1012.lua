#!/usr/bin/env lua

n = io.read("*number")
num = {}
for i = 1, n do
  num[#num+1] = io.read("*number")
end

function A1(num)
  sum=0
  isExist=false
  for i,v in ipairs(num) do
    if v%10==0 then
      sum=sum+v
      isExist=true
    end
  end
  return isExist and sum or nil
end
function A2(num)
  sign=0
  sum=0
  isExist=false
  for i,v in ipairs(num) do
    if v%5==1 then
      sum=sum+v*(-1)^sign
      sign=sign+1
      isExist=true
    end
  end
  return isExist and sum or nil
end
function A3(num)
  cnt=0
  isExist=false
  for i,v in ipairs(num) do
    if v%5==2 then
      cnt=cnt+1
      isExist=true
    end
  end
  return isExist and cnt or nil
end
function A4(num)
  sum=0
  cnt=0
  isExist=false
  for i,v in ipairs(num) do
    if v%5==3 then
      sum=sum+v
      cnt=cnt+1
      isExist=true
      end
  end
  return isExist and sum/cnt or nil
end
function A5(num)
  max=-1
  isExist=false
  for i,v in ipairs(num) do
    if v%5==4 and v>max then
      max=v
      isExist=true
    end
  end
  return isExist and max or nil
end

a = {
  A1(num), A2(num), A3(num),
  A4(num), A5(num),
}
for i = 1, 5 do
  if not a[i] then
    a[i] = 'N'
  elseif i == 4 then
    a[i] = string.format("%.1f", a[i])
  else
    a[i] = string.format("%d", a[i])
  end
end
print(string.format("%s %s %s %s %s",
      a[1], a[2], a[3], a[4], a[5]))