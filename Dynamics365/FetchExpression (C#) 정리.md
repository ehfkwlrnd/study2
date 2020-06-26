# FetchExpression (C#) 정리

* 해당 예제에서 필요한 클래스를 사용하기 아래와 같이 using선언을 해준다.

  ```c#
  using Microsoft.Xrm.Sdk;
  using Microsoft.Xrm.Sdk.Query;
  ```

* OrganizationServiceProxy를 통해 조직에 대한 인증은 거쳤다고 가정하고 진행한다.

  ```c#
  OrganizationServiceProxy service = GetCRMService();
  //또는
  CrmServiceClient service = new CrmServiceClient(conn);
  ```

* 쿼리 결과 가져오기

  ```c#
  string fetchXml = "{your_fetchXml}";
  FetchExpression query = new FetchExpression(fetchXml);
  EntityCollection results = service.RetrieveMultiple(query);
  DataCollection<Entity> entities = results.Entities; //쿼리 결과
  ```
  
* 예시1 : 단순 필드 값 가져오기

  ```c#
  foreach(Entity entity in entities)
  {
      Console.WriteLine(entity["{attribute_name}"]);
  }
  ```
  
* 예시2 : 특정 타입으로 형 변환이 필요한 경우

  ```c#
  foreach(Entity entity in entities)
  {
      OptionSetValue opt = (OptionSetValue)entity["{attribute_name}"]
      Console.WriteLine(opt.Value);
  }
  
  foreach(Entity entity in entities)
  {
      OptionSetValue opt = (EntityReference)entity["{attribute_name}"]
      Console.WriteLine(opt.Name);
  }
  ```

* 예시3 : alias사용 시

  ```c#
  foreach(Entity entity in entities)
  {
      AliasedValue al = (AliasedValue)entity["{attribute_name}"]
      OptionSetValue opt = (OptionSetValue)al.Value;
      Console.WriteLine(opt.Value);
  }
  ```

  

