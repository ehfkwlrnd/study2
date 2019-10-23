# dict 정리

* 형태

  ```python
  a = {'a' : 1, 'b' : 2, 'c' : 3}
  ```

* get

  ```python
  a['a'] # 1
  a.get('a') # 1
  
  a.['d'] # KeyError
  a.get('d') # None
  ```

* keys, values, items

  ```python
  a.keys() # dict_keys(['a', 'b', 'c'])
  a.values() # dict_values([1, 2, 3])
  a.items() # dict_items([('a', 1), ('b', 2), ('c', 3)])
  ```

* update

  ```python
  a.update({'a' : 4, 'c' : 5})
  print(a) # {'a': 4, 'b': 2, 'c': 3, 'd': 5}
  ```

* 순회

  ```python
  for e in a:
      print(e, ' : ', a[e]) # e 는 a의 key값
      
  '''
  a : 1
  b : 2
  c : 3
  '''
  ```

  

