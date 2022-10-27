		
<?php
// 1- connect to db
$host="127.0.0.1";
$user="root";
$password="";
$database="hotel system";
$connect=  mysqli_connect($host, $user, $password, $database);
if(mysqli_connect_errno()){
    die("cannot connect to database field:". mysqli_connect_error());
    
}
 else {
    echo '</br>';  
}
?>
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
		<style>
		body{
    background-color: #352D24;
}
.container{
    width: 940px;
    margin: auto;
    position: relative;
}


.bttnsearch{
	 padding: 10px;
    margin-top: 20px;
    border-radius: 5px;
    /*background-color:#352D24;*/
    background-color:#4a680a;
    padding-left: 30px;
    padding-right: 30px;
    width: 25%;
    border: none;
    color: #fff;
    font-size: 20px
}
    
.list2 li
{
	font-size:20px;
	color:white;
	display: block;
	font-weight: bold;
	margin-bottom:40px;
	word-spacing:10px;
}
		</style>
    </head>
	<body>
		<div class="container All_Booking">
		
            <button class="bttnsearch">All booking</button>
		
             <?php
		 
        //2- read from database
        $query="select * from booking";
        $result=  mysqli_query($connect, $query);
        if(! $result){
            die("Error in query");
        }
        ?>
        <ul class="list2">
        <?php
        // 3- write or display data
     
        while($row=  mysqli_fetch_assoc($result)){
        
            echo '<li>id:'.$row['id']  .', checkin date:' .$row['checkin'].', checkout date:' .$row['checkout'] .', board_type:' .$row['board_type'].', activation:' .$row['activation'].', customer_id:' .$row['customer_id']."</li>";
        }
     
        ?>
        </ul>
        <?php
        // 4 clear
        mysqli_free_result($result);
        
        ?>         
        </div>
		</body>
		</html>
		<?php
//5 close connection
mysqli_close($connect);
?>