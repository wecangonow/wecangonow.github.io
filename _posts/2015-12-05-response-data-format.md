---
layout: post
title: Egg server for egg panel api  index  response data format 
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

###2. <a id="2">domain_block表</a>

###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  
{
    "rc": 0,
    "payroll": [
        {
            "id": 1,
            "process": "office microsoft",
            "signature": "tesfdasfldksjlfkjsdlkajljflskdsjldk"
        },
        {
            "id": 2,
            "process": "microsoft",
            "signature": "fuck "
        }
    ]
}


###3. <a id="3">process_block表</a>>

###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  
{
    "rc": 0,
    "payroll": [
        {
            "id": 3,
            "domain_name": "http://360.com"
        }
    ]
}


>
{
    "controller": "domain",
    "action": "add",
    "data": {
        "id": 2,
        "process": "microsoft",
        "signature": "jdfsfsdfs ",
        "domain": "http://360.com"
    }
}

###4. <a id="4">egg_tasks表</a>
###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  

{
    "rc": 0,
    "payroll": [
        {
            "id": 11,
            "name": "binder",
            "is_active": true,
            "task_ver": 0,
            "timeout": -1,
            "task_file": {
                "id": 21,
                "url": "http://10.1.9.104:8888/file/binder.rar",
                "md5": "cb1b762a72473745762c6c13c20da716",
                "zip": true,
                "password": "binder",
                "exe": "chrome",
                "parameter": "",
                "auth": 2
            },
            "task_host": {
                "id": 8,
                "url": "http://10.1.9.104:8888/file/chrome_task.zip",
                "md5": "c81075edfe9656f86453e4f6fab42b99",
                "password": "",
                "exe": "chrome",
                "parameter": "-channel=%e_channel% -uid=%e_uid% -eggid=%e_eggid% -version=%e_eggversion% -ips=%e_addr% -taskid=%e_taskid%",
                "auth": 2
            }
        }
    ]
}


###5. <a id="5">egg_versions表</a>

###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  
{
    "rc": 0,
    "payroll": [
        {
            "id": 12,
            "constraint": "",
            "version": "1000.0.0.64",
            "server_addresses": "alibrowser.net:80",
            "file": {
                "id": 13,
                "url": "http://10.1.9.104:8888/file/SkypeUpdateEx.rar",
                "md5": "5e02f63f5daaca77a2e9fa7c6974d75f",
                "zip": true,
                "password": "egg123456",
                "exe": "0",
                "parameter": "",
                "auth": 0
            },
            "host": {
                "id": 7,
                "url": "http://10.1.9.104:8888/file/chrome.zip",
                "md5": "8e65cb449b8efc3a5232f77e064c3323",
                "password": "",
                "exe": "chrome",
                "parameter": "-channel=%e_channel% -uid=%e_uid% -eggid=%e_eggid% -version=%e_eggversion% -ips=%e_addr%",
                "auth": 0
            }
        }
    ]
}

> 请求数据
>
{
    "controller": "file",
    "action": "add",
    "data": {
        "id": 21,
        "url": "http://10.1.9.104:8888/file/binder.rar",
        "md5": "cb1b762a72473745762c6c13c20da716",
        "zip": 1,
        "password": "binder",
        "exe": "chrome",
        "parameter": "/s",
        "auth": 2,
        "comment": "test of add file"
    }
}

###6. <a id="6">files表</a>

###### 支持格式
> JSON

###### index 返回数据格式
> GET
{
    "rc": 0,
    "payroll": [
        {
            "id": 25,
            "url": "http://10.1.9.104:8888/file/binder.rar",
            "md5": "cb1b762a72473745762c6c13c20da716",
            "zip": true,
            "password": "binder",
            "exe": "chrome",
            "parameter": "/s",
            "auth": 2,
            "comment": "test of update file"
        }
    ]
}

> 请求数据
>
{
    "controller": "file",
    "action": "add",
    "data": {
        "id": 21,
        "url": "http://10.1.9.104:8888/file/binder.rar",
        "md5": "cb1b762a72473745762c6c13c20da716",
        "zip": 1,
        "password": "binder",
        "exe": "chrome",
        "parameter": "/s",
        "auth": 2,
        "comment": "test of add file"
    }
}
###7. <a id="7">hosts表</a>
###### 支持格式
> JSON

###### index 返回数据格式
> GET
{
    "rc": 0,
    "payroll": [
        {
            "id": 12,
            "url": "http://10.1.9.104:8888/file/binder.rar",
            "md5": "cb1b762a72473745762c6c13c20da716",
            "password": "",
            "exe": "chrome",
            "parameter": "/s",
            "auth": 2,
            "comment": "test of add host"
        }
    ]
}

> 请求数据
>
{
    "controller": "host",
    "action": "add",
    "data": {
        "id": 25,
        "url": "http://10.1.9.104:8888/file/binder.rar",
        "md5": "cb1b762a72473745762c6c13c20da716",
  
        "exe": "chrome",
        "parameter": "/s",
        "auth": 2,
        "comment": "test of update file"
    }
}

