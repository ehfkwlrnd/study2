# ExecuteMultipleRequest 이용하기

* using 선언

  ```c#
  using Microsoft.Xrm.Sdk;
  using Microsoft.Xrm.Sdk.Message;
  ```

* OrganizationServiceProxy를 통해 조직에 대한 인증은 거쳤다고 가정하고 진행한다.

  ```c#
  OrganizationServiceProxy service = GetCRMService();
  //또는
  CrmServiceClient service = new CrmServiceClient(conn);
  ```
  
* multipleRequest 선언

  ```c#
  var multipleRequest = new ExecuteMultipleRequest
  {
      Settings = new ExecuteMultipleSettings
      {
          ContinueOnError = true,
          ReturnResponses = true
      },
      Requests = new OrganizationRequestCollection()
  };
  ```

* CreateRequeset

  ```c#
  var account = new Account
  {
      Name = "Test",
      PhoneNumber = "000-0000-0000"
  }
  
  var request = new CreateRequest
  {
      Target = account //Entity 클래스 
  };
  ```

* UpdateRequest

  ```c#
  var account = new Account
  {
      Id = {GUID},
      PhoneNumber = "000-0000-0000"
  }
  
  var request = new UpdateRequest
  {
      Target = account //Entity 클래스 
  }
  ```

* DeleteRequest

  ```c#
  var request = new DeleteRequest
  {
      Target = new EntityReference("{logicalName}", {GUID})
  }
  ```

* Execute

  ```c#
  multipleRequest.Requests.Add(request);
  service.Execute(multipleRequest);
  ```

* 예시

  ```c#
  var multipleRequest = new ExecuteMultipleRequest
  {
      Settings = new ExecuteMultipleSettings
      {
          ContinueOnError = true,
          ReturnResponses = true
      },
      Requests = new OrganizationRequestCollection()
  };
  
  multipleRequest.Requests.Add(
  	new DeleteReques
      {
          Target = new EntityReference(Account.EntityLogicalName, entity.Id)
      }
  )
  ```

  