# time 모듈

* time()

  ```python
  from time import time
  time() #1573110913.07429
  # 1970-01-01 00:00:00 이후 경과한 시간을 초단위로 반환
  ```

* sleep()

  ```python
  from time import sleep
  sleep(2) # 2초 동안 멈춤
  ```

* process_time()

  ```python
  # 실제 연산 수행 시간 측정 (sleep 측정하지 않음)
  start = process_time()
  sleep(1)
  j = 0
  for i in range(100000):
      j += i
  end = process_time()
  print(end-start) # 0.015625
  ```

* perf_counter()

  ```python
  # 실제 대기한 시간 측정 (sleep 측정)
  start = perf_counter()
  sleep(1)
  j = 0
  for i in range(100000):
      j += i
  end = perf_counter()
  print(end-start) # 1.028067
  ```

  