---
layout: post
title: Egg server for egg panel api 
category: datastructure
---

#目录

主要内容如下：

1. <a href="#1">counter表</a>
2. <a href="#2">domain_block表</a>
3. <a href="#3">eggs表</a>
4. <a href="#4">egg_tasks表</a>
5. <a href="#5">egg_versions表</a>
6. <a href="#6">files表</a>
7. <a href="#7">hosts表</a>
8. <a href="#8">named_file表</a>
9. <a href="#9">process_block</a>
10. <a href="#10">schedules</a>
11. <a href="#11">task_strategies</a>

###1. <a id='1'>counter表</a>  

**1. 更新counter**
###### 接口功能
> 获取制定项目的分类信息

###### URL
> [http://www.api.com/index.php](www.api.com/index.php)

###### 支持格式
> JSON

###### HTTP请求方式
> GET

###### 请求参数
> |参数|必选|类型|说明|
|:-----  |:-------|:-----|-----                               |
|name    |ture    |string|请求的项目名                          |
|type    |true    |int   |请求项目的类型。1：类型一；2：类型二 。|

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|company  |string | 所属公司名                      |
|category |string |所属类型                         |

###### 接口示例
> 地址：[http://www.api.com/index.php?name="可口可乐"&type=1](http://www.api.com/index.php?name="可口可乐"&type=1)
``` javascript
{
    "statue": 0,
            "company": "可口可乐",
                        "category": "饮料",
                                    } `
                                    ` `
###2. <a id="2">C语言链表的实现</a>

