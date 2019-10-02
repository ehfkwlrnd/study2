# String 에 관한 기초

* string 과 String은 완전히 같은 클래스 이다.

* Substring

  ```c#
  string s = "0123456";
  s.Substring(3); //return "3456"
  s.Substring(3, 2); //return "34"
  ```

* Split

  ```c#
  s.Split(',');
  //s = null 이면 에러
  //s = "" 이면 return {""}
  //s = "abc" 이면 return {"abc"}
  //s = "," 이면 return {"", ""}
  //s = "1," 이면 return {"1", ""} 
  //s = "1,2" 이면 return {"1", "2"}
  ```

* 유효성 검사

  ```c#
  string.isNullOrEmpty(a); 
  string.isNullOrWhiteSpace(a);
  ```

* Format

  ```c#
  string.Format("hello {0} world {1}", "hail", "lol");
  //return ""hello hail world lol"
  ```

* 축자 리터럴

  ```c#
  // 여러줄 입력
  string s = @"hello
  world";
  
  // \사용
  string s = @"\"; //가능 (일반적으로 string s = "\\"; )
  // 응용
  string path = @"C:\User\Document\";
  
  // "표현 시 : "" -> "
  string s = @"""Hi"""; //"Hi" 로 표현됨 (일반적으로 string s = "\"Hi\"";)
  ```

* 문자열 보간

  ```c#
  // $을 사용하여 문자열 리터럴을 보간된 문자열로 식별함
  
  string name = "Mark";
  var date = DateTime.Now;
  
  // 기존 방법
  Console.WriteLine("Hello, {0}! Today is {1}, it's {2:HH:mm} now.", name, date.DayOfWeek, date);
  
  // $을 사용하여 같은 결과
  Console.WriteLine($"Hello, {name}! Today is {date.DayOfWeek}, it's {date:HH:mm} now.");
  
  // 기존 방법
  string introduce = "My name is " + name;
  
  // $을 사용하여 같은 결과
  string introduce = $"My name is {name}";
  ```

  