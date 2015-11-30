---
layout: post
title: Egg server for egg panel api 
category: datastructure
---

#目录

主要内容如下：

1. <a href="#1">counter表</a>
2. <a href="#2">domain_block表</a>
3. <a href="#3">process_block</a>
4. <a href="#4">egg_tasks表</a>
5. <a href="#5">egg_versions表</a>
6. <a href="#6">files表</a>
7. <a href="#7">hosts表</a>
8. <a href="#8">named_file表</a>
9. <a href="#9">eggs表</a>
10. <a href="#10">schedules</a>
11. <a href="#11">task_strategies</a>

###1. <a id='1'>counter表</a>  

###### 接口功能 更新counter 

###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |counter |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |counter_for_process (boolean) or counter_for_domain (boolean)      |        |

#####  request example 
> 
	{
		'controller' : 'counter',
		'action'     : 'update',
		'data'       : {
				'counter_for_domain' : true  // counter_for_domain 与counter_for_process 二者仅需要一个且必须有一个
				'counter_for_process' : true
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |


#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'ok'
	}

###2. <a id="2">domain_block表</a>

######2.1 接口功能  添加域名黑名单


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |domain |
   | action     | true     | string      |      |add  |
   | data       | true     | object      |domain(string)   |        |

#####  request example 
> 
	{
		'controller' : 'domain',
		'action'     : 'add',
		'data'       : {
				'domain' : 'domain_name'  // www.baidu.com
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add domain ok'
	}

######2.2 接口功能  更新域名黑名单

###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |domain |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |id (int)   |        |

#####  request example 
> 
	{
		'controller' : 'domain',
		'action'     : 'update',
		'data'       : {
				'id' : 11 // id for record
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update domain ok'
	}

######2.3 接口功能  删除域名黑名单


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |domain |
   | action     | true     | string      |      |delete  |
   | data       | true     | object      |id (int)   |   |

#####  request example 
> 
	{
		'controller' : 'domain',
		'action'     : 'delete',
		'data'       : {
				'id' : 11 // id for record
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

######2.4 接口功能  获取域名黑名单记录


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |domain |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |空   |   |

#####  request example 
> 
	{
		'controller' : 'domain',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

###3. <a id="3">process_block表</a>

######3.1 接口功能  添加进程黑名单


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |process |
   | action     | true     | string      |      |add  |
   | data       | true     | object      |process(string) signature(string)   |        |

#####  request example 
> 
	{
		'controller' : 'process',
		'action'     : 'add',
		'data'       : {
				'process' : 'process'  
				'signature' : 'signature' 
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add process ok'
	}

######3.2 接口功能  更新进程黑名单


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |process |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |id (int)   |        |

#####  request example 
> 
	{
		'controller' : 'process',
		'action'     : 'update',
		'data'       : {
				'id' : 11 // id for record
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update domain ok'
	}

######3.3 接口功能  删除进程黑名单


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |process |
   | action     | true     | string      |      |delete  |
   | data       | true     | object      |id (int)   |   |

#####  request example 
> 
	{
		'controller' : 'process',
		'action'     : 'delete',
		'data'       : {
				'id' : 11 // id for record
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

######3.4 接口功能  获取进程黑名单记录


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |domain |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |空   |   |

#####  request example 
> 
	{
		'controller' : 'process',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

###4. <a id="4">egg_tasks表</a>

######4.1 接口功能  添加egg 任务


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |task |
   | action     | true     | string      |      |add  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'task',
		'action'     : 'add',
		'data'       : {
				'task_file_id' : int,
				'task_host_id' : int,
				'strategy_id'  : int,
				'is_activer'   : boolean, // 1 or 0 
				'task_ver'     : int ,
				'timeout'      : int,
				'name'         : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add task ok'
	}

######4.2 接口功能  更新egg任务


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |task |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'task',
		'action'     : 'update',
		'data'       : {
				'id'           : int,
				'task_file_id' : int,
				'task_host_id' : int,
				'strategy_id'  : int,
				'is_activer'   : boolean, // 1 or 0 
				'task_ver'     : int ,
				'timeout'      : int,
				'name'         : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update task ok'
	}

######4.3 接口功能  停用egg 任务


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |task |
   | action     | true     | string      |      |stop  |
   | data       | true     | object      |id (int)   |   |

#####  request example 
> 
	{
		'controller' : 'task',
		'action'     : 'stop',
		'data'       : {
				'id' : 11 // id for task
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

######4.4 接口功能  启动egg任务


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |task |
   | action     | true     | string      |      |start  |
   | data       | true     | object      |id(int)   |   |

#####  request example 
> 
	{
		'controller' : 'task',
		'action'     : 'start',
		'data'       : {
			'id' : 11 // id of task
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

######4.5 接口功能  egg任务列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |task |
   | action     | true     | string      |      |start  |
   | data       | true     | object      |id(int)   |   |

#####  request example 
> 
	{
		'controller' : 'task',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |> }}}
|data	  |object | 响应数据                      |

###5. <a id="5">egg_versions表</a>

######5.1 接口功能  添加egg 版本


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |version |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'version',
		'action'     : 'add',
		'data'       : {
				'file_id'          : int,
				'host_id'          : int,
				'egg_id'           : int,
				'constraint'       : string,
				'version'          : string,
				'server_addresses' : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add version ok'
	}

######5.2 接口功能  更新egg version


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |version |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'version',
		'action'     : 'update',
		'data'       : {
				'id'               : int,
				'file_id'          : int,
				'host_id'          : int,
				'egg_id'           : int,
				'constraint'       : string,
				'version'          : string,
				'server_addresses' : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update version ok'
	}

######5.3 接口功能  egg version 列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |version |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'version',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |


###6. <a id="6">files表</a>

######6.1 接口功能  添加file


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |file |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'file',
		'action'     : 'add',
		'data'       : {
				'url'       : string,
				'md5'       : string,
				'zip'       : boolean, // 1 or 0
				'password'  : string,
				'exe'       : string,
				'parameter' : string,
				'auth'      : smallint,
				'comment'   : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add file ok',
		'data'   : {}
	}

######6.2 接口功能  更新file


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |file |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'file',
		'action'     : 'update',
		'data'       : {
				'id'               : int,
				'url'       : string,
				'md5'       : string,
				'zip'       : boolean, // 1 or 0
				'password'  : string,
				'exe'       : string,
				'parameter' : string,
				'auth'      : smallint,
				'comment'   : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update version ok',
		'data'   : {}
	}

######6.3 接口功能  file 列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |file |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'file',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

###7. <a id="7">hosts表</a>

######7.1 接口功能  添加host


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |host |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'host',
		'action'     : 'add',
		'data'       : {
				'url'       : string,
				'md5'       : string,
				'password'  : string,
				'exe'       : string,
				'parameter' : string,
				'auth'      : smallint,
				'comment'   : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add host ok',
		'data'   : {}
	}

######7.2 接口功能  更新host


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |host |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'host',
		'action'     : 'update',
		'data'       : {
				'id'               : int,
				'url'       : string,
				'md5'       : string,
				'password'  : string,
				'exe'       : string,
				'parameter' : string,
				'auth'      : smallint,
				'comment'   : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update host ok',
		'data'   : {}
	}

######7.3 接口功能  host 列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |host |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'host',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

###8. <a id="8">named_file表</a>

######8.1 接口功能  添加named_file


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |namedfile |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'namedfile',
		'action'     : 'add',
		'data'       : {
				'file_id' : int,
				'version' : string,
				'name'    : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add named file ok',
		'data'   : {}
	}

######7.2 接口功能  更新named file


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |namedfile |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'namedfile',
		'action'     : 'update',
		'data'       : {
				'id'      : int,
				'file_id' : int,
				'name'    : string,
				'version' : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update host ok',
		'data'   : {}
	}

######7.3 接口功能  named file 列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |namedfile |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'namedfile',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

###9. <a id="9">eggs表</a>

######9.1 接口功能  添加eggs


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |egg |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'egg',
		'action'     : 'add',
		'data'       : {
				'egg_id'            : int,
				'latest_version_id' : int,
				'name'              : string,
				'mdata_appid'       : bigint,
				'is_parasitic'      : tinyint,
				'service_name'      : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add egg ok',
		'data'   : {}
	}

######9.2 接口功能  更新egg


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |egg |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'egg',
		'action'     : 'update',
		'data'       : {
				'egg_id'            : int,
				'latest_version_id' : int,
				'name'              : string,
				'mdata_appid'       : bigint,
				'is_parasitic'      : tinyint,
				'service_name'      : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update egg ok',
		'data'   : {}
	}

######9.3 接口功能  egg列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |egg |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'egg',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

###10. <a id="10">schedules表</a>

######10.1 接口功能  添加schedules


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |schedule |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'schedule',
		'action'     : 'add',
		'data'       : {
				'task_file_id' : int,
				'task_host_id' : int,
				'strategy_id'  : int,
				'name'         : string,
				'timeout'      : int,
				'is_active'    : tinyint,
				'triggers'     : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add schedule ok',
		'data'   : {}
	}

######10.2 接口功能  更新schedule


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |schedule |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'schedule',
		'action'     : 'update',
		'data'       : {
				'taskid'       : int,
				'task_file_id' : int,
				'task_host_id' : int,
				'strategy_id'  : int,
				'name'         : string,
				'timeout'      : int,
				'is_active'    : tinyint,
				'triggers'     : string
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update schedule ok',
		'data'   : {}
	}

######10.3 接口功能  schedule列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |schedule |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'schedule',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

###11. <a id="11">task_strategies表</a>

######11.1 接口功能  添加task_strategies


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |strategy |
   | action     | true     | string      |      |add     |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'strategy',
		'action'     : 'add',
		'data'       : {
				'name'                : string,
				'antivirus_blacklist' : string,
				'expected_dx'         : string,
				'expected_dotnet'     : string,
				'expected_browser'    : string,
				'expected_bversion'   : string,
				'expected_ie'         : string,
				'expected_killer'     : string,
				'expected_egg'        : string,
				'expected_locale'     : string,
				'expected_user_group' : string,
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'add strategy ok',
		'data'   : {}
	}

######11.2 接口功能  更新strategy


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |strategy |
   | action     | true     | string      |      |update  |
   | data       | true     | object      |      |        |

#####  request example 
> 
	{
		'controller' : 'schedule',
		'action'     : 'update',
		'data'       : {
				'id'                  : int,
				'name'                : string,
				'antivirus_blacklist' : string,
				'expected_dx'         : string,
				'expected_dotnet'     : string,
				'expected_browser'    : string,
				'expected_bversion'   : string,
				'expected_ie'         : string,
				'expected_killer'     : string,
				'expected_egg'        : string,
				'expected_locale'     : string,
				'expected_user_group' : string,
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应信息                      |

#####  response example 
> 
	{
		'status' : 0,
		'msg'    : 'update strategy ok',
		'data'   : {}
	}

######11.3 接口功能  strategy列表


###### 支持格式
> JSON

###### HTTP请求方式
> POST

###### 请求参数
>  | 参数       | 必选     | 类型        | 说明 | 值 |
   | :-----     | :------- | :---------- |
   | controller | true     | string      |      |strategy |
   | action     | true     | string      |      |index  |
   | data       | true     | object      |      |   |

#####  request example 
> 
	{
		'controller' : 'strategy',
		'action'     : 'index',
		'data'       : {
		}
	}

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|msg	  |string | 响应信息                      |
|data	  |object | 响应数据                      |

