<title>Biswanath DasGupta</title>
<?php
    require_once "pdo.php";
    
    session_start();
    if (!isset($_SESSION['name']))
        die("Not Logged in");
    else {
     
  echo ("<h1>Tracking data for ".htmlentities($_SESSION['name'])."</h1>");
  if (isset($_SESSION['success']))
  {
      echo ('<p style="color:green">').htmlentities($_SESSION['success']).('</p>');
      unset($_SESSION['success']);
  }
?>
<?php
    echo ("<h3>Automobile</h3>");
    $stmt = $pdo->query("SELECT year,make,mileage FROM autos");
    echo "<ul>" ;
    while( $row = $stmt->fetch(PDO::FETCH_ASSOC) ) { 
    echo ("<li>");
    echo(htmlentities($row['year']).' '.htmlentities($row['make']).'/'.htmlentities($row['mileage']) ) ;
    echo "</li>\n";
}
    echo "</ul>";
}
?>
<p><a href = "add.php">Add New</a>  |   <a href = "logout.php">Log out</a></p>
 


