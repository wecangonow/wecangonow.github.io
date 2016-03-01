---
layout: post
title: egg server update
category: designpattern
---

## egg server 更新流程
1. 所有服务器停止nginx 
2. 从master分支pull最新代码
3. 如果config文件有修改,先更新config文件
4. 如果entity有更新: 清空缓存 =》 重新生成proxy文件(两台服务器都要做)
5. 如果db有更新结构：执行orm的update-schema(只要做一台即可)
6. 重启nginx

## Screens 

1. dynamo, 仅在egg4存在，自动调节dynamo各表的读写阈值
2. mdata，两台服务器都有，用来上报mdata事件
3. alq,只有egg4有，7日日志上传及归档，有两个分screen，分别负责上传和归档
4. atask，只有egg4有，监控活跃任务的成功率
