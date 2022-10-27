<?php?>
<htm lang="ENG-US">
   <head>
        <link href="css/deleteR.css" rel="stylesheet" type="text/css" media="all" />
       <title >Admin Control Panel</title>
  </head>

  <body>
      <div class='welcome'>
          <h1 align='Center' style="color:azure ; font-family:Verdana;">Welcome Admin </h1>
      </div>
    <div class="clear"></div>
	<div class="nav">
		<ul>
			<li ><a href="AddRooms.php">Add rooms</a></li>
			<li ><a href="updateRooms.php">Update rooms</a></li>
			<li><a href="DeleteRooms.php">Delete rooms</a></li>

			<li  style="margin-left:300px"><a href="addRecep.php">Add Receptionist</a></li>
			<li ><a href="updaterecep.php">Update Receptionist</a></li>
			<li class="active"><a href="deleteRecep.php">Delete Receptionist</a></li>	 
		</ul>
   </div>
	<div class="clear">
	</div>
    <div class="w3">
			<div class="addRecep">
                <h3>Delete Receptionist</h3>
                <div class="searchRooms" >
				   <form>
					   <fieldset>
							<label><input type="text" value="Search" onfocus="if(this.value=='Search'){this.value=''}" onblur="if(this.value==''){this.value='Search'}"></label><input type="image" src="images/search-form-input-img.png" alt="">
						</fieldset>
				   </form>
			   </div>		
				<div class="addRecep-form">
					<form action="#" method="post">
						<input type="text" name="name" placeholder="Name" required="">
						<input type="text" name="ID" placeholder=" ID" required="">
						<input type="text" name="pass" placeholder=" Password" required="">
						<div class="tp">
							<input type="submit" action="POST" value="Delete">
						</div>
					</form>
				</div>
			</div>
	</div>

	<div class="clear"></div>



  </body>
</html>