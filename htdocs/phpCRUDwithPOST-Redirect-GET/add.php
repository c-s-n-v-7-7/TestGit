<title>Biswanath DasGupta</title>
<?php 
require_once "pdo.php";
 session_start();
if (isset($_POST['cancel']))
{
    header("Location: view.php");
    return;
}
if (!isset($_SESSION['name']))
{
    die("Not logged in");
}
if (isset($_POST['make'])&&isset($_POST['year'])&&isset($_POST['mileage']))
    {
        unset($_SESSION['failure']) ; unset($_SESSION['success']); 
        if (!is_numeric($_POST['mileage'])||!is_numeric($_POST['year']))
            {
                $_SESSION['failure'] = "Mileage and Year should be numeric";
                header("Location: add.php");
                return;
            }
        else if (strlen($_POST['make'])<1)
            {
                $_SESSION['failure'] = "Make is required";
                header("Location: add.php");
                return;
            }
        else
        {
            $_SESSION['success'] = "Record inserted";
            $stmt = $pdo->prepare("INSERT INTO autos (make,year,mileage)
            VALUES (:mk , :yr , :mi )"); 
                $stmt->execute(array(
                    ':mk' => $_POST['make'],
                    ':yr' => $_POST['year'],
                    ':mi' => $_POST['mileage']
                ));
        header("Location: view.php");
        return;
        }
    }
    
echo "<h1>Tracking Autos for ".$_SESSION['name']."</h1>";
        if (isset($_SESSION['failure']))
        {
            echo '<p style="color:red;">'.htmlentities($_SESSION['failure'])."</p>";
            unset($_SESSION['failure']) ;
        }
?>
<html>
<body>
<form method='POST'>
<label for = 'mak'>Make: </label>
<input type= 'text' id = 'mak' name='make'><br/><br/>
<label for = 'yr'>Year:</label>
<input type = 'text' id = 'yr' name = 'year'><br/><br/>
<label for = 'mil'>Mileage: </label>
<input type = 'text' id = 'mil' name = 'mileage'><br/><br/>
<input type = 'submit' value = 'Add'>
<input type = 'submit' value = 'Cancel' name = 'cancel'> 
</form>
</body>
</html>