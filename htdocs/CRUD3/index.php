
<title>497e696fBiswanathDasGupta</title>
<h2>Welcome to the Automobiles Database</h2>
<?php
    session_start();
    if (!isset($_SESSION['email']))
    {
        echo "<a href='login.php'>Please log in</a><br/><br/>";
    }
    if (isset($_SESSION['email']))
    {
    require_once "pdo.php";
    
    //$empty = "SELECT COUNT(*) FROM autos";
            if (isset($_SESSION['success'])){
                echo "<p style='color:green;'>".htmlentities($_SESSION['success'])."</p>";
                unset($_SESSION['success']);
            }
            if (isset($_SESSION['error'])){
                echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>";
                unset($_SESSION['error']);
            }
            //$sql = "SELECT COUNT(*) FROM autos ";
            //$emp = $pdo->prepare($sql);
            //$emp->execute();
            //if ($emp==false)    echo "No Records found";
    $stmt = $pdo->query("SELECT autos_id,make,year,model,mileage FROM autos");
    //$stmt->execute();
   // $emp = $pdo->query("SELECT ")
    //$row = $stmt->fetch(PDO::FETCH_ASSOC);
                    echo('<table border="1">'."\n");
                    while( $row = $stmt->fetch(PDO::FETCH_ASSOC) )
                    {
                        echo "<tr><td>";
                        echo (htmlentities($row['make']));
                        echo "</td><td>";
                        echo (htmlentities($row['year']));
                        echo "</td><td>";
                        echo (htmlentities($row['model']));
                        echo "</td><td>";
                        echo (htmlentities($row['mileage']));
                        echo "</td><td>";
                        echo ('<a href="edit.php?autos_id='.$row['autos_id'].'">Edit</a> /');
                        echo ('<a href="delete.php?autos_id='.$row['autos_id'].'">Delete</a>');
                        echo "</td></tr>";
                    }
                    echo"</table>";
   // if ($stmt->fetch(PDO::FETCH_ASSOC)==false)    echo"<p>No Records Found</p>";
                
                    //if ($row==false)    echo"<p>No Records Found</p>";
    }    
                echo "<a href='add.php'>Add New Entry</a><br/>";

   if (isset($_SESSION['email'])) {echo "<a href='logout.php'>Logout</a>";}   
?>        