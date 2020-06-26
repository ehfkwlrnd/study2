# ServiceContext 얻기

* 다음과 같이 IOrganizationService를 얻어왔다고 가정하고 진행한다.

  ```c#
  IOrganizationService service = GetCRMService();
  ```

* CrmSvcUtil.exe를 이용한 경우

  Entity.cs 파일이 생성되었다면 아래와 같이 ServiceContext를 얻을 수 있고, Entity.cs에 정의된 

  각 엔티티별 어트리뷰트에 쉽게 접근할 수 있다.

  ```c#
  var sc = new ServiceContext(service);
  var contacts = (from c in sc.ContactSet
                 where c.FullName == "{name}"
                 select new
                 {
                     Name = c.FullName,
                     Phone = c.MobilePhone
                 });
  ```

* OrganizationServiceContext를 이용할 경우

  ```c#
  var sc = new OrganizationServiceContext(service);
  var what = (from c in ss.CreateQuery("contact")
              where c["fullname"].Equals("{name}")
              select new
              {
                  Name = (string)c["fullname"],
                  Phone = (string)c["mobilephone"]
              });
  ```

  