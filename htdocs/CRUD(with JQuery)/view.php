<title>101ca20bBiswanathDasGupta</title>
<head><link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.2.1.js" integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE=" crossorigin="anonymous"></script>
</head>
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

<?php
    $stmt = $pdo->prepare("SELECT year,description FROM position WHERE profile_id = :pi ORDER BY rank DESC ");
    $stmt->execute(array(':pi'=>$_GET['profile_id']));
    
    echo ("<p>Positions :</p><br/><ul>");
    while($row = $stmt->fetch(PDO::FETCH_ASSOC))
    {
        echo("<li>".$row['year']." : ".$row['description']."</li>");
    }
        //Secho ("<\ul>");
    echo("<p> <a href =\"index.php\">Done</a></p>");
?>
