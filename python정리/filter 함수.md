# filter 함수

```python
# filter(function, iterable)
# function의 return 값은 bool
a = [1, 2, 3, 4, 5]
b = filter(lambda x : x%2 == 1, a) # 홀수만
print(list(b)) # [1, 3, 5]
```

