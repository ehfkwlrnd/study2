# jQuery - Selector의 이해

* selector에 특수문자가 있다면

  ```html
  <div id="a.b"></div>
  ```

  ```javascript
  $('#a\\.b')
  
  // '#a\\.b' 는 #a\.b 값을 만들어 냄
  // 똑같은 예시로는
  
  var s = '#a\\.b'; // -> #a\.b
  $(s)
  ```

* eq

  ```html
  <div id="first"></div>
  <div id="second"></div>
  <div id="third"></div>
  ```

  ```javascript
  $('div:eq(0)') //first
  $('div').eq(0) //first
  ```

* nth-child

  ```html
  <div id="first"></div>
  <div id="second"></div>
  <div id="third"></div>
  ```

  ```javascript
  $('div:nth-child(1)') //first
  $('div:nth-child(2n+1)') //first, third
  ```

* select-option의 value

  ```html
  <select>
      <option value="1">a</option>
      <option value="2">b</option>
      <option value="3">c</option>
  </select>
  ```

  ```javascript
  //먼저 option c를 선택한 상황
  $('select').val() // 3
  $('option:selected').val() // 3
  $('option:selected').text() // c
  
  //선택 option을 바꾸기
  $('select').val(1) // a가 선택됨
  ```

* attribute

  ```html
  <div class="abc" id="first"></div>
  <div class="abc-def" id="second"></div>
  <div class="abcdef" id="third"></div>
  <div class="abc def" id="fourth"></div>
  <div class="cde" id="fifth"></div>
  ```

  ```javascript
  $('div[class="abc"]') //first
  $('div[class|="abc"]') //first, second
  $('div[class^="abc"]') //first, second, third, fourth
  $('div[class$="def"]') //second, third, fourth
  $('div[class*="cd"]') //third, fifth
  $('div[class~="abc"]') //first, fourth
  
  // | : starting
  // ^ : begin
  // $ : end
  // * : contain substring
  // ~ : contain word
  ```

* radio button

  ```html
  <input type="radio" name="test" value="1">a
  <input type="radio" name="test" value="2">b
  <input type="radio" name="test" value="3">c
  ```

  ```javascript
  //먼저 b를 선택한 상황
  $('input[name="test"]') //first, second, third
  $('input[name="test"]').val() // 1 (제일 앞의 value가 리턴 됨)
  $('input[name="test"]:checked') //second
  $('input[name="test"]:checked').val() // 2
  ```

* checkbox

  ```html
  <input type="checkbox" name="test" value="1">a
  <input type="checkbox" name="test" value="2">b
  <input type="checkbox" name="test" value="3">c
  ```

  ```javascript
  //먼저 b, c를 선택한 상황
  $('input[name="test"]') //first, second, third
  $('input[name="test"]').val() // 1 (제일 앞의 value가 리턴 됨)
  $('input[name="test"]:checked') //second, third
  $('input[name="test"]:checked').val() // 2 (제일 앞의 value가 리턴 됨)
  ```

* find

  ```html
  <select id="first">
  	<option value="1">a</option>
  	<option value="2">b</option>
  	<option value="3">c</option>
  </select>
  
  <select id="second">
  	<option value="4">a</option>
  	<option value="5">b</option>
  	<option value="6">c</option>
  </select>
  ```

  ```javascript
  $('select').eq(0).find('option:selected').val() // 1
  
  //물론 다음과 같이 표현할 수도 있다.
  $('select:eq(0) > option:selected').val()
  ```

  