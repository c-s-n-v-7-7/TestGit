<title>aedfc9ceBiswanathDasGupta</title>
<?php
session_start();
require_once "pdo.php";

    if (!isset($_SESSION['user_id']))
    {
        die("Not logged in");
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
        return ;
    }
    if (isset($_POST['first_name'])&&isset($_POST['last_name'])&&isset($_POST['email'])&&isset($_POST['headline'])&&isset($_POST['summary']))
    {
        //$_SESSION['error'] = "Compiling POST 1st";
    if ((strlen($_POST['first_name'])<1)||(strlen($_POST['last_name'])<1)||(strlen($_POST['email'])<1)||(strlen($_POST['headline'])<1)||(strlen($_POST['summary'])<1))
        {
            $_SESSION['error'] = "All fields are required";
            header("Location: edit.php?profile_id=".urlencode($_GET['profile_id']));
            return;
        }
    else if (!strpos($_POST['email'],'@'))
        {
            $_SESSION['error'] = 'Email must contain @ ';
            header("Location: edit.php?profile_id=".urlencode($_GET['profile_id']));
            return;
        }
    else
        {
            $sql = "UPDATE profile 
            SET first_name = :fn , last_name = :ln , email = :em , headline = :he , summary = :su
            WHERE profile_id = :p";
            $stmt = $pdo->prepare($sql);
            $stmt->execute(array(
            ':fn' => $_POST['first_name'],
            ':ln' => $_POST['last_name'],
            ':em' => $_POST['email'],
            ':he' => $_POST['headline'],
            ':su' => $_POST['summary'],
            ':p' => $_POST['profile_id']
        ));
        $_SESSION['success'] = "Profile Added";
        header("Location: index.php");
        return ;
        }
    }    
 /*$stmt = $pdo->prepare("UPDATE first_name,last_name,email,headline,Summary
                            ")*/
$stmt = $pdo->prepare("SELECT * FROM profile 
                            WHERE profile_id=:pi ");
    $stmt->execute(array(':pi'=>$_GET['profile_id']));
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
    if (!$row)
    {
        $_SESSION['error'] = "Could not load profile";
        header("Location: index.php");
        return;
    }
    $profile_id = htmlentities($row['profile_id']);
    $fn = htmlentities($row['first_name']);
    $ln = htmlentities($row['last_name']);    
    $ml = htmlentities($row['email']);
    $hl = htmlentities($row['headline']);
    $su = htmlentities($row['summary']);
    //$profile_id = htmlentities($row['profile_id']);
?>
<h2> Editing Profile</h2>
<?php
if (isset($_SESSION['error']))
    {
        echo ("<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>");
        unset($_SESSION['error']);
    }
?>
<form method = "POST">
<p>First Name:
<input type = 'text' value = "<?= $fn ?>" name= 'first_name'></p>
<p>Last Name:
<input type = 'text' value = '<?= $ln?>' name = 'last_name'></p>
<p>Email: 
<input type = 'text' value ='<?= $ml ?>'  name = 'email'></p>
<p> Headline:</p>
<input type = 'text' value = '<?= $hl ?>' name = 'headline'>
<input type = 'hidden' name = 'profile_id' value = "<?= $profile_id ?>" ><br/>
<p> Summary:<br/>
<textarea name="summary"><?= $su ?></textarea><br/>
<input type = 'submit' value = 'Save'>
<input type = 'submit' value = 'Cancel' name = 'cancel'>
</form>