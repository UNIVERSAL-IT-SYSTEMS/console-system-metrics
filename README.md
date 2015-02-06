# console-system-metrics

About
---
Windowsプラットフォームで下記の環境設定を読み書きするためのコマンドライン・プログラムです。

* ダブルクリックの間隔時間
* ダブルクリックの許容範囲（幅と高さ）

[SystemParametersInfo](https://msdn.microsoft.com/ja-jp/library/cc429946.aspx)

[GetSystemMetrics](https://msdn.microsoft.com/ja-jp/library/cc429812.aspx)

[GetDoubleClickTime](https://msdn.microsoft.com/ja-jp/library/cc364628.aspx)

Example
---
```
使用方法: system-metrics [options]
 -w 数値: ダブルクリック位置の許容範囲の幅をピクセル単位で設定します。
 -h 数値: ダブルクリック位置の許容範囲の高さをピクセル単位で設定します。
 -i 数値: ダブルクリック時間をミリ秒で設定します。
 -I : 現在の設定値を表示します。
 ```
