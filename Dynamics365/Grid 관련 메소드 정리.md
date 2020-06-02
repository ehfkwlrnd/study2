# Grid 관련 메소드 정리

* getGrid

  먼저 서브그리드를 통해 다음과 같이 그리드의 정보를 가져올 수 있다.

  ```javascript
  var grid = Xrm.Page.getControl('{grid_name}').getGrid();
  ```

* grid 메소드

  ```javascript
  var total = grid.getTotalRecordCount();
  var rows = grid.getRows();
  var selected = grid.getSelectedRows();
  ```

* rows

  rows는 _clientApiExecutor와 _collection을 포함하는 오브젝트이다.

  특히 _collection은 아래와 같이 key값이 guid이고 value가 v오브젝트인 딕셔너리 형태로 되어 있다.
  
  ```javascript
  {
      3fbd2b70-6bcb-e711-813d-e0071b673bc1: v {_applicationContext: {…}, _pageId: "0", _contextToken: {…}, _entityType: "skr_installation", _entityId: o},
          ...
}
  ```

  즉, 특정 레코드에 다음과 같이 접근할 수 있다.
  
  ```javascript
var row = rows._collection['3fbd2b70-6bcb-e711-813d-e0071b673bc1'];
  ```
  
  물론, 위처럼 굳이 _collection을 통해 접근할 필요는 없다.
  
  아래와 같이 각 레코드에 간편히 접근할 수 있는 메소들를 제공한다.
  
  ```javascript
  var rows_all = rows.getAll(); //v오브젝트 배열 [v, v, ... , v]
  var rows_filtering = rows.getByFilter(x = > x._entityId.guid == guid); //v오브젝트 배열
  var row_index = rows.getByIndex(2); //v오브젝트
  var row_name = rows.getByName('3fbd2b70-6bcb-e711-813d-e0071b673bc1'); //v오브젝트
  var length = rows.getLength();
  ```
  
* v-Object (row)

  ```javascript
  var attributes = row.getAttribute(); //object 배열
  var url = row.getUrl();
  ```

* Attribute

  ```javascript
  var attribute = attributes[0];
  
  var attribute_name = attribute._attributeName;//string : ex) skr_product_status
  var value = attribute.getValue();
  ```

  