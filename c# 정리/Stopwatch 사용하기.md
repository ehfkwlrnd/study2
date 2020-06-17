# Stopwatch 사용하기

* Stopwatch클래스는 `System.Diagnostics` 안에 정의되어 있다.

* 예시

  ```c#
  using System.Diagnostics;
  
  var stopwatch = new Stopwatch();
  
  stopwatch.Start();
  /*content*/
  stopwatch.Stop();
  
  TimeSpan time = stopwatch.Elapsed;
  long tick = stopwatch.ElapsedTicks;
  long milli = stopwatch.ElapsedMilliseconds; 
  ```

* Reset, Restart

  Reset은 시간을 0으로 되돌린다. Restart는 시간을 0으로 되돌리면서 시작한다.

  (Start는 Stop후에도 시간을 초기화하지 않고 시작한다.)

