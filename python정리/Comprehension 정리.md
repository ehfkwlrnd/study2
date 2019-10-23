# Comprehension 정리

```python
a = [1, 2, 3, 4, 5]

# 홀수만 뽑기
[e for e in a if e%2 == 1] # [1, 3, 5]

# 홀수 짝수 구분하기
['odd' if e%2 ==1 else 'even' for e in a] 
# ['odd', 'even', 'odd', 'even', 'odd']

# 0~99 숫자 리스트 만들기
[x for x in range(100)]
```

