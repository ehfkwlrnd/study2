# itertools를 이용한 순열 조합 

```python
from itertools import permutations as P
from itertools import combinations as C

A = [1, 2, 3]
p = P(A)
for a in p:
    print(list(a))

c = C(A, 2)
for a in c:
    print(list(a))

```

