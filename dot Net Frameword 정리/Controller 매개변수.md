# Controller 매개변수

* name 맞추기

  ```c#
  // 예를 들어 get방식으로 /Home/Index/?type=red&flag=false 라고 호출했다면
  // 아래와 같이 컨트롤러를 구성해야 type, flag의 값을 받을 수 있다.
  
  public ActionResult Index(string type, bool flag) { /*...*/ }
  
  // 만약 Model클래스가 다음과 같이 구성되어 있다면
  public class TestModel
  {
      public string type {get; set;},
      public bool flag {get; set;}
  }
  
  // 아래와 같이 구성해도 값을 받을 수 있다.
  public ActionResult Index(TestModel test) { /*...*/ }
  ```

* 자료형 맞추기

  ```c#
  public ActionResult Index(string select){}
  // url이 /Home/Index/ 일 때 select = null
  // url이 /Home/Index/?select= 일 때 select = ""
  // url이 /Home/Index/?select=hello 일 때 select = "hello"
  
  public ActionResult Index(int? select){}
  // url이 /Home/Index/ 일 때 select = null
  // url이 /Home/Index/?select= 일 때 select = null
  // url이 /Home/Index/?select=hello 일 때 select = null
  // url이 /Home/Index/?select=1 일 때 select = 1
  
  public ActionResult Index(bool? select){}
  // url이 /Home/Index/?select=1 일 때 select = null
  // url이 /Home/Index/?select=true 일 때 select = true
  
  public ActionResult Index(DateTime? select){}
  // url이 /Home/Index/?select= 일 때 select = null
  // url이 /Home/Index/?select=168456 일 때 select = null
  // url이 /Home/Index/?select=1992-12-25 일 때 select = new Date(1992, 12, 25)
  
  public ActionResult Index(OptionSetValue select){}
  // url이 /Home/Index/?select= 일 때 select.Value = 0
  // url이 /Home/Index/?select=1 일 때 select = null
  // url이 /Home/Index/?select=a 일 때 select = null
  // url이 /Home/Index/?select.Value= 일 때 select.Value = 0
  // url이 /Home/Index/?select.Value=1 일 때 select.Value = 1
  ```

  