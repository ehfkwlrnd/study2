# Xrm.Page.context 정리

* getUserId

  ```javascript
  var guid = Xrm.Page.context.getUserId();
  //{15E6C9A7-2094-43D0-A2FA-E6335EAAA74F}
  ```

* client.getClient

  ```javascript
  var client = Xrm.Page.context.client.getClient();
  //Web, Outlook, Mobile
  ```

* client.getFormFactor

  ```javascript
  var factor = Xrm.Page.context.client.getFormFactor();
  //0 : Unknown
  //1 : Desktop
  //2 : Tablet
  //3 : Phone
  ```

* getUserName

  ```javascript
  var name = Xrm.Page.context.getUserName();
  ```

* getUserRoles

  현재 사용자에게 부여된 "보안 역할"들의 guid를 array로 리턴

  ```javascript
  var roles = Xrm.Page.context.getUserRoles();
  //["cf4cc7ce-5d51-df11-97e0-00155db232d0", ..., ]
  ```

  

