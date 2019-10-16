# FileUpload 방법

* html

  ```html
  <form method="post" name="f">
  	<input type="file" name="file">    
  </form>
  ```

* ajax

  ```javascript
  $.ajax({
  	type: "post",
  	url: "/Home/FileUpload",
  	data: new FormData("f"),
  	processData: false, 
  	contentType: false,  
  	success: function (json) {
          if (json.success) {
              alert("저장됨");
          }
          else{
          	alert("저장되지 않음");   
          }
  	},
  	error: function (r) {
  		console.log(r.responseText);
  	}
  });
  ```

* Controller

  ```c#
  public ActionResult FileUpload()
  {
      var files = Request.Files;
      bool success = false;
      string url = "";
      for (int i = 0; i < files.Count; i++)
      {
          var file = files[i];
          string name = file.FileName;
          if (!string.IsNullOrEmpty(name))
          {
              string expand = name.Substring(name.LastIndexOf('.'));
              name = name.Replace(expand, DateTime.Now.ToString("yyyyMMddhhmmss") + expand);
              url = Server.MapPath("~/Upload/" + name);
              file.SaveAs(url);
              success = true;
          }
      }
      return Json(new { url = url, success = success });
  }
  ```

* Web.config

  ```xml
  <!--input파일은 default로 4MB까지 전송이 허용된다. 
  	최대 전송 길이를 늘이기 위해서는 다음과 같이 세팅값을 변경해준다.-->
  <configuration>
  	<system.web>
      	<httpRuntime maxRequestLength="2097152"
                       targetFramework="4.6.1" />
          <!-- maxRequestLength(KB) 기본 크기는 4096KB(4MB)-->
      </system.web>
      <system.webServer>
      	<security>
          	<requestFiltering>
              	<requestLimits maxAllowedContentLength="2147483648" />
                  <!--단위는 byte-->
              </requestFiltering>
          </security>
      </system.webServer>
  </configuration>
  ```

  