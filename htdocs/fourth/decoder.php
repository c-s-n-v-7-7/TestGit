

<html>
<body>
<h1>MD5 CRACKER</h1>
<pre>Debug Output : 
<?php
    $text = "Not Found";
        if ( isset($_GET['md5']) )
        {
            $time_pre = microtime(true) ;
            $md5 = $_GET['md5'] ;

            $gu_show = 16;
                $wee=2 ;
             for ( $i=0 ; ($i<10)&&($wee===2) ; $i++ )
             {
                 for ( $j=0 ; ($j<10)&&($wee==2) ; $j++ )
                 {
                     for ( $k=0 ; ($k<10)&&($wee==2) ; $k++ )
                     {
                         for ( $l=0 ; ($l<10)&&($wee==2) ; $l++ )
                         {
                             $try = $i.$j.$k.$l ;
                             $check = hash('md5',$try);
                             if ($check == $md5)
                             {
                                 $text = $try;
                                 $wee=1 ;
                                 break ;
                             }
                             if ($gu_show>0)
                             {
                                 print "$check $try\n";
                                 $gu_show--;
                             }
                         }
                     }
                 }
             }
             $time_post = microtime(true) ;
             echo "\nTime elapsed :".($time_post-$time_pre);
        }
        
?>
</pre>
<p>PIN: <?=htmlentities($text); ?></p>
<form>
<input type = "text" name = "md5" size = "40">
    <input type = "submit" value = "Crack MD5">
</form>
</body>
</html>