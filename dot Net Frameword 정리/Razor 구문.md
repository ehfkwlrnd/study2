# Razor 구문

* @을 붙임으로써 서버에서 작동할 기능을 명시

  ```html
  <!--Introduce.cshtml-->
  @{
  	string name = "Hail";
  }
  <h1>@name</h1>
  ```

  ```html
  <!--클라이언트가 받는 페이지-->
  <h1>Hail</h1>
  ```

* `<script>`에도 적용 예시

  ```html
  <script>
  	console.log(@ViewBag.user.Name);
  </script>
  ```

* 제어문 사용 예시

  ```html
  <h1>Test</h1>
  @foreach(var data in ViewBag.list)
  {
  	if(data.grade == 1)
  	{
  		<p><b>data.name</b></p>
  	}
  	else
  	{
  		<p>data.name</p>
  	}
  }
  ```

* Razor에서 지원하는 메소드

  ```html
  <!--데이터 변환-->
  <!--스트링에서 다른 자료형으로-->
  s.AsInt()
  s.AsFloat()
  s.AsDecimal()
  s.AsDateTime()
  s.AsBool()
  
  <!--데이터 확인-->
  a.IsInt()
  a.IsFloat()
  a.IsDecimal()
  a.IsDateTime()
  a.IsBool()
  ```

* 주석

  ```html
  @*
  	content
  *@
  ```

* @Html.Raw

  ```html
  <!--Test.cshtml-->
  @("<div>Normal String</div>")
@{
  	<div>This is Razor</div>
  }
  @Html.Raw("<div>Html String</div>")
  
  <!--클라이언트가 받는 페이지-->
  "<div>Normal String</div>" <!--그냥 텍스트-->
  <div>Html String</div> <!--div 태그-->
  <div>Html String</div> <!--div 태그-->
  ```
  
* @using

  ```html
  <!--다음과 같이 하면 using이 되지 않는다.-->
  @{
  	using System.Text.RegularExpressions;
  }
  
  <!--다음과 같이 using을 사용해야 한다.-->
  @using System.Text.RegularExpressions;
  ```

* @functions

  ```c#
  /*함수를 추가하고 싶다면*/
  /*Test.cshtml*/
  
  @functions{
  	public string getString()
  	{
  		return "Hello World";
  	}
  
  	public void RenderName(string name)
      {
          <div>Name : @name</div>
      }
  }
  
  <div>@getString()</div>
  @RenderName("Hail")
  
  /*클라이언트가 받는 페이지*/
  <div>Hello World</div>
  <div>Name : Hail</div>
  ```

  

  