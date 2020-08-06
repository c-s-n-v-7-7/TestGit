<title>Biswanath DasGupta</title>
<?php
$salt = 'XyZzy12*_';
$stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1'; 
session_start();
if (isset($_POST['cancel']))
{
    header("Location: index.php");
    return;
}
     if (isset($_POST['email'])&&isset($_POST['pass']))
     {
            //unset($_SESSION['fail_to_login']);
            unset($_SESSION['name']);
            $check = hash('md5', $salt.$_POST['pass']);
            if (strlen($_POST['email'])<1||strlen($_POST['pass'])<1)   
                {
                    error_log("Login fail ".$_POST['email']." $check");
                    $_SESSION['fail_to_login']='Email and password requiered';
                    header("Location: login.php");
                    return;
                }
            else if (strpos($_POST['email'],'@')==false)
            {
                error_log("Login fail ".$_POST['email']." $check");
                $_SESSION['fail_to_login'] = "Email must have an at-sign (@) " ;
                header("Location: login.php");
                return;
            }
            else
            {
                $check = hash('md5',$salt.$_POST['pass']) ;
                if ($check!=$stored_hash)   
                {
                    error_log("Login fail ".$_POST['email']." $check");
                    $_SESSION['fail_to_login'] = "Incorrect Password";
                    header("Location: login.php");
                    return;
                }
                else
                {
                    error_log("Login success ".$_POST['email']);
                    $_SESSION['name']=$_POST['email'];
                    header("Location: view.php");
                    return;
                }
            }
     }
     /*if (!isset($_POST['name'])||!isset($_POST['password']))
     {
         $_SESSION['fail_to_login'] = "Username and password can't be empty";
            header("Location: login.php");
            return;
     }*/
?>

<html>
<h1>
Login Page
</h1>
<?php
    if (isset($_SESSION['fail_to_login']))
    {
       //echo("Waddup");
        echo ('<p style="color:red">'.htmlentities($_SESSION['fail_to_login']).'</p>');
        unset($_SESSION['fail_to_login']);
    }
?>
<form method = "POST">
<label for="mail">Email </label>
<input type = "text" id = 'mail' name = 'email'><br/><br/>
<label for="pw">Password </label>
<input type = "text" id = 'pw' name = 'pass'><br/><br/>
<input type = "submit" name = 'login' value = 'Log In'>
<input type = "submit" value='Cancel' name = 'cancel'>


