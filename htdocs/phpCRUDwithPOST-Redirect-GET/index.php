<title>Biswanath DasGupta</title>
<?php  
    require_once "pdo.php";
session_start();
    unset($_SESSION['name']);
    $stmt = $pdo->prepare("DELETE FROM autos");
    $stmt->execute();
?>
<html>
<title>c7b3204eBiswanathDasgupta-Index</title>
<body>
<h1>Welcome to Autos Database</h1>
<a href = "login.php"> Please Log In</a>
<br>
<p><a href= "view.php">View</a></p>
<p><a href="add.php">Add</a></p>
</body>
</html>