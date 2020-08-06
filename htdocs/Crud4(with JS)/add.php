<title>aedfc9ceBiswanathDasGupta</title>

<?php
session_start();
require_once "pdo.php";
if (!isset($_SESSION['user_id']) )
    {
        die("Not logged in");
    }
    if (isset($_POST['cancel']))
    {
        header("Location: index.php");
        return ;
    }
echo "<h1>Adding Profile</h1>";
    if (isset($_SESSION['error']))
    {
            //header("Location: add.php");
    echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>";    
        unset($_SESSION['error']);
    }
if (isset($_POST['first_name'])&&isset($_POST['last_name'])&&isset($_POST['email'])&&isset($_POST['headline'])&&isset($_POST['summary']) )
{
if ( (strlen($_POST['first_name'])<1)||(strlen($_POST['last_name'])<1)||(strlen($_POST['email'])<1)||(strlen($_POST['headline'])<1)||(strlen($_POST['summary'])<1) )
        {
            $_SESSION['error'] = 'All values are required';
            header("Location: add.php");
            return;
        }
    if (!strpos($_POST['email'],'@'))
        {
            $_SESSION['error'] = "Email must have @ sign";
            header("Location: add.php");
            return;
        }
    $stmt = $pdo->prepare("INSERT INTO profile (user_id,first_name,last_name,email,headline,summary)
                           VALUES ( :ui, :fn, :ln, :em, :hl, :su )");
    $stmt->execute(array(
        ':ui' => $_SESSION['user_id'],
        ':fn' => $_POST['first_name'],
        ':ln' => $_POST['last_name'],
        ':em' => $_POST['email'],
        ':hl' => $_POST['headline'],
        ':su' => $_POST['summary']
    ));
    $_SESSION['success'] = "Record added";
    header("Location: index.php");
    return;
}   
?>
<form method = 'post'>
<label for = 'fn'>First Name: </label>
<input type = 'text' id = 'fn' name = 'first_name'><br/>
<label for = 'ln'>Last Name: </label>
<input type = 'text' id = 'lb' name = 'last_name'><br/>
<label for = 'mail'>Email: </label>
<input type = 'text' id = 'mail' name = 'email'><br/>
<label for = 'he'>Headline</label><br/>
<input type = 'tet' id = 'he' name = 'headline'><br/>
<p>Summary:</p>
<textarea name = 'summary'></textarea><br/>
<input type = 'submit' value = 'Add'>
<input type = 'submit' name = 'cancel' value = 'Cancel'>
