<?php

function maximum($a,$b,$c)
{
	return $a > $b ? ($a > $c ? $a : $c) : ($b > $c ? $b : $c);
}


echo maximum(34,45,99);
echo maximum(84,45,59);
