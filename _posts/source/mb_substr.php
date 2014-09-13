<?php

/* $str = "面试成功"; */

/* //echo mb_internal_encoding(); */
/* echo mb_substr($str,1,2,'utf8'); */


function substr_utf8($str,$start,$length = null)
{
	return join("",array_slice(

		preg_split("//u",$str,-1,PREG_SPLIT_NO_EMPTY),$start,$length
	
	));

}

  $str = '中国人民银行';
  $chars = preg_split('//u', $str, -1, PREG_SPLIT_NO_EMPTY);
  print_r($chars);

  echo substr_utf8($str,2);