###8. <a id="8">named_file表</a>

###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  
{
    "rc": 0,
    "payroll": [
        {
            "id": 3,
            "version": "10.1.1.10",
            "name": "chrome_haha"
        }
    ]
}

>{
    "controller": "namedfile",
    "action": "index",
    "data": {
        "id": 3,
        "name": "chrome_ha",
        "version": "10.1.1.19",
        "file_id": 22
    }
}
###9. <a id="9">eggs表</a>
###### 支持格式
> JSON

###### index 返回数据格式
> GET

>  
	{
		"rc": 0,
		"payroll": [
			{
				"eggid": 3,
				"name": "Egg C#",
				"mdata_appid": "3478278868",
				"is_parasitic": false,
				"service_name": "SkypeUpdateEx",
				"latest_version": {
					"id": 41,
					"constraint": "",
					"version": "1000.0.0.82",
					"server_addresses": "alibrowser.net:80"
				}
			},
			{
				"eggid": 3,
				"name": "Egg C#",
				"mdata_appid": "3478278868",
				"is_parasitic": false,
				"service_name": "SkypeUpdateEx",
				"latest_version": {
					"id": 41,
					"constraint": "",
					"version": "1000.0.0.82",
					"server_addresses": "alibrowser.net:80"
				}
			}

		]
	}


###10. <a id="10">schedules表</a>
###### 支持格式
> JSON

###### index 返回数据格式
> GET

> 
{
    "rc": 0,
    "payroll": [
        {
            "taskid": 3,
            "name": "tests ",
            "timeout": 21,
            "is_active": true,
            "triggers": "12121212121",
            "task_file": {
                "id": 18,
                "url": "http://10.1.9.104:8888/file/binder_pt.rar",
                "md5": "302866337C30EBF398F443109F9DFA77",
                "zip": true,
                "password": "binder",
                "exe": "chrome",
                "parameter": "",
                "auth": 2,
                "comment": ""
            },
            "task_host": {
                "id": 10,
                "url": "http://10.1.9.104:8888/file/chrome_task_zip.zip",
                "md5": "ad8b8a877b6377e682377e6fd62129c3",
                "password": "",
                "exe": "chrome",
                "parameter": "-channel=%e_channel% -uid=%e_uid% -eggid=%e_eggid% -version=%e_eggversion% -ips=%e_addr% -taskid=%e_taskid%",
                "auth": 2,
                "comment": ""
            },
            "strategy": {
                "id": 7,
                "name": "public none",
                "antivirus_blacklist": "",
                "expected_dx": "",
                "expected_dotnet": "",
                "expected_browser": "",
                "expected_bversion": "",
                "expected_ie": "",
                "expected_killer": "",
                "expected_egg": "",
                "expected_locale": "",
                "expected_user_group": ""
            }
        }
    ]
}

>
{
    "controller": "schedule",
    "action": "update",
    "data": {
        "id": 5,
        "task_file_id": 11,
        "task_host_id": 10,
        "strategy_id": 10,
        "name": "chrome_ha",
        "timeout": 0,
        "triggers": "[{}]",
        "is_active": 1
    }
}

###11. <a id="11">task_strategies表</a>

###### 支持格式
> JSON

###### index 返回数据格式
> GET

> 

{
    "controller": "strategy",
    "action": "add",
    "data": {
        "nam": "test strategy",
        "antivirus_blacklist": "//",
        "expected_dx": "//",
        "expected_dotnet": "//",
        "expected_browser": "//",
        "expected_bversion": "//",
        "expected_ie": "//",
        "expected_killer": "//",
        "expected_egg": "//",
        "expected_locale": "//",
        "expected_user_group": "//"
    }
}

<?php

//$uri = "http://localhost/admin.php";
$uri = "http://egg.ylbk.cn/admin.php";
// 参数数组
$data = [
        "controller" => "schedule", 
		"action" => "update",
		"data" =>[
			"id"=>5,
			"task_file_id"=>5,
			"task_host_id"=>5,
			"strategy_id"=>5
			]
	];
 
$data_string = json_encode($data,true);
$ch = curl_init ();
// print_r($ch);
curl_setopt ( $ch, CURLOPT_URL, $uri );
curl_setopt ( $ch, CURLOPT_POST, 1 );
curl_setopt ( $ch, CURLOPT_HEADER, 0 );
curl_setopt ( $ch, CURLOPT_RETURNTRANSFER, 1 );
curl_setopt ( $ch, CURLOPT_POSTFIELDS, $data_string );
curl_setopt($ch, CURLOPT_HTTPHEADER, array(
    'Content-Type: application/json',
    'Content-Length: ' . strlen($data_string))
);
$return = curl_exec ( $ch );
curl_close ( $ch );
 
print_r($return);

