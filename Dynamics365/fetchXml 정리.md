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

  * page

    count별로 페이징을 할 수 있다. (1부터 시작)

    ```xml
    <fetch count='10' page='1'>
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

  만약 레코드의 해당 필드값이 null값이면 해당 attribute자체를 반환하지 않으므로 주의해야 한다.

  * all-attributes

    모든 필드를 가져온다

    ```xml
    <all-attributes/>
    ```

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
    
  * groupby

    fetch에 aggregate를 true값으로 해줘야 하며, alias속성을 반드시 사용해야 한다.

    ```xml
    <attribute name='contact' groupby='true' alias='key'/>
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


* 예시

  * 기본

    ```xml
    <fetch>
    	<entity name='contact'>
        	<attribute name='fullname'/>
            <attribute name='mobilephone'/>
            <filter type='and'>
            	<condition attribute='fullname' operator='eq' value='hail'/>
                <condition attribute='mobilephone' operator='like' value='010%'/>
            </filter>
        </entity>
    </fetch>
    ```

  * 중복 제거 하여 fullname얻기

    ```xml
    <fetch distinct='true'>
    	<entity name='contact'>
        	<attribute name='fullname'/>
            <filter>
            	<condition attribute='fullname' operator='like' value='Kim%'/>
            </filter>
        </entity>
    </fetch>
    ```

  * count하기

    ```xml
    <fetch aggregate='true'>
    	<entity name='contact'>
        	<attribute name='fullname' aggregate='count' alias='count'/>
            <filter>
            	<condition attribute='fullname' operator='like' value='Kim%'/>
            </filter>
        </entity>
    </fetch>
    ```

  * distinct count하기

    ```xml
    <fetch aggregate='true'>
    	<entity name='contact'>
        	<attribute name='fullname' aggregate='countcolumn' 
                       alias='count' distinct='true'/>
            <filter>
            	<condition attribute='fullname' operator='like' value='Kim%'/>
            </filter>
        </entity>
    </fetch>
    ```

  * aggregate = avb, sum, max, min 사용 가능

  * in 사용

    ```xml
    <fetch>
    	<entity name='contact'>
        	<attribute name='fullname'/>
            <filter>
            	<condition attribute='mobilephone' operator='in'>
                	<value>010xxxxxxxx</value>
                    <value>010yyyyyyyy</value>
                    <value>010zzzzzzzz</value>
                </condition>
            </filter>
        </entity>
    </fetch>
    ```

  * between 사용

    ```xml
    <fetch>
    	<entity name='contact'>
        	<attribute name='fullname'/>
            <filter>
            	<condition attribute='createdon' operator='between'>
                    <value>2019-01-01 00:00:00</value>
                    <value>2020-01-01 00:00:00</value>
                </condition>
            </filter>
        </entity>
    </fetch>
    ```

  * operator = eq, ne, ge, le, like, null, between, not-in, this-year 등

  * join 사용

    link-entity 태그를 사용한다. 

    from속성은 참조할 엔티티의 필드, to는 자신의 필드이다.

    from을 사용하지 않으면 참조할 엔티티의 기본키를 참조한다.

    또한 link-entity안의 attribute는 alias속성을 사용해야 한다.

    ```xml
    <fetch>
    	<entity name='contact'>
        	<attribute name='fullname'/>
            <link-entity name='account' to='contact_account'>
                <filter>
                    <condition attribute='name' operator='eq' value='xxx'/>
                </filter>
            </link-entity>
        </entity>
    </fetch>
    
    
    <fetch>
    	<entity name='serial'>
        	<attribute name='serialno'/>
            <link-entity name='contact' from='contact_account' to='serial_account'>
                <attribute name='fullname' alias='name'/>
                <filter>
                    <condition attribute='fullname' operator='eq' value='xxx'/>
                </filter>
            </link-entity>
        </entity>
    </fetch>
    ```

  * groupby 사용

    ```xml
    <fetch distinct='true'>
    	<entity name='appointment'>
        	<attribute name='contact' groupby='true' alias='key'/>
            <attribute name='contact' aggregate='count' alias='count'/>
            <filter>
            	<condition attribute='contact' operator='not-null'/>
            </filter>
        </entity>
    </fetch>
    ```

  * 필터링 복합 논리
  
    ```xml
    <fetch>
    	<entity name='contact'>
            <attribute name='fullname'/>
            <filter type='and'>
            	<filter type='or'>
                    <condition />
                    <condition />
                </filter>
                <filter type='or'>
                    <condition />
                    <condition />
                </filter>
            </filter>
        </entity>
    </fetch>
    ```
  
    

