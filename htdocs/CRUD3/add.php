<title>497e696fBiswanathDasGupta</title>
<?php
    session_start();
    require_once"pdo.php";
    if (!isset($_SESSION['email']))
    {
        die("ACCESS DENIED");
    }
    if (isset($_POST['cancel']))
    {
        header("Location: index.php");
        return;
    } 
    if (isset($_POST['make'])&&isset($_POST['year'])&&isset($_POST['model'])&&isset($_POST['mileage']))
    {
        if (strlen($_POST['make'])<1||strlen($_POST['model'])<1||strlen($_POST['year'])<1||strlen($_POST['mileage'])<1)
        {
            $_SESSION['error']="All fields are required";
            header("Location: add.php");
            return;
        }
        else if (!is_numeric($_POST['year']))
        {
            $_SESSION['error'] = 'Year must be numeric';
            header("Location: add.php");
            return;
        }
        else if (!is_numeric($_POST['mileage']))
        {
            $_SESSION['error'] = 'Mileage must be numeric';
            header("Location: add.php");
            return;
        }
        else
        {
            $sql = "INSERT INTO autos (make,year,mileage,model) VALUES (:mk , :yr , :mi , :mod)";
            $stmt = $pdo->prepare($sql);
            $stmt->execute(array(
                ':mk' => $_POST['make'],
                ':yr' => $_POST['year'],
                ':mi' => $_POST['mileage'],
                ':mod' =>$_POST['model']
            ));
            $_SESSION['success'] = "Record added";
            header("Location: index.php");
            return;            
        }
        
    }
?>
<h2> Tracking Automobiles for <?= htmlentities($_SESSION['email'])?></h2>
<?php
    if (isset($_SESSION['error']))
    {
        echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>";
        unset($_SESSION['error']);
    }
?>
<form method = 'POST'>
<label for='mk'>Make: </label>
<input type = "text" id = 'mk' name = 'make'><br/><br/>
<label for='md'> Model:</label>
<input type = "text" id = 'md' name = 'model'><br/><br/>
<label for='yr'> Year:</label>
<input type = "text" id = 'yr' name = 'year'><br/><br/>
<label for='mil'>Mileage:</label>
<input type = "text" id = 'mil' name = 'mileage'><br/><br/>
<input type = 'submit' value = 'Add' >
<input type = 'submit' value = 'Cancel' name = 'cancel'>
