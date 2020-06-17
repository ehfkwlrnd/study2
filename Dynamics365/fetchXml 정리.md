# fetchXml 정리

* 기본적인 태그 위계는 아래와 같다.

  ```xml
  <fetch>
  	<entity>
          <attribute></attribute>
          <filter>
              <condition></condition>
          </filter>
          <order></order>
      </entity>
  </fetch>
  ```

* fetch 속성

  * count

    상위 몇 개 데이터를 가져올 건지 정한다.

    ```xml
    <fetch count='10'>
    </fetch>
    ```

  * distinct

    aggregate를 사용하지 않을 경우, fetch되는 attribute의 중복을 제거한다.

    ```xml
    <fetch distinct='ture'>
    </fetch>
    ```

  * aggregate

    집계함수를 사용할 것인지 정한다.

    ```xml
    <fetch aggregate='true'>
    </fetch>
    ```

* entity 속성

  * name

    entity의 이름을 적는다.

    ```xml
    <entity name='contact'>
    </entity>
    ```

* attribute 속성

  select의 역할을 한다.

  * name

    필드의 이름을 적는다. (스키마 이름 x )

    ```xml
    <attribute name='fullname' />
    ```

  * aggregate

    사용할 집계함수명을 적는다.

    ```xml
    <attribute name='fullname' aggregate='count' />
    ```

  * alias

    별칭, 특히 aggregate를 사용할 경우 반드시 적는다.

    ```xml
    <attribute name='fullname' aggregate='count' alias='mycount' />
    ```

  * distinct

    aggregate가 countcolumn일 때, 해당 열의 중복을 제하고 계산하고 싶다면 사용한다.

    ```xml
    <attribute name='fullname' aggregate='countcolumn' alias='mycount' distinct='true'/>
    ```

* filter 속성

  * type

    condition이 and인지 or인지 정한다. (default : and)

    ```xml
    <filter type='or'>
    </filter>
    ```

* order 속성

  * attribute

    ```xml
    <order attribute='fullname' />
    ```

  * alias

    ```xml
    <order alias='name' />
    ```

  * descending

    ```xml
    <order alias='name' descending='false' />
    ```

* condition 속성

  * attribute, operator, value

    ```xml
    <condition attribute='mobilephone' operator='eq' value='01099999999' />
    ```

    