<?php
$servername = "localhost";
$username = "root";      
$password = "";         
$dbname = "profile_db";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

if(isset($_POST['submit'])){ 
    $user = $_POST['username'];
    $pass = $_POST['password'];

    $sql = "SELECT * FROM users WHERE username='$user'";
    $result = mysqli_query($conn, $sql);
    
    if (mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        $passcheck = $row['password'];

        if($pass != $passcheck) {
            echo "<script> 
                window.onload = function() {
                    document.getElementById('passwordfail').innerHTML = '*Incorrect Password!';
                }
            </script>";
        }
        else{
            echo "<script> 
                window.onload = function() {
                    document.getElementById('success').innerHTML = 'Successfully Logged In!';
                }
            </script>";
        }
    }
    else {
        echo "<script> 
            window.onload = function() {
                document.getElementById('usernamefail').innerHTML = '*User Not Available!';
            }
        </script>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Login</title>
    <style>
        body{ 
            font-family: Arial, sans-serif;
            background:#f6f8fb; 
            padding:20px;
        }
        h2 { color: rgb(2,0,29); text-align: center; }
        form {
            background: #fff;
            padding: 20px;
            border-radius: 10px;
            width: 400px;
            margin: 0 auto 30px auto;
            box-shadow: 0 0 10px #ccc;
        }
        label { display: block; margin-bottom: 5px; font-weight: bold; }
        input {
            width: 100%; padding: 8px; margin-bottom: 5px;
            border: 1px solid #ccc; border-radius: 5px;
        }
        input[type="submit"] {
            background-color: rgb(2,0,29); color: white;
            border: none; cursor: pointer; font-size: 16px;
        }
        input[type="submit"]:hover {
            background-color: white; color: rgb(2,0,29);
            border: 1px solid rgb(2,0,29);
        }
        #success {
            text-align:center;
            color:rgb(0,195,0);
            font-size:25px;
        }
        .dodo {
            display: flex;
            text-align: center;
            align-items: center;
            justify-content: center;
        }
    </style>

    <script>
        function validateForm() {
            let x = document.forms["myform"]["username"].value;
            if(x == "") {
                alert("Name must be filled out");
                return false;
            }
            let z = document.forms["myform"]["password"].value;
            if(z == "") {
                alert("Password must be filled out");
                return false;
            }
            return true;
        }
    </script>
</head>

<body>

<h2>User Login</h2>

<form name="myform" method="POST" onsubmit="return validateForm()">

    <label>Username:</label>
    <input type="text" name="username" required>
    <span id="usernamefail" style="color:red; font-size:14px;"></span>

    <label>Password:</label>
    <input type="password" name="password" required>
    <span id="passwordfail" style="color:red; font-size:14px;"></span>

    <input id="go" type="submit" name="submit" value="Login">
</form>

<div class="dodo">
    <pre>Don't have an account? </pre> <a href="lab_practice15.php">Register</a>
</div>

<div id="success"></div>

</body>
</html>

<?php mysqli_close($conn); ?> 
