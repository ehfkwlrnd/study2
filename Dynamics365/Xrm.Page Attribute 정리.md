# Xrm.Page Attribute 정리

* getAttribute

  Dynamics 365 양식에 필드가 올라와 있을 경우, 필드의 정보를 가져올 때 사용한다.

  ```javascript
  var field = Xrm.Page.data.entity.attributes.get('{field_name}');
  var field = Xrm.Page.getAttribute('{field_name}');
  ```
  
* Value 컨트롤
  
  * getValue
  
    ```javascript
    var field_value = Xrm.Page.getAttribute('{field_name}').getValue();
    ```
  
    필드의 타입에 따라 값의 타입도 달라진다. 
  
    특히 lookup필드일 경우 아래와 같은 형식으로 반환한다.
  
    ```javascript
    //Array
    [{entityType: "account", id: "{D0F05A0E-9F43-E411-ADE7-D89D6779D5EC}", name: "서울아산병원"}]
    ```
  
  * setValue
  
    각 타입에 맞춰 인자값을 넘겨주면 되지만, 특히 lookup필드는 고유 형식이 있으므로 주의해야 한다.
  
    아래와 같은 형식은 에러를 발생시킨다.
  
    ```javascript
    Xrm.Page.getAttribute('{field_name}').setValue("서울아산병원");
    Xrm.Page.getAttribute('{field_name}').setValue("{D0F05A0E-9F43-E411-ADE7-D89D6779D5EC}");
    ```
  
    따라서 아래와 같이 정확히 입력해줘야 한다.
  
    ```javascript
    //배열 안에 객체를 넣어줘야 한다.
    Xrm.Page.getAttribute('{field_name}').setValue([{entityType: "account", id: "{D0F05A0E-9F43-E411-ADE7-D89D6779D5EC}", name: "서울아산병원"}]);
    
    //name은 생략 가능하다.
    Xrm.Page.getAttribute('{field_name}').setValue([{entityType: "account", id: "{D0F05A0E-9F43-E411-ADE7-D89D6779D5EC}"}]);
    
    //id의 중괄호도 생략 가능하다.
    Xrm.Page.getAttribute('{field_name}').setValue([{entityType: "account", id: "D0F05A0E-9F43-E411-ADE7-D89D6779D5EC"])
    ```
  
    또한 주의할 점으로, 날짜-시간 타입에 대해서는 Date객체를 전달해줘야 한다.
  
    ```javascript
    Xrm.Page.getAttribute('{date_field}').setValue(new Date());
    ```
  
* RequiredLevel 컨트롤

  ```javascript
  Xrm.Page.getAttribute('{field_name}').setRequiredLevel('none');
  Xrm.Page.getAttribute('{field_name}').setRequiredLevel('recommended');
  Xrm.Page.getAttribute('{field_name}').setRequiredLevel('required');
  ```

  

