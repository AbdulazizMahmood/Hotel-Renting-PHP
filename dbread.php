
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
		<style>body{
    background-color: #352D24;
}
.container{
    width: 940px;
    margin: auto;
    position: relative;
}
.search{
    overflow: hidden;
}

.search .fieldsearch{
    width: 30%;
    padding: 1%;
    margin: 2.5px;
    border-radius: 5px;
    border:2px solid #fff ;
    border-left: none;
    border-top: none;
    border-right: none;
    
    font-size: 12px;
    background: none;
    color: #fff;
    
}
.search .button{
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
.search .button:hover{
    cursor: pointer;
    background-color:green;
}
h2{
    margin-bottom: 30px;
    margin-top: 60px;
    color: #fff;
}
.list1 li
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
	        <div class="container ">
            
            <div class="search">

                    <form class="form">
                        <button class="button searchc">search customer</button>
                        <button class="button showb"action="allBooking.php" ><a href="allBooking.php" style="text-decoration:none;color:white" >All Booking</a></button>
                    </form>
                                        
           </div>
       </div>
        
        <div class="customer_info">
     <div class="container ">
            <div class="search">
                     <form class="form">
                        <input type="text" placeholder="search" class="fieldsearch">
                    </form>
           </div>
       </div>
	   <div class="container">
	    <h2>customer info</h2>
        <?php
        //2- read from database
        $query="select * from customer";
        $result=  mysqli_query($connect, $query);
        if(! $result){
            die("Error in query");
        }
        ?>
        <ul class="list1">
        <?php
        // 3- write or display data
     
        while($row=  mysqli_fetch_assoc($result)){
        
            echo '<li>Id:'.$row['id']   .' Name:' .$row['name'].' Username:' .$row['username'] .' Password:' .$row['password'].' ssn:' .$row['ssn'].' Email:' .$row['email']."</li>";
        }
     
        ?>
        </ul>
        <?php
        // 4 clear
        mysqli_free_result($result);
        
        ?>
        </div>
		</div>
		
    </body>
</html>
<?php
//5 close connection
mysqli_close($connect);
?>