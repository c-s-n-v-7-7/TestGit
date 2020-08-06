<?/*php
    if ( isset($_GET['txt']) ) {

    }
*/?>
<?php
    $error = false ;
    $md5 = false ;
    $code = "" ;
        if ( isset($_GET['code']) ) {
            
            //if (code!==$_GET['code']) code = $_GET['code'] ;

            $code = $_GET['code'];
                if (strlen($code) != 4 ) {
                    $error = "Input must be exactly 4 charecters ";
                }
                else 
                {
                    for ( $i=0 ; $i<4 ; $i++ )
                    {
                        if ( $code[$i] < "0" || $code[$i] > "9" ) 
                            $error = "Input must be from 0-9";
                    }
                }
                if ($error==false)
                    $md5 = hash('md5',$code);
        }
?>
<!DOCTYPE html>
<head><title>Biswanath Dasgupta PIN Code</title></head>
<body>
<h1>MD5 PIN Maker</h1>
<?php
    if ($error!==false)
    {
        print htmlentities($error);
    }
    if ($md5 !== false ) {
        print '<p>MD5 value : '.htmlentities($md5).'</p>';
    }

?>
<pre>Please enter a 4 digit PIN to encode

</pre>

<form>
    <input type = "text" name = "code" size = "60">
    <input type = "submit" value = "Get MD5">

</form>

</body>
</html>