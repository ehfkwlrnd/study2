# Error 페이지 핸들링

* HomeController

  ```c#
  public ActionResult Error()
  {
      return View();
  }
  ```

* Global.asax.cs

  ```c#
  protected void Application_Error(object sender, EventArgs e)
  {
      Server.ClearError();
      //Error스택을 클리어
      
      var routeData = new RouteData();
      routeData.Values["controller"] = "Home";
      routeData.Values["action"] = "Error";
      // 루트 ~/Home/Error
      
      Response.TrySkipIisCustomErrors = true; 
      // If you are using IIS7, have this line
      
      var wrapper = new HttpContextWrapper(Context);
      var rc = new System.Web.Routing.RequestContext(wrapper, routeData);
      
      IController controller = new HomeController();
      controller.Execute(rc);
      
      Response.End();
  }
  ```

