# MiniSudokuCalc
这是一款简易的数独计算器，可以帮助用户快速计算出任何难度的数独题目。  

本软件使用回溯算法实现对数独题目的计算，界面基于Qt5.9.9开发，Setup文件夹中包含已经编译完成的Windows安装包，可以下载直接安装。  

### 软件介绍：  
- **算法简单**：  
>该软件基于回溯算法，可以通过动画效果观察整个回溯算法的实现过程，非常是适合辅助初学理解回溯算法使用。  
- **界面简洁**：   
>该软主界面仅为一个QTableWidget控件，简洁明了，操作简单。
- **代码简单**：  
>该软件主要文件仅200行左右代码，运行速度快，结果准确。
- **功能**：
>1. 计算功能：根据题目在计算器表格的对应位置输入数值，点击等号后即可获得答案，通过字体大小来区分题目数值与计算后的数值，字体较大的为原题目中的数字。
>2. 动画功能：勾选动画对话框后可有显示整个回溯算法的计算过程，为了便于观察，在每次刷新界面后，延时100ms，整个动画过程会比较慢，但是该软件支持在**运算过程中取消动画效果**。  
>3. 检测功能：在开始计算前会校验已输入的题目是否符合要求，同时此功能也可以用于检查计算结果是否正确。  
- **后续工作**：
> 在此基础之上，开发一款数独软件，实现不同难度的题目，记录答题时间，判断是否正确等。

***欢迎各位伙伴提出宝贵意见，共同开发！！！***
