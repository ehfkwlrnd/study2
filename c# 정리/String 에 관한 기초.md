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

  