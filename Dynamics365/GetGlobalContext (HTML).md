# GetGlobalContext (HTML)

* HTML웹 리소스를 사용할 경우, Xrm클래스에 바로 접근할 수 없다. 

  하지만 아래와 같이 script를 추가하여 접근이 가능하다.

  ```html
  <script src="ClientGlobalContext.js.aspx" type="text/javascript" ></script>
  ```

* 만약 위 처럼 script를 추가하지 않으면 parent를 통해 접근해야 한다.

  ```javascript
  var name = parent.Xrm.Page.context.getUserName();
  ```

* 양식 속성에 추가한 Javascript라이브러리를 HTML에서 참조하려면 마찬가지로 script를 추가해야 한다.

  보통 웹리소스들은 {orgUrl}/WebResources/ 경로에 각 파일 이름으로 저장되어 있다.

  예를들어 new_commons라는 웹리소스의 URL은 {orgUrl}/WebResources/new_commons 이다.

  따라서 아래와 같이 script를 추가하여 다른 라이브러리를 참조할 수 있다.

  ```html
  <script src="new_commons" type="text/javascript"></script>
  ```

  