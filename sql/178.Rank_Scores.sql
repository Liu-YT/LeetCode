select Score, (select count(distinct score) from scores s1 where s1.score >= s2.score) as rank
from scores s2
order by Rank;