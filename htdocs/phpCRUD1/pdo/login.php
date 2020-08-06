<?php
$failure = false ;
$salt = 'XyZzy12*_';
$stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1'; 
if (isset($_POST['cancel']) ) 
{
    header("Location: index.php");
    return;
}    
if ( isset($_POST['who']) && isset($_POST['pass']) ) {
    $check = hash('md5', $salt.$_POST['pass']);
    if ( strlen($_POST['who']) < 1 || strlen($_POST['pass']) < 1 ) {
        error_log("Login fail ".$_POST['who']." $check");
        $failure = "User name and password are required";
    }
    else if ( strpos($_POST['who'],'@') == false )
        {
            error_log("Login fail ".$_POST['who']." $check");
            $failure = "Email must have an at-sign (@)";
        }
    else {
        
        
        if ( $check == $stored_hash ) {
            // Redirect the browser to game.php
            error_log("Login success ".$_POST['who']);
            $failure = false;
            header("Location: autos.php?name=".urlencode($_POST['who']));
            return;
        } else {
            error_log("Login fail".$_POST['pass']." $check") ;
            $failure = "Incorrect password";
        }
    }
}
?>

<html>
<title>c7b3204eBiswanathDasgupta-Login</title>
<body>
<h1>Please Log In</h1>
<br/>
<?php
    if ($failure!==false)
    echo('<p style="color: red;">'.htmlentities($failure)."</p>\n");
?>
<br/>
<form method='post'>
<lablel for = 'nam' ><b>Username </label>
<input type = 'text' id = 'nam' name = 'who'><br/><br/>
<label for = 'pw'>Password </lablel>
<input type= 'text' id='pw' name = 'pass'><br/><br/>
<input type="submit" value="Log In">
<input type="submit" name="cancel" value="Cancel">
</form>
</body>
</html>