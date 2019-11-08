# string 정리

* 문자열 포맷팅

  ```python
  year = 2019
  event = 'Party'
  per = 0.34523
  
  # f를 붙이면 포맷팅 됨.
  d = f'{{"year":"{year}", "event":"{event}", "per":"{per:.2f}"}}'
  # {변수명} 으로 포맷팅
  # {{ 는 문자 { 로 인식
  # {per : .2f} 와 같이 포맷 지정
  
  # dict 객체 빠르게 포맷팅하기
  dict_object = {'school':'Univ', 'name':'Hail', 'age':29}
  d = '{name} graduated from {school} and is {age} years old.'.format(**dict_object)
  
  # 정렬
  event = 'Party'
  d = f'{event:10}' # 'Party     '  10자리 확보
  d = f'{event:>10}' # '     Party' 오른쪽 정렬
  d = f'{event:^10}' # '  Party   ' 가운데 정렬
  
  # 공백 채우기
  d = f'{event:=^10}' # '==Party==='
  ```

* find, index

  ```python
  s.find('b') #처음으로 나온 위치 반환, 없으면 -1
  s.index('b') #처음으로 나온 위치 반환, 없으면 에러
  ```

* join

  ```python
  # join(iterable) iterable의 원소가 모두 string 이어야 한다.
  
  s = ', '.join(['Hail', 'Minsu', 'You']) # 'Hail, Minsu, You'
  s = ' and '.join(['Hail', 'Minsu', 'You']) # 'Hail and Minsu and You'
  ```

* upper, lower

  ```python
  u = s.upper()
  l = s.lower()
  ```

* lstrip, rstrip, strip

  ```python
  s = '  hello  '
  ls = s.lstrip() # 'hello  '
  rs = s.rstrip() # '  hello'
  ss = s.strip() # 'hello'
  ```

* replace

  ```python
  s = 'aaabbaa'
  rp = s.replace('a', 'c') # 'cccbbcc'
  ```

* split

  ```python
  s = 'a,b,c'
  s.split(',') # ['a', 'b', 'c']
  ```

* count

  ```python
  s = 'aaabbaa'
  s.count('a') # 5
  ```

  