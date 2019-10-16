# FileDownload 방법

* html

  ```html
  <a href="/Home/FileDownload/?url=test001.jpg&name=test.jpg">download</a>
  ```

* Controller

  ```c#
  public ActionResult FileDownload(string url, string name)
  {
      url = Server.MapPath("~/Upload/" + url.Substring(url.LastIndexOf('/') + 1));
      //Server는 Controller의 속성
      return File(System.IO.File.ReadAllBytes(url),
                  System.Net.Mime.MediaTypeNames.Application.Octet, name);
      //Controller의 File메소드와 구분하기 위해
      //System.IO.File이라고 명시함.
      //using static System.IO.File.ReadAllBytes를 사용해도 됨
  }
  ```

  

