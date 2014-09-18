<?php
    session_start();
    
    $fName  = $_SESSION['fName'];
    $mName  = $_SESSION['mName'];
    $lName  = $_SESSION['lName'];
    $aId    = $_SESSION['aId'];
    $email  = $_SESSION['email'];
    $pass   = $_SESSION['pass'];
    $gend   = $_SESSION['gend'];

?>

<html>
<head>
    <title>Show Info</title>
</head>

<body>
    <table border="0">
        <tr>
            <td height="50" width="50"></td>
            <th></th>
            <td></td>
        </tr>
        <tr>
            <td width="50"></td>
            <th bgcolor="#DCDCDC" align="right"> Name : </th>
            <td><?php echo "$fName $mName $lName"?></td>
        </tr>
        <tr>
            <td width="50"></td>
            <th bgcolor="#DCDCDC" align="right"> AIUB ID : </th>
            <td><?=$aId?></td>
        </tr>
        <tr>
            <td width="50"></td>
            <th bgcolor="#DCDCDC" align="right"> Password : </th>
            <td><?=$pass?></td>
        </tr>
        <tr>
            <td width="50"></td>
            <th bgcolor="#DCDCDC" align="right"> Gender : </th>
            <td><?php
                if($gend == 1)
                    echo "Male";
                else
                    echo "Female";
            ?></td>
        </tr>
    </table>
</body>
</html>
