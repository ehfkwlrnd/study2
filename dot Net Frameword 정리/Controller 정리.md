# Controller 정리

* controller의 기본적인 틀

  ```c#
  public class HomeController : Controller
  {
  	public ActionResult Index()
  	{
  		return View();
  	}
  }
  /* url이 /Home/Index 이면 위의 컨트롤러를 호출한다.
   * 그러면 /Views/Home/Index.cshtml을 클라이언트에게 전달한다.
   */
  ```

* RouteConfig

  ```c#
  /* 왜 /Home/Index 가 HomeController의 Index 메소드를 호출하는가.
   * App_Start디렉토리에 RouteConfig.cs 클래스가 들어있다.
   */
  routes.MapRoute(
  	name: "Default",
  	url: "{controller}/{action}/{id}",
  	defaults: new { controller = "Home", action = "Index", id = 			UrlParameter.Optional }
  );
  
  /* 만약 다음과 같이 변형하면 /Index/Home 으로 호출할 수 있다. */
  routes.MapRoute(
  	name: "Default",
  	url: "{action}/{controller}/{id}",
  	defaults: new { controller = "Home", action = "Index", id = 			UrlParameter.Optional }
  );
  ```

* Controller의 return 값

  ```c#
  /* 컨트롤러는 ActionResult를 반환하는게 일반적이다.
   * 만약 다른 자료형을 반환하면 어떻게 될까.
   * 다음과 같이 HomeController안에 구성한다.
   */
  
  public string StringResult()
  {
      return "Hello World";
  }
  ```

  ```html
  <!--html소스에 다음과 같이 구성한다.-->
  <a href="/Home/StringResult">GetString</a>
  ```

  ```html
  <!--a태그를 클릭하면 클라이언트에서 보여지는 결과는 다음과 같다.-->
  <html>
      <head></head>
      <body>
          Hello world
      </body>
  </html>
  ```

* ActionResult

  ```c#
  /* HomeController의 Index를 호출한다고 하자.
   * 아래와 같이 각각 return 되는 자료를 다르게 해본다.
   */
  public class HomeController : Controller
  {
  	public ActionResult Index()
  	{
  		return View(); 
  		// url : /Home/Index, page : /Views/Home/Index.cshtml
  		
  		return View("~/Views/Home/Index2.cshtml");
  		// url : /Home/Index, page : /Views/Home/Index2.cshtml
  		
  		return Redirect("/Home/Index2");
  		// url : /Home/Index2, HomeController의 Index2메소드 호출
  		
  		return Json(true);
  		// return true
  		
  		return Json(new { success = true });
  		// return { "success" : true }
  		
  		return Content("<script>alert('hello')</script>");
  		// 빈 화면에 경고창('hello')이 뜸
  		// string을 리턴하는 것과 같음
  	}
  }
  
  ```

