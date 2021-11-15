# 1.0``CLS_ShareSDK``

CLS_ShareSDK 是大学长平台开发的用户iOS端视频共享的SDK, 是配合大学长云直播SDK的插件SDK, 该SDK需要依靠第三方的支持: YYModel, AgoraRtcEngine_iOS(v 3.4.7), AFNetworking.

SDK现支持iOS 11.0版本以上系统.

使用方式
+ Pod仓引用

```
pod 'CloudLVB-ScreenShare-SDK-IOS'

```

## 1.0.1``Overview``

CLS_ShareSDK 是录制共享iOS端手机桌面的SDK

## 1.0.2``Methods``

|     方法     |       功能                              |
|       :----       |       :----                                   |
|   sharedInstance  |   CLS_ShareSDK 的初始化方法                  |
| joinRTCWithUserId:AuthToken:AuthToken:RoomNumber:CompletedHandler: | 加入到对应的RTC房间, 需要共享者的平台ID, 流推送的房间ID, 共享者的Auth_Token, 与在平台申请的App_Key |
|   startBroadcast  | 当加入房间成功后,  可以调用该方法付, 通知SDK可以开始直播了. |
|  sendVideoBuffer: | 在App的方法中回调中, 调用该方法上传视频的Buffer数据. |
| sendAudioAppBuffer: | 在App的方法中回调中, 调用该方法上传针当前打开的App的音频Buffer数据. |
| sendAudioMicBuffer: | 在App的方法中回调中, 调用该方法上传当前麦克风的音频Buffer数据. |
|   stopBroadcast   | 当需要结束或App已经结束时,  调用该方法通知SDK结束当前直播. |

## 关键字

由于共享组件与主App之间是跨进程的, 所以在SDK中设定一些跨进程通信的一些通知的关键字, 使用这些关键字的通知, 可以跟SDK内部进行交流, 同时SDK也使用这些关键字与App间通信, 用于状态交流.

|  通知名  | 描述 |
|         :----          |     :----    |
| notification_beigin_indentify | SDK将发送该名称的通知, 告诉响应者SDK当前已经开始直播. |
| notification_stop_indentify | SDK将发送该名称的通知, 告诉响应者SDK当前已停止直播. |
| notification_need_close_indentify | SDK会监听该名称的通知, 如果需要在某一时刻让直播结束, App可以发送该消息, SDK在接到通知后, 启动关闭直播的操作. 成功后发送notification_stop_indentify通知,  告知响应者. |
