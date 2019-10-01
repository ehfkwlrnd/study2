# using 사용법 정리

* `using`을 사용하지 않을 때

  ```c#
  System.Console.WriteLine("hello");
  ```

* `using System`;

  ```c#
  Console.WriteLine("hello");
  ```

* `using static System.Console`;

  ```c#
  WriteLine("hello");
  ```

***

* readonly

  ```c#
  using(var a = new MyClass())
  {
      /*a는 readonly
       *using문을 벗어나면 Dispose된다.
       *따라서 a는 IDisposable을 구현해야 한다.
       */
  }
  
  public class Myclass : IDisposable
  {
      public void Dispose()
      {
      	/*...*/
      }
  }
  ```

  

  

  