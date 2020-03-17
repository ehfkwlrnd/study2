# compare 기준 만들어 sort하기

```python
from functools import cmp_to_key

def cmp(a, b):
    return len(a) - len(b)

a = ['abc', 'b']
print(sorted(a, key=cmp_to_key(cmp)))
```

