select distinct a.Num as ConsecutiveNums
FROM Logs a, Logs b, Logs c
WHERE b.Id=a.Id+1 and c.Id=b.Id+1 and a.Num=b.Num and b.Num=c.Num