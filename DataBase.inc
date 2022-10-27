<?php 
       
  $host = "127.0.0.1"; 
  $database="hotel system";
  $connect = mysqli_connect($host, "root", "", $database);
  

if (!$connect) {
    die('Could not connect to MySQL: ' . mysqli_connect_error());
}
 else {
 echo '<br/>' .  'DONE' .  '<br/>';   
 }   

?>


