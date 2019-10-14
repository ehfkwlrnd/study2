# DateTime 에 관한 기초

* 초기화

  ```c#
  //DateTime은 not nullable이다.
  //DateTime d = null; 불가능
  
  DateTime d = new DateTime();
  //0001-01-01 오전 12:00:00
  
  DateTime d = new DateTime(2019, 12, 25, 13, 10, 15);
  //2019-12-25 오후 1:10:15
  ```

* 시간 이동

  ```c#
  d = d.AddDays(5);
  d = d.AddDays(-5);
  ```

* 시간 비교

  ```c#
  //최근일수록 큰 값
  //c : 어제, d : 오늘
  //c < d
  ```

* ToString

  ```c#
  d.ToShortDateString();
  //"2019-12-25"
  
  d.ToShortTimeString();
  //"오후 1:10"
  
  d.ToLongTimeString();
  //"오후 1:10:15"
  
  d.ToString(format);
  /*
  yy : 19
  yyyy : 2019
  MM : 12
  dd : 25
  hh : 01
  mm : 10
  ss : 15
  yyyy-MM-dd : 2019-12-25
  */
  ```

* 요일

  ```c#
  d.DayOfWeek
  //열거형
  //Sunday, MonDay, ..., Saturdat
  //0, 1, ..., 6
  ```

* Now, Today

  ```c#
  DateTime.Now;
  //현재 날짜와 시간으로 DateTime객체 반환
  
  DateTime.Today;
  //현재 날짜, 시간은 00:00:00으로 DateTime객체 반환
  ```

  

