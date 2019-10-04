# form의 data넘기기

* form객체 획득

  ```html
  <!--우선 아래와 같이 form이 구성되어 있다고 하자-->
  <form nctype="multipart/form-data" method="post" accept-charset="utf-8" id="f" name="f">
      <input type="text" name="name">
      <input type="checkbox" name="check" value="1">
      <input type="checkbox" name="check" value="2">
      <input type="file" name="files">
  </form>
  <button onclick="scriptSubmit()">click</button>
  ```

  ```javascript
  //fomr의 name인 f로 DOM에 접근할 수 있다.
  
  //예시
  console.log(f);
  
  //form의 필드와 메소드
  f.action
  f.method
  f.enctype
  f.encoding
  f.reset()
  f.submit()
  ```

* serialize()

  ```javascript
  $(f).serialize();
  //name=hail&check=1
  ```

  