<title>aedfc9ceBiswanathDasGupta</title>
<?php
    session_start();
    require_once "pdo.php";
    if (!isset($_SESSION['user_id']))
    {
        die('Not logged in');
    }

     if (!isset($_GET['profile_id']))
    {
        $_SESSION['error'] = "Missing profile_id";
        header("Location: index.php");
        return;
    }   
    
        if (isset($_POST['cancel']))
        {
            header("Location: index.php");
            return;
        }
        if (isset($_POST['profile_id']))
        {
            $stmt = $pdo->prepare("DELETE FROM profile WHERE profile_id=:p");
 $stmt->execute(array(':p'=>$_POST['profile_id']));
            $_SESSION['success'] = "Profile deleted";
            header("Location: index.php");
            return;
        }
$stmt = $pdo->prepare("SELECT first_name,last_name FROM profile WHERE profile_id=:pi");
$stmt->execute(array(':pi'=>$_GET['profile_id']));
        $row = $stmt->fetch(PDO::FETCH_ASSOC);
        if (!$row)
        {
            $_SESSION['error'] = "Could not load profile";
            header("Location: index.php");
            return ;
        }
    $fn = $row['first_name'];
    $ln = $row['last_name'];
    
?>
<h1>Deleting Profile</h1>
<p>First Name:<?=$fn?></p>
<p>Last Name:<?=$ln?></p><br/>
<form method = "POST">
<input type = "hidden" value = '<?=$_GET['profile_id']?>' name = 'profile_id'>
<input type = "submit" value = 'Delete' >
<input type = 'submit' value = "Cancel" name = 'cancel'>

