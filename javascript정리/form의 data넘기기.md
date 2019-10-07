# form의 data넘기기

* form객체 획득

  ```html
  <!--우선 아래와 같이 form이 구성되어 있다고 하자-->
  <form nctype="multipart/form-data" method="post" accept-charset="utf-8" id="f" name="f">
      <input type="text" name="name">
      <input type="checkbox" name="check" value="1">
      <input type="checkbox" name="check" value="2">
      <input type="file" name="files" multiple>
  </form>
  <button onclick="scriptSubmit()">click</button>
  ```

  ```javascript
  //form의 name으로 DOM을 호출 할 수 있다.
  
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
  //name=hail&check=1&check=2
  //파일은 serialize할 수 없음
```
  
* FormData

  ```javascript
  var formdata = new FormData(f);
  
  formdata.get('name') // "hail"
  formdata.get('check') // "1"
  formdata.getAll('check') // ["1", "2"]
  formdata.getAll('files') // [File, File]
  formdata.has('files') // true
  formdata.append('append', 'test') //name, value
  formdata.delete('append')
  ```

* File

  ```javascript
  var a = $('input[name="files"]'); // jQueryObject
  var b = a[0]; // DOM 
  var c = b.files; // FileList
  var d = c[0]; // File
  
  formdata.append('files', d);
  ```

  