<?php
    include_once 'person.inc';
    if(isset($_POST['username'])&&isset($_POST['password']))
    {
      $p=new person();
      $p->setUsername($_POST['username']);
      $p->setPassword($_POST['password']);
      if($p->Login($p->getUsername(),$p->getPassword(),'admin'))
      {
          header("Location:AddRooms.php");
          exit();
      
      }
      else if($p->Login($p->getUsername(),$p->getPassword(),'customer'))
      {
          header("Location:logged.php");
      }
      else if($p->Login($p->getUsername(),$p->getPassword(),'receptionist'))
      {
           header("Location:AddRooms.php");
      }
      else
      {
          $message="Username or Password are incorrect ";
          echo "<script type='text/javascript'>alert('$message');</script>";
      }
      
      
    }
  
?>
<html>
<head>
<!--Custom Theme files-->
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="keywords" content="Register Login Widget template Responsive, Login form web template,Flat Pricing tables,Flat Drop downs  Sign up Web Templates, Flat Web Templates, Login Signup Responsive web template, SmartPhone Compatible web template, free WebDesigns for Nokia, Samsung, LG, SonyEricsson, Motorola web design" />
<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
<!-- Custom Theme files -->
<link href="css/stylelogin.css" rel="stylesheet" type="text/css" media="all" />
<!--web-fonts-->
<link href='//fonts.googleapis.com/css?family=Jura:400,300,500,600' rel='stylesheet' type='text/css'>
<!--//web-fonts-->
</head>
<body>
	<h1>Register Login Widget</h1>
	<!-- main -->
	<div class="main">
		<!--login-profile-->
		
		<!--login-profile-->
		<!--signin-form-->
		<div class="w3">
			<div class="signin-form profile">
				<h3>Login</h3>
				
				<div class="login-form">
					<form action="login&register.php" method="post">
						<input type="text" name="username" placeholder="username" required="">
						<input type="password" name="password" placeholder="Password" required="">
						<div class="tp">
							<input type="submit" value="LOGIN NOW">
						</div>
					</form>
				</div>
				<div class="header-social wthree">
							<a href="#" class="face"><h5>Facebook</h5></a>
							<a href="#" class="goog"><h5>Google+</h5></a>
							<div class="clear"></div>
						</div>
				<p><a href="#"> Don't have an account?</a></p>
			</div>
		</div>
		<div class="agile">
			<div class="signin-form profile">
				<h3>Register</h3>
				
				<div class="login-form">
					<form action="login&register.php" method="post">
						<input type="text" name="email" placeholder="E-mail" required="">
						<input type="text" name="name" placeholder="Username" required="">
						<input type="password" name="Password" placeholder="Password" required="">
						<input type="text" name="SSN" placeholder="SSN" required="">
						<input type="submit" value="REGISTER">
					</form>
				</div>
				<p><a href="#"> By clicking register, I agree to your terms</a></p>
			</div>
		</div>
		<div class="clear"></div>
		<!--//signin-form-->	
	</div>					
</body>
</html>