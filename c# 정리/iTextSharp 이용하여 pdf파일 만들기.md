# iTextSharp 이용하여 pdf파일 만들기

* NuGet 패키지 관리

  > iTextSharp
  >
  > itextsharp.xmlworker 

* using

  ```c#
  using System.Text;
  using System.IO;
  using iTextSharp.text;
  using iTextSharp.text.pdf;
  using iTextSharp.tool.xml;
  ```

* 변수 예시값

  ```c#
  string html = @"
  <html>
  	<head></head>
  	<body>
  		<table>
  			<tr>
  				<td>name</td>
  				<td>age</td>
  			</tr>
  			<tr>
  				<td>hail</td>
  				<td>28</td>
  			</tr>
  		</table>
  	</body>
  </html>";
  string filePath = @"D:\Users\yuno\Desktop\Test\test.pdf";
  string cssPath = @"D:\Users\yuno\Desktop\Test\css\report.css";
  string fontPath = @"D:\Users\yuno\Desktop\Test\font\malgun.ttf";
  ```

* 구현

  ```c#
  Document document = new Document(PageSize.A4);
  FileStream file = new FileStream(filePath, FileMode.Create);
  PdfWriter pdfWriter = PdfWriter.GetInstance(document, file);
  
  MemoryStream inp = new MemoryStream(Encoding.UTF8.GetBytes(html));
  FileStream inCssFile = new FileStream(cssPath, FileMode.Open);
  
  //한글을 출력하려면 한글 폰트를 등록해줘야 한다.
  XMLWorkerFontProvider fontProvider = new XMLWorkerFontProvider(
      XMLWorkerFontProvider.DONTLOOKFORFONTS);
  fontProvider.Register(fontPath);
  
  document.Open();
  XMLWorkerHelper.GetInstance().ParseXHtml(pdfWriter, 
                                           document, 
                                           inp, 
                                           inCssFile, 
                                           Encoding.UTF8, 
                                           fontProvider);
  document.Close();
  ```
  
* .NET에서 Pdf전송할 경우

  ```c#
  public ActionResult PdfDownload()
  {
      Document document = new Document(PageSize.A4);
      MemoryStream output = new MemoryStream();
      PdfWriter pdfWriter = PdfWriter.GetInstance(document, output);
  
      MemoryStream inp = new MemoryStream(Encoding.UTF8.GetBytes(html));
      FileStream inCssFile = new FileStream(cssPath, FileMode.Open);
      
      XMLWorkerFontProvider fontProvider = new XMLWorkerFontProvider();
      fontProvider.Register(fontPath);
  
      document.Open();
      XMLWorkerHelper.GetInstance().ParseXHtml(pdfWriter,
                                               document,
                                               inp,
                                               inCssFile,
                                               Encoding.UTF8,
                                               fontProvider);
      document.Close();
  
      //브라우저에서 열고 싶으면 inline, 다운로드를 하려하면 attachment
      Response.AddHeader("Content-Disposition", "inline; filename=test.pdf");
      
      //File은 매개변수로 stream을 받을 수 있지만 왜인지 output을 매개변수로 받으면
      //데이터가 제대로 전송이 안됨, 따라서 output.ToArray()를 전송함
      return File(output.ToArray(), "application/pdf");
  }
  ```

  