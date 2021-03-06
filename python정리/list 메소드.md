# list 메소드

* copy

  ```python
  a = [1, 2, 3]
  
  # 단순 복사
  b = a
  a.append(4)
  print(b) # [1, 2, 3, 4]
  
  # 얕은 복사
  a = [1, 2, 3]
  b = a.copy()
  a.append(4)
  print(b) # [1, 2, 3]
  
  a = [[1, 2, 3]]
  b = a.copy()
  a[0].append(4)
  print(b) # [[1, 2, 3, 4]]
  
  # 깊은 복사
  import copy
  a = [[1, 2, 3]]
  b = copy.deepcopy(a)
  a[0].append(4)
  print(b) # [[1, 2, 3]]
  ```

* count

  ```python
  a = [1, 0, 1, 1, 0, 1]
  one = a.count(1)# 1의 개수
  print(one) # 4
  ```

* index

  ```python
  # index(value, [start, [stop]])
  a = [1, 1, 1, 0, 1, 0]
  first_zero = a.index(0) # 처음 0의 인덱스
  print(first_zero) # 3
  
  three = a.index(3) # 못 찾으면 에러 발생
  ```

* remove

  ```python
  a = [1, 1, 1, 0, 1, 0]
  a.remove(0) # 처음 0 삭제
  print(a) # [1, 1, 1, 1, 0]
  ```

* pop

  ```python
  # pop([index])
  a = [1, 2, 3, 4]
  a.pop() # 4
  a.pop(0) # 1
  ```

* append, extend

  ```python
  # append(value)
  a = [1, 2, 3]
  a.append([4, 5]) # [1, 2, 3, [4, 5]]
  
  # extend(iterable)
  a = [1, 2, 3]
  a.extend([4, 5]) # [1, 2, 3, 4 5]
  ```

* reverse

  ```python
  a = [1, 2, 3]
  a.reverse()
  print(a) # [3, 2, 1]
  
  a = [1, 2, 3]
  b = reversed(a) # list_reverseiterator object
  print(list(b)) # [3, 2, 1]
  ```

* sort

  ```python
  # sort(key=None, reverse=False)
  a = [2, 1, 3]
  a.sort() 
  print(a) # [1, 2, 3]
  
  a.sort(reverse=True)
  print(a) # [3, 2, 1]
  
  a = [['a', 2], ['b', 1], ['c', 3]]
  a.sort(key=lambda x : x[1])
  print(a) # [['b', 1], ['a', 2], ['c', 3]]
  
  # sorted(iterable, key=None, reverse=False)
  a = [2, 1, 3]
  b = sorted(a) # [1, 2, 3]
  ```

* insert

  ```python
  # insert(index, object)
  a = [1, 2, 3]
  a.insert(1, 4)
  print(a) # [1, 4, 2, 3]
  ```

  

