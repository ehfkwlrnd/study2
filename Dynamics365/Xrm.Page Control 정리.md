# Xrm.Page Control 정리

* getControl

  Dynamics 365 양식에 올려져 있는 각 컨트롤에 대해 정보를 가져온다.

  ```javascript
  var field = Xrm.Page.ui.controls.get('{control_name}');
  var field = Xrm.Page.getControl('{control_name}')
  ```

* Visible 컨트롤

  ```javascript
  Xrm.Page.getControl('{control_name}').setVisible(false);
  Xrm.Page.getControl('{control_name}').setVisible(true);
  ```

* Option 컨트롤

  ```javascript
  Xrm.Page.getControl('{control_name}').removeOption(2);
  Xrm.Page.getControl('{control_name}').addOption({value : 2, text : '매장'});
  ```

* PreSearch 컨트롤

  lookup필드에 대해, lookup 미리보기를 필터링 할 수 있다.

  addCustomFilter를 내부에 갖는 커스텀 메소드를 addPreSearch메소드에 콜백메소드로 인자값을 넘겨준다.

  ```javascript
  function FilteringTest(){
  	Xrm.Page.getControl('{control_name}').removePreSearch(PreSearchTest);
  	Xrm.Page.getControl('{control_name}').addPreSearch(PreSearchTest);
  }
  
  function PreSearchTest(){
      var guid = "{D0F05A0E-9F43-E411-ADE7-D89D6779D5EC}";
  	var filterXml = "<filter type='and'>" +
  				    	"<condition attribute='accountid' operator='like' value='" +
  				        	guid + "'/>" +
  				 	"</filter>";
  	Xrm.Page.getControl('{control_name}').addCustomFilter(filterXml);
  }
  ```

* Grid 컨트롤

  서브그리드에 대해 컨트롤을 얻어 올 수 있다.

  * get

    ```javascript
    var grid = Xrm.Page.getControl('{grid_name}').getGrid();
    var fetch = Xrm.Page.getControl('{grid_name}').getFetchXml();
    var filter = Xrm.Page.getControl('{grid_name}').getFilterXml();
    ```

  * set

    ```javascript
    var fetchXml = "<fetch version='1.0' output-format='xml-platform' 		mapping='logical' distinct='false'>"+
    						"<entity name='skr_installation'>"+
    							"<filter type='and'>"+
    								"<condition attribute='skr_account' operator='eq' uitype='account' value='" + accountid + "' />"+
    							"</filter>"+
    						"</entity>"+
    					"</fetch>";
    
    Xrm.Page.getControl('{grid_name}').setFetch(fetchXml);
    ```

  * refresh

    ```javascript
    Xrm.Page.getControl('{grid_name}').refresh();
    ```


