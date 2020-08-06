<title>497e696fBiswanathDasGupta</title>
<?php
    session_start();
    $salt = 'XyZzy12*_';
    $stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1';
    if (isset($_POST['email'])&&isset($_POST['pass']) )
    {
        unset($_SESSION['fail']);
        if (strlen($_POST['email'])<1||strlen($_POST['pass'])<1)
        {
            $_SESSION['fail'] = "User name and password are required";
            header("Location: login.php");
            return;
        }
        $check = hash('md5',$salt.$_POST['pass']);
        if ($check!=$stored_hash)
        {
            $_SESSION['fail'] = "Incorrect password";
            header("Location: login.php");
            return;
        }
        else
        {
            $_SESSION['email'] = $_POST['email'];
            header("Location: index.php");
            return;
        }
    }

?>

<html>
<title>BiswanathDasGupta</title>
<h2>Please Log In</h2><br/><br/>
<?php
    if (isset($_SESSION['fail']))
    {
        echo '<p style="color:red;">'.htmlentities($_SESSION['fail']).'</p>';
        unset($_SESSION['fail']);
    }
?>
<form method="POST">
<label for = 'un'><b>Username</b></label>
<input type='text' id = 'un' name = 'email'><br/><br/>
<label for = 'pass'><b>Password</b></label>
<input type ='password' id = 'pass' name = 'pass'><br/><br/>
<input type = 'submit' name = 'login' value = 'Log In'>
</form>
<p>         <a href = "index.php">Cancel</a></p>
</html>