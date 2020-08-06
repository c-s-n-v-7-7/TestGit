<?php
$c=0;
for ( $i=0 ; ($i<10) ; $i++ )
{
    for ( $j=0 ; ($j<10) ; $j++ )
        {
            for ( $k=0 ; ($k<10) ; $k++ )
            {
                for ( $l=0 ; ($l<10) ; $l++ )
                {
                    $try = $i.$j.$k.$l;
                    $check = hash('md5',$try);
                    if ($check!==hash('md5',$try))   print $try;
                    else    print   $c++."\n" ;
                }
            }
        }
}
?>