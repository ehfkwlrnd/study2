# lambda 정리

* lambda 만들기

  ```python
  func = lambda x : x+1
  print(func(1)) # 2
  ```

* lambda 자체 호출

  ```python
  print((lambda x : x+1)(1)) # 2
  ```

* 변수 생성 불가능

  ```python
  lambda x : y=10; x +y
  # SyntaxError
  ```

  

