# datetime 모듈

* datetime 클래스

  ```python
  from datetime import datetime
  
  # datetime(year, month, day, hour=0, minute=0, second=0, microsecond=0)
  d = datetime(2019, 11, 7)
  ```

	* today() 메소드

	  ```python
	  from datetime import datetime
	  
	  datetime.today() # datetime 객체
	  ```

	* strptime() 메소드

	  ```python
	  from datetime import datetime
	  
	  #문자열을 객체로
	  datetime.strptime('2019-11-07', '%Y-%m-%d') # datetime 객체
	  ```

	* strftime() 메소드

	  ```python
	  from datetime import datetime
	  
	  #객체를 문자열로
	  d.strftime('%Y-%m-%d') # 2019-11-07 
	  ```

	* 연산

	  ```python
	  from datetime import datetime
	  
	  d = datetime.strptime('2019-11-07', '%Y-%m-%d')
	  p = datetime.strptime('2019-11-04', '%Y-%m-%d')
	  
	  d - p # datetime.timedelta(3)
	  ```

* timedelta 클래스

  ```python
  from datetime import timedelta
  
  # timedelta(days=0, seconds=0, microseconds=0, milliseconds=0, minutes=0, hours=0, weeks=0)
  t = timedelta(days=20)
  ```

	* 연산

	  ```python
	  (d-p).days # 3
	  (d-t) # datetime.datetime(2019, 10, 18, 0, 0)
	  ```

  