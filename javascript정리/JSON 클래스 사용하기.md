# JSON 클래스 사용하기

* JSON.parse : 스트링을 객체로

  ```javascript
  var s = '{"name":"abc"}'
  var d = JSON.parse(s);
  d.name //"abc"
  ```

* JSON.stringify : 객체를 스트링으로

  ```javascript
  var obj = {name : "abc", func : console.log};
  JSON.stringify(obj) // {"name" : "abc"}
  ```
  
  
  
  