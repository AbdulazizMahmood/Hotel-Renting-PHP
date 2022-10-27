<?php?>

<?php ?>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
        <link href="css/styledeletebook.css" rel="stylesheet" type="text/css" media="all" />
    </head>
    <body>
        <h3 style="color: whitesmoke;font-size: 50px;margin-left: 500px"> Welcome </h3>
        <div class="nav">
            <ul>   	
                 <li><a href="index.html">Back</a></li>
                <li ><a href="profilepage.php">My profile</a></li>
                <li ><a href="Updatebooking.php">Update Booking</a></li>
                <li class="active"><a href="DeleteBooking.php">Delete BookinG</a></li>
                <li><a href="ExtendBooking.php">Extend Booking</a></li>
            </ul>
        </div>
        <div class="updatebook-form">
            <form action="#" method="post">
                <input type="text" name="bookid" placeholder="Enter Book ID" required="">
                <div class="tp">
                    <input type="submit" value="Delete">
                </div>
            </form>
        </div>
    </body>

</html>


