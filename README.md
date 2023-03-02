# The-Universe-Adventure
計算機圖學課程使用OpenGL實作的小遊戲。

## 開發環境和工具
OS：Windows 10  
IDE：Visual Studio 2015  
glut-3.7.6  

## 遊戲說明
最上方顯示：
- 生命(life)
- 時間(time)
- 分數(score)
- 遊玩的最高分數(Max)

按 g 或 G 按鍵開始遊戲，障礙物會不斷從上方往下，會有一條中線，只能在線段下方區塊做移動
- 玩家角色為青蛙，以 WSAD 做上下左右的移動  
- 當碰撞到地球 分數 +20
- 當碰撞到火星 生命 -1、分數 -15
- 當秒數歸零遊戲結束，或者生命為0，畫面會顯示得分(有負分)
- 按 h 或 H 可以回到首頁按 g 或 G則重新開始遊戲  

碰撞到的物體會消失，亂數決定X軸後移動到上面。  
![image](https://user-images.githubusercontent.com/86739086/221419627-2867680c-d024-4376-b7c6-e30a76c50d38.png)


## 聲明
本作品的圖片及內容皆為個人學習使用，無任何商業用途！


