<title>101ca20bBiswanathDasGupta</title>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.2.1.js" integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE=" crossorigin="anonymous"></script>
<h1> Please Log In</h1><br/>
<?php
$salt = 'XyZzy12*_';
//$stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1';
    session_start();
    require_once "pdo.php";
    if (isset($_POST['cancel']))
    {
        header("Location: index.php");
        return;
    }
    if (isset($_POST['email'])&&isset($_POST['pass']))
    {
        $check = hash('md5',$salt.$_POST['pass']);
    $stmt = $pdo->prepare('SELECT user_id,name FROM users
                           WHERE email =:em AND password = :pw');
    $stmt->execute(array('em'=>$_POST['email'],'pw'=>$check));
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($row!==false)
        {
            $_SESSION['name'] = $row['name'];
            $_SESSION['user_id'] = $row['user_id'];
           // $_SESSION['success'] = "Succesfully logged in to".htmlentities($_SESSION['user_id'])."";
            header("Location: index.php");
            return;
        }
        $_SESSION['error'] = "Incorrect Password";
        header("Location: login.php");
        return;
    }
    if (isset($_SESSION['error']))
    {
        echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>";
        unset($_SESSION['error']);
    }
?>

<form method = 'POST'>
<label for = 'ml'>Email </label>
<input type = 'text' id = 'ml' name = 'email'><br/><br/>
<label for = 'pws'>Password </lablel>
<input type = 'password' id = 'pws' name = 'pass'><br/><br/>
<input type = 'submit' onclick ="return doValidate();"value = 'Log In'>
<input type = 'submit' value = 'Cancel' name = 'cancel'>
</form> 
<script>
function doValidate() {
    console.log('Validating...');
    try {
        addr = document.getElementById('ml').value;
        pw = document.getElementById('pws').value;
        console.log("Validating addr="+addr+" pw="+pw);
        if (addr == null || addr == "" || pw == null || pw == "") {
            alert("Both fields must be filled out");
            return false;
        }
        if ( addr.indexOf('@') == -1 ) {
            alert("Invalid email address");
            return false;
        }
        return true;
    } catch(e) {
        return false;
    }
    return false;
}
</script>