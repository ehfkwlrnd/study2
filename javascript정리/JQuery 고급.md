# JQuery 고급

```html
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
```



- AJax 서버로 데이터 넘기기

  ```javascript
  $.ajax({
      url:'/Home/Contact',
      data: {id: 'ehfkwlrnd', pw: '1234'},
      type: 'post',
      dataType : 'json'
  });
  ```

- autocomplete

  ```javascript
  var data = ['안양', '안산', '서울'];
  $('#autoTest').autocomplete({
      source: data, //[{label:'안양', value:'안양'},... ] 으로 데이터 들어감
      minLength: 1, //default 0
      select: function(event, ui){
          console.log(ui.item.value); 
      }
  });
  
  var data = [{label:'안양', value:'안양', id:'efjkd-231qvmkjol'}, ...];
  $('#autoTest').autocomplete({
      source: data,
      focus: function () {//키보드를 이용하는 경우
  		return false;   //해당 데이터에 focus가 되면 입력창에 자동으로 값이 입력됨
  	},				    //그러한 현상을 방지하기 위함
      change: function(event, ui){
          console.log(ui.item.id);
      }
  });
  ```

- summernote

  ```html
  <!-- include libraries(jQuery, bootstrap) -->
  <link href="http://netdna.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.css" rel="stylesheet">
  <script src="http://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.js"></script> 
  <script src="http://netdna.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.js"></script> 
  
  <!-- include summernote css/js -->
  <link href="http://cdnjs.cloudflare.com/ajax/libs/summernote/0.8.12/summernote.css" rel="stylesheet">
  <script src="http://cdnjs.cloudflare.com/ajax/libs/summernote/0.8.12/summernote.js"></script>
  ```

  ```html
  <form method="post">
    <textarea id="summernote"></textarea>
  </form>
  ```

  ```javascript
  /*가장 기본*/
  $(function(){
      $('#summernote').summernote();
  })
  
  /*summernote 심화*/
  $('.summernote').summernote({
  	height: 350,                 
  	minHeight: null,             
  	maxHeight: null,             
  	focus: true, // set focus to editable area after initializing summernote
  	fontSizes: ['8', '9', '10', '11', '12', '14','16', '18', '24', '36', '48' , '64', '82', '150'],
  	imageTitle: {
  		specificAltField: true
  	},
  	lang: 'en-US',
  	popover: {
  		image: [
  			['imagesize', ['imageSize100', 'imageSize50', 'imageSize25']],
  			['float', ['floatLeft', 'floatRight', 'floatNone']],
  			['remove', ['removeMedia']],
  			['custom', ['imageTitle']]
  		]
  	},
  	toolbar: [  // [groupName, [list of button]]
  		['style', ['style']],
  		['style', ['bold', 'italic', 'underline', 'clear']],
  		['font', ['strikethrough', 'superscript', 'subscript']],
  		['fontsize', ['fontsize']],
  		['ol', ['ol']],
  		['ul', ['ul']],
  		['color', ['color']],
  		['link', ['link']],
  		['video', ['video']],
  		['table', ['table']],
  		['hr', ['hr']],
  		['para', ['ul', 'ol', 'paragraph']],
  		['height', ['height']],	
  		['picture', ['picture']],
  		['codeview', ['codeview']],
  		['undo', ['undo']],
  		['redo', ['redo']]
  	],
  	callbacks: {
  		onBlur: function() {
  			/*function contents*/
  		},
  		onImageUpload: function (files) {
  			/*function contents*/
  		}
  	}
  });
  

  /*이미지 삽입*/
  $('#summernote')
      .summernote('insertImage','D:/Users/yuno/Desktop/DoosanCapture/01.png');
  
  /*이미지 업로드*/
  onImageUpload: function (files) {
      for(var file of files)
  		sendFile(file);
  }
  
  function sendFile(file){
      var url = "https://devrobotlab.doosanrobotics.com/file/File/SaveUploadedImageForDropzone";
      var headers = {};
  	headers["Authorization"] = "Bearer fileupload";
      var data = new FormData();
  	data.append('uploadfile', file);
      
      $.ajax({
          url: url, 		
          data: data, 	
  		headers : headers,
  		type: "POST",	
  		cache: false,
  		contentType: false,
  		enctype: 'multipart/form-data',
  		processData: false,
          success: function(json){
              $('#summernote').summernote('insertImage',json.address);
          }
      });
  }
  ```
  
  

complete, form_data, RegExp

```javascript
특수문자 정규식 정리

r = new RegExp('(`|~|\\!|@|#|\\$|%|\\^|&|\\*|\\(|\\)|_|-|\\+|=|\\{|\\[|\\}|\\]|:|;|\'|"|,|\\.|\\/|\\?|\\||\\\\|\\ )', 'g')
```



