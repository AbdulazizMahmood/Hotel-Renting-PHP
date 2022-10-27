<?php
	if(isset($_POST['btnsubmit']))
	{
		echo '<script language="javascript">';
		echo 'alert("Deleted successfully")	';
		echo '</script>';
	} 
?>
<htm lang="ENG-US">
   <head>
        <link href="css/deleteRooms.css" rel="stylesheet" type="text/css" media="all" />
	   <title >Admin Control Panel</title>
	</head>

   <body>
      <div class='welcome'>
          <h1 align='Center' style="color:azure ; font-family:Verdana;">Welcome Admin </h1>
      </div>
    <div class="clear"></div>
	<div class="nav">
		<ul >
				<li><a href="AddRooms.php">Add rooms</a></li>
				<li ><a href="updateRooms.php">Update rooms</a></li>
				<li class="active"><a href="DeleteRooms.php">Delete rooms</a></li>
				
				<li style="margin-left:300px"><a href="addRecep.php">Add Receptionist</a></li>
				<li><a href="updaterecep.php">Update Receptionist</a></li>
				<li><a href="deleteRecep.php">Delete Receptionist</a></li>	 
		</ul>
	 </div>
	 <div class="clear"></div>
     <div class="w3">
		<div class="updateRoom">
			<h3>Update Rooms</h3>
				<div class="searchRooms" >
				   <form>
					   <fieldset>
							<label><input type="text" value="Search" onfocus="if(this.value=='Search'){this.value=''}" onblur="if(this.value==''){this.value='Search'}"></label><input type="image" src="images/search-form-input-img.png" alt="">
						</fieldset>
				   </form>
			   </div>
			<div class="updateRoom-form">
                <form action="DeleteRooms.php" method="post">
						<input type="submit" name="btnsubmit" value="Delete">
				</form>
			</div>
		</div>

	<div class="clear"></div>
  </body>
</html>