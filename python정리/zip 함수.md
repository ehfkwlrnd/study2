# zip 함수

```python
# zip(iter1 [, iter2 [...]])
a = [1, 2, 3]
b = ['a', 'b', 'c', 'd']
c = zip(a, b) # zip object
print(list(c)) # [(1, 'a'), (2, 'b'), (3, 'c')]

a = [1, 2, 3]
b = ('a', 'b', 'c')
c = {'d', 'e', 'f'}
list(zip(a, b)) # [(1, 'a'), (2, 'b'), (3, 'c')]
list(zip(a, c)) # [(1, 'd'), (2, 'e'), (3, 'f')]
list(zip(a, b, c)) # [(1, 'a', 'd'), (2, 'b', 'e'), (3, 'c', 'f')]
```

