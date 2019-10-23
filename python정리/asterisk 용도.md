# asterisk 용도

* 연산자

  ```python
  2*3 # 6 (곱하기)
  
  2**3 # 8 (제곱)
  ```

* 가변인자

  ```python
  # * 일 때 tuple로 받는다
  def print_param(*arg):
      print(args)
      
  print_param(1, 2, 3) # (1, 2, 3)
  
  # ** 일 때 dict로 받는다
  def print_param2(**args):
      print(args)
      
  print_param2(a=1, b=2, c=3) # {'a': 1, 'b': 2, 'c': 3}
  
  # 혼합
  def print_param3(zero, *one, **two):
      print(zero, one, two)
  
  print_param3(1, 2, a=1, b=2) # 1 (2,) {'a': 1, 'b': 2}
  ```

* Unpacking

  ```python
  q = [1, 2, 3, 4]
  
  *a, = q # a = [1, 2, 3, 4]
  *a, b = q # a = [1, 2, 3], b = 4
  a, *b = q # a = 1, b = [2, 3, 4]
  a, *b, c = q # a = 1, b = [2, 3], c = 4
  
  # 함수에 이용
  def print_params(a, b, c, d):
      print(a, b, c, d)
  
  print_params(*q) # 1 2 3 4
  ```

  