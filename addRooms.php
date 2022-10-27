<?php ?>
<htm lang="ENG-US">
    <head>
        <link href="css/addRooms.css" rel="stylesheet" type="text/css" media="all" />
        <title >Admin Control Panel</title>


    </head>

    <body>
        <div class='welcome'>
            <h1 align='Center' style="color:azure ; font-family:Verdana;">Welcome Admin </h1>
        </div>
        <div class="clear"></div>
        <div class="nav">
            <ul>
                <li class="active"><a href="AddRooms.php">Add rooms</a></li>
                <li ><a href="updateRooms.php">Update rooms</a></li>
                <li><a href="DeleteRooms.php">Delete rooms</a></li>

                <li style="margin-left:300px"><a href="addRecep.php">Add Receptionist</a></li>
                <li><a href="updaterecep.php">Update Receptionist</a></li>
                <li><a href="deleteRecep.php">Delete Receptionist</a></li>	 
            </ul>
        </div>
        <div class="clear">
        </div>
        <div class="w3">
            <div class="addRoom">
                <h3>Add Room</h3>	
                <div class="addRoom-form">
                    <form action="#" method="post">
                        <input type="text" name="Rnumber" placeholder=" Room Number" required="">
                        <input type="text" name="email" placeholder=" Type of Room" required="">
                        <input type="text" name="price" placeholder=" Price" required="">
                        <div class="tp">
                            <input type="submit" action="POST" value="ADD">
                        </div>
                    </form>
                </div>
            </div>
        </div>

        <div class="clear"></div>



    </body>
</html>