<?php
    require_once "pdo.php";
    $failure_in_autos = false ;
    $success_in_autos = false ;
    if (isset($_POST['logout']))
    {
        header("Location: index.php");
        return; 
    }
    if (!isset($_GET['name']))
    {
        die("Name parameter missing");
    }
    
    if (isset($_POST['make']) && isset($_POST['year']) && isset($_POST['mileage']))
    {
        if (!is_numeric($_POST['year'])||!is_numeric($_POST['mileage']))
            $failure_in_autos = "Mileage and year must be numeric";
        else
        {
            $success_in_autos = "Record inserted";
            $stmt = $pdo->prepare('INSERT INTO autos
                 (make, year, mileage) VALUES ( :mk, :yr, :mi)');
                $stmt->execute(array(
                ':mk' => $_POST['make'],
                ':yr' => $_POST['year'],
                ':mi' => $_POST['mileage']));
        }
       // var_dump($smtm);
    }
?>

<html>
<title>c7b3204eBiswanathDasgupta-Autos</title>
<body>
<?php 
echo "<h1>Tracking Autos for ".htmlentities($_GET['name'])."</h1>" ;
if ($failure_in_autos!==false)   
echo('<p style="color: red;">'.htmlentities($failure_in_autos)."</p>\n");
if($success_in_autos!==false)
echo('<p style="color:green;">'.htmlentities($success_in_autos)."</p>\n") ;
?>

<form method = "POST" >
<label for ='mak'>Make: </label>
<input type = 'text' id = 'mak' name = 'make'><br/><br/>
<label for ='yr'>Year: </label>
<input type = 'text' id = 'yr' name = 'year'><br/><br/>
<label for = 'mil'>Mileage: </label>
<input type = 'number' id = 'mil' name='mileage'><br/><br/>
<input type = 'submit' value = 'Add'>
<input type = 'submit' value = 'Logout' name='logout'>  
</form>
<?php
    echo ("<h2>Automobile</h2>");
    $stmt = $pdo->query("SELECT year,make,mileage FROM autos");
    echo "<ul>" ;
    while( $row = $stmt->fetch(PDO::FETCH_ASSOC) ) { 
    echo ("<li>");
    echo(htmlentities($row['year']).' '.htmlentities($row['make']).'/'.htmlentities($row['mileage']) ) ;
    echo "</li>\n";
}
    echo "</ul>"
?>
</body>
</html>