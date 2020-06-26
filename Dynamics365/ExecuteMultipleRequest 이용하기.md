# ExecuteMultipleRequest 이용하기

* using 선언

  ```c#
  using Microsoft.Xrm.Sdk;
  using Microsoft.Xrm.Sdk.Message;
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

  