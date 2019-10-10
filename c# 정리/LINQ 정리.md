# LINQ 정리

* LINQ(Language-INtergrated Query) 소개

  ```c#
  /* C# 언어에 자연스럽게 섞여서 데이터 처리 과정을 용이하게 함.
   * 메모리에 있는 Object, XML파일, DBMS에 대해 LINQ를 통해 질의를 처리하고
   * 그 결과를 .NET Object 형태로 전환하여 프로그램 내부에서 간편하게 사용함.
   *
   * 예를들어 
   * c# LINQ 구문
   * from c in db.Users
   * where uname = "lee"
   * select c.userid
   * 는 
   * SQL
   * "SELECT userid
   *  FROM Users
   *  WHERE uname = 'lee'"
   * 로 변환되어 처리된다.
   */
  ```

* Query 문법

  ```c#
  //select
  var qry = (from user in users
  		   select user);
  
  //select : field
  var qry = (from user in users
  		   select user.Name);
  
  //select : 익명 object
  var qry = (from user in users
  		   select new {Name = user.Name, Age = user.Age});
  
  //where
  var qry = (from user in users
  		   where user.Age > 19
             && user.Age < 30
             select user);
  
  //orderby
  var qry = (from user in users
             orderby user.Age descending
             select user);
  
  //groupby
  var qry = (from user in users
  		   group user by user.Age into age_grp
  		   orderby age_grp.Key descending
             select new {Age = age_grp.Key, Count = age_grp.Count()});
  
  /*
  join을 들어가기 전에 데이터 가정..
  
  users = [
  	{Name = "Hail", Team = "A"},
  	{Name = "Saerom", Team = "B"}
  ]
  teams = [
  	{Name = "A", Profit = 1000},
  	{Name = "A", Profit = 500}
  ]
  이라 하자
  */
  //inner join
  var qry = (from user in users
  		   join team in teams on user.Team equals team.Name
  		   select new { Name = user.Name, Profit = Team.Profit});
  /*
  [
  	{Name = "Hail", Profit = 1000},
  	{Name = "Hail", Profit = 500}
  ]
  */

  //group join
  var qry = (from user in users
  		   join team in teams on user.Team equals team.Name into grpTeam
  		   select new { Name = user.Name, Count = grpTeam.Count()});
  /*
  [
  	{Name = "Hail", Count = 2},
  	{Name = "Saerom", Count = 0}
  ]
  */
  
  //left outer join
  var qry = (from user in users
  		   join team in teams on user.Team equals team.Name into grpTeam
  		   from item in grpTeam.DefaultIfEmpty(
                 new Team(){Name = "null", Profit = 0})
             select new {Name = user.Name, Profit = item.Profit});
  /*
  [
  	{Name = "Hail", Profit = 1000},
  	{Name = "Hail", Profit = 500},
  	{Name = "Saerom", Profit = 0}
  ]
  */
  ```
  
* Method 문법
  
  ```c#
  //Select
  var qry = users.Select(user => user.Name);
  
  //Where
  var qry = users.Where(user => user.Age > 19);
  
  //OrderBy
  var qry = users.OrderBy(user => user.Age); 
  //리턴값이 키가 되고, 키가 오름차순이 되도록 정렬함.
  //만약 키값이 정수일 때, 내림차순이 되도록 정렬하고 싶다면 아래와 같이 하면 된다.
  var qry = users.OrderBy(user => -user.Age);
  //일반적으로는 Reverse를 사용하면 된다.
  var qry = users.OrderBy(user => user.Name).Reverse();
  //규칙이 없는 커스텀 순서를 정하고 싶다면 다음과 같이 코드를 작성 할 수 있다.
  string[] customOrder = {"Messi", "Fogbar", "Henry"};
  var qry = users.OrderBy(user => Array.IndexOf(customOrder, user.Name));
  //Comparer를 생성하여 비교할 수도 있다.
  var qry = users.OrderBy(user => user.Age, 
  			Comparer<int>.Create((x, y) => x < y ? 1 : x == y? 0 : -1));
  //위 코드는 Age에 대해 내림차순으로 정렬한다.
  
  //GroupBy
  var qry = users.GroupBy(user => user.Age).Select(grp => grp.Key);
  
  //Distinct
  var qry = users.Distinct();
  
  //Reverse
  var qry = users.Reverse();
  
  //Skip
  var qry  = users.Skip(n);
  
  //Take
  var qry = users.Take(n);
  
  //요소 연산자
  qry.ElementAt(n); //n번째 요소
  qry.First(); //첫 번째 요소
  ```
  
* 실행 시기

  ```c#
  //지연 실행
  var qry = (from user in users
  		   select user);
  //바로 질의를 수행하지 않는다.
  
  //이 때 질의를 수행한다.
  foreach(var item in qry){
      /*...*/
  }
  
  //즉시 실행
  var qry = (from user in users
  		   select user).ToList();
  
  //메소드 문법을 사용해도 지연 실행한다.
  var qry = users.Where(user.Age > 19); // 지연 실행된다.
  ```

  