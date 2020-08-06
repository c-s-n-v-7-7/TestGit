<title>101ca20bBiswanathDasGupta</title>
<head><link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.2.1.js" integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE=" crossorigin="anonymous"></script>
</head>

<?php
require_once "pdo.php";
require_once "util.php";
session_start();

//Displaying Errors and stuff-----------------------------------------------------------------------------------------------------------------------------------------
if (!isset($_SESSION['user_id']))
    die("Not logged in");
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Validation after POST --------------------------------------------------------------------------------------------------------------------------------------------------
if (isset($_POST['cancel']))
{
    header("Location: index.php");
    return; 
}

if (isset($_POST['first_name'])&&isset($_POST['last_name'])&&isset($_POST['email'])&&isset($_POST['headline'])&&isset($_POST['summary']) )
{
            $e = validateProfile();
            if (is_string($e))
            {
                $_SESSION['error'] = $e ;
                header("Location: add.php");
                return;
            }

                $z = validatePos();
                if (is_string($z))
                {
                    $_SESSION['error'] = $z ;
                    header("Location: add.php");
                    return;
                }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//After Validation ---------------------------------------------------------------------------------------------------------------------------------------------------------
$stmt = $pdo->prepare('INSERT INTO Profile (user_id, first_name, last_name, email, headline, summary) VALUES ( :uid, :fn, :ln, :em, :he, :su)');

$stmt->execute(array(
  ':uid' => $_SESSION['user_id'],
  ':fn' => $_POST['first_name'],
  ':ln' => $_POST['last_name'],
  ':em' => $_POST['email'],
  ':he' => $_POST['headline'],
  ':su' => $_POST['summary'])
);

$profile_id = $pdo->lastInsertId();

//$stmt = $pdo->prepare('INSERT INTO Position (profile_id, rank, year, description) VALUES ( :pid, :rank, :year, :desc)');

$rank = 1; 
    for ( $i=1 ; $i<=9 ; $i++ ) {
        if (!isset($_POST['year'.$i]) ) continue ;
        if (!isset($_POST['desc'.$i]) ) continue ;
            $year = $_POST['year'.$i];
            $desc = $_POST['desc'.$i];
        $stmt = $pdo->prepare('INSERT INTO position
        (profile_id,rank,year,description)
        VALUES ( :pid , :rank , :year , :desc )');
            $stmt->execute(array(
                ':pid' => $profile_id ,
                ':rank' => $rank ,
                ':year' => $year ,
                ':desc' => $desc
            ));
        $rank++;
    }
$_SESSION['success'] = "added";
header("Location: index.php");
return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
?>

<html>
<div class = "container">
<body>
<h1>Adding profile for Biswanath</h1>
<?php
    //---------------Displaying errors if any----------------------------------------------
if (isset($_SESSION['error']) )
{
    echo("<p style='color:red'>".htmlentities($_SESSION['error'])."</p>");
    unset($_SESSION['error']);
}
//------------------------------------------------------------------

?>

<form method = 'post'>
<p>First Name: 
<input type = 'text' name = 'first_name'>
<p>Last Name:
<input type = 'text'name = 'last_name'>
<p>Email:
<input type = 'text' name = 'email'>
<p>Headline</p>
<input type = 'text' name = 'headline'>
<p>Summary</p>
<input type = 'textarea' name = 'summary' rows="8" cols="80"></textarea>
<p>Position:
<input type='submit' id ='addPos' value='+'>
<div id ="position_fields"></p>
</div>
</p>
<p>
<input type = 'submit' value = 'Add'>
<input type = 'submit' value = 'Cancel' name = 'cancel'>
</p>
</form>
<script>
countPos = 0;

// http://stackoverflow.com/questions/17650776/add-remove-html-inside-div-using-javascript
$(document).ready(function(){
    window.console && console.log('Document ready called');
    $('#addPos').click(function(event){
        // http://api.jquery.com/event.preventdefault/
        event.preventDefault();
        if ( countPos >= 9 ) {
            alert("Maximum of nine position entries exceeded");
            return;
        }
        countPos++;
        window.console && console.log("Adding position "+countPos);
        $('#position_fields').append(
            '<div id="position'+countPos+'"> \
            <p>Year: <input type="text" name="year'+countPos+'" value="" /> \
            <input type="button" value="-" \
                onclick="$(\'#position'+countPos+'\').remove();return false;"></p> \
            <textarea name="desc'+countPos+'" rows="8" cols="80"></textarea>\
            </div>');
    });
});
</script>
</div>
</body>
</html>
