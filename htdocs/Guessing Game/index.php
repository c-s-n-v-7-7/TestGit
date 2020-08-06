<html>
<title>Biswanath Dasgupta1cb9a2cd</title>
<body>
<h1>Welcome to my Guessing Game</h1>


<p>
<?php
    if ( !isset($_GET['guess']) )           echo('Missing guess parameter');
    elseif ( strlen($_GET['guess'] ) < 1 )  echo('Your guess is too short');
    elseif ( !is_numeric($_GET['guess']) )  echo('Your guess is not a number');
    elseif ( $_GET['guess'] < 22 )          echo('Your guess is too low');
    elseif ( $_GET['guess'] > 22 )          echo('Your guess is too high');
    else    echo('Congratulations - You are righ') ;
?>
</p>
</body>
</html>