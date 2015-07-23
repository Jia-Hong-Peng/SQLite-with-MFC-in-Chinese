# SQLite-with-MFC-in-Chinese
MFC SQLite 不會中文亂碼

SQLite3  是用 C 語言編寫的開源數據庫，可移植性好，容易非常簡單，而且及其輕便。

但是 各種中文亂碼
![](http://i.imgur.com/iTHJh2K.png)

使用後
![](http://i.imgur.com/6I7Q3ef.png)

## Build sqlite.lib ##

官網上只有源代碼和dll文件下載，這裡記錄由源代碼導出的lib庫文件步驟。

從 [SQLite3官網](http://www.sqlite.org/download.html)  下載 sqlite-amalgamation-xxxx.zip。解壓縮後得到sqlite3.c 、sqlite3.h2個文件。 

打開vs2010 ，檔案-> 新增專案 -> Visual C++ -> Win32 -> Win32 專案，項目名稱輸入sqlite，點擊下一步，
![](http://i.imgur.com/KUNO8nz.png)

應用程序類型選擇"靜態程式庫"，
![](http://i.imgur.com/gHtuTHX.png)


網路上寫取消“預編譯頭”，不過我沒取消也能build


將sqlite3.c，sqlite3.h兩個文件複製到這個專案目錄下，在項目中將這兩個文件加到對應的Header和Source裡，直接build，然後在Debug下就可以得到sqlite3.lib。

我Build的自取： https://github.com/jhpeng/sqlite

## 使用 SQLite_Wrapper ##
- 從 [SQLite3官網](http://www.sqlite.org/download.html) 下載的 SourceCode 取出SQLite3.h，及自己編譯好的 SQLite.lib
- 從 [SQLite_Wrapper](http://www.codeproject.com/Articles/20094/An-Easy-to-Use-Wrapper-for-SQLite-Totally-Free-Em) 下載取得 SQLite.cpp和SQLite.h。
- 搞定了。


## 參考文獻 ##
- http://www.codeproject.com/Articles/20094/An-Easy-to-Use-Wrapper-for-SQLite-Totally-Free-Em
- http://code.qtuba.com/article-16119.html
- http://www.sqlite.org/download.html
- http://blog.csdn.net/sunnyloves/article/details/39010831
