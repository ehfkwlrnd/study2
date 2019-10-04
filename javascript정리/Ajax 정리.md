# jQuery Ajax 정리

```javascript
//ajax 옵션
$.ajax({
    async : Boolean, //default : true
    cache : Boolean, //default : true
    data : PlainObject or String or Array,
    method : 'post' or'get' or 'put', //default : 'get'
    dataType : String, //서버로부터 받는 데이터 타입
    url : String, //default : The current page
    global : Boolean, //default : true, Ajax 전역 이벤트를 사용할 건지
    contentType : Boolean or String,
    //default : 'application/x-www-form-urlencoded; charset=UTF-8'
    //application/x-www-form-urlencoded, multipart/form-data, or text/plain
    //false 
    processData : Boolean, // default : true
    headers : PlainObject, // default : {}
    context : DOM, // $('div')라 하면 ajax내에서 this는 'div'를 가리킴
    beforeSend : Function(jqXHR jqXHR, PlainObject settings),
    dataFilter : Function(Anything data, String type),
    //success이전에 실행, 이 함수의 return 값이 success의 data가 됨
    success : Function(Anything data, String textStatus, jqXHR jqXHR),
    error : Function(jqXHR jqXHR, String textStatus, String errorThrown),
    complete : Function(jqXHR jqXHR, String textStatus),
    statusCode : {
        200 : function(){},
        404 : function(){}
    }
});


//ajax 전역 이벤트
$.ajaxSetup({
    success : function(){
        
    },
    error : function(){
        
    },
    statusCode : {
        
    }
});


//$.getScript
$.getScript(url, handler);
//예시
$.getScript("https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js",
           function(data, textStatus, jqXHR){
    			console.log('jquery load');
			});
//아래와 같은 내용
$.ajax({
    url : url,
    dataType : 'script',
    success : handler
});
//에러를 핸들링 하고 싶다면
$.getScript(url, handler).fail(function(jqxhr, settings, exception){
    
});
```

