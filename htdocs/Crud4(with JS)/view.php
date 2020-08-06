<title>aedfc9ceBiswanathDasGupta</title>
<?php
    session_start();
    require_once "pdo.php";
        if (!isset($_GET['profile_id']))
        {
            $_SESSION['error'] = 'Profile not found';
            header("Location: index.php");
            return;
        }
    $stmt = $pdo->prepare("SELECT first_name,last_name,email,headline,summary FROM profile WHERE profile_id=:pi");
    $stmt->execute(array(':pi'=>$_GET['profile_id']));
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
        if (!$row)
            {
                $_SESSION['error'] = 'Could not load profile';
                header("Location: index.php");
                return ;
            }
        $fn = $row['first_name'];
        $ln = $row['last_name'];
        $ml = $row['email'];
        $hl = $row['headline'];
        $sm =  $row['summary'];
?>
<h2> Profile Information</h2>
    <p>First Name: <?=$fn?></p>
    <p>Last Name: <?=$ln?></p>
    <p>Email: <?=$ml?></p>
    <p>Headline:</p><p><?=$hl?></p>
    <p>Summary</p><p><?=$sm?></p>

<a href = "index.php" >Done</a>