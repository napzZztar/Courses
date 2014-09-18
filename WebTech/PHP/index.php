<?php
function tring1($x) {
	for($i=0;$i<$x;$i++){
		for($j=0; $j<$i; $j++){
			echo "*";
		}
		echo "<br/>";
	}
}

function tring2($x){
	for($i=0;$i<$x;$i++){
		for($j=0; $j<$x-$i; $j++){
			echo "&nbsp;";
		}
	
		for($j=0; $j<$i; $j++){
			echo "*";
		}
		echo "<br/>";
	}
}

function tring3($x){
	for($i=0;$i<$x;$i++){
		for($j=0; $j<$x-$i; $j++){
			echo "&nbsp;";
		}
	
		for($j=0; $j<$i; $j++){
			echo "**";
		}
		echo "<br/>";
	}
}

function tring4($x){
for($i=0;$i<$x;$i++){
	for($j=0; $j<$i; $j++){
		echo "&nbsp;";
	}
	
	for($j=0; $j<$x-$i; $j++){
		echo "**";
	}
	echo "<br/>";
}
}

?>


<pre>

<table width="960">
	<tr>
		<td>
			<?php tring1(10);?>
		</td>
		
		<td>
			<?php tring2(12);?>
		</td>
		
		<td>
			<?php tring3(10);?>
		</td>
		
		<td>
			<?php tring4(11);?>
		</td>
	</tr>
</table>

</pre>
