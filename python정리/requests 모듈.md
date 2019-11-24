# requests 모듈

* request

  ```python
  import requests
  
  #requests.get(url, params=None, **kwargs)
  #requests.post(url, data=None, json=None, **kwargs)
  #requests.patch(url, data=None, **kwargs)
  #requests.delete(url, **kwargs)
  
  #return Response
  ```

* response

  ```python
  import requests
  
  r = requests.get(url)
  
  r.ok #boolean
  r.text #string
  r.content #bytes
  ```

  