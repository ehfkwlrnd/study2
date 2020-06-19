# FetchExpression (C#) 정리

* 해당 예제에서 필요한 클래스를 사용하기 아래와 같이 using선언을 해준다.

  ```c#
  using Microsoft.Xrm.Sdk;
  using Microsoft.Xrm.Sdk.Query;
  ```

* OrganizationServiceProxy를 통해 조직에 대한 인증은 거쳤다고 가정하고 진행한다.

  ```c#
  OrganizationServiceProxy service = GetCRMService();
  ```

* 예시1 : 단순 text필드 가져오기

  ```c#
  string fetchXml = ".....";
  FetchExpression query = new FetchExpression(fetchXml6);
  EntityCollection results = service.RetrieveMultiple(query);
  DataCollection<Entity> entities = results.Entities;
  foreach(Entity entity in entities)
  {
      Console.WriteLine(entity["{attribute_name}"]);
  }
  ```

  

  