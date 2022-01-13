# YouTube_Download(final project)
>* TeamMember:魏美亞、傅于軒
>* 所有程式及UI介面都是原創作品

## 專案說明
* 我們製作一個YouTube的下載器

---

### 專案系統
* 目前功能:能夠透過網址下載YouTube影片到指定資料夾中

---

### 專案執行模式:
1. 首先美亞創造了一個[NubletZ/PyTubeC-](https://github.com/NubletZ/PyTubeC-)的repositories

2. 接下來，我fork美亞所創造的專案[FUYUHSUAN/PyTubeC-](https://github.com/FUYUHSUAN/PyTubeC-?organization=FUYUHSUAN&organization=FUYUHSUAN)，並且在我自己所fork的專案在vscode上來git clone https://github.com/FUYUHSUAN/PyTubeC-.git

3. 我們會用line來溝通甚麼時候誰做甚麼，以此來避免兩邊程式衝突

4. 接下來美亞會`git push`及`git pull` 來進行程式的撰寫

5. 而我則會需要當美亞`git pull` 之後進行`git fetch upstream`或是`git fetch + 原始我fork的網址`來進行即是更新

6. 當我製作完專案後我需要進行測試，然後將專案git push 上去，接下去給個pull request給美亞

7. 當美亞先測試完之後，就會將專案進行merge

8. 我們的專案便以此為模式進行數輪

---

### 工作分配

* 魏美亞: 
    * python引入C#
    * 設計UI介面
    * 並且進行測試python引入C#之測試
    * 進行單元及group測試
    * ppt整體流程的掌握及設計
* 傅于軒: 
    * 進行python套件pytube引入
    * 撰寫讀取檔案，並且下載youtube到想存取之資料夾功能
    * 進行套件及，後面所寫的程式進行測試
    * 進行單元及group測試
    * ppt內部流程圖，圖片製作


    ![](picture/workflow.jpg)

## 設計流程:
* 此為我們設計之專案流程這是我們git flow的圖形
    ![](picture/git_flow.jpg)

## 測試:
* 目前我們主要都是進行後端的程式進行測試，至於需要使用前端部分，我們都會將其寫到一開始的函式並進行後端測試


* 以下是我們進行後端程式的寫入開始的部分程式
    * 這三個是可進行單元測試的部分
    * 上層資料夾這是可進行部分測試

    * 單元測試

    ![](picture/unit1.PNG)
    * 群組測試

    ![](picture/group.PNG)

    ![](picture/test.jpg)
    ```C#
    public static void startPy()
    {
        Installer.InstallPath = Path.GetFullPath("."); //to declare workdir
        Debug.WriteLine($"Working directory : {Path.GetFullPath(".")}");
        Installer.SetupPython();
        string curPath = Directory.GetCurrentDirectory();
        PythonEngine.PythonPath = @$"{curPath}\python-3.7.3-embed-amd64\python37.zip;{curPath}\python-3.7.3-embed-amd64;{curPath}\python-3.7.3-embed-amd64\Lib\site-packages;{curPath}\python-3.7.3-embed-amd64\Lib\site-packages\numpy\core";
        PythonEngine.Initialize();
        if (Installer.IsPipInstalled()) Debug.WriteLine("Pip has been installed :)");
        pyInit = PythonEngine.IsInitialized;

        pytube = PythonEngine.ImportModule("pytube");
        recordpath = Directory.GetCurrentDirectory();
        string tmp = "https://www.youtube.com/watch?v=sHD_z90ZKV0";
        pytube.__main__.YouTube(tmp).streams.get_highest_resolution().download(recordpath);
    }
    ```

* 接下來是寫測試:
    * 這邊的每個程式可以進行Unit測試
    * 並且測試完後，進行Group測試
    ```C#
    [TestMethod()]
    public void MainWindowTest()
    {
        MainWindow.startPy();
        using (var sw = new StringWriter())
        {
            Console.SetOut(sw);
            MainWindow.pyVersion();

            var resVer = sw.ToString().Trim();
            StringAssert.Contains(resVer, "3.7.3");
        }

        bool resInit = MainWindow.pyInit;
        Assert.IsTrue(resInit);
    }

    PyObject dummy;
    [TestMethod()]
    public void libraryTest()
    {
        MainWindow.startPy();
        Assert.IsNotNull(MainWindow.pytube);
    }

    [TestMethod()]
    public void videoTest()
    {
        string filepath = $"{MainWindow.recordpath}/周杰倫 Jay Chou【稻香 Rice Field】-Official Music Video.mp4";
        Assert.IsTrue(File.Exists(filepath), "The video have not been downloaded yet!");
    }
    ```   

---     

## 前端介面
* 主要是輸入URL_link然後選擇想要放的檔案中，將下載的YouTube影片放到指定資料夾
![](picture/flow.jpg)
![](picture/youtube.jpg)

---

## 執行結果
* 執行前
![](picture/empty.jpg)
* 執行後
![](picture/have.jpg)




