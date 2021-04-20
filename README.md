# git7M3.0
启蒙上位机3.0版(多线程画图测试版)（账户：拆患 密码：1，该账号和密码兼容启蒙上位机的前几代版本）
<br>

![BJK_logo icon](https://github.com/bjk12/LittleBird_TypeExercise/blob/main/bjk1.ico)  
## 目录
* [概述](#概述)
  * [软件简介](#软件简介)
  * [版权说明](#版权说明)
* [使用说明](#使用说明)
  * [主界面](#主界面)
  * [登录界面](#登录界面)
  * [预约开启](#预约开启)
  * [重复发送](#重复发送)
  * [定时保存](#定时保存)
## 概述
### 软件简介
&#8195;&#8195;本软件的全称为“**启蒙上位机软件**”，意思是希望通过本软件能为单片机的初学者们提供一个功能完善的上位机，启发他们利用串口通信来进行发明与创新。
启蒙上位机软件采用面向对象的设计方法，利用 **C++编程语言** 和 **Qt Creator 4.5.1开发平台**进行设计编写。
本系统主要针对广大单片机初学者在完成串口通信的硬件连接之后找不到一款功能强大的上位机软件来实现串口调试与串口通信的问题，不仅实现了普通上位机所拥有的基本功能，
如**搜索串口**、**打开串口**、**选择串口**、**选择波特率**和**收发数据**等，还新增了一些能够减少用户工作量的高级功能，如**重复发送**、**定时保存**和**预约开启**等。  
&#8195;&#8195;在电脑和单片机之间建立了串口通信的硬件连接之后，用户可以通过本软件在电脑端对串口通信进行调试，调试内容包括却不仅限于搜索串口、调整波特率、选择串口、调整数据帧格式、发送数据并显示、接收数据并显示和将接收到的数据以文本文档的格式保存到电脑桌面处等，同时本软件还具有重复发送、定时保存和预约开启等高级功能。
<br>
&#8195;&#8195;**重复发送功能**是指用户可以使用键盘输入需要发送的数据（包括且不仅限于数字、字母和汉字等）和需要发送的次数，软件会自动将用户输入的数据按照用户预订的次数通过串口通信重复快速地发送给单片机；<br>
&#8195;&#8195;**定时保存功能**是指用户可以使用键盘输入设置每次保存的间隔时间，软件会按照用户设置的保存周期定时自动地将接收到的数据以文本文档的格式保存到电脑桌面处；<br>
&#8195;&#8195;**预约开启**是指用户可以使用键盘输入设置开启和关闭串口的时间，软件会在预设的开始时刻打开串口，会在预设的结束时刻关闭串口。<br>
&#8195;&#8195;这三种高级功能减少了用户调试串口时的工作量，使得电脑与单片机之间的串口通信在无人监管时仍可以安全运行。<br>

&#8195;&#8195;启蒙上位机3.0版在保留上述功能的基础上，又新增了 **隐藏接收** 和 **数据实时可视化** 的功能。<br>

**No picture,No truth:**<br>

3.0版截图：<br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image3v0.png" alt="pic4_readme"/></div><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image3v1.png" alt="pic4_readme"/></div><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image3v2.png" alt="pic4_readme"/></div><br>
1.0版截图：<br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image019.png" alt="pic4_readme"/></div>
<br>

### 版权说明
已申软著，请勿商用 (＃｀д´)ﾉ<br>
## 使用说明
&#8195;&#8195;**启蒙上位机软件主要包括五个界面：主界面、登录界面、定时保存界面、重复发送界面和预约开启界面。**<br>

&#8195;&#8195;**主界面**提供搜索串口、选择串口、调整波特率、调整数据帧格式、发送数据并显示、接收数据并显示、将接收到的数据以文本文档的格式保存到电脑桌面处和打开登录界面等功能，用户可以在主界面实现一般上位机能提供的串口通信的基本收发能力，但无法使用高级功能。<br>
&#8195;&#8195;如果用户想使用高级功能就必须输入**账号**（拆患）和**密码**（1），单击主界面的“更多功能”按钮进入登录界面，在输入正确的账号和密码后就可以获得使用本软件高级功能的特权。<br>
&#8195;&#8195;**登录界面**用来确认用户是普通用户还是有权使用本软件高级功能的特权用户，特权用户成功登录后就可以获得使用高级功能的权利。为了防止他人的误操作，特权用户每次使用完高级功能后需要重新输入账号和密码完成登录才能继续使用高级功能。<br>
&#8195;&#8195;**定时保存**界面通过不断查询电脑的系统时间，周期性地将接收到的数据以文本文档的格式保存至电脑桌面处，并以当前时间命名；<br>
&#8195;&#8195;**重复发送**界面为用户提供将预设数据（包括且不仅限于数字、汉字和字母）按照预设次数重复发送给单片机的功能；<br>
&#8195;&#8195;**预约开启**界面通过不断查询电脑的系统时间，在用户预设的开始时刻打开串口，在用户预设的结束时刻关闭串口。<br> 
### 主界面
&#8195;&#8195;双击快捷方式开启主界面。主界面包括“搜索串口”按钮、“打开串口”按钮、“清空接收区”按钮、“保存接收区”按钮、“发送数据”按钮、“更多功能”按钮、串口号选择框、波特率选择框、数据位选择框、奇偶校验位选择框、停止位选择框、流控制选择框、发送文本编辑框和接收文本编辑框。接下来本文将按照正常的使用顺序对以上组件的功能进行介绍。<br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image019.png" alt="pic4_readme"/></div><br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image020.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，进行串口通信的第一步就是按下“搜素串口”按钮，查询硬件连接是否已完成。在完成串口通信所需的硬件连接后双击电脑桌面处的启蒙上位机软件快捷方式打开本软件的主界面。由于此时还未完成搜索串口、配置数据格式、打开串口等操作，所以“发送数据”按钮处于禁用状态，即该按钮无法按下，只有完成以上所述操作后该按钮才被使能，允许按下。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image021.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;此时执行串口通信的第二步——配置数据格式。如上图所示，按下“搜素串口”按钮后，若硬件连接已完成就可以搜索到串口号并在串口号选择框中显示出来。依次点击串口号选择框、波特率选择框、数据位选择框、奇偶校验位选择框、停止位选择和流控制选择框，在其下拉选择框中选择与单片机串口通信相匹配的串口号、波特率、数据位数、奇偶校验模式、停止位数和流控制模式。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image022.png" alt="pic4_readme"/></div><br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image023.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;串口通信第三步——打开串口。如上图所示，按下“打开串口”按钮后，“打开串口”按钮变成“关闭串口”按钮，“发送数据”按钮被使能，允许用户按下，即允许进行串口通信。为了保证串口通信期间软件的安全运行，此时除“清空接收区”按钮、“保存接收区”按钮、“发送数据”按钮和“关闭串口”按钮外，其余按钮均被禁止按下。若点击“关闭串口”按钮，则“关闭串口”按钮变成“打开串口”按钮，停止串口通信，返回到打开串口前的状态。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image024.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，用户在发送文本编辑框中键盘输入想要发送的数据（这里以“1a鲍”为例）后，点击“发送数据”按钮就可以将数据串行传输到单片机中。这里为了方便调试本软件在串口通信时接收数据的功能，单片机会将接收到的数据再串行发送回电脑端，因此接收文本编辑框中会显示与发送数据相同的文本信息。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image026.png" alt="pic4_readme"/></div><br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image027.png" alt="pic4_readme"/></div><br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image028.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如以上三图所示，点击“保存接收区”按钮就可以将已接收的数据以文本文档的格式保存至电脑桌面处，同时弹出“温馨提示”消息框，提醒用户“接收区数据以文本文档格式保存在电脑桌面处”。该文件的命名格式为当前时间加“_uart.txt”（例如图3.2.9中的“10时32分32秒_uart.txt”）。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image029.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，为了防止接收文本编辑框接收数据过多导致溢出和方便用户查看，用户可以通过点击“清空接收区”按钮将接收文本编辑框内的数据清空。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image030.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，如果因为突发故障导致串口通信未完成硬件连接或未搜索到串口，此时试图点击“打开串口”按钮强行打开串口，软件就会弹出“温馨提示”消息框，提醒用户“无法打开串口，请重试。”<br><br>

### 登录界面
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image031.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，可以点击主界面的“更多功能”按钮，调出登录界面来申请使用本软件的三个高级功能。在未登录前三个高级功能按钮无法被按下，即只有能输入正确账号和对应密码才有权使用这三个高级功能。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image032.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，在输入正确账号和对应密码并点击“登录”按钮后，三个高级功能按钮（预约开启、重复发送和定时保存）允许被按下，同时软件弹出“温馨提示”消息框，提醒用户“身份确认，获得本软件高级功能使用权。” 为了防止他人的误操作，每次使用完高级功能后需要重新输入账号和密码完成登录才能继续使用高级功能。<br><br>

### 预约开启
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image033.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，在登录界面登录成功后点击“预约开启”按钮就可以调出预约开启界面。可在预约开启界面按照文字提示依次设置开始时刻，设置结束时刻，最后点击“确认”按钮开启预约功能，即本软件通过不断查询电脑的系统时间，在预设的开始时刻打开串口，在预设的结束时刻关闭串口。此时“中断”按钮被允许按下。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image034.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，用户在预约开启界面按照文字提示开启预约功能后，“确认”按钮被禁止按下，“中断”按钮被允许按下。如果用户需要终止预约开启功能，转为手动操作，则需要点击“中断”按钮，终止预约开启功能，再点击“退出”按钮即可退出预约开启界面。<br><br>

### 重复发送
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image035.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，用户在登录界面登录成功后点击“重复发送”按钮就可以调出重复发送界面。用户可在重复发送界面按照文字提示依次预设发送数据，预设重发次数，最后点击“确认”按钮开启重复发送功能，即本软件将用户预设的数据（包括且不仅限于数字、汉字和字母）按照用户预设的次数重复串行发送给单片机的功能。<br><br>

<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image036.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，重复发送完毕，用户可以点击“退出”按钮退出重复发送界面。<br><br>

### 定时保存
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image037.png" alt="pic4_readme"/></div><br>
<div align=center><img src="https://github.com/bjk12/git7M3.0/blob/main/pic4_readme/image038.png" alt="pic4_readme"/></div><br>
&#8195;&#8195;如上图所示，用户在登录界面登录成功后点击“定时保存”按钮就可以调出定时保存界面。用户可在定时保存界面按照文字提示预设保存周期，然后点击“开始”按钮开启定时保存功能，即本软件通过不断查询电脑的系统时间，周期性地将接收到的数据以文本文档的格式保存至电脑桌面处，并以当前时间命名的功能。此时“开始”按钮和“退出”按钮被禁止按下。如果用户需要终止定时保存功能，转为手动操作，则需要点击“停止”按钮，终止定时保存功能，同时“开始”按钮和“退出”按钮允许被按下。用户可以点击“退出”按钮退出定时保存界面。<br><br>

