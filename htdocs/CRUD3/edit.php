<title>497e696fBiswanathDasGupta</title>

<?php
    session_start();
    require_once "pdo.php";
        if (!isset($_GET['autos_id']))
        {
            $_SESSION['error'] = "Bad value for id";
            header("Location: index.php");
            return;
        }
        if (isset($_POST['cancel']))
        {
            header("Location: index.php");
            return;
        }
    if (isset($_POST['make'])&&isset($_POST['model'])&&isset($_POST['year'])&&isset($_POST['mileage']))
       
    {
        if (strlen($_POST['make'])<1||strlen($_POST['model'])<1||strlen($_POST['year'])<1||strlen($_POST['mileage'])<1)
        {
            $_SESSION['error']="All fields are required";
            header("Location: edit.php?autos_id=".urlencode($_GET['autos_id']));
            return;
        }
        else if (!is_numeric($_POST['year']))
        {
            $_SESSION['error'] = 'Year must be numeric';
            header("Location: edit.php?autos_id=".urlencode($_GET['autos_id']));
            return;
        }
        else if (!is_numeric($_POST['mileage']))
        {
            $_SESSION['error'] = 'Mileage must be numeric';
            header("Location: edit.php?autos_id=".urlencode($_GET['autos_id']));
            return;
        }
        else
        {
            $sql = " UPDATE autos
            SET make = :mk , year = :yr , model = :mo , mileage = :mi
            WHERE autos_id = :ai";
            $stmt = $pdo->prepare($sql);
            $stmt->execute(array(
                ':mk' => $_POST['make'],
                ':yr' => $_POST['year'],
                ':mo' => $_POST['model'],
                ':mi' => $_POST['mileage'],
                ':ai' => $_POST['autos_id']
            ));
            $_SESSION['success'] = "Record updated";
            header("Location: index.php");
            return;
        }
    }
//        UPDATE make,model,year,mileage FROM autos
 //       SET make = :mk , year = :yr , model = :md , mileage = :ml;
$sql = "SELECT * FROM autos
        WHERE autos_id=:ai";
        $stmt = $pdo->prepare($sql);
        $stmt->execute(array(':ai'=>$_GET['autos_id']));
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            if ($row==false)
            {
                $_SESSION['error'] = "Bad value for id";
                header("Location: Index.php");
                return;
            }
            $mk = htmlentities($row['make']);
            $mo = htmlentities($row['model']);
            $yr = htmlentities($row['year']);
            $mi = htmlentities($row['mileage']);
            $autos_id = htmlentities($row['autos_id']);
?>
<h2>Editing Automobile</h2>
<?php
    if (isset($_SESSION['error']))
    {
        echo "<p style='color:red;'>".htmlentities($_SESSION['error'])."</p>" ;
        unset($_SESSION['error']);

    }
?>
<form method = "post">
<p>Make:
<input type = "text" name = 'make' value ="<?= $mk ?>"></p>
<p>Model:
<input type = "text" name = 'model' value ="<?= $mo ?>"></p>
<p>Year:
<input type = "text" name = 'year' value ="<?= $yr ?>"></p>
<p>Mileage:
<input type = "text" name = 'mileage' value ="<?= $mi ?>"></p>
<input type = "hidden" name = 'autos_id' value ="<?= $autos_id ?>">
<input type = "submit" value = "Save">
<input type = "submit" value = "Cancel" name = 'cancel'>
</form>