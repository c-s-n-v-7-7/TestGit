<title497e696f>BiswanathDasGupta</title>
<?php
    require "pdo.php";
    session_start();
    if (!isset($_GET['autos_id']))
    {
        $_SESSION['error'] = "Bad value for id";
        header("Location: index.php");
        return;
    }

    if (isset($_POST['delete'])&&isset($_POST['autos_id']))
    {
        $sql = "DELETE FROM autos WHERE autos_id = :ai";
        $stmt = $pdo->prepare($sql);
        $stmt->execute(array(':ai'=>$_POST['autos_id']));
        $_SESSION['success'] = "Record deleted";
        header("Location: index.php");
        return;
    }

$sql = "SELECT * FROM autos WHERE autos_id=:ai";
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
            $autos_id = htmlentities($row['autos_id']);

?>
<p>Confirm: Deleting <?= $mk ?>
<form method = "POST">
<input type = "submit" value = "Delete" name = "delete"><br\>
<input type = "hidden" name = "autos_id" value = "<?= $autos_id?>">
<a href = "index.php">Cancel</a>

