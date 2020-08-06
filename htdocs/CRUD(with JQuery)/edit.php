<title>101ca20bBiswanathDasGupta</title>
<head><link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.2.1.js" integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE=" crossorigin="anonymous"></script>
</head>

<?php 
session_start();
require_once "pdo.php";
require_once "util.php";

if (!isset($_SESSION['name']))
    die("Not logged in");
if (!isset($_REQUEST['profile_id']))
    {
        $_SESSION['error'] = "Missing profile_id";
        header("Location: index.php");
        return;
    }
if (isset($_POST['cancel']))
{
    unset($_SESSION['error']);
    header("Location: index.php");
    return ;
}

if (isset($_POST['first_name'])&&isset($_POST['last_name'])&&isset($_POST['email'])&&isset($_POST['headline'])&&isset($_POST['summary']) )
{

$e = validateProfile();
if (is_string($e))
{
    $_SESSION['error'] = $e ;
    header("Location: edit.php?profile_id=".urlencode($_REQUEST['profile_id']));
    return;
}
$e = validatePos();
if (is_string($e))
{
    $_SESSION['error'] = $e ;
    header("Location: edit.php?profile_id=".urlencode($_REQUEST['profile_id']));
    return;
}
else
{
    $stmt = $pdo->prepare("UPDATE profile SET first_name = :fn, last_name = :ln, email=:em , headline=:he ,summary = :su  WHERE profile_id = :pi AND user_id = :ui ");
    $stmt->execute(array(
        ':pi' => $_REQUEST['profile_id'],
        ':ui' =>$_SESSION['user_id'],
        ':fn' => $_POST['first_name'],
        ':ln' => $_POST['last_name'], 
        ':em' => $_POST['email'], 
        ':he' => $_POST['headline'],
        ':su' => $_POST['summary']
    ));
    
    
    
    $sql = "DELETE FROM position WHERE profile_id = :pi";
    $stmt = $pdo->prepare($sql);
        $stmt->execute(array(':pi'=>$_POST['profile_id']));
        $stmt = $pdo->prepare('DELETE FROM Position
        WHERE profile_id=:pid');
    $stmt->execute(array( ':pid' => $_REQUEST['profile_id']));

    // Insert the position entries
    $rank = 1;
    for($i=1; $i<=9; $i++) {
        if ( ! isset($_POST['year'.$i]) ) continue;
        if ( ! isset($_POST['desc'.$i]) ) continue;
        $year = $_POST['year'.$i];
        $desc = $_POST['desc'.$i];
        $stmt = $pdo->prepare('INSERT INTO Position
                              (profile_id, rank, year, description)
                               VALUES ( :pid, :rank, :year, :desc)');
        $stmt->execute(array(
            ':pid' => $_REQUEST['profile_id'],
            ':rank' => $rank,
            ':year' => $year,
            ':desc' => $desc)
        );
        $rank++;
    }
        header("Location: index.php");
        return;
}
}
$sql = "SELECT * FROM profile WHERE profile_id = :pi AND user_id= :ui";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(':pi'=>$_GET['profile_id'],':ui'=>$_SESSION['user_id']));
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
    if (!$row)
    {
        $_SESSION['error'] = "Could not load profile";
        header("Location: index.php");
        return;
    }  
        $fn = htmlentities($row['first_name']);
        $ln = htmlentities($row['last_name']);
        $hl = htmlentities($row['headline']);
        $em = htmlentities($row['email']);
        //echo (htmlentities($em));
        $su = htmlentities($row['summary']);
        $profile_id = $row['profile_id'];
    //$sql = ("SELECT year,description FROM position WHERE profile_id = :pi ORDER BY rank DESC ");
    //$stmt = $pdo->execute(array(':pi'=>profile_id));
    
?>
<body>

<div class = "container">
<h1> Editing profile for <?=htmlentities($_SESSION['name'])?></h1>
<?php
    //---------------Displaying errors if any----------------------------------------------
if (isset($_SESSION['error'])){
    //header("Location: edit.php?profile_id=".urlencode($_GET['profile_id']));
    echo("<p style='color:red'>".htmlentities($_SESSION['error'])."</p>");
    unset($_SESSION['error']);
}
//------------------------------------------------------------------

?>
<script
  src="https://code.jquery.com/jquery-3.2.1.js"
  integrity="sha256-DZAnKJ/6XZ9si04Hgrsxu/8s717jcIzLy3oi35EouyE="
  crossorigin="anonymous"></script>
<form method = 'post' action="edit.php">
<p>First Name: 
<input type = 'text' name = 'first_name' value = '<?= $fn ?>'>
<input type = 'hidden' name = 'profile_id' value = '<?=$_REQUEST['profile_id']?>'>
<p>Last Name:
<input type = 'text'name = 'last_name' value = '<?= $ln ?>'>
<p>Email:
<input type = 'text' name = 'email' value = '<?= $em ?> '>    
<p>Headline</p>
<input type = 'text' name = 'headline' value = '<?= $hl ?>'>
<input type = 'hidden' name = 'profile_id' value = '<?= $profile_id?>'>
<p>Summary</p>
<textarea name = 'summary'><?= $su ?></textarea><br/>
<p>Position: <input type="submit" id="addPos" value="+">
<div id="position_fields">
</div></p>
</p>
<p>
<input type = 'submit' value = 'Save'>
<input type = 'submit' value = 'Cancel' name = 'cancel'>
</p>
</form>


<?php
    $pos = 0 ;
$stmt = $pdo->prepare("SELECT * FROM  position WHERE profile_id = :pid ORDER BY rank");
    $stmt->execute(array( ':pid'=> $_REQUEST['profile_id']) );
    while ( $row = $stmt->fetch(PDO::FETCH_ASSOC))
    {
    echo("<script>"."$('#position_fields').append(
        '<div id=\"position'+".htmlentities($row['rank'])."+'\"> \
        <p>Year: <input type=\"text\" name=\"year'+".htmlentities($row['rank'])."+'\" value=\"".htmlentities($row['year'])."\" /> \
        <input type=\"button\" value=\"-\" \
        onclick=\"$(\'#position'+".htmlentities($row['rank'])."+'\').remove();--countPos;return false;\"></p> \
        <textarea name=\"desc'+".htmlentities($row['rank'])."+'\" rows=\"8\" cols=\"80\">".htmlentities($row['description'])."</textarea>\
        </div>');"."</script>");
    $pos++;
    }
   // echo ("!!!!!!!!!!!!!!".$pos."");
?>

<script>

countPos = <?= $pos ?>;
    
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
            onclick="$(\'#position'+countPos+'\').remove();--countPos;return false;"></p> \
            <textarea name="desc'+countPos+'" rows="8" cols="80"></textarea>\
            </div>');
    });
});
</script>
</div>
</html>