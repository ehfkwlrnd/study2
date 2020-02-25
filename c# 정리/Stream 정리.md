# Stream 정리

* FileStream

  ```c#
  //READ
  
  using System.IO; //Stream
  using System.Text; //Encoding
  
  string path = @"C:test.txt";
  Stream stream = new FileStream(path, FileMode.Open);
  // FileMode : Open, Create, Append, CreateNew
  // FileMode반드시 지정해줘야 함
  
  int length = (int)stream.Length; //type long
  byte[] bytes = new byte[length];
  stream.Read(bytes, 0, length);
  string content = Encoding.Default.GetString(bytes); //bytes -> string
  ```

  ```c#
  //WRITE
  
  using System.IO;
  using System.Text;
  
  string path = @"C:test.txt";
  Stream stream = new FileStream(path, FileMode.CreateNew);
  //CreateNew : 파일이 존재하면 에러
  
  string content = "test";
  int length = content.Length;
  byte[] bytes = Encoding.Default.GetBytes(content); //string -> bytes
  stream.Write(bytes, 0, length);
  ```

* StreamReader

  ```c#
  using System.IO;
  
  string path = @"C:test.txt";
  StreamReader reader = new StreamReader(path, Encoding.Default);
  
  string line = reader.ReadLine(); //한 라인
  string content = reader.ReadToEnd(); //현재 커서에서 끝까지
  
  reader.Close();
  ```

* StreamWriter

  ```c#
  using System.IO;
  
  string path = @"C:test.txt";
  StreamWriter writer = new StreamWriter(path);
  
  string content = "test";
  writer.Write(content);
  writer.WriteLine(content);
  
  writer.Close();
  ```

* File

  ```c#
  using static System.IO.File;
  
  string path = @"c:test.txt";
  
  byte[] bytes = ReadAllBytes(path);
  string[] lines = ReadAllLines(path, Encoding.Default);
  string content = ReadAllText(path, Encoding.Default);
  ```

* Stream을 파일로 저장하는 쉬운 방법

  ```c#
  //아래의 result를 파일로 저장하는 것이 목적
  var client = new HttpClient();
  var result = client.GetAsync(url).Result.Content.ReadAsStreamAsync();
  
  //저장하는 코드
  var ms = new MemoryStream();
  result.CopyTo(ms);
  File.WriteAllBytes(path, ms.ToArray());
  ```

  



