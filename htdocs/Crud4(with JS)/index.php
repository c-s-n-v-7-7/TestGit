<title>aedfc9ceBiswanathDasGupta</title>
<h1>Biswanath DasGupta's Resume Registry</h1><br/>
<?php
    session_start();
    require_once "pdo.php";
    if (isset($_SESSION['success'])){
        echo "<p style='color:green;'>".htmlentities($_SESSION['success'])."</p>";
        unset($_SESSION['success']);
    }
    if (isset($_SESSION['error'])){
        echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>";
        unset($_SESSION['error']);
    }
    if (!isset($_SESSION['name']))
    echo "<a href='login.php'>Please log in</a><br/>";
    else
    echo "<a href = 'logout.php'>Log out</a><br/>";
    $sql = "SELECT profile_id,first_name,last_name,headline FROM profile";
    $stmt = $pdo->query($sql);
    echo('<table border="1">'."\n");
    
    while( $row = $stmt->fetch(PDO::FETCH_ASSOC) )
    {
        echo "<tr><td>";
        echo ('<a href = "view.php?profile_id='.$row['profile_id'].'">'.htmlentities($row['first_name']).' '.htmlentities($row['last_name']).'</a>');
        echo "</td><td>";
        echo ( htmlentities($row['headline']));
        echo "</td>";
        if (isset($_SESSION['user_id']))
        {
            echo "<td>";
            echo ('<a href="edit.php?profile_id='.$row['profile_id'].'">Edit</a>  ');
            echo ('<a href="delete.php?profile_id='.$row['profile_id'].'">Delete</a>');
            echo("</td>");
        }
        //echo (htmlentities($row['model']));
        //echo "</td><td>";
        //echo (htmlentities($row['mileage']));
        
        echo ("</tr>");
    }
    echo"</table>";
     if (isset($_SESSION['user_id']))
    echo"<a href = 'add.php'>Add New Entry</a><br/>";
?>