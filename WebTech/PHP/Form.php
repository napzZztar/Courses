<html>
<head>
    <title>Form Varification</title>
</head>

<?php
if(isset($_POST["fSubmit"])){
    $error  = 0;
    $fName  = trim($_POST["fName"]);
    $mName  = trim($_POST["mName"]);
    $lName  = trim($_POST["lName"]);
    $aId    = trim($_POST["aId"]);
    $email  = trim($_POST["email"]);
    $pass   = $_POST["pass"];
    $rePass = $_POST["rePass"];

    //====================
    //If array has any numbers
    //====================
    function hasNumber($arr){
        for ($i = 0; $i < strlen($arr); $i++) {
            if(is_numeric($arr[$i]))
                return TRUE;
        }
    }
    
    //====================
    //Check Gend
    //====================
    if(isset($_POST["gend"])) {
        $gend = $_POST["gend"];
        if($gend == "1")
            $mCheck = "Checked";
        else
            $fCheck = "Checked";
    } else
        $err['gend'] = "<div style='color:FF0000'>&#171; <font size='2'><i>Please select your gender</i></font></div>";

    //====================
    //Check First Name
    //====================
    if ($fName == "") 
        $err['fName']= "<div style='color:FF0000'>&#171; <font size='2'> <i>First name can't be empty</i> </font></div>";
    else if(hasNumber($fName))
        $err['fName']= "<div style='color:FF0000'>&#171; <font size='2'> <i>Your name can't contain any number(s)</i> </font></div>";

    //====================
    //Check Middle Name
    //====================
    if(hasNumber($mName))
        $err['mName']= "<div style='color:FF0000'>&#171; <font size='2'> <i>Your name can't contain any number(s)</i> </font></div>";

    //====================
    //Check Last Name
    //====================
    if ($lName == "") 
        $err['lName']= "<div style='color:FF0000'>&#171; <font size='2'><i>Last name can't be empty</i></font></div>";
    else if(hasNumber($lName))
        $err['lName']= "<div style='color:FF0000'>&#171; <font size='2'> <i>Your name can't contain any number(s)</i> </font></div>";

    //====================
    //Check AIUB ID
    //====================
    if($aId == ""){
        $err['aId'] = "<div style='color:FF0000'>&#171; <font size='2'><i>ID can't be empty</i></font></div>";
    }else{
        for ($i = 0; $i < strlen($aId); $i++) {
            if($i == 2 || $i == 8){
                if($aId[$i] != '-')
                    $err['aId'] = "<div style='color:FF0000'>&#171; <font size='2'><i>Your ID must be in XX-XXXXX-X format</i></font></div>";
            }else if (!is_numeric($aId[$i])) {
                $err['aId'] = "<div style='color:FF0000'>&#171; <font size='2'><i>Your ID can't contain any character</i></font></div>";
                break;
            }else if ($i>9) {
                $err['aId'] = "<div style='color:FF0000'>&#171; <font size='2'><i>Length of the id must be 10 character</i></font></div>";
                break;
            }
        }
    }

    //====================
    //Check E-mail
    //====================

    if ($email == ""){  
        $err['emal'] = "<div style='color:FF0000'>&#171; <font size='2'><i>Please your valid e-mail address</i></font></div>";
    } else{
        $posDot = 0;
        $posAt = 0;
        $countAt =0;

        for ($i = 0; $i < strlen($email); $i++) {
            if($email[$i] == '@'){
                $posAt = $i;
                $countAt++;
            }else if ($email[$i] == '.') {
                $posDot = $i;
            }
        }

        if($countAt != 1 || $posDot-2 <= $posAt) 
            $err['emal'] = "<div style='color:FF0000'>&#171; <font size='2'><i>You have entered an invalid e-mail address</i></font></div>";

    }

    //====================
    //Check Password
    //====================

    if($pass == "")
        $err["pass"] = "<div style='color:FF0000'>&#171; <font size='2'><i>Please enter a password</i></font></div>";
    else if (strlen($pass) <7) {
        $err["pass"] = "<div style='color:FF0000'>&#171; <font size='2'><i>Your password can't be less than 8 character</i></font></div>";
    }else{
        $cc = 0;
        $nc = 0;

        for ($i = 0; $i < strlen($pass); $i++) {
            if(is_numeric($pass[$i]))
                $nc++;
            else
                $cc++;
        }

        if($nc<1 || $cc < 1)
            $err["pass"] = "<div style='color:FF0000'>&#171; <font size='2'><i>Your password must contain atleast one number and one charracter</i></font></div>";
    }

    //====================
    //Check Re-Password
    //====================

    if($pass != $rePass)
            $err["rePass"] = "<div style='color:FF0000'>&#171; <font size='2'><i>Doesn't match with the password</i></font></div>";

    if(!isset($err)){
        session_start();

        $_SESSION['fName'] = $fName;
        $_SESSION['mName'] = $mName;
        $_SESSION['lName'] = $lName;
        $_SESSION['aId']   = $aId;
        $_SESSION['email'] = $email;
        $_SESSION['pass']  = $pass;
        $_SESSION['gend']  = $gend;
        header("Location: Show.php");
    }
}
?>

<body>
    <form name="input" action="Form.php" method="post">
        <table border="0">
            <tr>
                <td width="50" height="50"></td>
                <th></th>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td width="50"></td>
                <th align="Right">First Name :</th>
                <td><input type="text" name="fName" id="" value="<?=@$fName?>" /></td>
                <td><div> <?=@$err['fName']?> </div></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Middle Name :</th>
                <td><input type="text" name="mName" id="" value="<?=@$mName?>" /></td>
                <td><?=@$err['mName']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Last Name :</th>
                <td><input type="text" name="lName" id="" value="<?=@$lName?>" /></td>
                <td><?=@$err['lName']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Aiub ID :</th>
                <td><input type="text" name="aId" id="" value="<?=@$aId?>" /></td>
                <td><?=@$err['aId']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">E-mali :</th>
                <td><input type="text" name="email" id="" value="<?=@$email?>" /></td>
                <td><?=@$err['emal']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Password :</th>
                <td><input type="password" name="pass" id="" value="" /></td>
                <td><?=@$err['pass']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Re-enter Password :</th>
                <td><input type="password" name="rePass" id="" value="" /></td>
                <td><?=@$err['rePass']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right">Gender</th>
                <td>
                <input type="radio" name="gend" id="" value="1" <?=@$mCheck?>/>Male
                    <input type="radio" name="gend" id="" value="2" <?=@$fCheck?>/>Female
                </td>
                <td><?=@$err['gend']?></td>
            </tr>

            <tr>
                <td width="50"></td>
                <th align="Right"></th>
                <td><input type="submit" name="fSubmit" id="" value="submit" /></td>
                <td></td>
            </tr>

        </table>
    </form>

</body>
</html>
