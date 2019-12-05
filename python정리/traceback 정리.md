# traceback 정리

* 함수 정의
	```python
	def a(i):
      b(i)
	def b(i):
      a = 1/i
	```

* 에러가 나는 소스

  ```python   
  a(0)
  ```
  
	* 에러 내용
	```python
	Traceback (most recent call last):
	  File "D:\Users\yuno\Desktop\tracebackTest.py", line 9, in <module>
		a(0)
	  File "D:\Users\yuno\Desktop\tracebackTest.py", line 5, in a
		b(i)
	  File "D:\Users\yuno\Desktop\tracebackTest.py", line 7, in b
		a = 1/i
	ZeroDivisionError: division by zero
	```
  
* try-except

  ```python
  try:
  	a(0)
  except Exception as e:
      print(e)
  ```

  * Exception 프린트
  ```python
  division by zero
  ```

* traceback

	```python
	#traceback.print_exc(file=sys.stdout) 사용
  
  import sys
  import traceback
  
  try:
  	a(0)
  except:
      traceback.print_exc(file=sys.stdout)
  ```
  * Traceback 프린트
  ```python
  Traceback (most recent call last):
    File "D:\Users\yuno\Desktop\tracebackTest.py", line 10, in <module>
      a(0)
    File "D:\Users\yuno\Desktop\tracebackTest.py", line 5, in a
      b(i)
    File "D:\Users\yuno\Desktop\tracebackTest.py", line 7, in b
      a = 1/i
  ZeroDivisionError: division by zero
  ```
* traceback 변수에 저장
	```python
	# traceback.format_exc() 사용
	
	msg = ''
	try:
	    a(0)
	except Exception as e:
	    msg += traceback.format_exc()
	```

